#ifndef TCL_H
#define TCL_H

#include <cassert>
#include <cmath>
#include <cstring>


namespace TCL
{


double *trchlu(const double *a, double *b, int n)
{
   /* Local variables */
   int ipiv, kpiv, i__, j;
   double r__, dc;
   int id, kd;
   double sum;

   /* Parameter adjustments */
   --b;    --a;

   /* Function Body */
   ipiv = 0;

   i__ = 0;

   do {
      ++i__;
      ipiv += i__;
      kpiv = ipiv;
      r__ = a[ipiv];

      for (j = i__; j <= n; ++j) {
         sum = 0.;
         if (i__ == 1)       goto L40;
         if (r__ == 0.)      goto L42;
         id = ipiv - i__ + 1;
         kd = kpiv - i__ + 1;

         do {
            sum += b[kd] * b[id];
            ++kd;   ++id;
         } while (id < ipiv);

L40:
         sum = a[kpiv] - sum;
L42:
         if (j != i__) b[kpiv] = sum * r__;
         else {
            dc = std::sqrt(sum);
            b[kpiv] = dc;
            if (r__ > 0.)  r__ = (double)1. / dc;
         }
         kpiv += j;
      }

   } while  (i__ < n);

   return 0;
} /* trchlu_ */



double *trinv(const double *t, double *s, int n)
{
   int lhor, ipiv, lver,  j;
   double r__;
   int mx, ndTep, ind;
   double sum;

   /* Parameter adjustments */
   --s;    --t;

   /* Function Body */
   mx = (n * n + n) / 2;
   ipiv = mx;

   int i = n;
   do {
      r__ = 0.;
      if (t[ipiv] > 0.)  r__ = (double)1. / t[ipiv];
      s[ipiv] = r__;
      ndTep = n;
      ind = mx - n + i;

      while (ind != ipiv) {
         sum = 0.;
         if (r__ != 0.) {
            lhor = ipiv;
            lver = ind;
            j = i;

            do {
               lhor += j;
               ++lver;
               sum += t[lhor] * s[lver];
               ++j;
            } while  (lhor < ind);
         }
         s[ind] = -sum * r__;
         --ndTep;
         ind -= ndTep;
      }

      ipiv -= i;
      --i;
   } while (i > 0);

   return 0;
} /* trinv_ */



double *trsmul(const double *g, double *gi, int n)
{

   /* Local variables */
   int lhor, lver, lpiv, i__, j, k, ind;
   double sum;

   /* Parameter adjustments */
   --gi;    --g;

   /* Function Body */
   ind = 1;
   lpiv = 0;
   for (i__ = 1; i__ <= n; ++i__) {
      lpiv += i__;
      for (j = 1; j <= i__; ++j,++ind) {
         lver = lpiv;
         lhor = ind;
         sum = 0.;
         for (k = i__; k <= n;lhor += k,lver += k,++k)
            sum += g[lver] * g[lhor];
         gi[ind] = sum;
      }
   }

   return 0;
} /* trsmul_ */



double *trsinv(const double *g, double *gi, int n)
{

   /* Function Body */
   trchlu(g, gi, n);
   trinv(gi, gi, n);
   trsmul(gi, gi, n);

   return 0;
} /* trsinv_ */



double *trsa(const double *s, const double *a, double *b, int m, int n)
{
   /* Local variables */
   int inds, i__, j, k, ia, ib, is;
   double sum;

   /* Parameter adjustments */
   --b;    --a;    --s;

   /* Function Body */
   inds = 0;
   ib = 0;
   i__ = 0;

   do {
      inds += i__;

      for (j = 1; j <= n; ++j) {
         ia = j;
         is = inds;
         sum = 0.;
         k = 0;

         do {
            if (k > i__) is += k;
            else         ++is;
            sum += s[is] * a[ia];
            ia += n;
            ++k;
         } while (k < m);
         ++ib;
         b[ib] = sum;
      }
      ++i__;
   } while (i__ < m);

   return 0;
} /* trsa_ */



inline double *ucopy(const double *b, double *a, int n)
{
   //to be documented
   if (n <= 0) return 0;
   std::memcpy(a,b,n*sizeof(double));
   return a;
}



inline double *vsub(const double *a, const double *b, double *x, int n)
{
  //to be documented
   if (n <= 0) return 0;
   for (int i=0;i<n;i++) x[i] = a[i]-b[i];
   return x;
}



inline double *vadd(const double *b, const double *c,  double *a, int n)
{
   //to be documented
   if (n <= 0)  return 0;
   for (int i=0;i<n;i++) a[i] = b[i] + c[i];
   return a;
}



#define TCL_MXMAD(n_,a,b,c,i,j,k)                       \
    /* Local variables */                                \
    int l, m, n, ia, ic, ib, ja, jb, iia, iib, ioa, iob; \
                                                         \
    /* Parameter adjustments */                          \
    --a;  --b;  --c;                                     \
    /* Function Body */                                  \
/*                      MXMAD MXMAD1 MXMAD2 MXMAD3 MXMPY MXMPY1 MXMPY2 MXMPY3 MXMUB MXMUB1 MXMUB2 MXMUB3 */ \
/*  const int iandj1[] = {21,   22,    23,    24,   11,    12,    13,    14,    31,   32,   33,    34 }; */ \
    const int iandj1[] = {2,    2 ,    2 ,    2 ,   1 ,    1 ,    1 ,    1 ,    3 ,   3 ,   3 ,    3  }; \
    const int iandj2[] = { 1,    2,     3,     4,    1,     2,     3,     4,     1,    2,    3,     4 }; \
    int n1 = iandj1[n_];                                  \
    int n2 = iandj2[n_];                                  \
    if (i == 0 || k == 0) return 0;                       \
                                                          \
    switch (n2) {                                         \
      case 1: iia = 1; ioa = j; iib = k; iob = 1; break;  \
      case 2: iia = 1; ioa = j; iib = 1; iob = j; break;  \
      case 3: iia = i; ioa = 1; iib = k; iob = 1; break;  \
      case 4: iia = i; ioa = 1; iib = 1; iob = j; break;  \
      default: iia = ioa = iib = iob = 0; assert(iob);    \
    };                                                    \
                                                          \
    ia = 1; ic = 1;                                       \
    for (l = 1; l <= i; ++l) {                            \
            ib = 1;                                           \
            for (m = 1; m <= k; ++m,++ic) {                   \
              switch (n1) {                                   \
                      case 1:  c[ic] = 0.;      break;            \
                      case 3:  c[ic] = -c[ic];  break;            \
              };                                              \
              if (j == 0) continue;                           \
              ja = ia; jb = ib;                               \
          double cic = c[ic];                             \
              for (n = 1; n <= j; ++n, ja+=iia, jb+=iib)      \
                       cic += a[ja] * b[jb];                      \
          c[ic] = cic;                                    \
              ib += iob;                                      \
            }                                                 \
            ia += ioa;                                        \
    }



double *mxmad_0_(int n_, const double *a, const double *b, double *c, int i, int j, int k)
{
   TCL_MXMAD(n_,a,b,c,i,j,k)
   return c;
} /* mxmad_ */



inline double *mxmpy(const double *a, const double *b, double *c, int i, int j, int k)
{
   return mxmad_0_(4, a, b, c, i, j, k);
}



inline double *vzero(double *a, int n1)
{
   //to be documented
   if (n1 <= 0) return 0;
   return (double *)memset(a,0,n1*sizeof(double));
}


#define TCL_TRAS(a, s, b, m, n)     \
   int inds, i__, j, k, ia, ib, is; \
   double sum;                      \
   --b;    --s;    --a;             \
   ib = 0; inds = 0; i__ = 0;       \
   do {                             \
      inds += i__;                  \
      ia = 0;                       \
      ib = i__ + 1;                 \
      for (j = 1; j <= m; ++j) {    \
         is = inds;                 \
         sum = 0.;                  \
         k = 0;                     \
         do {                       \
            if (k > i__) is += k;   \
            else        ++is;       \
            ++ia;                   \
            sum += a[ia] * s[is];   \
            ++k;                    \
         } while (k < n);           \
         b[ib] = sum;               \
         ib += n;                   \
      }                             \
      ++i__;                        \
   } while (i__ < n);               \
   ++b;


double *tras(const double *a, const double *s, double *b, int m, int n)
{
   // Symmetric - Rectangular Multiplication
   // CERN PROGLIB# F112    TRAS            .VERSION KERNFOR  4.15  861204 */
   // ORIG. 18/12/74 WH */
   // tras.F -- translated by f2c (version 19970219).
 //BEGIN_HTML <!--
 /* -->
  <b>see original documentation of CERNLIB package</b> <A HREF="http://wwwasdoc.web.cern.ch/wwwasdoc/shortwrupsdir/f112/top.html">F112</A>
 <!--*/
 // -->END_HTML
   TCL_TRAS(a, s, b, m, n)
   return b;
} /* tras_ */

#undef TCL_TRAS


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


double *trasat(const double *a, const double *s, double *r__, int m, int n)
{
   TCL_TRASAT(a, s, r__, m, n)
   return r__;
} /* trasat_ */


double *trqsq(const double *q, const double *s, double *r__, int m)
{
   // trqsq.F -- translated by f2c (version 19970219).
   // CERN PROGLIB# F112    TRQSQ           .VERSION KERNFOR  4.15  861204 */
   // ORIG. 18/12/74 WH */
 //BEGIN_HTML <!--
 /* -->
  <b>see original documentation of CERNLIB package</b> <A HREF="http://wwwasdoc.web.cern.ch/wwwasdoc/shortwrupsdir/f112/top.html">F112</A>
 <!--*/
 // -->END_HTML

   int indq, inds, imax, i__, j, k, l;
   int iq, ir, is, iqq;
   double sum;

   /* Parameter adjuTments */
   --r__;    --s;    --q;

   /* Function Body */
   imax = (m * m + m) / 2;
   vzero(&r__[1], imax);
   inds = 0;
   i__ = 0;

   do {
      inds += i__;
      ir = 0;
      indq = 0;
      j = 0;

      do {
         indq += j;
         is = inds;
         iq = indq;
         sum = 0.;
         k = 0;

         do {
            if (k > i__)  is += k;
            else          ++is;

            if (k > j)    iq += k;
            else        ++iq;

            sum += s[is] * q[iq];
            ++k;
         } while (k < m);
         iqq = inds;
         l = 0;

         do {
            ++ir;
            if (l > i__)  iqq += l;
            else          ++iqq;
            r__[ir] += q[iqq] * sum;
            ++l;
         } while (l <= j);
         ++j;
      } while (j < m);
      ++i__;
   } while (i__ < m);

   return 0;
} /* trqsq_ */


inline double *vcopyn(const double *a, double *x, int n)
{
   //to be documented
   if (n <= 0) return 0;
   for (int i=0;i<n;i++) x[i] = -a[i];
   return x;
}


}


#endif
