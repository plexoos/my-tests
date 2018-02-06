#include <cassert>

#include "Eigen/Dense"


namespace eigen_NxN
{


template<typename _Scalar, int _N>
_Scalar joinTwoUnpacked( const _Scalar *P1, const _Scalar *E1,
                         const _Scalar *P2, const _Scalar *E2,
                               _Scalar *PJ,       _Scalar *EJ )
{
  using namespace Eigen;

  using VecN   = Matrix<_Scalar,  1, _N, RowMajor>;
  using MatNxN = Matrix<_Scalar, _N, _N, RowMajor>;

  Map<const VecN>  P1_m( P1 );
  Map<const VecN>  P2_m( P2 );
  Map<      VecN>  PJ_m( PJ );

  Map<const MatNxN>  E1_m( E1 );
  Map<const MatNxN>  E2_m( E2 );
  Map<      MatNxN>  EJ_m( EJ );

  // M = B*(1/(A+B))*X + A*(1/(A+B))*Y
  // EJ_M is the inverse of the sum
  EJ_m.noalias() = (E1_m + E2_m).llt().solve(MatNxN::Identity());

  // PJ_m = P1_m * EJ_m * E1_m + P2_m * EJ_m * E2_m;
  // PJ_m = E1_m * EJ_m * P1_m.transpose() + E2_m * EJ_m * P2_m.transpose();
  PJ_m.noalias() = (P2_m - P1_m);

  _Scalar chi2 = PJ_m * EJ_m * PJ_m.transpose();

  // PJ_m = (P2_m - P1_m) * EJ_m * E1_m + P1_m;
  PJ_m.noalias() = PJ_m * EJ_m * E1_m;
  PJ_m += P1_m;

  // C = A * (A+B)^-1 * B
  EJ_m.noalias() = E1_m * EJ_m * E2_m;

  return chi2;
}




template<int _InputDim>
double joinTwoIgnoreX(const double *P1, const double *E1,
                      const double *P2, const double *E2,
                            double *PJ,       double *EJ)
{
  static_assert(_InputDim == 3 || _InputDim == 6, "Supported dimensions are 3 and 6 only");

  return 0;
}



template<>
double joinTwoIgnoreX<3>(const double *P1, const double *E1,
                         const double *P2, const double *E2,
                               double *PJ,       double *EJ)
{
  //const double E1_full[ InputDim_t*(InputDim_t - 1)/2 ] =
  const double E1_full[4] =
  {
    E1[ 2], E1[ 4],
    E1[ 4], E1[ 5]
  };

  const double E2_full[4] =
  {
    E2[ 2], E2[ 4],
    E2[ 4], E2[ 5]
  };

  double EJ_u[4];

  double chi2 = joinTwoUnpacked<double, 2>( &P1[1], E1_full, &P2[1], E2_full, &PJ[1], EJ_u );

  // Just assign something to x...
  PJ[0] = P2[0];

  EJ[ 0] = 0;
  EJ[ 1] = 0; EJ[ 2] = EJ_u[ 0];
  EJ[ 3] = 0; EJ[ 4] = EJ_u[ 2];  EJ[ 5] = EJ_u[ 3];

  return chi2;
}



template<>
double joinTwoIgnoreX<6>(const double *P1, const double *E1,
                         const double *P2, const double *E2,
                               double *PJ,       double *EJ)
{
  const double E1_full[25] =
  {
    E1[ 2], E1[ 4], E1[ 7], E1[11], E1[16],
    E1[ 4], E1[ 5], E1[ 8], E1[12], E1[17],
    E1[ 7], E1[ 8], E1[ 9], E1[13], E1[18],
    E1[11], E1[12], E1[13], E1[14], E1[19],
    E1[16], E1[17], E1[18], E1[19], E1[20]
  };

  const double E2_full[25] =
  {
    E2[ 2], E2[ 4], E2[ 7], E2[11], E2[16],
    E2[ 4], E2[ 5], E2[ 8], E2[12], E2[17],
    E2[ 7], E2[ 8], E2[ 9], E2[13], E2[18],
    E2[11], E2[12], E2[13], E2[14], E2[19],
    E2[16], E2[17], E2[18], E2[19], E2[20]
  };

  double EJ_u[25];

  double chi2 = joinTwoUnpacked<double, 5>( &P1[1], E1_full, &P2[1], E2_full, &PJ[1], EJ_u );

  // Just assign something to x...
  PJ[0] = P2[0];

  EJ[ 0] = 0;
  EJ[ 1] = 0; EJ[ 2] = EJ_u[ 0];
  EJ[ 3] = 0; EJ[ 4] = EJ_u[ 5];  EJ[ 5] = EJ_u[ 6];
  EJ[ 6] = 0; EJ[ 7] = EJ_u[10];  EJ[ 8] = EJ_u[11];  EJ[ 9] = EJ_u[12];
  EJ[10] = 0; EJ[11] = EJ_u[15];  EJ[12] = EJ_u[16];  EJ[13] = EJ_u[17];  EJ[14] = EJ_u[18];
  EJ[15] = 0; EJ[16] = EJ_u[20];  EJ[17] = EJ_u[21];  EJ[18] = EJ_u[22];  EJ[19] = EJ_u[23];  EJ[20] = EJ_u[24];

  return chi2;
}


double joinTwo(int nP1, const double *P1, const double *E1,
               int nP2, const double *P2, const double *E2,
                              double *PJ,       double *EJ)
{
  // This test expects nP1 == nP2
  assert(nP1 == nP2);

  if (nP1 == 6)
     return joinTwoIgnoreX<6>(P1, E1, P2, E2, PJ, EJ);
 
  if (nP1 == 3)
     return joinTwoIgnoreX<3>(P1, E1, P2, E2, PJ, EJ);
}


}
