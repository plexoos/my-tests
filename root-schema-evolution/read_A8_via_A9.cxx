#include "TChain.h"

#include "MyClassA_9.h"


int main(int argc, char **argv)
{
   TChain myTreeChain("t", "My Test TTree");
   myTreeChain.AddFile("evolu.root");

   MyClassA* myA = new MyClassA();

   myTreeChain.SetBranchAddress("e.", &myA);

   const int n_records = myTreeChain.GetEntries();

   for (int i_record = 1; i_record <= n_records; i_record++)
   {
      myTreeChain.GetEntry(i_record-1);
      myA->Print();
   }

   delete myA;

   return EXIT_SUCCESS;
}
