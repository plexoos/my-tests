//////////////////////////////////////////////////////////
//   This class has been generated by TFile::MakeProject
//     (Mon Jul 23 18:55:02 2018 by ROOT version 6.13/04)
//      from the StreamerInfo in file sb/install-star-cvs-deb-32-root5-gcc4/st_physics_17135012_raw_2000025.MuDst.root
//////////////////////////////////////////////////////////


#ifndef StTrigger_h
#define StTrigger_h
class StTrigger;

#include "Rtypes.h"
#include "StObject.h"

class StTrigger : public StObject {

public:
// Nested classes declaration.

public:
// Data Members.
   UInt_t      mTriggerActionWord;    //
   UInt_t      mTriggerWord;          //

   StTrigger();
   StTrigger(const StTrigger & );
   virtual ~StTrigger();

   ClassDef(StTrigger,3); // Generated by MakeProject.
};
#endif
