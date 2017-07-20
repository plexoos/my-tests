#include "Eigen/Dense"


namespace eigen_float
{

using namespace Eigen;


double joinTwo(int nP1, const double *P1, const double *E1,
               int nP2, const double *P2, const double *E2,
                              double *PJ,       double *EJ)
{
  // This test assumes nP1 == nP2 == 6
  assert(nP1 == 6 && nP1 == nP2);

  float P1_f[6];
  float P2_f[6];
  float PJ_f[6];

  std::copy(P1, P1 + nP1, P1_f);
  std::copy(P2, P2 + nP1, P2_f);

  float E1_full[36] =
  {
    (float)E1[ 0], (float)E1[ 1], (float)E1[ 3], (float)E1[ 6], (float)E1[10], (float)E1[15],
    (float)E1[ 1], (float)E1[ 2], (float)E1[ 4], (float)E1[ 7], (float)E1[11], (float)E1[16],
    (float)E1[ 3], (float)E1[ 4], (float)E1[ 5], (float)E1[ 8], (float)E1[12], (float)E1[17],
    (float)E1[ 6], (float)E1[ 7], (float)E1[ 8], (float)E1[ 9], (float)E1[13], (float)E1[18],
    (float)E1[10], (float)E1[11], (float)E1[12], (float)E1[13], (float)E1[14], (float)E1[19],
    (float)E1[15], (float)E1[16], (float)E1[17], (float)E1[18], (float)E1[19], (float)E1[20]
  };
 
  float E2_full[36] =
  {
    (float)E2[ 0], (float)E2[ 1], (float)E2[ 3], (float)E2[ 6], (float)E2[10], (float)E2[15],
    (float)E2[ 1], (float)E2[ 2], (float)E2[ 4], (float)E2[ 7], (float)E2[11], (float)E2[16],
    (float)E2[ 3], (float)E2[ 4], (float)E2[ 5], (float)E2[ 8], (float)E2[12], (float)E2[17],
    (float)E2[ 6], (float)E2[ 7], (float)E2[ 8], (float)E2[ 9], (float)E2[13], (float)E2[18],
    (float)E2[10], (float)E2[11], (float)E2[12], (float)E2[13], (float)E2[14], (float)E2[19],
    (float)E2[15], (float)E2[16], (float)E2[17], (float)E2[18], (float)E2[19], (float)E2[20]
  };

  float EJ_full[36];

  using Vector6  = Matrix<float, 1, 6, RowMajor>;
  using Matrix66 = Matrix<float, 6, 6, RowMajor>;

  Map< const Vector6 >  P1_m( P1_f );
  Map< const Vector6 >  P2_m( P2_f );
  Map<       Vector6 >  PJ_m( PJ_f );

  Map< const Matrix66 >  E1_m( E1_full );
  Map< const Matrix66 >  E2_m( E2_full );
  Map<       Matrix66 >  EJ_m( EJ_full );


  // M = B*(1/(A+B))*X + A*(1/(A+B))*Y
  EJ_m.noalias() = (E1_m + E2_m).llt().solve(Matrix66::Identity());

  //PJ_m = P1_m * EJ_m * E1_m + P2_m * EJ_m * E2_m;
  //PJ_m = (P2_m - P1_m) * EJ_m * E1_m + P1_m;
  //PJ_m = E1_m * EJ_m * P1_m.transpose() + E2_m * EJ_m * P2_m.transpose();
  PJ_m.noalias() = (P2_m - P1_m);

  double chi2 = PJ_m * EJ_m * PJ_m.transpose();

  PJ_m.noalias() = PJ_m * EJ_m * E1_m;
  PJ_m += P1_m;

  float* pj = PJ_m.array().data();
  std::copy(pj, pj + nP1, PJ);

  // C = A*(A+B)**(-1)*B 
  EJ_m.noalias() = E1_m * EJ_m * E2_m;

  float* d =  EJ_m.array().data();
  //EJ =  EJ_m.array().data();

  EJ[ 0] = d[ 0];
  EJ[ 1] = d[ 6];  EJ[ 2] = d[ 7];
  EJ[ 3] = d[12];  EJ[ 4] = d[13];  EJ[ 5] = d[14];
  EJ[ 6] = d[18];  EJ[ 7] = d[19];  EJ[ 8] = d[20];  EJ[ 9] = d[21];
  EJ[10] = d[24];  EJ[11] = d[25];  EJ[12] = d[26];  EJ[13] = d[27];  EJ[14] = d[28];
  EJ[15] = d[30];  EJ[16] = d[31];  EJ[17] = d[32];  EJ[18] = d[33];  EJ[19] = d[34];  EJ[20] = d[35];

  return chi2;
}


}
