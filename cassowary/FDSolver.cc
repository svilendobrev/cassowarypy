// $Id: FDSolver.cc,v 1.1.1.1 2003/01/15 14:06:20 svilen Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// ( C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// FDSolver.cc


#ifdef HAVE_CONFIG_H
#include <cassowary/config.h>
#define CONFIG_H_INCLUDED
#endif

#ifndef FDSOLVE_DEBUG
#define NO_FDSOLVE_DEBUG
#endif

#include "Cassowary.h"
#include "FDSolver.h"
#include "FDBinaryOneWayConstraint.h"
#include "Variable.h"
#include "debug.h"
#include <GTL/topsort.h>
#include <pair.h>
#include <math.h>
#include <stdarg.h>

static int fDebugFDSolve;

FDSolver & 
FDSolver::AddConstraint( P_Constraint pcn)
{
  AddConstraintInternal( pcn);
  if ( _fAutosolve) Solve();
  return * this;
}

FDSolver & 
FDSolver::RemoveConstraint( P_Constraint pcn)
{
  RemoveConstraintInternal( pcn);
  if ( _fAutosolve) Solve();
  return * this;
}

FDSolver & 
FDSolver::AddConstraintInternal( P_Constraint pcn)
{
#ifdef CL_TRACE
  Tracer TRACER( __FUNCTION__);
  cerr << "(" << * pcn << ")" << endl;
#endif

  FDBinaryOneWayConstraint * pcnfd = dynamic_cast<FDBinaryOneWayConstraint * >( pcn.ptr());
  if (!pcnfd) 
    throw ExCLTooDifficultSpecial("Can only add FDBinaryOneWayConstraint-s to FDSolvers");
  
  Variable rw = pcnfd->vRW();
  Variable ro = pcnfd->vRO();
  if (!rw.IsFDVariable()) {
    throw ExCLTooDifficultSpecial("RW variable must be an FDVariable");
  }
  if (!( ro.IsNil() || ro.IsFDVariable())) {
    throw ExCLTooDifficultSpecial("RO variable must be an FDVariable or clvNil");
  }
  // add the constraint to our set of cns
  _setCns.insert( pcn);
  // and add the constraint to the cns that affect var rw
  assert(!rw.IsNil());
  _mapvToCns[rw].insert( pcn);


  node nRw = GetVarNode( rw);
  if (!ro.IsNil()) {
    node nRo = GetVarNode( ro);
    edge e = G.new_edge( nRo, nRw);

    _mapCnToEdge[pcn] = e;

    if (!G.is_acyclic()) {
      /* there is a cycle... give up after cleaning up */
      RemoveConstraint( pcn);
      throw ExCLCycleNotAllowed();
    }
  }
  return * this;
}

FDSolver & 
FDSolver::RemoveConstraintInternal( P_Constraint pcn)
{
#ifdef CL_TRACE
  Tracer TRACER( __FUNCTION__);
  cerr << "(" << * pcn << ")" << endl;
#endif

  FDBinaryOneWayConstraint * pcnfd = dynamic_cast<FDBinaryOneWayConstraint * >( pcn.ptr()); 
  if (!pcnfd) 
    throw ExCLInternalError("Could not downcast to a FDBinaryOneWayConstraint");

  ConstraintSet::iterator itCn = _setCns.find( pcnfd);
  if ( itCn == _setCns.end()) {
    throw ExCLConstraintNotFound( pcn);
  }
  _setCns.erase( itCn);
  
  Variable rw = pcnfd->vRW();
  Variable ro = pcnfd->vRO();
  ConstraintSet & _cnsAffectingRW = _mapvToCns[rw];
  ConstraintSet::iterator it = _cnsAffectingRW.find( pcnfd);
  if ( it == _cnsAffectingRW.end()) {
    throw ExCLInternalError("Cannot find pcnfd");
  }
  _cnsAffectingRW.erase( it);

  if (!ro.IsNil()) {
    edge e = _mapCnToEdge[pcn];
    G.del_edge( e);
    _mapCnToEdge.erase( pcn);

    if ( _mapVarToNode.find( ro) != _mapVarToNode.end() &&
        _mapVarToNode[ro].degree() == 0) {
      G.del_node( _mapVarToNode[ro]);
      _mapVarToNode.erase( ro);
    }
  }
  if ( _mapVarToNode.find( rw) != _mapVarToNode.end() &&
      _mapVarToNode[rw].degree() == 0) {
    G.del_node( _mapVarToNode[rw]);
    _mapVarToNode.erase( rw);
  }
  if ( _mapvToCns[rw].size() == 0) {
    _mapvToCns.erase( rw);
  }

  return * this;
}

FDSolver & 
FDSolver::Solve()
{
  topsort t;
  t.run( G);
  topsort::topsort_iterator it = t.top_order_begin();
  topsort::topsort_iterator end = t.top_order_end();
  SymbolicWeight errorTotal;
  ResetSetFlagsOnVariables();
  for (; it != end; ++it) {
    Variable clv = nodeToVar[*it];
    FDVariable * pcldv = dynamic_cast<FDVariable*>( clv.get_pclv());
#ifndef NO_FDSOLVE_DEBUG
    if ( fDebugFDSolve) {
      if (!clv.IsNil()) cout << "node " << (*it) << " is " << clv << endl;
      cerr << "Set from: " << endl;
      for ( ConstraintSet::iterator itCns = _mapvToCns[clv].begin();
           itCns != _mapvToCns[clv].end();
           ++itCns) {
        const Constraint * pcn = * itCns;
        cerr << * pcn << endl;
      }
      cerr << endl;
    }
#endif
    pair<SymbolicWeight,FDNumber> p = ComputeBest( pcldv);
    SymbolicWeight e = p.first;
    FDNumber v = p.second;
    if ( v == FDN_NOTSET)
      throw ExCLRequiredFailure();
    pcldv->ChangeValue( v);
    pcldv->SetFIsSet( true);
    errorTotal += e;
  }
  return * this;
}

/* return the best ( lowest) incremental error and the value
   at which that error occurs */
pair<SymbolicWeight,FDNumber>
FDSolver::ComputeBest( FDVariable * pcldv)
{
  assert( pcldv);
  //  assert(!pcldv->FIsSet()); //GJB:FIXME::
  SymbolicWeight minError = sRequired().symbolicWeight();
  FDNumber bestValue = FDN_NOTSET;
  //  Variable clv( pcldv);
  // for each domain value
  for ( list<FDNumber>::const_iterator itVal= pcldv->PlfdnDomain()->begin();
       itVal != pcldv->PlfdnDomain()->end();
       ++itVal) {
    FDNumber value = * itVal;
    SymbolicWeight error;
    const ConstraintSet & setCns = _mapvToCns[pcldv];
    // for each constraint affecting * pcldv
    for ( ConstraintSet::const_iterator itCn = setCns.begin();
         itCn != setCns.end();
         ++itCn) {
      P_Constraint pcn = * itCn;
      SymbolicWeight e = ErrorForvAtValSubjectToCn( pcldv,value,pcn);
      error += e;
    }
    // now error is the total error for binding clv <- value
    if ( error < minError) {
      minError = error;
      bestValue = value;
    }
  }
  // now minError is the lowest error we can get for clv
  // and it occurs binding clv <- bestValue
  if  ( bestValue == FDN_NOTSET)
    throw ExCLRequiredFailure();
  return pair<SymbolicWeight,FDNumber>( minError,bestValue);
}

SymbolicWeight
FDSolver::ErrorForvAtValSubjectToCn( FDVariable * pcldv,FDNumber value, P_Constraint cn)
{
  FDBinaryOneWayConstraint * pcnFd = dynamic_cast<FDBinaryOneWayConstraint*>( cn.ptr());
  if (!pcnFd)
     throw ExCLInternalError("Not a binary FD constraint.");
  CnRelation rel = pcnFd->Relation();
  double m = pcnFd->Coefficient();
  double b = pcnFd->Constant();
  Variable rw = pcnFd->vRW();
  Variable ro = pcnFd->vRO();
  assert( rw.get_pclv() == pcldv);
  double e;
  double x = ro.IsNil()? 0 : ro.Value();
  // return the error in satisfying:
  // value REL m*x + b
  double rhs = m*x + b;
  switch ( rel) {
  case cnLEQ:
    if ( value <= rhs) e = 0;
    else e = 1 + value-rhs;
    break;
  case cnLT:
    if ( value < rhs) e = 0;
    else e = 1 + value-rhs;
    break;
  case cnGEQ:
    if ( value >= rhs) e = 0;
    else e = 1+ rhs-value;
    break;
  case cnGT:
    if ( value > rhs) e = 0;
    else e = 1 + rhs-value;
    break;
  case cnEQ:
    if ( value == rhs) e = 0;
    else e = 1 + fabs( rhs-value);
    break;
  case cnNEQ:
    if ( value != rhs) e = 0;
    else e = 1; /* GJB:FIXME:: what makes sense here? */
    break;
  default:
    e = 0; /* quiet warning */
    assert( false);
  }

  SymbolicWeight err;
  if ( cn->IsRequired() && e > 0)
    err = sRequired().symbolicWeight();
  else
    err = cn->symbolicWeight() * ( e * cn->_weight);
#ifndef NO_FDSOLVE_DEBUG
  if ( fDebugFDSolve) {
    cerr << "Error at " << value << " = " << err << endl;
  }
#endif
  return err;
}


FDSolver & 
FDSolver::ShowSolve()
{
  topsort t;
  t.run( G);
  topsort::topsort_iterator it = t.top_order_begin();
  topsort::topsort_iterator end = t.top_order_end();
#ifndef NO_FDSOLVE_DEBUG
  for (; it != end; ++it) {
    Variable clv = nodeToVar[*it];
    if (!clv.IsNil()) cout << "Node " << (*it) << " is " << clv << endl;
    cout << "Set from: " << endl;
    for ( ConstraintSet::iterator itCns = _mapvToCns[clv].begin();
         itCns != _mapvToCns[clv].end();
         ++itCns) {
      const Constraint * pcn = * itCns;
      cout << * pcn << endl;
    }
    cout << endl;
  }
#endif
  return * this;
}


/* Turn all FDVariable FIsSet() flags to false */
void 
FDSolver::ResetSetFlagsOnVariables()
{
  for ( VarToConstraintSetMap::iterator it = _mapvToCns.begin();
       it != _mapvToCns.end();
       ++it) {
    Variable clv = (*it).first;
    FDVariable * pcldv = dynamic_cast<FDVariable*>( clv.get_pclv());
    assert( pcldv);
    pcldv->SetFIsSet( false);
  }
}

#ifndef CL_NO_IO
ostream & 
FDSolver::PrintOn( ostream & xo) const
{
  xo << "FDSolver: " 
     << _setCns
     << "Graph nodes, edges = " << G.number_of_nodes() << ", " << G.number_of_edges()
     << endl;
  return xo;
}

ostream & 
FDSolver::PrintInternalInfo( ostream & xo) const
{  return xo; }


ostream & operator<<( ostream & xo, const FDSolver & clfds)
{  return clfds.PrintOn( xo); }
#endif

//// protected member functions

/* Create node for v in G, if necessary,
   otherwise return the node we already created. */
node 
FDSolver::GetVarNode( Variable v)
{
  Map<Variable,node>::iterator it = _mapVarToNode.find( v);
  if ( it == _mapVarToNode.end()) {
    node n = G.new_node();
    _mapVarToNode[v] = n;
    nodeToVar[n] = v;
    return n;
  } else {
    return (*it).second;
  }
}


void 
ListPushOnto( list<FDNumber> * pl, ...)
{
  va_list ap;
  va_start( ap, pl);
  FDNumber n;
  while ( ( n = va_arg( ap, FDNumber)) != FDN_EOL) {
    pl->push_back( n);
  }
  va_end( ap);
}
