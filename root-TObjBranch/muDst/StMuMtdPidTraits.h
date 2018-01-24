//////////////////////////////////////////////////////////
//   This class has been generated by TFile::MakeProject
//     (Mon Jul 23 18:55:02 2018 by ROOT version 6.13/04)
//      from the StreamerInfo in file sb/install-star-cvs-deb-32-root5-gcc4/st_physics_17135012_raw_2000025.MuDst.root
//////////////////////////////////////////////////////////


#ifndef StMuMtdPidTraits_h
#define StMuMtdPidTraits_h
class StMuMtdPidTraits;

#include "Rtypes.h"
#include "TObject.h"
#include "StThreeVector_float_.h"

class StMuMtdPidTraits : public TObject {

public:
// Nested classes declaration.

public:
// Data Members.
   UChar_t     mMatchFlag;    //
   Float_t     mYLocal;       //
   Float_t     mZLocal;       //
   Float_t     mThetaLocal;    //
   StThreeVector<float> mPosition;      //
   Float_t              mTimeOfFlight;    //Measured time-of-flight
   Float_t              mPathLength;      //Path length obtained from track extrapolation
   Float_t              mBeta;            //
   Float_t              mSigmaMuon;       //
   Float_t              mProbMuon;        //
   Float_t              mExpTimeOfFlight;    //Expected time-of-flight obtained from track extrapolation
   Float_t              mDeltaY;             //DeltaY between matched track-hit pair
   Float_t              mDeltaZ;             //DeltaZ between matched track-hit pair

   StMuMtdPidTraits();
   StMuMtdPidTraits(const StMuMtdPidTraits & );
   virtual ~StMuMtdPidTraits();

   ClassDef(StMuMtdPidTraits,4); // Generated by MakeProject.
};
#endif
