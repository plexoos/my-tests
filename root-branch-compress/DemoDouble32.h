#ifndef DemoDouble32_h
#define DemoDouble32_h

#include "TMath.h"


struct DemoDouble32
{
   double      fMin = -100;
   double      fMax =  100;
   double      fScale;

   Double_t    fD64;     //reference member with full double precision
   Double32_t  fF32;     //saved as a 32 bit Float_t

   Double32_t  fI32;     //[-100,100]    saved as a 32 bit unsigned int
   Double32_t  fI30;     //[-100,100,30] saved as a 30 bit unsigned int
   Double32_t  fI28;     //[-100,100,28] saved as a 28 bit unsigned int
   Double32_t  fI26;     //[-100,100,26] saved as a 26 bit unsigned int
   Double32_t  fI24;     //[-100,100,24] saved as a 24 bit unsigned int
   Double32_t  fI22;     //[-100,100,22] saved as a 22 bit unsigned int
   Double32_t  fI20;     //[-100,100,20] saved as a 20 bit unsigned int
   Double32_t  fI18;     //[-100,100,18] saved as a 18 bit unsigned int
   Double32_t  fI16;     //[-100,100,16] saved as a 16 bit unsigned int
   Double32_t  fI14;     //[-100,100,14] saved as a 14 bit unsigned int
   Double32_t  fI12;     //[-100,100,12] saved as a 12 bit unsigned int
   Double32_t  fI10;     //[-100,100,10] saved as a 10 bit unsigned int
   Double32_t  fI8;      //[-100,100, 8] saved as a  8 bit unsigned int
   Double32_t  fI6;      //[-100,100, 6] saved as a  6 bit unsigned int
   Double32_t  fI4;      //[-100,100, 4] saved as a  4 bit unsigned int
   Double32_t  fI2;      //[-100,100, 2] saved as a  2 bit unsigned int

   Double32_t  fR16;     //[0,  0, 16] saved as a 32 bit float with a 16 bits mantissa
   Double32_t  fR14;     //[0,  0, 14] saved as a 32 bit float with a 14 bits mantissa
   Double32_t  fR12;     //[0,  0, 12] saved as a 32 bit float with a 12 bits mantissa
   Double32_t  fR10;     //[0,  0, 10] saved as a 32 bit float with a 10 bits mantissa
   Double32_t  fR8;      //[0,  0,  8] saved as a 32 bit float with a  8 bits mantissa
   Double32_t  fR6;      //[0,  0,  6] saved as a 32 bit float with a  6 bits mantissa
   Double32_t  fR4;      //[0,  0,  4] saved as a 32 bit float with a  4 bits mantissa
   Double32_t  fR2;      //[0,  0,  2] saved as a 32 bit float with a  2 bits mantissa

   Float16_t   fI16F;    //[-100, 100, 16]
   Float16_t   fI14F;    //[-100, 100, 14]
   Float16_t   fI12F;    //[-100, 100, 12]
   Float16_t   fI10F;    //[-100, 100, 10]
   Float16_t   fI8F;     //[-100, 100,  8]
   Float16_t   fI6F;     //[-100, 100,  6]
   Float16_t   fI4F;     //[-100, 100,  4]
   Float16_t   fI2F;     //[-100, 100,  2]

   Float16_t   fR16F;    //[0, 0, 16]
   Float16_t   fR14F;    //[0, 0, 14]
   Float16_t   fR12F;    //[0, 0, 12]
   Float16_t   fR10F;    //[0, 0, 10]
   Float16_t   fR8F;     //[0, 0,  8]
   Float16_t   fR6F;     //[0, 0,  6]
   Float16_t   fR4F;     //[0, 0,  4]
   Float16_t   fR2F;     //[0, 0,  2]

   Short_t     fSh;
   UShort_t    fUSh;
   UInt_t      fUI;

   void Set(Double_t ref)
   {
      fD64  = fF32  = fI32  = fI30  = fI28 = fI26 = fI24 = fI22 = fI20 = fI18 = ref;

      fI16  = fI14  = fI12  = fI10  = fI8  = fI6  = fI4  = fI2  = ref;
      fI16F = fI14F = fI12F = fI10F = fI8F = fI6F = fI4F = fI2F = ref;
      fR16  = fR14  = fR12  = fR10  = fR8  = fR6  = fR4  = fR2  = ref;
      fR16F = fR14F = fR12F = fR10F = fR8F = fR6F = fR4F = fR2F = ref;

      // -1 added to deal with overflow in UShort_t
      fScale = (0xffff - 1)/(fMax - fMin);

      if (ref < fMin) ref = fMin;
      if (ref > fMax) ref = fMax;

      fSh  = std::round( (ref-fMin)*fScale ) - (1<<15);
      fUSh = std::round( (ref-fMin)*fScale );
      fUI  = std::round( (ref-fMin)*fScale );
   }
};

#endif
