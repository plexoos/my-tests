#include "Eigen/Dense"

#include "common/matrix.h"


namespace eigen
{


double joinTwo(int nP1, const double *P1, const double *E1,
               int nP2, const double *P2, const double *E2,
                              double *PJ,       double *EJ)
{
  // This test assumes nP1 == nP2 == 6
  assert(nP1 == 6 && nP1 == nP2);

  static double E1_full[36];
  static double E2_full[36];
  static double EJ_full[36];

  matrix::Matrix<6>::unpack(E1, E1_full);
  matrix::Matrix<6>::unpack(E2, E2_full);


  using namespace Eigen;

  Map< const Matrix<double, 1, 6, RowMajor> >  P1_m( P1 );
  Map< const Matrix<double, 1, 6, RowMajor> >  P2_m( P2 );
  Map<       Matrix<double, 1, 6, RowMajor> >  PJ_m( PJ );

  using M66 = Matrix<double, 6, 6, RowMajor>;

  Map<       Matrix<double, 6, 6, RowMajor> >  E1_m( E1_full );
  Map<       Matrix<double, 6, 6, RowMajor> >  E2_m( E2_full );
  Map<       Matrix<double, 6, 6, RowMajor> >  EJ_m( EJ_full );


  // M = B*(1/(A+B))*X + A*(1/(A+B))*Y
  // EJ_M is the inverse of the sum
  EJ_m.noalias() = (E1_m + E2_m);
  EJ_m(0, 0) = 1;
  EJ_m.noalias() = EJ_m.llt().solve(M66::Identity());
  EJ_m(0, 0) = 0;

  // PJ_m = P1_m * EJ_m * E1_m + P2_m * EJ_m * E2_m;
  // PJ_m = E1_m * EJ_m * P1_m.transpose() + E2_m * EJ_m * P2_m.transpose();
  PJ_m.noalias() = (P2_m - P1_m);

  double chi2 = PJ_m * EJ_m * PJ_m.transpose();

  // PJ_m = (P2_m - P1_m) * EJ_m * E1_m + P1_m;
  PJ_m.noalias() = PJ_m * EJ_m * E1_m;
  PJ_m += P1_m;

  // C = A * (A+B)^-1 * B
  EJ_m.noalias() = E1_m * EJ_m * E2_m;

  double* d =  EJ_m.array().data();

  matrix::Matrix<6>::pack(EJ_full, EJ);

  return chi2;
}


}
