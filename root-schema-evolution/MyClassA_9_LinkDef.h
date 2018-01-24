#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ class MyClassA+;


#pragma read sourceClass="MyClassA" version="[8]" targetClass="MyClassA" \
   source="int fX; int fY; int fZ" target="fW" \
   code="{ fW = 1000*onfile.fX + 10*onfile.fY + onfile.fZ; }"
