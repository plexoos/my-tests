double StiTrackNodeHelper::joinTwo(int nP1, const double *P1, const double *E1,
                                   int nP2, const double *P2, const double *E2,
                                                  double *PJ,       double *EJ)
{
  assert(nP1 <= nP2);

  // Number of elements in packed symmetric triangular matrix, e.g. 15 for 6x6 matrix
  // nE2 >= nE1
  int nE1 = nP1 * (nP1 + 1) / 2;
  int nE2 = nP2 * (nP2 + 1) / 2;

  TArrayD ard(nE2*6);

  double *a = ard.GetArray();
  double *sumE          = (a);         // pointer to begin
  double *sumEI         = (a += nE2);  // pointer to begin + 1*nE2
  double *e1sumEIe1     = (a += nE2);  // pointer to begin + 2*nE2
  double *subP          = (a += nE2);  // pointer to begin + 3*nE2
  double *sumEIsubP     = (a += nE2);  // pointer to begin + 4*nE2

  double chi2 = 3e33;
  double p, q;

  // Prepare for swapping the measurements based on the smalest errors
  const double *p1 = P1, *p2 = P2, *e1 = E1, *e2 = E2;
  const double *t;

  double choice = (nP1 == nP2) ? 0 : 1;

  if ( !choice ) // true if nP1 == nP2, i.e. choice == 0
  {
    for (int i = 0, n = 1; i < nE2; i += (++n))
    {
      p = std::fabs(e1[i]);
      q = std::fabs(e2[i]);
      // Compare signs of corresponding diagonal elements in E1 and E2
      choice += (p - q) / (p + q + 1e-10);
    }
  }

  // Swap P1 and P2, E1 and E2. Choice is positive when all diagonal elements
  // in E1 larger than corresponding elements in E2
  if ( choice > 0 )
  {
    t = p2; p2 = p1; p1 = t;
    t = e2; e2 = e1; e1 = t;
  }

  do { // empty loop
    // Join errors
    TCL::vadd(e1, e2, sumE, nE1);

    // Check _cYY component?
    int negati = (sumE[2] < 0);

    // Change the sign of all elements
    if (negati)
      TCL::vcopyn(sumE, sumE, nE1);

    // Check _cXX component?
    int ign0re = (sumE[0] <= 0);

    if (ign0re)
      sumE[0] = 1;

    // Invert triangular symmetric matrix sumE^-1 -> sumEI
    TCL::trsinv(sumE, sumEI, nP1);

    if (ign0re)
    {
      sumE[0] = 0;
      sumEI[0] = 0;
    }

    if (negati)
    {
      TCL::vcopyn(sumE,  sumE,  nE1);
      TCL::vcopyn(sumEI, sumEI, nE1);
    }

    // subP = p2 - p1
    TCL::vsub(p2, p1, subP, nP1);
    // chi2 = subP * sumEI * subP^T (ASA^T)
    TCL::trasat(subP, sumEI, &chi2, 1, nP1);

    // Calculate error on joined parameters
    if (!EJ) break;

    // I think errors in e1 assumed to be much less than in e2
    //
    // trqsq(Q, S, R, M); R = QSQ; Q, S, and R are MxM symmetric matrices
    // (nP2 x nP2) * (nP2 x nP2) * (nP2 x nP2) = (nP2 x nP2)
    TCL::trqsq(e1, sumEI, e1sumEIe1, nP2);
    // EJ = e1 - e1sumEIe1
    TCL::vsub(e1, e1sumEIe1, EJ, nE2);

  } while(0);

  // Join params
  // Calculate weighted average?
  if (PJ)
  {
    // subP * sumEI = sumEIsubP;
    // (1 x nP1) * (nP1 x nP1) = (1 x nP1)
    TCL::tras(subP,      sumEI, sumEIsubP, 1, nP1);

    // (1 x nP2) * (nP2 x nP2) = (1 x nP2)
    TCL::tras(sumEIsubP, e1,    PJ,        1, nP2);

    // (1 x nP2) + (1 x nP2)
    TCL::vadd(PJ,        p1,    PJ,           nP2);
  }

  return chi2;
}
