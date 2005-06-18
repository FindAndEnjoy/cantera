
/*
 *  $Author$
 *  $Date$
 *  $Revision$
 *
 *  Copyright 2002 California Institute of Technology
 *
 */

#include "Cantera.h"
#include "IdealGasMix.h"
#include "equilibrium.h"

int main(int argc, char **argv) {
  try {
    IdealGasMix g("silane.xml", "silane");
    g.setState_TPX(1500.0, 100.0, "SIH4:0.01, H2:0.99");
    //g.setState_TPX(1500.0, 1.0132E5, "SIH4:0.01, H2:0.99");
    equilibrate(g, TP);
    cout << g;
    return 0;
  }
  catch (CanteraError) {
    showErrors(cerr);
    cerr << "program terminating." << endl;
    return -1;
  }
}
