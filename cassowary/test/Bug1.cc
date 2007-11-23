#include "Cl.h"

int main()
{
  Variable var;
  SimplexSolver solver;
  P_Constraint stcn = new StayConstraint( var,sWeak(),1.0);

  cout << solver;
  solver.AddConstraint(stcn);
  cout << solver;
  solver.RemoveConstraint(stcn);
  cout << solver;
}
/*
The result is a segmentation fault when the constraint is removed.  I
don't understand why.

Anthony Beurive'" <beurive@labri.u-bordeaux.fr>
*/

