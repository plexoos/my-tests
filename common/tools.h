#ifndef common_tools_h
#define common_tools_h

#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <time.h>


#define TO_STRING(x) #x

#ifndef NDEBUG
#define DEBUG_CODE(x) do { x } while (0)
#define NDEBUG_STR TO_STRING(yes)
#else
#define DEBUG_CODE(x)
#define NDEBUG_STR TO_STRING(no)
#endif


namespace tools {


void print(timespec ts)
{
   std::printf("%lld.%.9ld\n", (long long) ts.tv_sec, ts.tv_nsec);
}


timespec time_diff(timespec time_start, timespec time_end)
{
   timespec temp;

   if ((time_end.tv_nsec - time_start.tv_nsec) < 0)
   {
      temp.tv_sec = time_end.tv_sec - time_start.tv_sec - 1;
      temp.tv_nsec = 1000000000 + time_end.tv_nsec - time_start.tv_nsec;
   }
   else
   {
      temp.tv_sec = time_end.tv_sec - time_start.tv_sec;
      temp.tv_nsec = time_end.tv_nsec - time_start.tv_nsec;
   }

   return temp;
}


void time_add(timespec& time_cumul, timespec time_add)
{
   if (time_cumul.tv_nsec + time_add.tv_nsec > 999999999)
   {
      time_cumul.tv_sec  += time_add.tv_sec + 1;
      time_cumul.tv_nsec += time_add.tv_nsec - 1000000000;
   }
   else
   {
      time_cumul.tv_sec  += time_add.tv_sec;
      time_cumul.tv_nsec += time_add.tv_nsec;
   }
}


double my_rand(const double min, const double max)
{
   return ( std::rand()/(static_cast<double>(RAND_MAX)+1) ) * (max-min) + min;
}


/**
 * Returns a positive integer extracted from arg string.
 */
int process_arg_absi(const char *arg)
{
   return !arg ? 0 : std::abs( std::atoi(arg) );
}


/**
 * Returns a positive real number in (0,1] extracted from arg string or -1 if no
 * conversion can be performed.
 */
double process_arg_d01(const char *arg)
{
   double arg3 = std::atof(arg);

   return ( arg3 <= 0 || arg3 > 1 ? -1 : arg3);
}


/**
 * Expects a string of form "v#" and extracts the number #.
 */
int process_arg_verb(const char *arg)
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


}

#endif
