#ifndef MyClassA_h
#define MyClassA_h

#include <iostream>

#include "TObject.h"


class MyClassA : public TObject
{
public:

   MyClassA() : TObject(),
      fX(111), fY(22), fZ(3)
   { }


   void Generate()
   {
      fX = rand() % 1000;
      fY = rand() % 100;
      fZ = rand() % 10;
   }

   virtual void Print(Option_t* option = "") const
   {
      std::cout << "MyClassA_8: " << fX << ", " << fY << ", " << fZ << "\n";
   }

private:

   int fX;
   int fY;
   int fZ;

   ClassDef(MyClassA, 8)
};

#endif
