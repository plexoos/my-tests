//////////////////////////////////////////////////////////
//   This class has been generated by TFile::MakeProject
//     (Mon Jul 23 18:55:02 2018 by ROOT version 6.13/04)
//      from the StreamerInfo in file sb/install-star-cvs-deb-32-root5-gcc4/st_physics_17135012_raw_2000025.MuDst.root
//////////////////////////////////////////////////////////


#ifndef StMuTofHit_h
#define StMuTofHit_h
class StMuTofHit;

#include "Rtypes.h"
#include "StObject.h"
#include "StThreeVector_float_.h"

class StMuTofHit : public StObject {

public:
// Nested classes declaration.

public:
// Data Members.
   Int_t       mIconf;      //
   Int_t       mTrayIndex;    //
   Int_t       mModuleIndex;    //
   Int_t       mCellIndex;      //
   Int_t       mDaqIndex;       //
   Int_t       mADC;            //
   Float_t     mTimeOfFlight;    //
   Float_t     mPathLength;      //
   Float_t     mBeta;            //
   Int_t       mAssociatedTrackId;    //
   StThreeVector<float> mProjectedPoint;       //
   Float_t              mTOFExpectedAsElectron;    //
   Float_t              mTOFExpectedAsPion;        //
   Float_t              mTOFExpectedAsKaon;        //
   Float_t              mTOFExpectedAsProton;      //
   Float_t              mSigmaElectron;            //
   Float_t              mSigmaPion;                //
   Float_t              mSigmaKaon;                //
   Float_t              mSigmaProton;              //
   Int_t                mParticleHypothesis;       //

   StMuTofHit();
   StMuTofHit(const StMuTofHit & );
   virtual ~StMuTofHit();

   ClassDef(StMuTofHit,2); // Generated by MakeProject.
};
#endif
