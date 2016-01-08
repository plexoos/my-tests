#include <cstdlib>
#include <iostream>
#include <limits.h>

#include "common/tools.h"



int main()
{
   float  fval = 0.;
   double dval = 0.;
   unsigned n_iterations = UINT_MAX;

   timespec time1, time2;


   std::cout << "1 case (float): ...    " << std::flush;
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);

   for (unsigned j = 0; j < n_iterations; ++j)
   {
      fval += 3.3f;
   }

   std::cout << fval << "\n";

   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
   std::cout << "1 case: elapsed time: " << tools::time_diff(time1, time2).tv_sec << "." << tools::time_diff(time1, time2).tv_nsec << "\n";



   std::cout << "2 case (double): ...    " << std::flush;
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);

   for (unsigned j = 0; j < n_iterations; ++j)
   {
      dval += 3.3;
   }

   std::cout << dval << "\n";

   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
   std::cout << "2 case: elapsed time: " << tools::time_diff(time1, time2).tv_sec << "." << tools::time_diff(time1, time2).tv_nsec << "\n";


   return EXIT_SUCCESS;
}
