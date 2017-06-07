#include <iostream>
#include <iterator>
#include <string>

#include "common/tools.h"
#include "test-StiTrackNode-errPropag6/before.h"
#include "test-StiTrackNode-errPropag6/after.h"
#include "test-StiTrackNode-errPropag6/trasat.h"


double G_zero_freq[21];
double F_zero_freq[36];

using tested_function_t = void (*)(double G[21], const double F[6][6], int nF);

tested_function_t process_arg1(const char *arg);
int  process_arg2(const char *arg);
void print(const double (&G)[21], const double (&F)[6][6]);
void fill_G(double (&G)[21]);
void fill_F(double (&F)[6][6]);
void fill_zero_freq(double (&G_zero_freq)[21], double (&F_zero_freq)[36]);



int main(int argc, char **argv)
{
   // Process first optional argument
   tested_function_t test_func = (argc >= 2 ? process_arg1(argv[1]) : before::errPropag6);

   // Process second optional argument
   int n_iterations = (argc >= 3 ? process_arg2(argv[2]) : 10000000);

   std::cout << "DEBUG?:       " << NDEBUG_STR << "\n"
             << "test_case:    " << test_func_name << "\n"
             << "n_iterations: " << n_iterations << "\n";


   // Generate histograms with zeros to simulate realistic input
   fill_zero_freq(G_zero_freq, F_zero_freq);

   double myG[21] = {};
   double myF[6][6] = {};

   timespec time_0, time_1, time_2;
   timespec time_accum{};

   srand(1);


   for (int i=0; i<n_iterations; i++)
   {
      // Generate input for the function being tested
      fill_G(myG);
      fill_F(myF);

      DEBUG_CODE(

      std::cout << "\nIteration: #" << i+1 << "\n"
                << "input:\n";
      print(myG, myF);

      );

      // Perform the actual measurement
      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time_0);

      test_func(myG, myF, 6);

      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time_1);

      DEBUG_CODE(

      std::cout << "output:\n";
      print(myG, myF);

      );

      tools::time_add(time_accum, tools::time_diff(time_0, time_1) );
   }

   std::cout << "elapsed time: " << time_accum.tv_sec << "." << time_accum.tv_nsec << std::endl;

   return EXIT_SUCCESS;
}



tested_function_t process_arg1(const char *arg)
{
   std::string arg1(arg);

   // The arg1 value does not match any valid value
   if ( std::string("after").find(arg1) &&
        std::string("before").find(arg1) &&
        std::string("trasat").find(arg1) )
   {
      std::cout << "error: arg1 ignored\n";
   }

   if (std::string("after").find(arg1) == 0)
      return after::errPropag6;

   if (std::string("trasat").find(arg1) == 0)
      return trasat::errPropag6;

   return before::errPropag6;
}



int process_arg2(const char *arg)
{
   int arg2 = std::atoi(arg) - 1;

   if (arg2 < 0)
      std::cout << "ERROR: arg2 ignored\n";

   return (arg2 < 0 ? 10000000 : arg2+1);
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



void fill_G(double (&G)[21])
{
   for (int i = 0; i < 21; i++)
   {
      G[i] = (tools::my_rand(0, 1) <= G_zero_freq[i]) ? 0 : tools::my_rand(-0.5, 0.5);

      // Fifty percent chance to get a zero element
      //G[i] = (tools::my_rand(0, 1) < 0.9) ? 0 : tools::my_rand(-0.5, 0.5);
   }
}



void fill_F(double (&F)[6][6])
{
   for (int i=0; i<6; i++)
   {
      for (int j=0; j<6; j++)
      {
         F[i][j] = (tools::my_rand(0, 1) <= F_zero_freq[i*6+j]) ? 0 : tools::my_rand(-0.5, 0.5);

         // Fifty percent chance to get a zero element
         //F[i][j] = (tools::my_rand(0, 1) < 0.5 ) ? 0 : tools::my_rand(-0.5, 0.5);
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
