#include "TChain.h"

#include "MyClassB_3.h"


int main(int argc, char **argv)
{
   TChain myTreeChain("t", "My Test TTree");
   myTreeChain.AddFile("evolu.root");

   MyClassB* myB = new MyClassB();

   myTreeChain.SetBranchAddress("e.", &myB);

   const int n_records = myTreeChain.GetEntries();

   for (int i_record = 1; i_record <= n_records; i_record++)
   {
      myTreeChain.GetEntry(i_record-1);
      myB->Print();
   }

   delete myB;

   return EXIT_SUCCESS;
}
