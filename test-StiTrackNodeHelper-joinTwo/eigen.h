#include "Eigen/Dense"


namespace eigen
{


double joinTwo(int nP1, const double *P1, const double *E1,
               int nP2, const double *P2, const double *E2,
                              double *PJ,       double *EJ)
{
  // This test assumes nP1 == nP2 == 6
  assert(nP1 == 6 && nP1 == nP2);

  double E1_full[36] =
  {
    E1[ 0], E1[ 1], E1[ 3], E1[ 6], E1[10], E1[15],
    E1[ 1], E1[ 2], E1[ 4], E1[ 7], E1[11], E1[16],
    E1[ 3], E1[ 4], E1[ 5], E1[ 8], E1[12], E1[17],
    E1[ 6], E1[ 7], E1[ 8], E1[ 9], E1[13], E1[18],
    E1[10], E1[11], E1[12], E1[13], E1[14], E1[19],
    E1[15], E1[16], E1[17], E1[18], E1[19], E1[20]
  };
 
  double E2_full[36] =
  {
    E2[ 0], E2[ 1], E2[ 3], E2[ 6], E2[10], E2[15],
    E2[ 1], E2[ 2], E2[ 4], E2[ 7], E2[11], E2[16],
    E2[ 3], E2[ 4], E2[ 5], E2[ 8], E2[12], E2[17],
    E2[ 6], E2[ 7], E2[ 8], E2[ 9], E2[13], E2[18],
    E2[10], E2[11], E2[12], E2[13], E2[14], E2[19],
    E2[15], E2[16], E2[17], E2[18], E2[19], E2[20]
  };

  double EJ_full[36];

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
  EJ_m.noalias() = (E1_m + E2_m).llt().solve(M66::Identity());

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

  EJ[ 0] = d[ 0];
  EJ[ 1] = d[ 6];  EJ[ 2] = d[ 7];
  EJ[ 3] = d[12];  EJ[ 4] = d[13];  EJ[ 5] = d[14];
  EJ[ 6] = d[18];  EJ[ 7] = d[19];  EJ[ 8] = d[20];  EJ[ 9] = d[21];
  EJ[10] = d[24];  EJ[11] = d[25];  EJ[12] = d[26];  EJ[13] = d[27];  EJ[14] = d[28];
  EJ[15] = d[30];  EJ[16] = d[31];  EJ[17] = d[32];  EJ[18] = d[33];  EJ[19] = d[34];  EJ[20] = d[35];

  return chi2;
}


}
