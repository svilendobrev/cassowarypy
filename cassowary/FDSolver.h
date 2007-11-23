// $Id$
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// ( C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// Solver.h

#ifndef FDSolver_H
#define FDSolver_H

#if defined( HAVE_CONFIG_H) && !defined( CONFIG_H_INCLUDED) && !defined( CONFIG_INLINE_H_INCLUDED)
#include <cassowary/config-inline.h>
#define CONFIG_INLINE_H_INCLUDED
#endif

#include "Cassowary.h"
#include "Solver.h"
#include "Variable.h"
#include "Errors.h"
#include "Typedefs.h"
#include "SymbolicWeight.h"
#include <GTL/graph.h>

class Variable;
class FDBinaryOneWayConstraint;

// FDSolver is a concrete class
// implementing a very restricted ( for now --04/23/99 gjb)
// finite-domain constraint solving algorithm
class FDSolver: public Solver {
 public:
  FDSolver()
      : _setCns(), _mapvToCns(), G(), nodeToVar( G)
    { G.make_directed(); }

  virtual FDSolver & AddConstraint( P_Constraint );
  virtual FDSolver & RemoveConstraint( P_Constraint );

  virtual FDSolver & Solve(); 
  virtual FDSolver & ShowSolve();

  void Changev( Variable clv, FDNumber n) {
    clv.ChangeValue( n); 
    if ( _pfnChangevCallback) {
      _pfnChangevCallback(&clv,this);
    }
  }


#ifndef CL_NO_IO
  ostream & PrintOn( ostream & xo) const;
  
  ostream & PrintInternalInfo( ostream & xo) const;

  ostream & PrintOnVerbose( ostream & xo) const 
    { PrintOn( xo); PrintInternalInfo( xo); xo << endl; return xo; }

  friend ostream & operator<<( ostream & xo, const FDSolver & solver);

#endif

 protected:

  virtual FDSolver & AddConstraintInternal( P_Constraint ); 
  virtual FDSolver & RemoveConstraintInternal( P_Constraint );

  /* Create node for v in G, if necessary,
     otherwise return the node we already created. */
  node GetVarNode( Variable v);

  /* return the best ( lowest) incremental error and the value
     at which that error occurs */
  pair<SymbolicWeight,FDNumber> ComputeBest( FDVariable * pcldv);

  SymbolicWeight ErrorForvAtValSubjectToCn( FDVariable * pcldv,
                                               FDNumber value, P_Constraint );

  /* Turn all FDVariable FIsSet() flags to false */
  void ResetSetFlagsOnVariables();

  /* all the constraints in the solver */
  ConstraintSet _setCns;

  /* _mapvToCns maps variable to the constraints in which
     it is rw ( it omits where it is ro) */
  VarToConstraintSetMap _mapvToCns;

  /* track what edges correspond to which constraints
     so we can update the constraint graph when
     removing a constraint */
  Map<P_Constraint, edge> _mapCnToEdge;

  /* track what nodes correspond to which variables */
  Map<Variable, node> _mapVarToNode;

  /* directed graph that mirrors the structure of
     the relations of the added constraints */
  graph G;

  node_map<Variable> nodeToVar;
};

#define FDN_EOL LONG_MIN

void ListPushOnto( list<FDNumber> * pl, ...);

#endif
