#include <iostream>
#include <iomanip>
#include <iterator>
#include <string>

#include "Eigen/Dense"

#include "common/tools.h"
#include "test-StiTrackNodeHelper-joinTwo/orig.h"
#include "test-StiTrackNodeHelper-joinTwo/eigen.h"
#include "test-StiTrackNodeHelper-joinTwo/eigen_float.h"
#include "test-StiTrackNodeHelper-joinTwo/eigen_as_orig.h"
#include "test-StiTrackNodeHelper-joinTwo/eigen_unpacked.h"


using tested_function_t = double (*)(int nP1, const double *P1, const double *E1,
                                     int nP2, const double *P2, const double *E2,
                                                    double *PJ,       double *EJ);


tested_function_t process_arg1(const char *arg, std::string& test_func_name);
int  process_arg2(const char *arg);
int  process_arg4(const char *arg);

void simulate_measurement(double (&P)[6], double (&E)[21]);
void print_measurement(const double (&P)[6], const double (&E)[21]);

void pack(const double (&Eu)[36], double (&Ep)[21]);
void unpack(const double (&Ep)[21], double (&Eu)[36]);



int main(int argc, char **argv)
{
   // Process 1st optional argument
   std::string       test_func_name("orig");
   tested_function_t test_func = (argc > 1 ? process_arg1(argv[1], test_func_name) : orig::joinTwo);

   // Process 2nd optional argument
   int n_iterations = (argc > 2 ? process_arg2(argv[2]) : 500000);

   // Process optional argument: verbosity level
   int verbosity = (argc > 3 ? process_arg4(argv[3]) : 1);

   if (verbosity > 1)
   {
      std::cout << "DEBUG?:       " << NDEBUG_STR << "\n"
                << "test_case:    " << test_func_name << "\n"
                << "n_iterations: " << n_iterations << "\n";
   }


   double P1[6]  = {},  P2[6]  = {},  PJ[6]  = {};
   double E1[21] = {},  E2[21] = {},  EJ[21] = {};

   timespec time_0, time_1;
   timespec time_accum{};

   srand(1);


   for (int i = 0; i < n_iterations; i++)
   {
      // Generate input for the function being tested
      simulate_measurement(P1, E1);
      simulate_measurement(P2, E2);

      DEBUG_CODE(

      std::cout << "\nIteration: #" << i+1 << "\n"
                << "input:\n";
      print_measurement(P1, E1);
      print_measurement(P2, E2);

      );

      // Perform the actual measurement
      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time_0);

      double chi2 = test_func(6, P1, E1, 6, P2, E2, PJ, EJ);

      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time_1);

      DEBUG_CODE(

      std::cout << "output:\n"
                << "chi2: " << chi2 << "\n";
      print_measurement(PJ, EJ);

      );

      tools::time_add(time_accum, tools::time_diff(time_0, time_1) );
   }

   // Print out final result based on verbosity level
   if (verbosity > 1)
      std::cout << "elapsed time: " << test_func_name << ", "
                << time_accum.tv_sec << "." << time_accum.tv_nsec << ", " << std::endl;
   else if (verbosity > 0)
      std::cout << std::setprecision(10)
                << time_accum.tv_sec*1000 + time_accum.tv_nsec/1000000. << std::endl;
   else {}

   return EXIT_SUCCESS;
}



tested_function_t process_arg1(const char *arg, std::string& test_func_name)
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



int process_arg2(const char *arg)
{
   int arg2 = std::atoi(arg) - 1;

   return (arg2 < 0 ? 500000 : arg2+1);
}



int process_arg4(const char *arg)
{
   const std::string verbosity(arg);

   if (verbosity.size() == 2 && verbosity[0] == 'v' && isdigit(verbosity[1]))
   {
      return std::atoi( &verbosity[1] );
   }
   else
   {
      return 1;
   }
}



void print_measurement(const double (&P)[6], const double (&E)[21])
{
   std::cout << std::setprecision(5);

   std::cout << "P: ";
   std::copy(P, P + 6, std::ostream_iterator<double>(std::cout, ", "));
   std::cout << "\n";

   std::cout << "E: ";
   std::copy(E, E + 21, std::ostream_iterator<double>(std::cout, ", "));
   std::cout << "\n";
}



void simulate_measurement(double (&P)[6], double (&E)[21])
{
   using namespace Eigen;
   using Matrix6x6 = Matrix<double, 6, 6, RowMajor>;

   double Eu[36];
   Map< Matrix6x6 >  Eu_m( Eu );

   Eu_m.setRandom();

   Eu_m.diagonal() = Eu_m.diagonal().cwiseAbs();

   Eu_m.noalias() = Matrix6x6(Eu_m.triangularView<Lower>()) * Matrix6x6(Eu_m.triangularView<Lower>()).transpose();


   for (int i = 0; i < 6; i++)
   {
      P[i] = tools::my_rand(-0.5, 0.5);
   }

   pack(Eu, E);
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
