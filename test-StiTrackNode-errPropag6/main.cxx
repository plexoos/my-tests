#include <iostream>
#include <iterator>
#include <string>

#include "common/tools.h"
#include "test-StiTrackNode-errPropag6/orig.h"
#include "test-StiTrackNode-errPropag6/orig_no_branch.h"
#include "test-StiTrackNode-errPropag6/trasat.h"
#include "test-StiTrackNode-errPropag6/smatrix.h"
#include "test-StiTrackNode-errPropag6/eigen.h"


double G_zero_freq[21];
double F_zero_freq[36];

using tested_function_t = void (*)(double G[21], const double F[6][6], int nF);

tested_function_t process_arg_test_func(const char *arg, std::string& test_func_name);

void print(const double (&G)[21], const double (&F)[6][6]);
void fill_G(double (&G)[21], double zero_freq);
void fill_F(double (&F)[6][6], double zero_freq);
void fill_zero_freq(double (&G_zero_freq)[21], double (&F_zero_freq)[36]);



int main(int argc, char **argv)
{
   // Process 1st optional argument
   std::string       test_func_name("orig");
   tested_function_t test_func = process_arg_test_func(argc > 1 ? argv[1] : "orig", test_func_name);

   // Process 2nd optional argument
   const int n_iterations = tools::process_arg_absi(argc > 2 ? argv[2] : "1000000");

   // Process 3rd optional argument
   const double zero_freq = tools::process_arg_d01(argc > 3 ? argv[3] : "-1");

   // Process 4th optional argument
   const int verbosity = tools::process_arg_verb(argc > 4 ? argv[4] : "v1");


   if (verbosity > 1)
   {
      std::cout << "test_func_name:  " << test_func_name << "\n"
                << "n_iterations:    " << n_iterations << "\n"
                << "zero_freq:       " << zero_freq << " (<= 0 means measured freq.)\n"
                << "verbosity:       " << verbosity << "\n";
   }


   // Generate histograms with zeros to simulate realistic input
   fill_zero_freq(G_zero_freq, F_zero_freq);

   double myG[21] = {};
   double myF[6][6] = {};

   timespec time_0, time_1, time_2;
   timespec time_accum{};

   srand(1);


   for (int i = 0; i < n_iterations; i++)
   {
      // Generate input for the function being tested
      fill_G(myG, zero_freq);
      fill_F(myF, zero_freq);

      DEBUG_CODE(

      std::cout << "\nIteration: #" << i+1 << "\n"
                << "input:\n";
      print(myG, myF);

      );

      // Adjustments for original errPropag6
      if (test_func == orig::errPropag6 || test_func == orig_no_branch::errPropag6)
         for (int jk=0; jk<6; jk++) { myF[jk][jk] -= 1; }

      // Perform the actual measurement
      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time_0);

      test_func(myG, myF, 6);

      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time_1);

      // Adjustments for original errPropag6
      if (test_func == orig::errPropag6 || test_func == orig_no_branch::errPropag6)
         for (int jk=0; jk<6; jk++) { myF[jk][jk] += 1; }

      DEBUG_CODE(

      std::cout << "output:\n";
      print(myG, myF);

      );

      tools::time_add(time_accum, tools::time_diff(time_0, time_1) );
   }

   // Print out final result based on verbosity level
   if (verbosity > 1)
      std::cout << "elapsed time: " << test_func_name << ", "
                << time_accum.tv_sec << "." << time_accum.tv_nsec << ", \n";
   else if (verbosity > 0)
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
      return orig::errPropag6;
   }
   else if (std::string("orig_no_branch").find(arg1) == 0)
   {
      test_func_name = "orig_no_branch";
      return orig_no_branch::errPropag6;
   }
   else if (std::string("trasat").find(arg1) == 0)
   {
      test_func_name = "trasat";
      return trasat::errPropag6;
   }
   else if (std::string("smatrix").find(arg1) == 0)
   {
      test_func_name = "smatrix";
      return smatrix::errPropag6;
   }
   else if (std::string("eigen").find(arg1) == 0)
   {
      test_func_name = "eigen";
      return eigen::errPropag6;
   }
   else // The arg1 value does not match any valid value. Use default
   {
      std::cout << "ERROR: arg1 ignored\n";
      test_func_name = "orig";
      return orig::errPropag6;
   }
}



void print(const double (&G)[21], const double (&F)[6][6])
{
   std::cout << std::setprecision(5);

   std::cout << "G: ";
   std::copy(G, G + 21, std::ostream_iterator<double>(std::cout, ", "));
   std::cout << "\n";

   std::cout << "F: ";
   std::copy(&F[0][0], &F[0][0] + 36, std::ostream_iterator<double>(std::cout, ", "));
   std::cout << "\n";
}



void fill_G(double (&G)[21], double zero_freq)
{
   for (int i = 0; i < 21; i++)
   {
      if (zero_freq <= 0)
         G[i] = (tools::my_rand(0, 1) <= G_zero_freq[i]) ? 0 : tools::my_rand(-0.5, 0.5);
      else // a "zero_freq" chance to get a zero element
         G[i] = (tools::my_rand(0, 1) < zero_freq) ? 0 : tools::my_rand(-0.5, 0.5);
   }
}



void fill_F(double (&F)[6][6], double zero_freq)
{
   for (int i=0; i<6; i++)
   {
      for (int j=0; j<6; j++)
      {
         if (zero_freq <= 0)
            F[i][j] = (tools::my_rand(0, 1) <= F_zero_freq[i*6+j]) ? 0 : tools::my_rand(-0.5, 0.5);
         else // a "zero_freq" chance to get a zero element
            F[i][j] = (tools::my_rand(0, 1) < zero_freq) ? 0 : tools::my_rand(-0.5, 0.5);
      }
   }
}



void fill_zero_freq(double (&G_zero_freq)[21], double (&F_zero_freq)[36])
{
   G_zero_freq[0 ]=1;
   G_zero_freq[1 ]=1;
   G_zero_freq[2 ]=0;
   G_zero_freq[3 ]=1;
   G_zero_freq[4 ]=0;
   G_zero_freq[5 ]=0;
   G_zero_freq[6 ]=1;
   G_zero_freq[7 ]=0;
   G_zero_freq[8 ]=0;
   G_zero_freq[9 ]=0;
   G_zero_freq[10]=1;
   G_zero_freq[11]=0;
   G_zero_freq[12]=0;
   G_zero_freq[13]=0;
   G_zero_freq[14]=0;
   G_zero_freq[15]=1;
   G_zero_freq[16]=0;
   G_zero_freq[17]=0;
   G_zero_freq[18]=0;
   G_zero_freq[19]=0;
   G_zero_freq[20]=0;

   F_zero_freq[0 ]=0.013141;
   F_zero_freq[1 ]=0.978458;
   F_zero_freq[2 ]=1;
   F_zero_freq[3 ]=1;
   F_zero_freq[4 ]=1;
   F_zero_freq[5 ]=1;
   F_zero_freq[6 ]=0.013141;
   F_zero_freq[7 ]=0.796382;
   F_zero_freq[8 ]=1;
   F_zero_freq[9 ]=0.034683;
   F_zero_freq[10]=0.034683;
   F_zero_freq[11]=1;
   F_zero_freq[12]=0.034683;
   F_zero_freq[13]=1;
   F_zero_freq[14]=1;
   F_zero_freq[15]=0.034683;
   F_zero_freq[16]=0.034683;
   F_zero_freq[17]=0.034683;
   F_zero_freq[18]=0.034683;
   F_zero_freq[19]=1;
   F_zero_freq[20]=1;
   F_zero_freq[21]=1;
   F_zero_freq[22]=0.034683;
   F_zero_freq[23]=1;
   F_zero_freq[24]=1;
   F_zero_freq[25]=1;
   F_zero_freq[26]=1;
   F_zero_freq[27]=1;
   F_zero_freq[28]=1;
   F_zero_freq[29]=1;
   F_zero_freq[30]=1;
   F_zero_freq[31]=1;
   F_zero_freq[32]=1;
   F_zero_freq[33]=1;
   F_zero_freq[34]=1;
   F_zero_freq[35]=1;
}
