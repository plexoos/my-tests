#include "TCanvas.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"
#include "TROOT.h"


TH1D  h_G_zer("h_G_zer", "h_G_zer", 21, 0, 21);
TH1D  h_F_zer("h_F_zer", "h_F_zer", 36, 0, 36);


/**
 * This macro can be used to produce a csv file with values sampling the input
 * to StiTrackNode::errPropag6(). The values are extracted from a ROOT tree
 * saved in a file.
 */
void calc_zero_freq(std::string fileName)
{
   TFile file_in(fileName.c_str(), "READ");

   file_in.ls();

   TTree* tree_in = dynamic_cast<TTree*>( file_in.Get("t") );

   tree_in->Print();

   double G[21];
   double F[6][6];

   tree_in->SetBranchAddress("g", G);
   tree_in->SetBranchAddress("f", F);

   for (int i_event = 0; i_event < tree_in->GetEntries(); ++i_event)
   {
      //std::cout << "i_event: " << i_event << "\n";

      tree_in->GetEntry(i_event);

      for (int i_bin = 0; i_bin < 21; ++i_bin)
      {
         if ( G[i_bin] == 0 )
            h_G_zer.AddBinContent(i_bin + 1);
      }

      for (int i_bin = 0; i_bin < 36; ++i_bin)
      {
         if ( *(F[0] + i_bin) == 0 )
            h_F_zer.AddBinContent(i_bin + 1);
      }

      //std::cout << "G: ";
      //std::copy(G, G+21, std::ostream_iterator<double>(std::cout, ", "));
      //std::cout << "\n";

      //std::cout << "F: ";
      //std::copy(&F[0][0], &F[0][0]+36, std::ostream_iterator<double>(std::cout, ", "));
      //std::cout << "\n";
   }

   h_G_zer.Scale(1./tree_in->GetEntries());
   h_G_zer.Print("all");

   h_F_zer.Scale(1./tree_in->GetEntries());
   h_F_zer.Print("all");
}
