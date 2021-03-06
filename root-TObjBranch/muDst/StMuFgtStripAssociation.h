//////////////////////////////////////////////////////////
//   This class has been generated by TFile::MakeProject
//     (Mon Jul 23 18:55:02 2018 by ROOT version 6.13/04)
//      from the StreamerInfo in file sb/install-star-cvs-deb-32-root5-gcc4/st_physics_17135012_raw_2000025.MuDst.root
//////////////////////////////////////////////////////////


#ifndef StMuFgtStripAssociation_h
#define StMuFgtStripAssociation_h
class StMuFgtStripAssociation;

#include "Rtypes.h"
#include "TObject.h"

class StMuFgtStripAssociation : public TObject {

public:
// Nested classes declaration.

public:
// Data Members.
   Int_t       mClusIdx;    //index of the cluster in the muFgtClusters TClonesArray
   Int_t       mStripIdx;    //index of the strip in the muFgtStrips TClonesArray
   Float_t     mWeight;      //membership weight of the strip in the given cluster.

   StMuFgtStripAssociation();
   StMuFgtStripAssociation(const StMuFgtStripAssociation & );
   virtual ~StMuFgtStripAssociation();

   ClassDef(StMuFgtStripAssociation,2); // Generated by MakeProject.
};
#endif
