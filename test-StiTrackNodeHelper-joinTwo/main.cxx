#include <iostream>
#include <iomanip>
#include <iterator>
#include <string>

#include "TFile.h"
#include "TTree.h"

#include "Eigen/Dense"

#include "common/tools.h"
#include "test-StiTrackNodeHelper-joinTwo/orig.h"
#include "test-StiTrackNodeHelper-joinTwo/eigen.h"
#include "test-StiTrackNodeHelper-joinTwo/eigen_NxN.h"
#include "test-StiTrackNodeHelper-joinTwo/eigen_5x5.h"
#include "test-StiTrackNodeHelper-joinTwo/eigen_float.h"
#include "test-StiTrackNodeHelper-joinTwo/eigen_as_orig.h"
#include "test-StiTrackNodeHelper-joinTwo/eigen_unpacked.h"

#include "test-StiTrackNodeHelper-joinTwo/FuncArgsJoinTwo.h"


using tested_function_t = double (*)(int nP1, const double *P1, const double *E1,
                                     int nP2, const double *P2, const double *E2,
                                                    double *PJ,       double *EJ);


tested_function_t process_arg_test_func(const char *arg, std::string& test_func_name);

template<int N>
void simulate_measurement(double (&P)[N], double (&E)[ N*(N + 1)/2 ]);

int  read_measurements(int& nP1, double* P1, double* E1, int& nP2, double* P2, double* E2);
void print_measurement(const int nP, const double* P, const double* E);

void pack(const double (&Eu)[36], double (&Ep)[21]);
void unpack(const double (&Ep)[21], double (&Eu)[36]);



int main(int argc, char **argv)
{
   // Process 1st optional argument
   std::string       test_func_name("orig");
   tested_function_t test_func = process_arg_test_func(argc > 1 ? argv[1] : "orig", test_func_name);

   // Process 2nd optional argument
   const int n_iterations = tools::process_arg_absi(argc > 2 ? argv[2] : "500000");

   // Process 3rd optional argument
   const int verbosity = tools::process_arg_verb(argc > 3 ? argv[3] : "v1");

   if (verbosity >= 2)
   {
      std::cout << "test_func_name:  " << test_func_name << "\n"
                << "n_iterations:    " << n_iterations << "\n";
   }


   int    nP1, nP2;
   double P1[6]  = {},  P2[6]  = {},  PJ[6]  = {};
   double E1[21] = {},  E2[21] = {},  EJ[21] = {};

   timespec time_0, time_1;
   timespec time_accum{};

   srand(1);


   for (int i = 0; i < n_iterations; i++)
   {
      if ( read_measurements(nP1, P1, E1, nP2, P2, E2) != 0 ) { i--; continue; }

      // Generate input for the function being tested

      if (verbosity >= 3) {
         std::cout << "\nIteration: #" << i+1 << "\ninput:\n";
         print_measurement(nP1, P1, E1);
         print_measurement(nP2, P2, E2);
      }

      // Perform the actual measurement
      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time_0);

      double chi2 = test_func(nP1, P1, E1, nP2, P2, E2, PJ, EJ);

      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time_1);

      if (verbosity >= 3) {
         std::cout << "output:\n" << "chi2: " << chi2 << "\n";
         print_measurement(nP1, PJ, EJ);
      }

      tools::time_add(time_accum, tools::time_diff(time_0, time_1) );
   }

   // Print out final result based on verbosity level
   if (verbosity >= 2)
      std::cout << "elapsed time: " << test_func_name << ", "
                << time_accum.tv_sec << "." << time_accum.tv_nsec << ", \n";
   else if (verbosity >= 1)
      std::cout << std::setprecision(10)
                << time_accum.tv_sec*1000 + time_accum.tv_nsec/1000000. << "\n";
   else {}

   return EXIT_SUCCESS;
}



tested_function_t process_arg_test_func(const char *arg, std::string& test_func_name)
{
   std::string arg1(arg);

   if (std::string("orig").find(arg1) == 0)
   {
      test_func_name = "orig";
      return orig::joinTwo;
   }
   else if (std::string("eigen").find(arg1) == 0)
   {
      test_func_name = "eigen";
      return eigen::joinTwo;
   }
   else if (std::string("eigen_NxN").find(arg1) == 0)
   {
      test_func_name = "eigen_NxN";
      return eigen_NxN::joinTwo;
   }
   else if (std::string("eigen_5x5").find(arg1) == 0)
   {
      test_func_name = "eigen_5x5";
      return eigen_5x5::joinTwo;
   }
   else if (std::string("eigen_float").find(arg1) == 0)
   {
      test_func_name = "eigen_float";
      return eigen_float::joinTwo;
   }
   else if (std::string("eigen_as_orig").find(arg1) == 0)
   {
      test_func_name = "eigen_as_orig";
      return eigen_as_orig::joinTwo;
   }
   else if (std::string("eigen_unpacked").find(arg1) == 0)
   {
      test_func_name = "eigen_unpacked";
      return eigen_unpacked::joinTwo;
   }
   else // The arg1 value does not match any valid value. Use default
   {
      std::cout << "ERROR: arg1 ignored\n";
      test_func_name = "orig";
      return orig::joinTwo;
   }
}



void print_measurement(const int nP, const double* P, const double* E)
{
   std::cout << std::setprecision(5);

   std::cout << "P: ";
   std::copy(P, P + nP, std::ostream_iterator<double>(std::cout, ", "));
   std::cout << "\n";

   std::cout << "E: ";
   std::copy(E, E + nP*(nP + 1)/2, std::ostream_iterator<double>(std::cout, ", "));
   std::cout << "\n";
}



template<int N>
void simulate_measurement(double (&P)[N], double (&E)[ N*(N + 1)/2 ])
{
   using namespace Eigen;
   using MatrixNxN = Matrix<double, N, N, RowMajor>;

   double Eu[36];
   Map< MatrixNxN >  Eu_m( Eu );

   Eu_m.setRandom();

   Eu_m.diagonal() = Eu_m.diagonal().cwiseAbs();

   Eu_m.noalias() = MatrixNxN(Eu_m.template triangularView<Lower>()) * MatrixNxN(Eu_m.template triangularView<Lower>()).transpose();


   for (int i = 0; i < N; i++)
   {
      P[i] = tools::my_rand(-0.5, 0.5);
   }

   pack(Eu, E);
}



int read_measurements(int& nP1, double* P1, double* E1, int& nP2, double* P2, double* E2)
{
   static int i_entry = 0;
   static int i_accepted_entry = -1;
   static int n_entries = 0;
   static TFile inFile("inputs_joinTwo.root", "READ");
   static TTree* inTree;
   static FuncArgsJoinTwo *fa = new FuncArgsJoinTwo();

   if ( i_accepted_entry == -1 ) {
      inTree = static_cast<TTree*>( inFile.Get("t") );
      inTree->SetBranchAddress("b", &fa);
      n_entries = inTree->GetEntries();
      i_accepted_entry++;
   }

   if ( i_entry >= n_entries) i_entry = 0;

   inTree->GetEntry(i_entry);

   i_entry++;

   if (fa->nP1 != fa->nP2)
      return -1;

   i_accepted_entry++;

   nP1 = fa->nP1;
   std::copy(fa->P1, fa->P1 + fa->nP1, P1);
   std::copy(fa->E1, fa->E1 + fa->nE1, E1);

   nP2 = fa->nP2;
   std::copy(fa->P2, fa->P2 + fa->nP2, P2);
   std::copy(fa->E2, fa->E2 + fa->nE2, E2);

   return 0;
}



void unpack(const double (&Ep)[21], double (&Eu)[36])
{
   Eu[ 0] = Ep[ 0];  Eu[ 1] = Ep[ 1];  Eu[ 2] = Ep[ 3];  Eu[ 3] = Ep[ 6];  Eu[ 4] = Ep[10];  Eu[ 5] = Ep[15];
   Eu[ 6] = Ep[ 1];  Eu[ 7] = Ep[ 2];  Eu[ 8] = Ep[ 4];  Eu[ 9] = Ep[ 7];  Eu[10] = Ep[11];  Eu[11] = Ep[16];
   Eu[12] = Ep[ 3];  Eu[13] = Ep[ 4];  Eu[14] = Ep[ 5];  Eu[15] = Ep[ 8];  Eu[16] = Ep[12];  Eu[17] = Ep[17];
   Eu[18] = Ep[ 6];  Eu[19] = Ep[ 7];  Eu[20] = Ep[ 8];  Eu[21] = Ep[ 9];  Eu[22] = Ep[13];  Eu[23] = Ep[18];
   Eu[24] = Ep[10];  Eu[25] = Ep[11];  Eu[26] = Ep[12];  Eu[27] = Ep[13];  Eu[28] = Ep[14];  Eu[29] = Ep[19];
   Eu[30] = Ep[15];  Eu[31] = Ep[16];  Eu[32] = Ep[17];  Eu[33] = Ep[18];  Eu[34] = Ep[19];  Eu[35] = Ep[20];
}



void pack(const double (&Eu)[36], double (&Ep)[21])
{
   Ep[ 0] = Eu[ 0];
   Ep[ 1] = Eu[ 6];  Ep[ 2] = Eu[ 7];
   Ep[ 3] = Eu[12];  Ep[ 4] = Eu[13];  Ep[ 5] = Eu[14];
   Ep[ 6] = Eu[18];  Ep[ 7] = Eu[19];  Ep[ 8] = Eu[20];  Ep[ 9] = Eu[21];
   Ep[10] = Eu[24];  Ep[11] = Eu[25];  Ep[12] = Eu[26];  Ep[13] = Eu[27];  Ep[14] = Eu[28];
   Ep[15] = Eu[30];  Ep[16] = Eu[31];  Ep[17] = Eu[32];  Ep[18] = Eu[33];  Ep[19] = Eu[34];  Ep[20] = Eu[35];
}
