// $Id: FDConnectorVariable.cc,v 1.1.1.1 2003/01/15 14:06:20 svilen Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// ( C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// FDConnectorVariable.cc

#include "FDConnectorVariable.h"
#include "Solver.h" // for list<FDNumber> printing

#ifdef HAVE_CONFIG_H
#include <cassowary/config.h>
#define CONFIG_H_INCLUDED
#endif

FDConnectorVariable::FDConnectorVariable( string name, FDNumber Value, const list<FDNumber> & initial_domain,
                        SimplexSolver & solver, Variable clvFloat) 
    : FDVariable( name,Value,initial_domain),
      _solver( solver),
      _clvFloat( clvFloat),
      _pcnRequiredLink( new LinearEquation( clvFloat,Value))
{ solver.AddConstraint( _pcnRequiredLink); }

void FDConnectorVariable::ChangeValue( FDNumber Value) { 
      if ( _value != Value) {
        _value = Value;
#ifndef CL_NO_IO
        cerr << "Updating " << _clvFloat << " now!" << endl;
#endif        
        _solver.RemoveConstraint( _pcnRequiredLink);
        _pcnRequiredLink->ChangeConstant( _value);
        _solver.AddConstraint( _pcnRequiredLink);
      }
}

// Use < > for FDConnector-s, instead of [ ]
#ifndef CL_NO_IO
ostream & FDConnectorVariable::PrintOn( ostream & xo) const
{  
  xo << "<" << Name() << "=" << Value() 
     << "{" << _clvFloat << "}"
     << ":" << * PlfdnDomain() << ">";
  return xo;
}
#endif
