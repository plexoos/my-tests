//////////////////////////////////////////////////////////
//   This class has been generated by TFile::MakeProject
//     (Mon Jul 23 18:55:02 2018 by ROOT version 6.13/04)
//      from the StreamerInfo in file sb/install-star-cvs-deb-32-root5-gcc4/st_physics_17135012_raw_2000025.MuDst.root
//////////////////////////////////////////////////////////


#ifndef StMuL3EventSummary_h
#define StMuL3EventSummary_h
class StMuL3EventSummary;

#include "Rtypes.h"
#include "TObject.h"
#include "StThreeVector_float_.h"

class StMuL3EventSummary : public TObject {

public:
// Nested classes declaration.

public:
// Data Members.
   int         mNumberOfProcessedEvents;    //
   int         mNumberReconstructedEvents;    //
   int         mNumberOfTracks;               //
   int         mNumberOfAlgorithms;           //
   unsigned char mFlags;                        //* bit mask 1=mZVertexTrigger; bit mask mUnbiasedTrigger; *
   unsigned int  mL0TriggerWord;                //
   int           mUnbiasedPreScale;             //
   StThreeVector<float> mPrimaryVertex;                //

   StMuL3EventSummary();
   StMuL3EventSummary(const StMuL3EventSummary & );
   virtual ~StMuL3EventSummary();

   ClassDef(StMuL3EventSummary,2); // Generated by MakeProject.
};
#endif
