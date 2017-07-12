#include <functional>
#include <iostream>


void glob_func(int, double) {  };

struct Foo
{
   void memb_func(int, double) {  }
};

void callback( void(*f)(int, double) ) {};


/**
 * See how global function signature differes from member function signature
 */
int main()
{
   Foo myfoo;

   using namespace std::placeholders;

   std::function<void(int, double)> wrap_memb_func = std::bind(&Foo::memb_func, &myfoo, _1, _2);

   std::function<void(int, double)> wrap_glob_func(&glob_func);

   std::cout << "wrap_glob_func: " << wrap_glob_func.target_type().name() << '\n'
             << "wrap_memb_func: " << wrap_memb_func.target_type().name() << std::endl;

   callback( *wrap_glob_func.target<void(*)(int, double)>() );
   //callback( *wrap_memb_func.target<void(*)(int, double)>() );

   return EXIT_SUCCESS;
}
