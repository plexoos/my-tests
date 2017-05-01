#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>


void errPropag6_orig(double G[21], const double F[6][6], int nF);
void errPropag6_trasat(double G[21], const double F[6][6], int nF);

void print(const double (&G)[21], const double (&F)[6][6]);
void print(const double (&G)[21], const double (&G1)[21], const double (&G2)[21]);
double my_rand(const double min, const double max);



int main(int argc, char **argv)
{
   double myG[21] = {};
   double myF[6][6] = {};

   srand(1);

   // Generate input for the functions
   for (int i = 0; i < 21; i++)
      myG[i] = my_rand(-0.5, 0.5);

   for (int i=0; i<6; i++)
      for (int j=0; j<6; j++)
         myF[i][j] = my_rand(-0.5, 0.5);

   std::cout << "\n" << "input:\n";
   print(myG, myF);

   double myG_orig[21];
   std::copy( std::begin(myG), std::end(myG), std::begin(myG_orig) );

   errPropag6_orig(myG_orig, myF, 6);

   double myG_trasat[21];
   std::copy( std::begin(myG), std::end(myG), std::begin(myG_trasat) );

   errPropag6_trasat(myG_trasat, myF, 6);

   std::cout << "\n" << "output:\n";

   print(myG, myG_orig, myG_trasat);

   return EXIT_SUCCESS;
}



static const int idx66[6][6] =
  {{ 0, 1, 3, 6,10,15},
   { 1, 2, 4, 7,11,16},
   { 3, 4, 5, 8,12,17},
   { 6, 7, 8, 9,13,18},
   {10,11,12,13,14,19},
   {15,16,17,18,19,20}};



void errPropag6_orig(double G[21], const double F[6][6], int nF)
{
  enum {NP=6,NE=21};

  double g[NE];      memcpy(g,    G,sizeof( g));
  double fg[NP][NP]; memset(fg[0],0,sizeof(fg));

  //double myF[6][6];  memcpy(myF[0],F[0],sizeof(fg));
  //for (int i=0;i<NP;i++) {myF[i][i]+=1.;}

  for (int i=0;i<nF;i++) {
  for (int j=0;j<nF;j++) {
    if (!F[i][j])    continue;
    for (int k=0;k<NP;k++) {
      int jk = idx66[j][k];
      if (!g[jk]) continue;
      fg[i][k] += F[i][j]*g[jk];
  }}}

  for (int i=0;i<NP;i++) {
  for (int k=i;k<NP;k++) {
    int ik = idx66[i][k];
    double s = 0;
    for (int j=0;j<NP;j++) {
      if (!F[k][j])  continue;
      s += fg[i][j]*F[k][j];
    }
    G[ik] += (s + fg[i][k] + fg[k][i]);
  }}

}



inline double* vzero(double *a, int n1)
{
   //to be documented
   if (n1 <= 0) return 0;
   return (double *)memset(a,0,n1*sizeof(double));
}



#define TCL_TRASAT(a, s, r__, m, n) \
   int imax,  k;                    \
   int ia, mn, ir, is, iaa;         \
   double sum;                      \
   --r__;    --s;    --a;           \
   imax = (m * m + m) / 2;          \
   vzero(&r__[1], imax);            \
   mn = m * n;                      \
   int ind = 0;                     \
   int i__ = 0;                     \
   do {                             \
      ind += i__;                   \
      ia = 0; ir = 0;               \
      do {                          \
         is = ind;                  \
         sum = 0.;   k = 0;         \
         do {                       \
            if (k > i__) is += k;   \
            else         ++is;      \
            ++ia;                   \
            sum += s[is] * a[ia];   \
            ++k;                    \
         } while (k < n);           \
         iaa = i__ + 1;             \
         do {                       \
            ++ir;                   \
            r__[ir] += sum * a[iaa];\
            iaa += n;               \
         } while (iaa <= ia);       \
      } while (ia < mn);            \
      ++i__;                        \
   } while (i__ < n);               \
   ++r__;



double* trasat(const double *a, const double *s, double *r__, int m, int n)
{
   TCL_TRASAT(a, s, r__, m, n)
   return r__;
} /* trasat_ */



void errPropag6_trasat(double G[21], const double F[6][6], int nF)
{
  double r[21] = {};

  trasat(&F[0][0], G, r, nF, nF);

  std::memcpy(G, r, sizeof(double)*21);
}



void print(const double (&G)[21], const double (&F)[6][6])
{
   std::cout << "G: ";
   std::copy(G, G + 21, std::ostream_iterator<double>(std::cout, ", "));
   std::cout << "\n";

   std::cout << "F: ";
   std::copy(&F[0][0], &F[0][0] + 36, std::ostream_iterator<double>(std::cout, ", "));
   std::cout << "\n";
}



void print(const double (&G)[21], const double (&G1)[21], const double (&G2)[21])
{
   std::cout << std::fixed << std::setprecision(6) << std::right;

   std::cout << std::setw(17) << "index"
             << std::setw(17) << "G in"
             << std::setw(17) << "G out: orig"
             << std::setw(17) << "G out: trasat" << "\n";

   for (int i = 0; i < 21; i++)
   {
      std::cout << std::setw(17) << i
                << std::setw(17) << G[i]
                << std::setw(17) << G1[i]
                << std::setw(17) << G2[i] << "\n";
   }
}



double my_rand(const double min, const double max)
{
   return ( std::rand()/(static_cast<double>(RAND_MAX)+1) ) * (max-min) + min;
}
