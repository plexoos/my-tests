#ifndef MyClassB_h
#define MyClassB_h

#include <iostream>

#include "TObject.h"


class MyClassB : public TObject
{
public:

   MyClassB() : TObject(),
      fW(345678)
   { }

   virtual void Print(Option_t* option = "") const
   {
      int fX = fW / 1000;
      int fY = (fW % 1000) / 10;
      int fZ = fW % 10;

      std::cout << "MyClassB_3: " << fW << ": " << fX << ", " << fY << ", " << fZ << "\n";
   }

private:

   int fW;

   ClassDef(MyClassB, 3)
};

#endif
