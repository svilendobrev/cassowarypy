/* $Id: Bug2.cc,v 1.1 2003/08/21 15:34:29 SVILEN Exp $

From: "Anthony Beurive'" <beurive@labri.u-bordeaux.fr> 
Subject: cassowary 
To: gjb@cs.washington.edu 
Date: Tue, 9 Mar 1999 12:42:24 +0100 (CET) 

I believe there's a bug in cassowary.  It seems to be related to the 
previous one I encountered a while ago, concerning the removal of 
constraints. 
 
The three following examples may help you to track the bug, I hope. 
 
-------------------------------------------------------------------------------- 
#include "Cl.h" 
 
void main() 
{ 
  SimplexSolver *solver = new SimplexSolver(); 
  Variable *var = new Variable(); 
  StayConstraint *stcn = new StayConstraint(*var,sWeak(),1.0); 
 
  solver->AddConstraint(*stcn); 
  cout << *solver; 
  solver->RemoveConstraint(*stcn); 
  cout << *solver; 
} 
-------------------------------------------------------------------------------- 
This works fine. 
 
 
Now, the factor of the stay constraint is changed. 
-------------------------------------------------------------------------------- 
#include "Cl.h" 
 
void main() 
{ 
  SimplexSolver *solver = new SimplexSolver(); 
  Variable *var = new Variable(); 
  StayConstraint *stcn = new StayConstraint(*var,sWeak(),2.0); 
 
  solver->AddConstraint(*stcn); 
  cout << *solver; 
  solver->RemoveConstraint(*stcn); 
  cout << *solver; 
} 
-------------------------------------------------------------------------------- 
The result is: 
test2: SimplexSolver.cc:1199: void SimplexSolver::Optimize(class Variable): Assertion \
`pzRow != __null' failed. 
Aborted 
 
 
Now, the solver is created after the variable. 
-------------------------------------------------------------------------------- 
#include "Cl.h" 
 
void main() 
{ 
  Variable *var = new Variable(); 
  SimplexSolver *solver = new SimplexSolver(); 
  StayConstraint *stcn = new StayConstraint(*var,sWeak(),2.0); 
 
  solver->AddConstraint(*stcn); 
  cout << *solver; 
  solver->RemoveConstraint(*stcn); 
  cout << *solver; 
} 
-------------------------------------------------------------------------------- 
This works again. 
 
 
Can you reproduce the same results?  Maybe the cause is my c++ 
compiler (egcs-2.90.29 980515 (egcs-1.0.3 release)).  I don't know. 

*/

#include "Cl.h"

void foo1() 
{ 
  SimplexSolver *solver = new SimplexSolver(); 
  Variable var;
  P_Constraint stcn = new StayConstraint( var,sWeak(),1.0); 
 
  solver->AddConstraint(stcn); 
  cout << *solver; 
  solver->RemoveConstraint(stcn); 
  cout << *solver; 
	delete solver;
} 


void foo2() 
{ 
  SimplexSolver *solver = new SimplexSolver(); 
  Variable var;
  P_Constraint stcn = new StayConstraint( var,sWeak(),2.0); 
 
  solver->AddConstraint(stcn); 
  cout << *solver; 
  solver->RemoveConstraint(stcn); 
  cout << *solver; 
	delete solver;
} 


void foo3() 
{ 
  Variable var;
  SimplexSolver *solver = new SimplexSolver(); 
  P_Constraint stcn = new StayConstraint( var,sWeak(),2.0); 
 
  solver->AddConstraint(stcn); 
  cout << *solver; 
  solver->RemoveConstraint(stcn); 
  cout << *solver; 
	delete solver;
} 


int main()
{
  cerr << "Test1: " << endl;
  foo1();

  cerr << "\nTest2: " << endl;
  foo2();

  cerr << "\nTest3: " << endl;
  foo3();

}
