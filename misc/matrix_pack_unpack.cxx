#include <algorithm>
#include <array>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <numeric>

#include "common/tools.h"
#include "common/matrix.h"


template<class T>
void print(std::string prefix, T container)
{
   std::cout << prefix << ": ";
   std::copy( std::begin(container), std::end(container), std::ostream_iterator<typename T::value_type>(std::cout, ", "));
   std::cout << "\n";
}


int main()
{
   const int n_dim = 6;
   const int n_full = n_dim*n_dim;
   const int n_tria = n_dim*(n_dim + 1)/2;

   using InputType_t = double;
   using OutputType_t = double;

   // Define three row-major matrices
   std::array<InputType_t, n_full> a;
   std::array<OutputType_t, n_tria> b = {0};
   std::array<InputType_t, n_full> c = {0};

   // Generate symmetric matrix a
   for (int irow = 0; irow < n_dim; ++irow)
   {
     for (int icol = 0; icol <= irow; ++icol)
     {
       a[ n_dim*irow + icol ] = static_cast<int>(tools::my_rand(0, 100));

       // In case of non-diagonal elements also fill the transposed one
       if (irow != icol)
         a[ n_dim*icol + irow ] = a[ n_dim*irow + icol ];
     }
   }


   print("a", a);
   print("b", b);
   print("c", c);

   std::cout << "pack a -> b\n";

   //matrix::pack(n_dim, a, b);
   //matrix::pack_recurr_start(n_dim, a.data(), b.data());
   matrix::Matrix<n_dim, InputType_t, OutputType_t>::pack(a.data(), b.data());

   print("a", a);
   print("b", b);
   print("c", c);

   std::cout << "unpack b -> c\n";

   //matrix::unpack_recurr_start(n_dim, b.data(), a.data());
   matrix::Matrix<n_dim, InputType_t, OutputType_t>::unpack(b.data(), c.data());

   print("a", a);
   print("b", b);
   print("c", c);

   assert( a == c );

   return EXIT_SUCCESS;
}
