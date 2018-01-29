#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>

#include "TChain.h"
#include "TFile.h"
#include "TTree.h"

#include "muDst/StMuPrimaryTrackCovariance.h"
#include "muDst/StDcaGeometry.h"
#include "muDst/StMuTrack.h"

#include "TObjBranch.h"


void write_tree();
void read_tree();
void print(const StMuTrack& track);


int main(int argc, char **argv)
{
   enum class Mode { Read, Write};

   std::string arg1 = argc > 1 ? std::string(argv[1]) : "";

   Mode mode = (arg1 == "read" ? Mode::Read : Mode::Write);

   std::srand(std::time(0));

   switch (mode)
   {
   case Mode::Read:
      std::cout << "\nReading events from tree...\n";
      read_tree();
      break;

   case Mode::Write:
   default:
      std::cout << "\nWriting events into tree...\n";
      write_tree();
   }

   return EXIT_SUCCESS;
}


void write_tree()
{
   TFile out_file("out_file.root", "RECREATE");
   TTree out_tree("MuDst", "My Test TTree", 99, &out_file);

   TObjTree objTree(out_tree);

   auto& glob_tracks = objTree.WriteTCA< StMuTrack >("GlobalTracks");
   auto& prim_tracks = objTree.WriteTCA< StMuTrack >("PrimaryTracks");

   StMuTrack* track;
   int track_index;

   const int n_events = 10;
   const int n_tracks = 5;

   std::cout << "n_events: " << n_events << "\n";
   std::cout << "n_tracks/event: " << n_tracks << "\n";

   for (int i_event = 0; i_event < n_events; i_event++)
   {
      glob_tracks.Clear();

      for (int i_track = 0; i_track < n_tracks; i_track++)
      {
         std::tie(track, track_index) = glob_tracks.AddObj();
         track->mId = 700 + track_index;
      }

      out_tree.Fill();
   }

   out_tree.Write();
   out_file.Close();
}


void read_tree()
{
   TChain chain("MuDst", "My Test TTree");

   chain.SetBranchStatus("*", 0);
   chain.SetBranchStatus("GlobalTracks.*", 1);
   chain.SetBranchStatus("CovGlobTrack.*", 1);
   chain.SetBranchStatus("PrimaryTracks.*", 1);
   chain.SetBranchStatus("CovPrimTrack.*", 1);

   chain.AddFile("/scratch/smirnovd/random_tests/st_physics_19129011_raw_5500026.MuDst.root");
   //chain.AddFile("out_file.root");

   TObjTree objTree(chain);

   auto& glob_tracks     = objTree.ReadTCA< StMuTrack >("GlobalTracks");
   auto& glob_tracks_cov = objTree.ReadTCA< StDcaGeometry >("CovGlobTrack");
   auto& prim_tracks     = objTree.ReadTCA< StMuTrack >("PrimaryTracks");
   auto& prim_tracks_cov = objTree.ReadTCA< StMuPrimaryTrackCovariance >("CovPrimTrack");

   const int n_events = chain.GetEntries();

   std::cout << "n_events: " << n_events << "\n";

   for (int i_event = 0; i_event < std::min(3, n_events); i_event++)
   {
      chain.GetEntry(i_event);

      int n_glob_tracks     = glob_tracks.GetSize();
      int n_glob_tracks_cov = glob_tracks_cov.GetSize();
      int n_prim_tracks     = prim_tracks.GetSize();
      int n_prim_tracks_cov = prim_tracks_cov.GetSize();

      int n_records = std::min( {2, n_glob_tracks, n_glob_tracks_cov, n_prim_tracks, n_prim_tracks_cov} );

      std::cout << "i_event: "             << i_event << "\n"
                << "  n_glob_tracks: "     << n_glob_tracks
                << "  n_glob_tracks_cov: " << n_glob_tracks_cov
                << "  n_prim_tracks: "     << n_prim_tracks
                << "  n_prim_tracks_cov: " << n_prim_tracks_cov
                << "\n"
                << "  records to read: "   << n_records << "\n";

      std::cout << "Primary tracks:\n";

      for (int i_track = 1; i_track <= n_records; i_track++)
      {
         std::cout << "  " << "track: " << i_track << "\n";

         StMuTrack& track = prim_tracks.GetObj(i_track-1);
         print(track);

         StMuPrimaryTrackCovariance& track_cov = prim_tracks_cov.GetObj(i_track-1);
         track_cov.Dump();
      }

      std::cout << "Global tracks:\n";

      for (int i_track = 1; i_track <= n_records; i_track++)
      {
         std::cout << "  " << "track: " << i_track << "\n";

         StMuTrack& track = glob_tracks.GetObj(i_track-1);
         print(track);

         StDcaGeometry& track_cov = glob_tracks_cov.GetObj(i_track-1);
         track_cov.Dump();
      }

      std::cout << std::endl;
   }
}



void print(const StMuTrack& track)
{
   std::cout
   <<   "  " << "mId                      : " <<  (int)track.mId
   << "\n  " << "mType                    : " <<  (int)track.mType
   << "\n  " << "mFlag                    : " <<  (int)track.mFlag
   << "\n  " << "mFlagExtension           : " <<  (int)track.mFlagExtension
   << "\n  " << "mIndex2Global            : " <<  (int)track.mIndex2Global
   << "\n  " << "mIndex2RichSpectra       : " <<  (int)track.mIndex2RichSpectra
   << "\n  " << "mIndex2BTofHit           : " <<  (int)track.mIndex2BTofHit
   << "\n  " << "mIndex2MtdHit            : " <<  (int)track.mIndex2MtdHit
   << "\n  " << "mVertexIndex             : " <<  (int)track.mVertexIndex
   << "\n  " << "mNHits                   : " <<  (int)track.mNHits
   << "\n  " << "mNHitsPoss               : " <<  (int)track.mNHitsPoss
   << "\n  " << "mNHitsDedx               : " <<  (int)track.mNHitsDedx
   << "\n  " << "mNHitsFit                : " <<  (int)track.mNHitsFit
   << "\n  " << "mNHitsPossInner          : " <<  (int)track.mNHitsPossInner
   << "\n  " << "mNHitsFitInner           : " <<  (int)track.mNHitsFitInner
   << "\n  " << "mNHitsPossTpc            : " <<  (int)track.mNHitsPossTpc
   << "\n  " << "mNHitsFitTpc             : " <<  (int)track.mNHitsFitTpc
   << "\n  " << "mPidProbElectron         : " <<  (int)track.mPidProbElectron
   << "\n  " << "mPidProbPion             : " <<  (int)track.mPidProbPion
   << "\n  " << "mPidProbKaon             : " <<  (int)track.mPidProbKaon
   << "\n  " << "mPidProbProton           : " <<  (int)track.mPidProbProton
   << "\n  " << "mNSigmaElectron          : " <<  (int)track.mNSigmaElectron
   << "\n  " << "mNSigmaPion              : " <<  (int)track.mNSigmaPion
   << "\n  " << "mNSigmaKaon              : " <<  (int)track.mNSigmaKaon
   << "\n  " << "mNSigmaProton            : " <<  (int)track.mNSigmaProton
   << "\n  " << "mdEdx                    : " <<  track.mdEdx
   << "\n  " << "mChiSqXY                 : " <<  track.mChiSqXY
   << "\n  " << "mChiSqZ                  : " <<  track.mChiSqZ
   << "\n  " << "mPt                      : " <<  track.mPt
   << "\n  " << "mEta                     : " <<  track.mEta
   << "\n  " << "mPhi                     : " <<  track.mPhi
   << "\n  " << "mMap0, mMap1             : " <<  track.mTopologyMap.mMap0 << ", " <<  track.mTopologyMap.mMap1
   << "\n  " << "mP                       : " <<  track.mP.mX1 << ", " <<  track.mP.mX2 << ", " <<  track.mP.mX3
   << "\n  " << "mDCA                     : " <<  track.mDCA.mX1 << ", " <<  track.mDCA.mX2 << ", " <<  track.mDCA.mX3
   << "\n  " << "mDCAGlobal               : " <<  track.mDCAGlobal.mX1 << ", " <<  track.mDCAGlobal.mX2 << ", " <<  track.mDCAGlobal.mX3
   << "\n  " << "mFirstPoint              : " <<  track.mFirstPoint.mX1 << ", " <<  track.mFirstPoint.mX2 << ", " <<  track.mFirstPoint.mX3
   << "\n  " << "mLastPoint               : " <<  track.mLastPoint.mX1 << ", " <<  track.mLastPoint.mX2 << ", " <<  track.mLastPoint.mX3
   << "\n  " << "mIndex2Cov               : " <<  (int)track.mIndex2Cov
   << "\n  " << "mIdTruth                 : " <<  (int)track.mIdTruth
   << "\n  " << "mQuality                 : " <<  (int)track.mQuality
   << "\n  " << "mIdParentVx              : " <<  (int)track.mIdParentVx
   << "\n";
}
