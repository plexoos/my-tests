double StiTrackNodeHelper::joinTwo(int nP1, const double *P1, const double *E1,
                                   int nP2, const double *P2, const double *E2,
                                                  double *PJ,       double *EJ)
{
  assert(nP1 <= nP2);

  int nE1 = nP1 * (nP1 + 1) / 2;
  int nE2 = nP2 * (nP2 + 1) / 2;

  TArrayD ard(nE2*6);

  double *a = ard.GetArray();
  double *sumE          = (a);
  double *sumEI         = (a += nE2);
  double *e1sumEIe1     = (a += nE2);
  double *subP          = (a += nE2);
  double *sumEIsubP     = (a += nE2);

  double chi2 = 3e33;
  double p, q;

  // Choose the smalest errors
  const double *p1 = P1, *p2 = P2, *e1 = E1, *e2 = E2;
  const double *t;

  double choice = (nP1 == nP2) ? 0 : 1;

  if ( !choice )
  {
    for (int i = 0, n = 1; i < nE2; i += (++n))
    {
      p = std::fabs(e1[i]);
      q = std::fabs(e2[i]);
      choice += (p - q) / (p + q + 1e-10);
    }
  }

  if ( choice > 0 )
  {
    t = p2; p2 = p1; p1 = t;
    t = e2; e2 = e1; e1 = t;
  }

  do { // empty loop
    // Join errors
    TCL::vadd(e1, e2, sumE, nE1);
    int negati = (sumE[2] < 0);

    if (negati)
      TCL::vcopyn(sumE, sumE, nE1);

    int ign0re = (sumE[0] <= 0);

    if (ign0re)
      sumE[0] = 1;

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

    TCL::vsub(p2, p1, subP, nP1);
    TCL::trasat(subP, sumEI, &chi2, 1, nP1);

    if (!EJ) break;

    TCL::trqsq(e1, sumEI, e1sumEIe1, nP2);
    TCL::vsub(e1, e1sumEIe1, EJ, nE2);

  } while(0);

  // Join params
  if (PJ)
  {
    TCL::tras(subP,      sumEI, sumEIsubP, 1, nP1);
    TCL::tras(sumEIsubP, e1,    PJ,        1, nP2);
    TCL::vadd(PJ,        p1,    PJ,           nP2);
  }

  return chi2;
}
