// $Id$
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// ( C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// FDBinaryOneWayConstraint.h

#ifndef FDBinaryOneWayConstraint_H
#define FDBinaryOneWayConstraint_H

#if defined( HAVE_CONFIG_H) && !defined( CONFIG_H_INCLUDED) && !defined( CONFIG_INLINE_H_INCLUDED)
#include <cassowary/config-inline.h>
#define CONFIG_INLINE_H_INCLUDED
#endif

#include "Cassowary.h"
#include "FDConstraint.h"

class LinearConstraint;

// Just a node in the class hierarchy for now
class FDBinaryOneWayConstraint : public FDConstraint {
 private: typedef FDConstraint super;

 public:

  FDBinaryOneWayConstraint( Variable vRW, enum CnRelation rel, Variable vRO, 
                             double coefficient = 1.0, double constant = 0.0,
                             const Strength & strength = sRequired(),
                             double weight = 1.0)
      : FDConstraint( strength,weight), _vRW( vRW), _rel( rel), _vRO( vRO),
        _coefficient( coefficient), _constant( constant)
    { }
  
  FDBinaryOneWayConstraint( Variable vRW, enum CnRelation rel, double constant,
                             const Strength & strength = sRequired(),
                              double weight = 1.0)
      : FDConstraint( strength,weight), _vRW( vRW), _rel( rel), _vRO( clvNil),
        _coefficient( 0), _constant( constant)
    { }
  
  FDBinaryOneWayConstraint( const Constraint & cn);

  static void EnsurePreconditionsForCn( const Constraint & cn);

  static bool FCanConvertCn( const Constraint & cn);

#ifndef CL_NO_IO
  virtual ostream & PrintOn( ostream & xo) const
    { 
      xo << "FDCn: " << _vRW << " " << StrCnRelation( _rel) << " ";
      if ( _coefficient != 0) {
        if ( _coefficient != 1) xo << _coefficient << "*";
        if ( _vRO != clvNil) xo << _vRO;
      }
      if ( _constant != 0) xo << " + " << _constant;
      return xo;
    }

  friend ostream& operator<<( ostream & xos, const FDBinaryOneWayConstraint & constraint)
    { return constraint.PrintOn( xos); }

#endif

  Variable vRW() const
    { return _vRW; }
  Variable vRO() const 
    { return _vRO; }
  CnRelation Relation() const 
    { return _rel; }
  double Coefficient() const 
    { return _coefficient; }
  double Constant() const 
    { return _constant; }

  bool IsInequality() const
    { return ( _rel != cnEQ && _rel != cnNEQ); }

  bool IsStrictInequality() const
    { return ( _rel == cnGT || _rel == cnLT); }

 protected:
  Variable _vRW;
  CnRelation _rel;
  Variable _vRO;
  double _coefficient;
  double _constant;
};

#endif
