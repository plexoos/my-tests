#include <chrono>
#include <iostream>
#include <iomanip>
#include <thread>
 


int main()
{
   using namespace std::chrono;

   auto start_time = system_clock::now();

   std::this_thread::sleep_for(std::chrono::seconds(1));

   auto end_time   = system_clock::now();
 
   nanoseconds elapsed_s = duration_cast<nanoseconds>(end_time - start_time);
 
   minutes mm = duration_cast<minutes>(elapsed_s);
   seconds ss = duration_cast<seconds>(elapsed_s % minutes(1));
   milliseconds ms = duration_cast<milliseconds>(elapsed_s % seconds(1));
   microseconds us = duration_cast<microseconds>(elapsed_s % milliseconds(1));
 
   std::cout << "XXXX " << std::setfill('0') << std::setw(2) << mm.count() << "::"
                                             << std::setw(2) << ss.count() << "::"
                                             << std::setw(3) << ms.count() << "::"
                                             << std::setw(3) << us.count() << std::endl;

   return EXIT_SUCCESS;
}
