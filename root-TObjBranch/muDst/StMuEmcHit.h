//////////////////////////////////////////////////////////
//   This class has been generated by TFile::MakeProject
//     (Mon Jul 23 18:55:02 2018 by ROOT version 6.13/04)
//      from the StreamerInfo in file sb/install-star-cvs-deb-32-root5-gcc4/st_physics_17135012_raw_2000025.MuDst.root
//////////////////////////////////////////////////////////


#ifndef StMuEmcHit_h
#define StMuEmcHit_h
class StMuEmcHit;

#include "Rtypes.h"
#include "TObject.h"

class StMuEmcHit : public TObject {

public:
// Nested classes declaration.

public:
// Data Members.
   float       mEnergy;     //
   short       mId;         //
   short       mAdc;        //
   char        mCalType;    //

   StMuEmcHit();
   StMuEmcHit(const StMuEmcHit & );
   virtual ~StMuEmcHit();

   ClassDef(StMuEmcHit,3); // Generated by MakeProject.
};
#endif
