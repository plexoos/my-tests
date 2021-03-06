//////////////////////////////////////////////////////////
//   This class has been generated by TFile::MakeProject
//     (Mon Jul 23 18:55:02 2018 by ROOT version 6.13/04)
//      from the StreamerInfo in file sb/install-star-cvs-deb-32-root5-gcc4/st_physics_17135012_raw_2000025.MuDst.root
//////////////////////////////////////////////////////////


#ifndef StV0MuDst_h
#define StV0MuDst_h
class StV0MuDst;

#include "Rtypes.h"
#include "StStrangeMuDst.h"
#include "StV0I.h"
#include "StTrackTopologyMap.h"

class StV0MuDst : public StStrangeMuDst , public StV0I {

public:
// Nested classes declaration.

public:
// Data Members.
   Float_t     mDecayVertexV0X;    //These are written out
   Float_t     mDecayVertexV0Y;    //
   Float_t     mDecayVertexV0Z;    //
   Float_t     mDcaV0Daughters;    //
   Float_t     mDcaV0ToPrimVertex;    //
   Float_t     mDcaPosToPrimVertex;    //
   Float_t     mDcaNegToPrimVertex;    //
   Float_t     mMomPosX;               //
   Float_t     mMomPosY;               //
   Float_t     mMomPosZ;               //
   Float_t     mMomNegX;               //
   Float_t     mMomNegY;               //
   Float_t     mMomNegZ;               //
   Int_t       mKeyPos;                //
   Int_t       mKeyNeg;                //
   StTrackTopologyMap mTopologyMapPos;        //
   StTrackTopologyMap mTopologyMapNeg;        //
   Float_t            mChi2V0;                //
   Float_t            mClV0;                  //
   Float_t            mChi2Pos;               //
   Float_t            mClPos;                 //
   Float_t            mChi2Neg;               //
   Float_t            mClNeg;                 //
   Float_t            mDedxPos;               //
   Float_t            mDedxNeg;               //
   Float_t            mErrDedxPos;            //
   Float_t            mErrDedxNeg;            //
   UShort_t           mNumDedxPos;            //
   UShort_t           mNumDedxNeg;            //

   StV0MuDst();
   StV0MuDst(const StV0MuDst & );
   virtual ~StV0MuDst();

   ClassDef(StV0MuDst,8); // Generated by MakeProject.
};
#endif
