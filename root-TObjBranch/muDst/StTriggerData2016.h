//////////////////////////////////////////////////////////
//   This class has been generated by TFile::MakeProject
//     (Mon Jul 23 18:55:02 2018 by ROOT version 6.13/04)
//      from the StreamerInfo in file sb/install-star-cvs-deb-32-root5-gcc4/st_physics_17135012_raw_2000025.MuDst.root
//////////////////////////////////////////////////////////


#ifndef StTriggerData2016_h
#define StTriggerData2016_h
class StTriggerData2016;

#include "Rtypes.h"
#include "StTriggerData.h"
#include "TriggerDataBlk2016.h"

class StTriggerData2016 : public StTriggerData {

public:
// Nested classes declaration.

public:
// Data Members.
   TriggerDataBlk2016* mData;       //
   unsigned short      mxq[11][16][32];    //
   unsigned short      feq[11][16][32];    //
   unsigned short      bbq[11][16][32];    //
   unsigned short      qt1[11][16][32];    //
   unsigned short      qt2[11][16][32];    //
   unsigned short      qt3[11][16][32];    //
   unsigned char       tmxq[11][16][32];    //
   unsigned char       tfeq[11][16][32];    //
   unsigned char       tbbq[11][16][32];    //
   unsigned char       tqt1[11][16][32];    //
   unsigned char       tqt2[11][16][32];    //
   unsigned char       tqt3[11][16][32];    //

   StTriggerData2016();
   StTriggerData2016(const StTriggerData2016 & );
   virtual ~StTriggerData2016();

   ClassDef(StTriggerData2016,2); // Generated by MakeProject.
};
#endif
