#ifndef MyClassA_h
#define MyClassA_h

#include <iostream>

#include "TObject.h"


class MyClassA : public TObject
{
public:

   MyClassA() : TObject(),
      fW(345678)
   { }

   virtual void Print(Option_t* option = "") const
   {
      int fX = fW / 1000;
      int fY = (fW % 1000) / 10;
      int fZ = fW % 10;

      std::cout << "MyClassA_9: " << fW << ": " << fX << ", " << fY << ", " << fZ << "\n";
   }

private:

   int fW;

   ClassDef(MyClassA, 9)
};

#endif
