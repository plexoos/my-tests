//////////////////////////////////////////////////////////
//   This class has been generated by TFile::MakeProject
//     (Mon Jul 23 18:55:02 2018 by ROOT version 6.13/04)
//      from the StreamerInfo in file sb/install-star-cvs-deb-32-root5-gcc4/st_physics_17135012_raw_2000025.MuDst.root
//////////////////////////////////////////////////////////


#ifndef StKinkBase_h
#define StKinkBase_h
class StKinkBase;

#include "Rtypes.h"
#include "StStrangeMuDst.h"
#include "StKinkI.h"

class StKinkBase : public StStrangeMuDst , public StKinkI {

public:
// Nested classes declaration.

public:
// Data Members.
   Int_t       mParentGeantId;    //
   Int_t       mDaughterGeantId;    //
   Float_t     mParentMomentumX;    //
   Float_t     mParentMomentumY;    //
   Float_t     mParentMomentumZ;    //
   Float_t     mParentPrimMomentumX;    //
   Float_t     mParentPrimMomentumY;    //
   Float_t     mParentPrimMomentumZ;    //
   Float_t     mDaughterMomentumX;      //
   Float_t     mDaughterMomentumY;      //
   Float_t     mDaughterMomentumZ;      //
   Float_t     mPositionX;              //
   Float_t     mPositionY;              //
   Float_t     mPositionZ;              //

   StKinkBase();
   StKinkBase(const StKinkBase & );
   virtual ~StKinkBase();

   ClassDef(StKinkBase,7); // Generated by MakeProject.
};
#endif
