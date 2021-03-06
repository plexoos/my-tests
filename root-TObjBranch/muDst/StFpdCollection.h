//////////////////////////////////////////////////////////
//   This class has been generated by TFile::MakeProject
//     (Mon Jul 23 18:55:02 2018 by ROOT version 6.13/04)
//      from the StreamerInfo in file sb/install-star-cvs-deb-32-root5-gcc4/st_physics_17135012_raw_2000025.MuDst.root
//////////////////////////////////////////////////////////


#ifndef StFpdCollection_h
#define StFpdCollection_h
class StFpdCollection;

#include "Rtypes.h"
#include "StObject.h"

class StFpdCollection : public StObject {

public:
// Nested classes declaration.

public:
// Data Members.
   UShort_t    mAdc[256];    //
   UShort_t    mTdc[8];      //
   UShort_t    mReg[3];      //
   UShort_t    mPed[256];    //
   UInt_t      mScl[128];    //
   UShort_t    mToken;       //

   StFpdCollection();
   StFpdCollection(const StFpdCollection & );
   virtual ~StFpdCollection();

   ClassDef(StFpdCollection,3); // Generated by MakeProject.
};
#endif
