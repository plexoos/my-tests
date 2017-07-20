#include "Eigen/Dense"


namespace eigen_as_orig
{

using namespace Eigen;


double joinTwo(int nP1, const double *P1, const double *E1,
               int nP2, const double *P2, const double *E2,
                              double *PJ,       double *EJ)
{
  // Test assumes nP1 = nP2 = 6

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

  Map< const Matrix<double, 1, 6, RowMajor> >  P1_m( P1 );
  Map< const Matrix<double, 1, 6, RowMajor> >  P2_m( P2 );
  Map<       Matrix<double, 1, 6, RowMajor> >  PJ_m( PJ );

  Map< const Matrix<double, 6, 6, RowMajor> >  E1_m( E1_full );
  Map< const Matrix<double, 6, 6, RowMajor> >  E2_m( E2_full );
  //Map< const Matrix<double, 6, 6, RowMajor> >  E1_m( E1 );
  //Map< const Matrix<double, 6, 6, RowMajor> >  E2_m( E2 );
  //Map<       Matrix<double, 6, 6, RowMajor> >  sumEI_m( EJ );
  Map<       Matrix<double, 6, 6, RowMajor> >  EJ_m( EJ_full );

  //TCL::vadd(e1, e2, sumE, nE1);
  //TCL::trsinv(sumE, sumEI, nP1);
  //TCL::vsub(p2, p1, subP, nP1);
  //TCL::tras(subP, sumEI, sumEIsubP, 1, nP1);
  //TCL::tras(sumEIsubP, e1, PJ, 1, nP2);
  //TCL::vadd(PJ, p1, PJ, nP2);
 
  //Matrix<double, 6, 6, RowMajor> sumEI_m( (E1_m + E2_m).inverse() );
  //sumEI_m = (E1_m + E2_m).inverse();
  EJ_m = (E1_m + E2_m).llt().solve(Matrix<double, 6, 6, RowMajor>::Identity());
  //EJ_m = (E1_m + E2_m);
  //Matrix<double, 1, 6, RowMajor> subP_m( P2_m - P1_m );
 
  //PJ_m = (P2_m - P1_m) * sumEI_m;
  //PJ_m = (P2_m - P1_m) * EJ_m;

  //PJ_m = ( (P2_m - P1_m) * (E1_m + E2_m).inverse() ) * E1_m + P1_m;

  //TCL::trasat(subP, sumEI, &chi2, 1, nP1);
  //double chi2 = subP_m * sumEI_m * subP_m.transpose();
  //double chi2 = PJ_m * sumEI_m * PJ_m.transpose();
  //double chi2 = PJ_m * sumEI_m * PJ_m.transpose();
  //double chi2 = PJ_m * (P2_m - P1_m).transpose();
  double chi2 = (P2_m - P1_m) * EJ_m * (P2_m - P1_m).transpose();

  //double chi2 = (P2_m - P1_m) * (E1_m + E2_m).inverse() * (P2_m - P1_m).transpose();

  //sumEI_m = sumEI_m * E1_m;

  //PJ_m = subP_m * sumEI_m * E1_m + P1_m;
  //PJ_m = subP_m * sumEI_m + P1_m;
  //PJ_m = PJ_m * sumEI_m + P1_m;
  //PJ_m = PJ_m * E1_m + P1_m;
  PJ_m = (P2_m - P1_m) * EJ_m * E1_m + P1_m;

  //TCL::trqsq(e1, sumEI, e1sumEIe1, nP2);
  //TCL::vsub(e1, e1sumEIe1, EJ, nE2);
  //Matrix<double, 6, 6, RowMajor> EJ_m( E1_m - E1_m * sumEI_m * E1_m );
  //Matrix<double, 6, 6, RowMajor> EJ_m( E1_m - (E1_m * (E1_m + E2_m).inverse() * E1_m) );
  //Matrix<double, 6, 6, RowMajor> EJ_m( E1_m - E1_m * sumEI_m );
  //static Matrix<double, 6, 6, RowMajor> EJ_m;
  //EJ_m = ( E1_m - E1_m * sumEI_m );
  //sumEI_m = ( E1_m - E1_m * sumEI_m * E1_m );
  EJ_m = (E1_m - E1_m * EJ_m * E1_m).eval();


  double* d =  EJ_m.array().data();
  //EJ =  EJ_m.array().data();
  //const double* d = (E1_m - (E1_m * (E1_m + E2_m).inverse() * E1_m)).array().data();

  EJ[ 0] = d[ 0];
  EJ[ 1] = d[ 6];  EJ[ 2] = d[ 7];
  EJ[ 3] = d[12];  EJ[ 4] = d[13];  EJ[ 5] = d[14];
  EJ[ 6] = d[18];  EJ[ 7] = d[19];  EJ[ 8] = d[20];  EJ[ 9] = d[21];
  EJ[10] = d[24];  EJ[11] = d[25];  EJ[12] = d[26];  EJ[13] = d[27];  EJ[14] = d[28];
  EJ[15] = d[30];  EJ[16] = d[31];  EJ[17] = d[32];  EJ[18] = d[33];  EJ[19] = d[34];  EJ[20] = d[35];

  return chi2;
}


}
