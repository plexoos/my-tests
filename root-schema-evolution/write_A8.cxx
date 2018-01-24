#include <cstdlib>
#include <ctime>

#include "TFile.h"
#include "TTree.h"

#include "MyClassA_8.h"


int main(int argc, char **argv)
{
   std::srand( std::time(nullptr) );

   TFile out_file("evolu.root", "recreate", "My Test Tree", 7);

   TTree myTree("t", "My Test TTree");

   MyClassA* myA = new MyClassA();

   myTree.Branch("e.", "MyClassA", &myA, 32000, 99);

   const int n_records = 5;

   for (int i_record = 1; i_record <= n_records; i_record++)
   {
      myA->Generate();
      myA->Print();
      myTree.Fill();
   }

   delete myA;

   out_file.Write();
   out_file.Close();

   return EXIT_SUCCESS;
}
