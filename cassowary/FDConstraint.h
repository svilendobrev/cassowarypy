// $Id$
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// ( C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// FDConstraint.h

#ifndef FDConstraint_H
#define FDConstraint_H

#if defined( HAVE_CONFIG_H) && !defined( CONFIG_H_INCLUDED) && !defined( CONFIG_INLINE_H_INCLUDED)
#include <cassowary/config-inline.h>
#define CONFIG_INLINE_H_INCLUDED
#endif

#include "Cassowary.h"
#include "Constraint.h"


// Just a node in the class hierarchy for now
class FDConstraint : public Constraint {
 private: typedef Constraint super;

 public:
  // Constructor
  FDConstraint( const Strength & strength = sRequired(),
		     double weight = 1.0) 
      : Constraint( strength, weight) { }

  virtual bool FIsOkayForSimplexSolver() const { return false; }

 protected:

};

#endif
