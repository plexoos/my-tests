#ifndef FuncArgsJoinTwo_h
#define FuncArgsJoinTwo_h



struct FuncArgsJoinTwo
{

  FuncArgsJoinTwo() {}

  int    dir;
  int    type;
  int    iter;
  int    nP1;
  int    nP2;
  int    nE1;
  int    nE2;
  float  lar;
  float  P1[6];   //[nP1]
  float  P2[6];   //[nP2]
  float  PJ[6];   //[nP2]
  float  E1[21];  //[nE1]
  float  E2[21];  //[nE2]
  float  EJ[21];  //[nE2]

  // size 356 = 7x4 + (1 + 18 + 63)x4

  ClassDef(FuncArgsJoinTwo, 1)
};

#endif
