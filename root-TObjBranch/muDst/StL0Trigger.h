//////////////////////////////////////////////////////////
//   This class has been generated by TFile::MakeProject
//     (Mon Jul 23 18:55:02 2018 by ROOT version 6.13/04)
//      from the StreamerInfo in file sb/install-star-cvs-deb-32-root5-gcc4/st_physics_17135012_raw_2000025.MuDst.root
//////////////////////////////////////////////////////////


#ifndef StL0Trigger_h
#define StL0Trigger_h
class StL0Trigger;

#include "Rtypes.h"
#include "StTrigger.h"

class StL0Trigger : public StTrigger {

public:
// Nested classes declaration.

public:
// Data Members.
   Int_t       mCoarsePixelArray[32];    //
   Int_t       mMwcCtbMultiplicity;      //
   Int_t       mMwcCtbDipole;            //
   Int_t       mMwcCtbTopology;          //
   Int_t       mMwcCtbMoment;            //
   UShort_t    mDsmInput;                //
   UChar_t     mDetectorBusy;            //
   UShort_t    mTriggerToken;            //
   UShort_t    mDsmAddress;              //
   UChar_t     mAddBits;                 //
   UShort_t    mLastDsmArray[8];         //
   UShort_t    mBcDataArray[16];         //

   StL0Trigger();
   StL0Trigger(const StL0Trigger & );
   virtual ~StL0Trigger();

   ClassDef(StL0Trigger,3); // Generated by MakeProject.
};
#endif
