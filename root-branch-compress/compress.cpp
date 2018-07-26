#include <string>
#include <cmath>

#include "TFile.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TH1.h"
#include "TMath.h"
#include "TRandom3.h"
#include "TGraph.h"
#include "TLegend.h"
#include "TFrame.h"
#include "TPaveLabel.h"

#include "DemoDouble32.h"


// show the use and precision of the Double32_t data type
int main()
{
   DemoDouble32 *d = new DemoDouble32();

   //create a Tree with 40000 objects DemoDouble32
   TFile::Open("DemoDouble32.root","recreate", "title", 9);
   TTree *T = new TTree("T","DemoDouble32");
   TBranch *bd = T->Branch("d","DemoDouble32",&d,4000);
   TRandom3 r;
   Double_t xmin = d->fMin;
   Double_t xmax = d->fMax;
   Int_t n = 40000;
   for (int i=0; i<n; i++) {
      d->Set(r.Uniform(xmin*1.05, xmax*1.05));
      //d->Set(r.Gaus(0, 40));
      T->Fill();
   }
   T->Write();

   //Create the frame histogram and the graphs
   TObjArray *branches = bd->GetListOfBranches();
   Int_t nb = branches->GetEntries();
   Long64_t zip64 = static_cast<TBranch*>(branches->At(3))->GetZipBytes();
   Double_t cx = 1;
   Double_t drange = 15;
   Double_t dval = 15;

   TCanvas *c1 = new TCanvas("c1","c1",1000,600);
   c1->SetGrid();
   c1->SetHighLightColor(0);
   c1->SetFillColor(17);
   c1->SetFrameFillColor(20);
   c1->SetFrameBorderSize(10);

   TH1F *h = new TH1F("h", "", nb, 0, nb);
   h->SetMaximum(16);
   h->GetXaxis()->SetLabelSize(0.02);
   h->SetStats(0);
   h->Draw();
   c1->GetFrame()->SetFillColor(21);
   c1->GetFrame()->SetBorderSize(12);

   TGraph *gcx = new TGraph(nb);
   gcx->SetName("gcx");
   gcx->SetMarkerStyle(21);
   gcx->SetMarkerColor(kBlue);

   TGraph *gdrange = new TGraph(nb);
   gdrange->SetName("gdrange");
   gdrange->SetMarkerStyle(20);
   gdrange->SetMarkerColor(kRed);

   TGraph *gdval = new TGraph(nb);
   gdval->SetName("gdval");
   gdval->SetMarkerStyle(20);
   gdval->SetMarkerColor(kBlack);

   TPaveLabel *title = new TPaveLabel(.15,.92,.85,.97,"Double32_t compression and precision","brNDC");
   title->Draw();

   //loop on branches to get the precision and compression factors
   for (int i=1+3; i<=nb; i++)
   {
      TBranch* br = (TBranch*)branches->At(i-1);
      h->GetXaxis()->SetBinLabel(i,br->GetName());
      cx = Double_t(zip64)/Double_t(br->GetZipBytes());
      gcx->SetPoint(i-1, i-0.5, cx);

      if (i > 1+3)
      {
         if ( std::string(br->GetName()).find("fSh") != std::string::npos )
            T->Draw(Form("(fD64 - ((%s + (1<<15))/fScale) - fMin)/%g", br->GetName(), xmax-xmin),"","goff");
            //T->Draw(Form("(fD64 - %s/fScale)/%g", br->GetName(), xmax-xmin),"","goff"); // approx
         else if ( std::string(br->GetName()).find("fUSh") != std::string::npos )
            T->Draw(Form("(fD64 - %s/fScale - fMin)/%g", br->GetName(), xmax-xmin),"","goff");
         else if ( std::string(br->GetName()).find("fUI") != std::string::npos )
            T->Draw(Form("(fD64 - %s/fScale - fMin)/%g", br->GetName(), xmax-xmin),"","goff");
         else
            T->Draw(Form("(fD64-%s)/(%g)",br->GetName(),xmax-xmin),"","goff");

         double rms = TMath::RMS(n,T->GetV1());
         drange = TMath::Max(0.,-TMath::Log10(rms));
      }

      gdrange->SetPoint(i-1,i-0.5,drange);

      if (i > 1+3)
      {
         if ( std::string(br->GetName()).find("fSh") != std::string::npos )
            T->Draw(Form("(fD64 - ((%s + (1<<15))/fScale) - fMin)/(fD64 + 1e-300)",br->GetName()),"","goff");
            //T->Draw(Form("(fD64 - %s/fScale)/(fD64 + 1e-300)",br->GetName()),"","goff"); // approx
         else if ( std::string(br->GetName()).find("fUSh") != std::string::npos )
            T->Draw(Form("(fD64 - %s/fScale - fMin)/(fD64 + 1e-300)",br->GetName()),"","goff");
         else if ( std::string(br->GetName()).find("fUI") != std::string::npos )
            T->Draw(Form("(fD64 - %s/fScale - fMin)/(fD64 + 1e-300)",br->GetName()),"","goff");
         else
            T->Draw(Form("(fD64-%s)/(fD64 + 1e-300)",br->GetName()),"","goff");

         double rms = TMath::RMS(n,T->GetV1());
         dval = TMath::Max(0.,-TMath::Log10(rms));
      }

      gdval->SetPoint(i-1, i-0.5, dval);
   }

   gcx->Draw("lp");
   gdrange->Draw("lp");
   gdval->Draw("lp");

   h->GetXaxis()->LabelsOption("v");

   TLegend *legend = new TLegend(0.2,0.7,0.7,0.85);
   legend->SetTextFont(72);
   legend->SetTextSize(0.04);
   legend->AddEntry(gcx,"Compression factor","lp");
   legend->AddEntry(gdrange,"Log of precision wrt range","lp");
   legend->AddEntry(gdval,"Log of precision wrt value","lp");
   legend->Draw();

   TPaveLabel *rang = new TPaveLabel(.75,.75,.88,.80,Form("[%g, %g]", d->fMin, d->fMax),"brNDC");
   rang->Draw();

   c1->Write();
}
