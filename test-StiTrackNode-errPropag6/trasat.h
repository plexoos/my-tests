#include <cstring>

namespace trasat
{


inline double* vzero(double *a, int n1)
{
   //to be documented
   if (n1 <= 0) return 0;
   return (double *)memset(a,0,n1*sizeof(double));
};


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
}; /* trasat_ */


double* tratsa(const double *a, const double *s, double *r__, int m, int n)
{
   /* Local variables */
   int imax, i__, j, k;
   int ia, ir, is, iaa, ind;
   double sum;

   /* Parameter adjustments */
   --r__;    --s;    --a;

   /* Function Body */
   imax = (m * m + m) / 2;
   vzero(&r__[1], imax);
   ind = 0;
   i__ = 0;

   do {
      ind += i__;
      ir = 0;

      for (j = 1; j <= m; ++j) {
         is = ind;
         ia = j;
         sum = (double)0.;
         k = 0;

         do {
            if (k > i__) is += k;
            else         ++is;
            sum += s[is] * a[ia];
            ia += m;
            ++k;
         } while  (k < n);
         iaa = i__ * m;

         for (k = 1; k <= j; ++k) {
            ++iaa;
            ++ir;
            r__[ir] += sum * a[iaa];
         }
      }
      ++i__;
   } while (i__ < n);

   return 0;
} /* tratsa_ */


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
  double r[21] = {};

  trasat(&F[0][0], G, r, nF, nF);
  //tratsa(&F[0][0], G, r, nF, nF);

  std::memcpy(G, r, sizeof(double)*21);
}


}
