//////////////////////////////////////////////////////////
//   This class has been generated by TFile::MakeProject
//     (Mon Jul 23 18:55:02 2018 by ROOT version 6.13/04)
//      from the StreamerInfo in file sb/install-star-cvs-deb-32-root5-gcc4/st_physics_17135012_raw_2000025.MuDst.root
//////////////////////////////////////////////////////////


#ifndef StMuPrimaryTrackCovariance_h
#define StMuPrimaryTrackCovariance_h
class StMuPrimaryTrackCovariance;

#include "Rtypes.h"
#include "TObject.h"

class StMuPrimaryTrackCovariance : public TObject {

public:
// Nested classes declaration.

public:
// Data Members.
   Float_t     mTanTan;     //Psi = azimuthal angle of pT vector (deg)     
   Float_t     mPsiTan;     //
   Float_t     mPsiPsi;     //Tan = tan(dip) =pz/pt at start               
   Float_t     mPtiTan;     //
   Float_t     mPtiPsi;     //
   Float_t     mPtiPti;     //Pti = 1/pt at start (GeV/c)^(-1)             

   StMuPrimaryTrackCovariance();
   StMuPrimaryTrackCovariance(const StMuPrimaryTrackCovariance & );
   virtual ~StMuPrimaryTrackCovariance();

   ClassDef(StMuPrimaryTrackCovariance,2); // Generated by MakeProject.
};
#endif
