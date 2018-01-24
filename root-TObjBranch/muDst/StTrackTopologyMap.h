//////////////////////////////////////////////////////////
//   This class has been generated by TFile::MakeProject
//     (Mon Jul 23 18:55:02 2018 by ROOT version 6.13/04)
//      from the StreamerInfo in file sb/install-star-cvs-deb-32-root5-gcc4/st_physics_17135012_raw_2000025.MuDst.root
//////////////////////////////////////////////////////////


#ifndef StTrackTopologyMap_h
#define StTrackTopologyMap_h
class StTrackTopologyMap;

#include "Rtypes.h"
#include "StObject.h"

class StTrackTopologyMap : public StObject {

public:
// Nested classes declaration.

public:
// Data Members.
   UInt_t      mMap0;       //
   UInt_t      mMap1;       //
   ULong64_t   mMap_iTpc;    //

   StTrackTopologyMap();
   StTrackTopologyMap(const StTrackTopologyMap & );
   virtual ~StTrackTopologyMap();

   ClassDef(StTrackTopologyMap,3); // Generated by MakeProject.
};
#endif
