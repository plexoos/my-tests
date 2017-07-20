#include "Eigen/Dense"


namespace eigen_unpacked
{

using namespace Eigen;


/**
 * The input data is unpacked, i.e. E1[36], E2[36], EJ[36]
 */
double joinTwo(int nP1, const double *P1, const double *E1,
               int nP2, const double *P2, const double *E2,
                              double *PJ,       double *EJ)
{
  // Test assumes nP1 = nP2 = 6

  Map< const Matrix<double, 1, 6, RowMajor> >  P1_m( P1 );
  Map< const Matrix<double, 1, 6, RowMajor> >  P2_m( P2 );
  Map<       Matrix<double, 1, 6, RowMajor> >  PJ_m( PJ );

  using M66 = Matrix<double, 6, 6, RowMajor>;

  Map< const Matrix<double, 6, 6, RowMajor> >  E1_m( E1 );
  Map< const Matrix<double, 6, 6, RowMajor> >  E2_m( E2 );
  Map<       Matrix<double, 6, 6, RowMajor> >  EJ_m( EJ );

  
  // M = (1/A + 1/B)**(-1) * ((1/A)*X + (1/B)*Y)
  //
  // (1/A + 1/B) * M = 1/A*X + 1/B*Y
  //
  //
  // (1/A + 1/B)**(-1) == B*(1/B)* (1/A + 1/B)**(-1) *(1/A)*A ==
  //
  // = A * (A + B)^-1 * B
  // = B * (A + B)^-1 * A
  //
  //
  // M = B*(1/(A+B))*X + A*(1/(A+B))*Y
  //
  //
  // (1/A + 1/B)**(-1) == B* (A+B)**(-1) *A == A* (A+B)**(-1) *B = C
  //
  // 1/A * C = (1/(A+B)) * B
  //
  EJ_m = (E1_m + E2_m).llt().solve(M66::Identity()); // no need .noalias()
  //EJ_m.noalias() = (E1_m + E2_m);

  PJ_m.noalias() = (P2_m - P1_m);

  double chi2 = PJ_m * EJ_m * PJ_m.transpose();

  PJ_m.noalias() = PJ_m * EJ_m * E1_m;
  PJ_m += P1_m;
  //
  // Direct implementation of M (slower)
  //PJ_m.noalias()  = E2_m * EJ_m * P1_m.transpose();
  //PJ_m.noalias() += E1_m * EJ_m * P2_m.transpose();

  // C = A*(A+B)**(-1)*B 
  EJ_m.noalias() = E1_m * EJ_m * E2_m;

  ////////////////////////////////////////////////////////////////

  return chi2;
}


}
