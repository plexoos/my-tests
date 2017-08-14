#include <cstring>
#include <algorithm>

#include "Eigen/Dense"


namespace eigen
{


/**
 * This function updates the contents of the G array
 */
void errPropag6( double G[21],const double F[6][6],int nF )
{

  double G_full[36] =
  {
    G[ 0], G[ 1], G[ 3], G[ 6], G[10], G[15],
    G[ 1], G[ 2], G[ 4], G[ 7], G[11], G[16],
    G[ 3], G[ 4], G[ 5], G[ 8], G[12], G[17],
    G[ 6], G[ 7], G[ 8], G[ 9], G[13], G[18],
    G[10], G[11], G[12], G[13], G[14], G[19],
    G[15], G[16], G[17], G[18], G[19], G[20]
  };

  using namespace Eigen;

  Map< const Matrix<double, 6, 6, RowMajor> >  F_m( &F[0][0] );
  Map< Matrix<double, 6, 6, RowMajor> >  G_m( G_full );

  G_m = F_m * G_m * F_m.transpose();

  double* A =  G_m.array().data();

  G[ 0] = A[ 0];
  G[ 1] = A[ 6]; G[ 2] = A[ 7];
  G[ 3] = A[12]; G[ 4] = A[13]; G[ 5] = A[14];
  G[ 6] = A[18]; G[ 7] = A[19]; G[ 8] = A[20]; G[ 9] = A[21];
  G[10] = A[24]; G[11] = A[25]; G[12] = A[26]; G[13] = A[27]; G[14] = A[28];
  G[15] = A[30]; G[16] = A[31]; G[17] = A[32]; G[18] = A[33]; G[19] = A[34]; G[20] = A[35];

}


}
