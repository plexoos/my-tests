#include <cstring>
#include <algorithm>

#include "Math/SMatrix.h"
#include "Math/MatrixFunctions.h"


namespace smatrix
{

typedef ROOT::Math::SMatrix<double, 6>  SMatrix66;
typedef ROOT::Math::SMatrix<double, 6, 6, ROOT::Math::MatRepSym<double, 6> >  SMatrixSym6;


/**
 * This function updates the contents of the G array
 */
void errPropag6( double G[21],const double F[6][6],int nF )
{
  static SMatrixSym6 G_s(G, G + 21);
  static SMatrix66   F_s(&F[0][0], &F[0][0] + 36);

  G_s = ROOT::Math::Similarity(F_s, G_s);

  //G = G_s.Array();
  std::copy(G_s.begin(), G_s.end(), G);
}

}
