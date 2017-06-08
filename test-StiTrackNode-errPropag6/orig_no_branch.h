#include <cstring>

namespace after
{

static const int idx66[6][6] =
  {{ 0, 1, 3, 6,10,15},
   { 1, 2, 4, 7,11,16},
   { 3, 4, 5, 8,12,17},
   { 6, 7, 8, 9,13,18},
   {10,11,12,13,14,19},
   {15,16,17,18,19,20}};

/**
 * This function updates the contents of the G array
 */
void errPropag6( double G[21],const double F[6][6],int nF )
{
  enum {NP=6,NE=21};

  double g[NE];      memcpy(g,    G,sizeof( g));
  double fg[NP][NP]; memset(fg[0],0,sizeof(fg));

  //double myF[6][6];  memcpy(myF[0],F[0],sizeof(fg));
  //for (int i=0;i<NP;i++) {myF[i][i]+=1.;}

  for (int i=0;i<nF;i++) {
  for (int j=0;j<nF;j++) {
    for (int k=0;k<NP;k++) {
      int jk = idx66[j][k];
      fg[i][k] += F[i][j]*g[jk];
  }}}

  for (int i=0;i<NP;i++) {
  for (int k=i;k<NP;k++) {
    int ik = idx66[i][k];
    double s = 0;
    for (int j=0;j<NP;j++) {
      s += fg[i][j]*F[k][j];
    }
    G[ik] += (s + fg[i][k] + fg[k][i]);
  }}

}

}
