// $Id$
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// Reader.h
// Original implementation contributed by Steve Wolfman
// Subsequently largely revised by Greg J. Badros

#ifndef CREADER_H
#define CREADER_H

#if defined(HAVE_CONFIG_H) && !defined(CONFIG_H_INCLUDED) && !defined(CONFIG_INLINE_H_INCLUDED)
#include <cassowary/config-inline.h>
#define CONFIG_INLINE_H_INCLUDED
#endif

#include <string>
#include <map>
#include <algorithm>
#include "Errors.h"
#include "Variable.h"
#include "Strength.h"
#include "LinearExpression_fwd.h"

class Constraint;
class istream;

class VarLookupFunction : public unary_function<const string &,Variable *> {
public:
  virtual Variable *operator()(const string &) const { return &clvNil; }
};


// Attempts to read a constraint of input stream in
// Returns constraint (freshly allocated, client responsibility to deallocate)
// if succesful. Otherwise, returns 0.
Constraint *PcnParseConstraint(istream &xi, const VarLookupFunction &lookup_func,
                                 const Strength &strength = sRequired());

class VarLookupInMap : public VarLookupFunction {
public:
  VarLookupInMap(StringToVarMap *pmapVars, bool fAutoCreate) 
      : _pmapVars(pmapVars), _fAutoCreate(fAutoCreate) { }

  Variable *operator()(const string &str) const
    { 
      if (!_pmapVars)
        return &clvNil;
      StringToVarMap &_mapVars = *_pmapVars;
      StringToVarMap::iterator it = _mapVars.find(str);
      if (it != _mapVars.end()) {
        return &it->second;
      } else if (_fAutoCreate) {
        // save the old symbol table, if any
        StringToVarMap *pmapOld = Variable::VarMap();
	// and set it to this one temporarily
        Variable::SetVarMap(&_mapVars);
	Variable *pclv = new Variable(str);
        // now switch it back
        Variable::SetVarMap(pmapOld);
        return pclv;
      } else {
        return &clvNil;
      }
    }
private:
  StringToVarMap *_pmapVars;
  bool _fAutoCreate;
};


/* the "yyerror" function */
void clerror(const char *sz);

struct ParseData {
  ParseData(istream &xi, const VarLookupFunction &lookup_func)
      : _xi(xi), _lookup_func(lookup_func) { }

  Constraint *Pcn() { return _pcn; }

  VarSet _readOnlyVarsSoFar;
      
  istream & _xi;
  Constraint * _pcn;
  const VarLookupFunction &_lookup_func;
};


inline 
const Strength
&sFromSz(const char *sz)
{
  const Strength *pcls = &sRequired();
  double n1, n2, n3;
  if (strcmp("required",sz) == 0)
    ; /* initialized to sRequired, above */
  else if (strcasecmp("strong",sz) == 0) { pcls = &sStrong(); }
  else if (strcasecmp("medium",sz) == 0) { pcls = &sMedium(); }
  else if (strcasecmp("weak",sz) == 0) { pcls = &sWeak(); }
  else if (sscanf(sz,"(%lf,%lf,%lf)",&n1,&n2,&n3) == 3) {
    pcls = new Strength("parsed",n1,n2,n3);
  } else {
    throw ExCLParseErrorMisc("Error parsing strength");
  }
  return *pcls;
}


#endif
