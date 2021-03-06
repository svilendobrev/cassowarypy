// $Id: SimplexSolver.cc,v 1.2 2003/08/21 15:34:29 SVILEN Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// ( C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// SimplexSolver.cc

#include "SimplexSolver.h"
#include "LinearInequality.h"
#include "StayConstraint.h"
#include "EditConstraint.h"
#include "Errors.h"
#include "Variable.h"
#include "Point.h"
#include "SlackVariable.h"
#include "ObjectiveVariable.h"
#include "DummyVariable.h"
#include <algorithm>
#include <float.h>
#include <sstream>
#include <queue>
#include "debug.h"

#ifdef HAVE_CONFIG_H
#include <cassowary/config.h>
#define CONFIG_H_INCLUDED
#endif

//#define CL_TRACE 1

const char * szCassowaryVersion = VERSION;

  // EditInfo is a privately-used class
  // that just wraps a constraint, its positive and negative
  // error variables, and its prior edit Constant.
  // It is used as values in _editInfoList, and replaces
  // the parallel vectors of error variables and previous edit
  // constants from the smalltalk version of the code.
class SimplexSolver::EditInfo {
    REFCOUNT_DEF                 //from nref.h
  public:
    
    // These instances own none of the pointers;
    // the tableau row ( the Expression) owns the peplus, peminus,
    // and AddEditVar/RemoveEditVar pair or the client code owns
    // the constraint object
    EditInfo( const Variable & clv,
               EditConstraint * pconstraint, 
               const Variable & eplus, const Variable & eminus,
               Number prevEditConstant)
        :_clv( clv),
         _pconstraint( pconstraint),
         _clvEditPlus( eplus), _clvEditMinus( eminus),
         _prevEditConstant( prevEditConstant)
      { }
    
    ~EditInfo() { REFCOUNT_DIE( EditInfo) }

#ifndef CL_NO_IO
    ostream & PrintOn( ostream & xo) const
      { xo << _clv << " -> [" << _clvEditPlus << ", " << _clvEditMinus << "](" 
           << _prevEditConstant << ")@" << " -- " 
           << * _pconstraint; 
      return xo; }
    
    friend ostream & operator<<( ostream & xo, const EditInfo & cei)
      { return cei.PrintOn( xo); }
#endif

    Variable _clv;
    P_Constraint _pconstraint;
    Variable _clvEditPlus;
    Variable _clvEditMinus;
    Number _prevEditConstant;
};

#include "my/refcntp.h"
REFCOUNT_DECL( SimplexSolver::EditInfo)         //from refcntp.h
REFCOUNT_INST( SimplexSolver::EditInfo)         //from refcnt.h

#ifndef CL_NO_IO
ostream & PrintTo( ostream & xo, const SimplexSolver::EditInfoList & listPEditInfo);
ostream & operator<<( ostream & xo, const SimplexSolver::EditInfoList & listPEditInfo);
#endif


SimplexSolver::P_EditInfo SimplexSolver::PEditInfoFromv( const Variable & clv) {
    EditInfoList::iterator it = _editInfoList.begin();
    for (; it != _editInfoList.end(); ++it) {
      P_EditInfo pei = (*it);
      if ( pei->_clv == clv)
        return pei;
    }
    return NULL;
}

SimplexSolver & SimplexSolver::RemoveEditVar( const Variable & v) {
      P_EditInfo pcei = PEditInfoFromv( v);
      if (!pcei) {
        throw ExCLEditMisuse("Removing edit variable that was not found");
      }
      P_Constraint pcnEdit = pcei->_pconstraint;
      RemoveConstraint( pcnEdit);
      return *this;
}
SimplexSolver & SimplexSolver::BeginEdit() {
      if ( _editInfoList.size() == 0) {
        throw ExCLEditMisuse("BeginEdit called, but no edit variable");
      }
      // may later want to do more in here
      _infeasibleRows.clear();
      ResetStayConstants();
      _stkCedcns.push( _editInfoList.size());
      return *this;
}
SimplexSolver & SimplexSolver::EndEdit() {
      if ( _editInfoList.size() == 0)
        throw ExCLEditMisuse("EndEdit called but no edit variables");
      Resolve();
      _stkCedcns.pop();
      RemoveEditVarsTo( _stkCedcns.top());
      // may later want to do more in here
      return *this;
}

SimplexSolver & SimplexSolver::AddLowerBound( Variable v, Number lower) { 
    return AddConstraint( new LinearInequality( LinearExpression( v - lower)));
}
SimplexSolver & SimplexSolver::AddUpperBound( Variable v, Number upper) {
    return AddConstraint( new LinearInequality( LinearExpression( upper - v)));
}
SimplexSolver & SimplexSolver::AddEditVar( const Variable & v, const Strength & strength, double weight ) { 
    return AddConstraint( new EditConstraint( v, strength, weight));
}
SimplexSolver & SimplexSolver::AddStay( const Variable & v, const Strength & strength, double weight ) {
    return AddConstraint( new StayConstraint( v,strength,weight)); 
}

SimplexSolver::SimplexSolver() :
    Solver(),
    _objective( new ObjectiveVariable("Z")),
    _slackCounter( 0),
    _artificialCounter( 0),
#ifdef CL_FIND_LEAK
    _cArtificialVarsDeleted( 0),
#endif
    _dummyCounter( 0),
    _epsilon( 1e-8),
    _fResetStayConstantsAutomatically( true),
    _fNeedsSolving( false),
    _fExplainFailure( false),
    _pfnResolveCallback( NULL),
    _pfnCnSatCallback( NULL)
    { 
    _rows[_objective] = new LinearExpression(); 
    // start out with no edit variables
    _stkCedcns.push( 0);
#ifdef CL_TRACE
    cout << "objective row new@ " << _rows[_objective].ptr() << endl;
#endif
}


SimplexSolver::~SimplexSolver()
{
#ifdef CL_SOLVER_STATS
  cout << "_slackCounter == " << _slackCounter
       << "\n_artificialCounter == " << _artificialCounter
       << "\n_dummyCounter == " << _dummyCounter << endl;
  cout << "stayMinusErrorVars " << _stayMinusErrorVars.size() << ", "
       << "stayPlusErrorVars " << _stayPlusErrorVars.size() << ", "
       << "errorVars " << _errorVars.size() << ", "
       << "markerVars " << _markerVars.size() << endl;
#endif
  // Cannot print *this here, since local Variable-s may have been
  // destructed already
#ifdef CL_FIND_LEAK
  cout << "die SimplexSolver== " << this << endl;
#endif  
}

// Add the constraint cn to the tableau
SimplexSolver & 
SimplexSolver::AddConstraint( P_Constraint pcn)
{
#ifdef CL_TRACE
  Tracer TRACER( __FUNCTION__);
  cout << "(" << * pcn << ")" << endl;
#endif
  
  if (!pcn->FIsOkayForSimplexSolver()) {
    throw ExCLTooDifficultSpecial("SimplexSolver cannot handle this constraint object");
  }

  if ( pcn->IsStrictInequality()) {
    // cannot handle strict inequalities
    throw ExCLStrictInequalityNotAllowed();
  }

  if ( pcn->ReadOnlyVars().size() > 0) {
    // cannot handle read-only vars
    throw ExCLReadOnlyNotAllowed();
  }

  if ( pcn->IsEditConstraint())
    {
    EditConstraint * pcnEdit = dynamic_cast<EditConstraint * >( pcn.ptr());
    const Variable & v = pcnEdit->variable();
    if (!v.IsExternal() ||
        (!FIsBasicVar( v) && !ColumnsHasKey( v)))
      {
      // we could try to make this case work,
      // but it'd be unnecessarily inefficient --
      // and probably easier for the client application
      // to deal with
      throw ExCLEditMisuse("( ExCLEditMisuse) Edit constraint on variable not in tableau.");
      }
    P_EditInfo pcei = PEditInfoFromv( v);
    if ( pcei)
      {
      // we need to only add a partial _editInfoList entry for this
      // edit constraint since the variable is already being edited.
      // otherwise a more complete entry is added later in this function
      _editInfoList.push_back( new EditInfo( v, NULL, clvNil, clvNil, 0));
      return *this;
      }
    }

  Variable clvEplus, clvEminus;
  Number prevEConstant;
  P_LinearExpression expr = NewExpression( pcn, /* output to: */
                                            clvEplus,clvEminus,
                                            prevEConstant);
  bool fAddedOkDirectly = false;

  try 
    {
    // If possible Add expr directly to the appropriate tableau by
    // choosing a subject for expr ( a variable to become basic) from
    // among the current variables in expr.  If this doesn't work use an
    // artificial variable.  After adding expr re-Optimize.
    fAddedOkDirectly = TryAddingDirectly( expr);
    }
  catch ( ExCLRequiredFailure & error)
    {
#ifdef CL_TRACE
    cout << "could not Add directly -- caught ExCLRequiredFailure error" << endl;
#endif
    RemoveConstraintInternal( pcn);
    throw;
    }

  if (!fAddedOkDirectly)
    { // could not Add directly
    ExCLRequiredFailureWithExplanation e;
    if (!AddWithArtificialVariable( expr, e))
      {
#ifdef CL_DEBUG_FAILURES
      cout << "Failed solve! Could not Add constraint.\n"
           << *this << endl;
#endif
      RemoveConstraintInternal( pcn);
      if ( FIsExplaining())
        throw e;
      else
        throw ExCLRequiredFailure();
      }
    }

  _fNeedsSolving = true;

  if ( pcn->IsEditConstraint())
    {
    EditConstraint * pcnEdit = dynamic_cast<EditConstraint * >( pcn.ptr());
    const Variable & clv = pcnEdit->variable();
    _editInfoList.push_back( new EditInfo( clv, pcnEdit, clvEplus, clvEminus,
                                       prevEConstant));
    }

  if ( _fAutosolve)
    {
    Optimize( _objective);
    SetExternalVariables();
    }

  pcn->addedTo(*this);
  return *this;
}

// Add weak stays to the x and y parts of each point. These have
// increasing weights so that the solver will try to satisfy the x
// and y stays on the same point, rather than the x stay on one and
// the y stay on another.
SimplexSolver & 
SimplexSolver::AddPointStays( const vector<const Point * > & listOfPoints,
                               const Strength & strength)
{
#ifdef CL_TRACE
  Tracer TRACER( __FUNCTION__);
#endif

  vector<const Point * >::const_iterator it = listOfPoints.begin();
  double weight = 1.0;
  static const double multiplier = 2.0;
  for ( ; it != listOfPoints.end(); ++it )
    {
    AddPointStay((*it)->X(),(*it)->Y(),strength,weight);
    weight *= multiplier;
    }
  return *this;
}

SimplexSolver & 
SimplexSolver::AddPointStay( const Point & clp, const Strength & strength, double weight)
{ 
  AddPointStay( clp.X(),clp.Y(),strength,weight);
  return *this;
}


SimplexSolver & 
SimplexSolver::RemoveEditVarsTo( int n)
{
  queue<Variable> qclv;
  VarSet sclvStillEditing; // Set of edit variables that we need to * not* remove
#ifdef DEBUG_NESTED_EDITS
  cout << __FUNCTION__ << " " << n << endl;
#endif
  int i = 0;
  for ( EditInfoList::const_iterator it = _editInfoList.begin();
        ( it != _editInfoList.end() && _editInfoList.size() != (unsigned)n);
        ++it, ++i ) 
    {
    P_EditInfo pcei = (*it);
    assert( pcei);
#ifdef DEBUG_NESTED_EDITS
    cout << __FUNCTION__ << "Checking " << pcei->_clv
         << ", index = " << i << endl;
#endif
    if ( i >= n 
         && pcei->_pconstraint)      //FIX: svd - complementary of 
                    //::AddConstraint() - adding a partial _editInfoList 
                    //_editInfoList.push_back( new EditInfo( v, NULL, clvNil, clvNil, 0));
      qclv.push( pcei->_clv);
    else
      sclvStillEditing.insert( pcei->_clv);
    }
  while (!qclv.empty()) 
    {
    Variable clv = qclv.front();
    // only remove the variable if it's not in the set of variable
    // from a previous nested outer edit
    // e.g., if I do:
    // Edit x,y
    // Edit w,h,x,y
    // EndEdit
    // The end edit needs to only get rid of the edits on w,h
    // not the ones on x,y
    if ( sclvStillEditing.find( clv) == sclvStillEditing.end())
      {
#ifdef DEBUG_NESTED_EDITS
      cout << __FUNCTION__ << ": Removing " << clv << endl;
#endif
      RemoveEditVar( clv);
      }
#ifdef DEBUG_NESTED_EDITS
    else
      {
      cout << __FUNCTION__ << ": Not removing " << clv << endl;
      }
#endif
    qclv.pop();
    }
  while ( _editInfoList.size() > (unsigned)n) {
    _editInfoList.pop_back();
  }
  
  return *this;
}


/* A predicate used for remove_if */
class VarInVarSet : public unary_function<Variable,bool> {
public:
  VarInVarSet( const VarSet & clvset) : 
      _set( clvset),
      _setEnd( clvset.end()) 
    { }

  bool operator ()( const Variable & clv) const {
    return ( _set.find( clv) != _setEnd);
  }
  
private:
  const VarSet & _set;
  const VarSet::iterator _setEnd;
};



// Remove the constraint cn from the tableau
// Also remove any error variable associated with cn
SimplexSolver & 
SimplexSolver::RemoveConstraintInternal( P_Constraint pcn)
{
#ifdef CL_TRACE
  Tracer TRACER( __FUNCTION__);
  cout << "(" << * pcn << ")" << endl;
#endif

  // We are about to remove a constraint.  There may be some stay
  // constraints that were unsatisfied previously -- if we just
  // removed the constraint these could come into play.  Instead,
  // Reset all of the stays so that things should stay where they are
  // at the moment.
  _fNeedsSolving = true;

  ResetStayConstants();

  // remove any error variables from the objective function
  P_LinearExpression pzRow = RowExpression( _objective);

#ifdef CL_TRACE
  cout << _errorVars << endl << endl;
#endif

  ConstraintToVarSetMap::iterator 
    it_eVars = _errorVars.find( pcn);
  bool fFoundErrorVar = ( it_eVars != _errorVars.end());

  if ( fFoundErrorVar)
    {
    VarSet & eVars = (*it_eVars).second;
    VarSet::iterator it = eVars.begin();
    for ( ; it != eVars.end(); ++it )
      {
      P_LinearExpression pexpr = RowExpression(*it);
      if ( pexpr == NULL )
        {
        pzRow->AddVariable(*it,-pcn->weight() * pcn->strength().symbolicWeight().AsDouble(),
                           _objective,*this);
        }
      else
        { // the error variable was in the basis
        pzRow->AddExpression(*pexpr,-pcn->weight() * pcn->strength().symbolicWeight().AsDouble(),
                             _objective,*this);
        }
      }
    }

  ConstraintToVarMap::iterator 
    it_marker = _markerVars.find( pcn);
  if ( it_marker == _markerVars.end())
    { // could not find the constraint
    throw ExCLConstraintNotFound( pcn);
    }
  // try to make the marker variable basic if it isn't already
  const Variable marker = (*it_marker).second;
  _markerVars.erase( it_marker);
  _constraintsMarked.erase( marker);
#ifdef CL_TRACE
  cout << "Looking to remove var " << marker << endl;
#endif
  if (!FIsBasicVar( marker))
    { // not in the basis, so need to do some work
    // first choose which variable to move out of the basis
    // only consider restricted basic variables
    VarSet & col = _columns[marker];
    VarSet::iterator it_col = col.begin();
#ifdef CL_TRACE
    cout << "Must Pivot -- columns are " << col << endl;
#endif

    Variable exitVar = clvNil;
    bool fExitVarSet = false;
    double minRatio = 0.0;
    for ( ; it_col != col.end(); ++it_col) 
      {
      const Variable & v = *it_col;
      if ( v.IsRestricted() )
        {
        P_LinearExpression pexpr = RowExpression( v);
        assert( pexpr != NULL );
        Number coeff = pexpr->CoefficientFor( marker);
#ifdef CL_TRACE
        cout << "Marker " << marker << "'s coefficient in " << * pexpr << " is "
             << coeff << endl;
#endif
        // only consider negative coefficients
        if ( coeff < 0.0) 
          {
          Number r = - pexpr->Constant() / coeff;
          if (!fExitVarSet || r < minRatio)
            {
            minRatio = r;
            exitVar = v;
            fExitVarSet = true;
            }
          }
        }
      }
    // if we didn't set exitvar above, then either the marker
    // variable has a positive coefficient in all equations, or it
    // only occurs in equations for unrestricted variables.  If it
    // does occur in an equation for a restricted variable, pick the
    // equation that gives the smallest ratio.  ( The row with the
    // marker variable will become infeasible, but all the other rows
    // will still be feasible; and we will be dropping the row with
    // the marker variable.  In effect we are removing the
    // non-negativity restriction on the marker variable.)
    if (!fExitVarSet)
      {
#ifdef CL_TRACE
      cout << "exitVar did not get set" << endl;
#endif
      it_col = col.begin();
      for ( ; it_col != col.end(); ++it_col) 
        {
        Variable v = * it_col;
        if ( v.IsRestricted() )
          {
          P_LinearExpression pexpr = RowExpression( v);
          assert( pexpr != NULL);
          Number coeff = pexpr->CoefficientFor( marker);
          Number r = pexpr->Constant() / coeff;
          if (!fExitVarSet || r < minRatio)
            {
            minRatio = r;
            exitVar = v;
            fExitVarSet = true;
            }
          }
        }
      }

    if (!fExitVarSet)
      { // exitVar is still nil
      // If col is empty, then exitVar doesn't occur in any equations,
      // so just remove it.  Otherwise pick an exit var from among the
      // unrestricted variables whose equation involves the marker var
      if ( col.size() == 0)
        {
        RemoveColumn( marker);
        }
      else
        {
          // A. Beurive' Tue Sep 14 18:26:05 CEST 1999
          // Don't pick the objective, or it will be removed!
          it_col = col.begin();
          for ( ; it_col != col.end(); ++it_col)
            {
              Variable v = * it_col;
              if ( v != _objective)
                {
                  exitVar = v;
                  fExitVarSet = true;
                  break;
                }
            }
          assert( fExitVarSet == true);
        }
      }
    
    if ( fExitVarSet)
      {
      Pivot( marker,exitVar);
      }
    }
  
  if ( FIsBasicVar( marker))
    {
    P_LinearExpression pexpr = RemoveRow( marker);
#ifdef CL_TRACE
    cout << "delete@ " << pexpr.ptr() << endl;
#endif
    }

  // Delete any error variables.  If cn is an inequality, it also
  // contains a slack variable; but we use that as the marker variable
  // and so it has been deleted when we removed its row.
  if ( fFoundErrorVar)
    {
    VarSet & eVars = (*it_eVars).second;
    VarSet::iterator it = eVars.begin();
    for ( ; it != eVars.end(); ++it )
      {
      Variable v = (*it);
      if ( v != marker)
        {
        RemoveColumn( v);
        }
      }
    }

  if ( pcn->isStayConstraint())
    {
    // iterate over the stay{Plus,Minus}ErrorVars and remove those
    // variables v in those vectors that are also in set eVars
    if ( fFoundErrorVar)
      {
      VarSet & eVars = (*it_eVars).second;
      _stayPlusErrorVars
        .erase( remove_if( _stayPlusErrorVars.begin(),_stayPlusErrorVars.end(),
                         VarInVarSet( eVars)),
               _stayPlusErrorVars.end());
      _stayMinusErrorVars
        .erase( remove_if( _stayMinusErrorVars.begin(),_stayMinusErrorVars.end(),
                         VarInVarSet( eVars)),
               _stayMinusErrorVars.end());
      }
    }
  else if ( pcn->IsEditConstraint())
    {
    EditConstraint * pcnEdit = dynamic_cast<EditConstraint * >( pcn.ptr());
    const Variable & clv = pcnEdit->variable();
    P_EditInfo pcei = PEditInfoFromv( clv);
    assert( pcei);
    Variable clvEditMinus = pcei->_clvEditMinus;
    RemoveColumn( clvEditMinus);  // clvEditPlus is a marker var and gets removed later
    _editInfoList.remove( pcei);
    }

  if ( fFoundErrorVar)
    {
    // This code is not needed since the variables are deleted
    // when they are removed from the row --
    // leaving it in results in double deletions
    // delete the constraint's error variables
    //    VarSet & evars_set = (*it_eVars).second;
    //    VarSet::const_iterator it_set = evars_set.begin();
    //    for ( ; it_set != evars_set.end(); ++it_set)
    //      {
    //      delete * it_set;
    //      }
    _errorVars.erase((*it_eVars).first);
    }

  if ( _fAutosolve)
    {
    Optimize( _objective);
    SetExternalVariables();
    }

  return *this;
}


// Re-initialize this solver from the original constraints, thus
// getting rid of any accumulated numerical problems.  ( Actually,
// Alan hasn't observed any such problems yet, but here's the method
// anyway.)
void 
SimplexSolver::Reset()
{
#ifdef CL_TRACE
  Tracer TRACER( __FUNCTION__);
  cout << "()" << endl;
#endif
  // FIXGJB  -- can postpone writing this for a while
  // gotta be careful, though, as it's a likely place for
  // a memory leak to sneak in
  assert( false);
}


// Re-solve the cuurent collection of constraints, given the new
// values for the edit variables that have already been
// suggested ( see SuggestValue() method)
void 
SimplexSolver::Resolve()
{ // CODE DUPLICATED ABOVE
#ifdef CL_TRACE
  Tracer TRACER( __FUNCTION__);
#endif
  DualOptimize();
  SetExternalVariables();
  _infeasibleRows.clear();
  if ( _fResetStayConstantsAutomatically)
    ResetStayConstants();
}

SimplexSolver & 
SimplexSolver::SuggestValue( const Variable & v, Number x)
{
#ifdef CL_TRACE
  Tracer TRACER( __FUNCTION__);
#endif
  P_EditInfo pcei = PEditInfoFromv( v);
  if ( NULL == pcei)
    {
#ifndef CL_NO_IO
    ostringstream ss;
    ss << "SuggestValue for variable " << v << ", but var is not an edit variable" << ends;
    throw ExCLEditMisuse( ss.str() );
#else
    throw ExCLEditMisuse( v.Name() );
#endif
    }
  Variable clvEditPlus = pcei->_clvEditPlus;
  Variable clvEditMinus = pcei->_clvEditMinus;
  Number delta = x - pcei->_prevEditConstant;
  pcei->_prevEditConstant = x;
  DeltaEditConstant( delta,clvEditPlus,clvEditMinus);
  return *this;
}

// Re-solve the curent collection of constraints, given the new
// values for the edit variables that have already been
// suggested ( see SuggestValue() method)
// This is not guaranteed to work if you remove an edit constraint
// from the middle of the edit constraints you added
// ( e.g., edit A, edit B, edit C, remove B -> this will fail!)
// DEPRECATED
void 
SimplexSolver::Resolve( const vector<Number> & newEditConstants)
{
  EditInfoList::iterator it = _editInfoList.begin();
  unsigned i = 0;
  for (; i < newEditConstants.size() && it != _editInfoList.end(); ++it, ++i)
    {
    P_EditInfo pcei = (*it);
    SuggestValue( pcei->_clv,newEditConstants[i]);
    }
  Resolve();
}

SimplexSolver & SimplexSolver::Solve() {
#ifdef CL_SOLVER_CHECK_INTEGRITY
    AssertValid();
#endif
    if ( _fNeedsSolving) 
      {
      Optimize( _objective);
      SetExternalVariables();
#ifdef CL_TRACE_VERBOSE
      cout << "Manual solve actually solving." << endl;
#endif
      }
    return *this;
}
SimplexSolver & SimplexSolver::SetEditedValue( Variable v, double n) {
    if (!FContainsVariable( v))
      {
      Changev( v,n);
      return *this;
      }

    if (!Approx( n, v.Value())) 
      {
      AddEditVar( v);
      BeginEdit();
      SuggestValue( v,n);
      EndEdit();
      }
    return *this;
}

//// protected

// Add the constraint expr=0 to the inequality tableau using an
// artificial variable.  To do this, create an artificial variable
// av and Add av=expr to the inequality tableau, then make av be 0.
// ( Raise an exception if we can't attain av=0 -- and prepare explanation)
bool
SimplexSolver::AddWithArtificialVariable( P_LinearExpression expr,
                                           ExCLRequiredFailureWithExplanation & e)
{
#ifdef CL_TRACE
  Tracer TRACER( __FUNCTION__);
  cout << "(" << expr.ptr() << ")" << endl;
#endif
  
  // Allocate the objects on the heap because the objects
  // will remain in the tableau if we throw an exception,
  // and that will result in the destructor cleaning up
  // after us
  P_AbstractVariable pav = new SlackVariable(++_artificialCounter,"a");
  P_AbstractVariable paz = new ObjectiveVariable("az");
  P_LinearExpression pazRow = new LinearExpression( *expr); //copy
  // the artificial objective is av, which we know is equal to expr
  // ( which contains only parametric variables)

#ifdef CL_FIND_LEAK
  cout << "aC = " << _artificialCounter
       << "\nDeletes = " << _cArtificialVarsDeleted << endl;
#endif
#ifdef CL_TRACE
  cout << __FUNCTION__ << " before addRow-s:\n"
       << (*this) << endl;
#endif

  // the artificial objective is av, which we know is equal to expr
  // ( which contains only parametric variables)
  
  // objective is treated as a row in the tableau,
  // so do the substitution for its value ( we are minimizing
  // the artificial variable)
  // this row will be removed from the tableau after optimizing
  addRow(*paz,pazRow);
  
  // now Add the normal row to the tableau -- when artifical
  // variable is minimized to 0 ( if possible)
  // this row remains in the tableau to maintain the constraint
  // we are trying to Add
  addRow(*pav,expr);

#ifdef CL_TRACE
  cout << __FUNCTION__ << " after addRow-s:\n"
       << (*this) << endl;
#endif

  // try to Optimize az to 0
  // note we are * not* optimizing the real objective, but optimizing
  // the artificial objective to see if the error in the constraint
  // we are adding can be set to 0
  Optimize(*paz);

  // Careful, we want to get the Expression that is in
  // the tableau, not the one we initialized it with!
  P_LinearExpression pazTableauRow = RowExpression(*paz);
#ifdef CL_TRACE
  cout << "pazTableauRow->Constant() == " << pazTableauRow->Constant() << endl;
#endif

  // Check that we were able to make the objective value 0
  // If not, the original constraint was not satisfiable
  if (!Approx( pazTableauRow->Constant(),0.0))
    {
    BuildExplanation( e, paz.ptr(), pazTableauRow);
    // remove the artificial objective row that we just
    // added temporarily
        RemoveRow(*paz);
    // and the artificial objective variable that we also added above 
    // will die as well
    return false;
    }

  // see if av is a basic variable
  P_LinearExpression pe = RowExpression(*pav);
  if ( pe != NULL)
    {
    // FIXGJB: do we ever even get here?
    // Find another variable in this row and Pivot, so that av becomes parametric
    // If there isn't another variable in the row then 
    // the tableau contains the equation av = 0  -- just delete av's row
    if ( pe->IsConstant())
      {
      // FIXGJB: do we ever get here?
      assert( Approx( pe->Constant(),0.0));
          RemoveRow(*pav);
      // remove the temporary objective function
      // FIXGJB may need this too: delete RemoveRow(*paz);
#ifdef CL_FIND_LEAK
      ++_cArtificialVarsDeleted;
#endif
      return true;
      }
    Variable entryVar = pe->AnyPivotableVariable();
    if ( entryVar.IsNil())
      {
      BuildExplanation( e, * pav, pe);
      return false; /* required failure */
      }
    Pivot( entryVar, * pav);
    }
  // now av should be parametric
  assert( RowExpression(*pav) == NULL);
  RemoveColumn(*pav);
#ifdef CL_FIND_LEAK
  ++_cArtificialVarsDeleted;
#endif
  // remove the temporary objective function
      RemoveRow(*paz);
  return true;
}


// Using the given equation ( av = cle) build an explanation which
// implicates all constraints used to construct the equation. That
// is, everything for which the variables in the equation are markers.
void SimplexSolver::BuildExplanation( ExCLRequiredFailureWithExplanation & e,
                                       Variable av,
                                       P_LinearExpression pcle)
{
  VarToConstraintMap::iterator it_cn;
  it_cn = _constraintsMarked.find( av);
  if ( it_cn != _constraintsMarked.end()) 
    {
      e.AddConstraint((*it_cn).second);
    }
  
  assert( pcle != NULL);
  
  const VarToNumberMap & terms = pcle->Terms();
  VarToNumberMap::const_iterator it_term;
  for ( it_term = terms.begin(); it_term != terms.end(); it_term++)
    {
    it_cn = _constraintsMarked.find((*it_term).first);
    if ( it_cn != _constraintsMarked.end()) 
      {
      e.AddConstraint((*it_cn).second);
      }
    }
}



// We are trying to Add the constraint expr=0 to the appropriate
// tableau.  Try to Add expr directly to the tableaus without
// creating an artificial variable.  Return true if successful and
// false if not.
bool 
SimplexSolver::TryAddingDirectly( P_LinearExpression expr) 
{
#ifdef CL_TRACE
  Tracer TRACER( __FUNCTION__);
  cout << "(" << *expr << ")" << endl;
#endif
  Variable subject = ChooseSubject( expr);
  if ( subject.get_pclv() == NULL )
    {
#ifdef CL_TRACE
    cout << "- returning false" << endl;
#endif
    return false;
    }
  expr->NewSubject( subject);
  if ( ColumnsHasKey( subject))
    {
    SubstituteOut( subject,expr);
    }
  addRow( subject,expr);
#ifdef CL_TRACE
  cout << "- returning true" << endl;
#endif
  return true; // successfully added directly
}


// We are trying to Add the constraint expr=0 to the tableaux.  Try
// to choose a subject ( a variable to become basic) from among the
// current variables in expr.  If expr contains any unrestricted
// variables, then we must choose an unrestricted variable as the
// subject.  Also, if the subject is new to the solver we won't have
// to do any substitutions, so we prefer new variables to ones that
// are currently noted as parametric.  If expr contains only
// restricted variables, if there is a restricted variable with a
// negative coefficient that is new to the solver we can make that
// the subject.  Otherwise we can't find a subject, so return nil.
// ( In this last case we have to Add an artificial variable and use
// that variable as the subject -- this is done outside this method
// though.)
// 
// Note: in checking for variables that are new to the solver, we
// ignore whether a variable occurs in the objective function, since
// new slack variables are added to the objective function by
// 'NewExpression:', which is called before this method.
Variable
SimplexSolver::ChooseSubject( P_LinearExpression expr)
{
#ifdef CL_TRACE
  Tracer TRACER( __FUNCTION__);
  cout << "(" << *expr << ")" << endl;
#endif
  Variable subject( clvNil); // the current best subject, if any

  // true iff we have found a subject that is an unrestricted variable
  bool foundUnrestricted = false; 

  // true iff we have found a restricted variable that is new to the
  // solver ( except for being in the obj. function) and that has a
  // negative coefficient
  bool foundNewRestricted = false;

  const VarToNumberMap & terms = expr->Terms();
  VarToNumberMap::const_iterator it = terms.begin();
  for ( ; it != terms.end(); ++it )
    {
    Variable v = (*it).first;
    Number c = (*it).second;

    if ( foundUnrestricted)
      {
      // We have already found an unrestricted variable.  The only
      // time we will want to use v instead of the current choice
      // 'subject' is if v is unrestricted and new to the solver and
      // 'subject' isn't new.  If this is the case just pick v
      // immediately and return.
      if (!v.IsRestricted())
        {
        if (!ColumnsHasKey( v))
          return v;
        }
      }
    else
      { // we haven't found an restricted variable yet
      if ( v.IsRestricted())
        {
        // v is restricted.  If we have already found a suitable
        // restricted variable just stick with that.  Otherwise, if v
        // is new to the solver and has a negative coefficient pick
        // it.  Regarding being new to the solver -- if the variable
        // occurs only in the objective function we regard it as being
        // new to the solver, since error variables are added to the
        // objective function when we make the Expression.  We also
        // never pick a dummy variable here.
        if (!foundNewRestricted && !v.IsDummy() && c < 0.0)
          {
          const TableauColumnsMap & col = Columns();
          TableauColumnsMap::const_iterator it_col = col.find( v);
          if ( it_col == col.end() || 
              ( col.size() == 1 && ColumnsHasKey( _objective) ) )
            {
            subject = v;
            foundNewRestricted = true;
            }
          }
        }
      else
        {
        // v is unrestricted.  
        // If v is also new to the solver just pick it now
        subject = v;
        foundUnrestricted = true;
        }
      }
    }
  if (!subject.IsNil())
    return subject;

  // subject is nil. 
  // Make one last check -- if all of the variables in expr are dummy
  // variables, then we can pick a dummy variable as the subject
  Number coeff = 0;
  it = terms.begin();
  for ( ; it != terms.end(); ++it )
    {
    Variable v = (*it).first;
    Number c = (*it).second;
    if (!v.IsDummy())
      return clvNil; // nope, no luck
    // if v is new to the solver, tentatively make it the subject
    if (!ColumnsHasKey( v))
      {
      subject = v;
      coeff = c;
      }
    }

  // If we get this far, all of the variables in the Expression should
  // be dummy variables.  If the Constant is nonzero we are trying to
  // Add an unsatisfiable required constraint.  ( Remember that dummy
  // variables must take on a value of 0.)  Otherwise, if the Constant
  // is Zero, multiply by -1 if necessary to make the coefficient for
  // the subject negative."
  if (!Approx( expr->Constant(),0.0))
    {
#ifdef CL_DEBUG_FAILURES
    cout << "required failure in choose subject:\n"
         << *this << endl;
#endif
    if ( FIsExplaining()) 
      {
      ExCLRequiredFailureWithExplanation e;
      BuildExplanation( e, clvNil, expr);
      throw e;
      }
    else
      throw ExCLRequiredFailure();
    }
  if ( coeff > 0.0)
    {
    expr->MultiplyMe(-1);
    }
  return subject;
}
  
// Each of the non-required edits will be represented by an equation
// of the form
//    v = c + eplus - eminus 
// where v is the variable with the edit, c is the previous edit
// value, and eplus and eminus are slack variables that hold the
// error in satisfying the edit constraint.  We are about to change
// something, and we want to fix the constants in the equations
// representing the edit constraints.  If one of eplus and eminus is
// basic, the other must occur only in the Expression for that basic
// error variable.  ( They can't both be basic.)  Fix the Constant in
// this Expression.  Otherwise they are both nonbasic.  Find all of
// the expressions in which they occur, and fix the constants in
// those.  See the UIST paper for details.  
// ( This comment was for resetEditConstants(), but that is now
// gone since it was part of the screwey vector-based interface
// to resolveing. --02/15/99 gjb)
void 
SimplexSolver::DeltaEditConstant( Number delta,
                                   Variable plusErrorVar,
                                   Variable minusErrorVar)
{
#ifdef CL_TRACE
  Tracer TRACER( __FUNCTION__);
  cout << "(" << delta << ", " << plusErrorVar << ", " << minusErrorVar << ")" << endl;
#endif
  // first check if the plusErrorVar is basic
  P_LinearExpression pexprPlus = RowExpression( plusErrorVar);
  if ( pexprPlus != NULL )
    {
    pexprPlus->IncrementConstant( delta);
    // error variables are always restricted
    // so the row is infeasible if the Constant is negative
    if ( pexprPlus->Constant() < 0.0)
      {
      _infeasibleRows.insert( plusErrorVar);
      }
    return;
    }
  // check if minusErrorVar is basic
  P_LinearExpression pexprMinus = RowExpression( minusErrorVar);
  if ( pexprMinus != NULL)
    {
    pexprMinus->IncrementConstant(-delta);
    if ( pexprMinus->Constant() < 0.0)
      {
      _infeasibleRows.insert( minusErrorVar);
      }
    return;
    }
  // Neither is basic.  So they must both be nonbasic, and will both
  // occur in exactly the same expressions.  Find all the expressions
  // in which they occur by finding the column for the minusErrorVar
  // ( it doesn't matter whether we look for that one or for
  // plusErrorVar).  Fix the constants in these expressions.
  VarSet & columnVars = _columns[minusErrorVar];
  VarSet::iterator it = columnVars.begin();
  for (; it != columnVars.end(); ++it)
    {
    Variable basicVar = * it;
    P_LinearExpression pexpr = RowExpression( basicVar);
    assert( pexpr != NULL );
    double c = pexpr->CoefficientFor( minusErrorVar);
    pexpr->IncrementConstant( c*delta);
    if ( basicVar.IsRestricted() && pexpr->Constant() < 0.0)
      {
      _infeasibleRows.insert( basicVar);
      }
    }
}
  
// We have set new values for the constants in the edit constraints.
// Re-Optimize using the dual simplex algorithm.
void 
SimplexSolver::DualOptimize()
{
#ifdef CL_TRACE
  Tracer TRACER( __FUNCTION__);
  cout << "()" << endl;
#endif
  P_LinearExpression pzRow = RowExpression( _objective);
  // need to handle infeasible rows
  while (!_infeasibleRows.empty())
    {
    VarSet::iterator it_exitVar = _infeasibleRows.begin();
    Variable exitVar = * it_exitVar;
    _infeasibleRows.erase( it_exitVar);
    Variable entryVar;
    // exitVar might have become basic after some other pivoting
    // so allow for the case of its not being there any longer
    P_LinearExpression pexpr = RowExpression( exitVar);
    if ( pexpr != NULL )
      {
      // make sure the row is still not feasible
      if ( pexpr->Constant() < 0.0)
        {
        double ratio = DBL_MAX;
        double r;
        VarToNumberMap & terms = pexpr->Terms();
        VarToNumberMap::iterator it = terms.begin();
        for ( ; it != terms.end(); ++it )
          {
          Variable v = (*it).first;
          Number c = (*it).second;
          if ( c > 0.0 && v.IsPivotable())
            {
            Number zc = pzRow->CoefficientFor( v);
            r = zc/c; // FIXGJB r:= zc/c or Zero, as SymbolicWeight-s
            if ( r < ratio)
              {
              entryVar = v;
              ratio = r;
              }
            }
          }
        if ( ratio == DBL_MAX)
          {
		
          ostringstream ss;
          ss << "ratio == nil ( DBL_MAX)" << ends;
          throw ExCLInternalError( ss.str() );
          }
        Pivot( entryVar,exitVar);
        }
      }
    }
}

// Make a new linear Expression representing the constraint cn,
// replacing any basic variables with their defining expressions.
// Normalize if necessary so that the Constant is non-negative.  If
// the constraint is non-required give its error variables an
// appropriate weight in the objective function.
P_LinearExpression SimplexSolver::NewExpression( P_Constraint pcn,
                               /* output to */
                               Variable & clvEplus,
                               Variable & clvEminus,
                               Number & prevEConstant)
{
#ifdef CL_TRACE
  Tracer TRACER( __FUNCTION__);
  cout << "(" << * pcn << ")" << endl;
  cout << "cn.IsInequality() == " << pcn->IsInequality() << endl;
  cout << "cn.IsRequired() == " << pcn->IsRequired() << endl;
#endif
  LinearExpression cnExpr = pcn->Expression();
        
  P_LinearExpression pexpr( new LinearExpression( cnExpr.Constant()));
  P_AbstractVariable pslackVar;
  P_AbstractVariable pdummyVar;
  P_AbstractVariable peminus;
  P_AbstractVariable peplus;
  const VarToNumberMap & cnTerms = cnExpr.Terms();
  VarToNumberMap::const_iterator it = cnTerms.begin();
  for ( ; it != cnTerms.end(); ++it)
    {
    Variable v = (*it).first;
    Number c = (*it).second;
    P_LinearExpression pe = RowExpression( v);
    if ( pe == NULL)
      {
      pexpr->AddVariable( v,c);
      }
    else
      {
      pexpr->AddExpression(*pe,c);
      }
    }

  // Add slack and error variables as needed
  if ( pcn->IsInequality())
    {
    // cn is an inequality, so Add a slack variable.  The original
    // constraint is expr>=0, so that the resulting equality is
    // expr-slackVar=0.  If cn is also non-required Add a negative
    // error variable, giving
    //    expr-slackVar = -errorVar, in other words
    //    expr-slackVar+errorVar=0.
    // Since both of these variables are newly created we can just Add
    // them to the Expression ( they can't be basic).
    ++_slackCounter;
    pslackVar = new SlackVariable( _slackCounter, "s");
    pexpr->setVariable(*pslackVar,-1);
    // index the constraint under its slack variable and vice-versa
    _markerVars[pcn] = pslackVar;
    _constraintsMarked[pslackVar] = pcn;
    
    if (!pcn->IsRequired())
      {
      ++_slackCounter;
      peminus = new SlackVariable( _slackCounter, "em");
      pexpr->setVariable( peminus,1.0);
      // Add emnius to the objective function with the appropriate weight
      P_LinearExpression pzRow = RowExpression( _objective);
      // FIXGJB: pzRow->AddVariable( eminus,pcn->strength().symbolicWeight() * pcn->weight());
      SymbolicWeight sw = pcn->strength().symbolicWeight().Times( pcn->weight());
      pzRow->setVariable( peminus,sw.AsDouble());
      _errorVars[pcn].insert( peminus);
      NoteAddedVariable( peminus,_objective);
      }
    }
  else
    { // cn is an equality
    if ( pcn->IsRequired())
      {
      // Add a dummy variable to the Expression to serve as a marker
      // for this constraint.  The dummy variable is never allowed to
      // enter the basis when pivoting.
      ++_dummyCounter;
      pdummyVar = new DummyVariable( _dummyCounter, "d");
      pexpr->setVariable( pdummyVar,1.0);
      _markerVars[pcn] = pdummyVar;
      _constraintsMarked[pdummyVar] = pcn;
#ifdef CL_TRACE
      cout << "Adding dummyVar == d" << _dummyCounter << endl;
#endif
      }
    else
      {
      // cn is a non-required equality.  Add a positive and a negative
      // error variable, making the resulting constraint 
      //       expr = eplus - eminus, 
      // in other words:  expr-eplus+eminus=0
      ++_slackCounter;
      peplus  = new SlackVariable( _slackCounter, "ep");
      peminus = new SlackVariable( _slackCounter, "em");

      pexpr->setVariable( peplus,-1.0);
      pexpr->setVariable( peminus,1.0);
      // index the constraint under one of the error variables
      _markerVars[pcn] = peplus;
      _constraintsMarked[peplus] = pcn;

      P_LinearExpression pzRow = RowExpression( _objective);
      // FIXGJB: pzRow->AddVariable( eplus,pcn->strength().symbolicWeight() * pcn->weight());
      SymbolicWeight sw = pcn->strength().symbolicWeight().Times( pcn->weight());
      double swCoeff = sw.AsDouble();
#ifdef CL_TRACE
      if ( swCoeff == 0) 
                {
                cout << "sw == " << sw << endl
                         << "cn == " << * pcn << endl;
                cout << "adding " << * peplus << " and " << * peminus 
                         << " with swCoeff == " << swCoeff << endl;
                }
#endif      
      pzRow->setVariable( peplus,swCoeff);
      NoteAddedVariable( peplus,_objective);
      // FIXGJB: pzRow->AddVariable( eminus,pcn->strength().symbolicWeight() * pcn->weight());
      pzRow->setVariable( peminus,swCoeff);
      NoteAddedVariable( peminus,_objective);
      _errorVars[pcn].insert( peminus);
      _errorVars[pcn].insert( peplus);
      if ( pcn->isStayConstraint()) 
        {
        _stayPlusErrorVars.push_back( peplus);
        _stayMinusErrorVars.push_back( peminus);
        }
      else if ( pcn->IsEditConstraint())
        {
        clvEplus = peplus;
        clvEminus = peminus;
        prevEConstant = cnExpr.Constant();
        }
      }
    }

  // the Constant in the Expression should be non-negative.
  // If necessary normalize the Expression by multiplying by -1
  if ( pexpr->Constant() < 0)
    {
#ifdef CL_TRACE
    cout << "NewExpression's Constant is " << pexpr->Constant() << ", < 0, so flipping" << endl;
#endif
    pexpr->MultiplyMe(-1);
    }
#ifdef CL_TRACE
  cout << "- returning " << *pexpr << endl;
#endif
    return pexpr;
}

// Minimize the value of the objective.  ( The tableau should already
// be feasible.)
void 
SimplexSolver::Optimize( const Variable & zVar)
{
#ifdef CL_TRACE
  Tracer TRACER( __FUNCTION__);
  cout << "(" << zVar << ")\n"
       << *this << endl;
#endif
  P_LinearExpression pzRow = RowExpression( zVar);
  assert( pzRow != NULL);
  Variable entryVar = clvNil;
  Variable exitVar = clvNil;
  while ( true)
    {
    Number objectiveCoeff = 0;
    // Find the most negative coefficient in the objective function
    // ( ignoring the non-pivotable dummy variables).  If all
    // coefficients are positive we're done
    VarToNumberMap & terms = pzRow->Terms();
    VarToNumberMap::iterator it = terms.begin();
    for (; it != terms.end(); ++it)
      {
      Variable v = (*it).first;
      Number c = (*it).second;
      if ( v.IsPivotable() && c < objectiveCoeff)
        {
        objectiveCoeff = c;
        entryVar = v;
        // A. Beurive' Tue Jul 13 23:03:05 CEST 1999 Why the most
        // negative?  I encountered unending cycles of pivots!
        break;
        }
      }
    // if all coefficients were positive ( or if the objective
    // function has no pivotable variables)
    // we are at an optimum
    if ( objectiveCoeff >= -_epsilon)
      return;
#ifdef CL_TRACE
    cout << "entryVar == " << entryVar << ", "
         << "objectiveCoeff == " << objectiveCoeff
         << endl;
#endif

    // choose which variable to move out of the basis
    // Only consider pivotable basic variables
    // ( i.e. restricted, non-dummy variables)
    double minRatio = DBL_MAX;
    VarSet & columnVars = _columns[entryVar];
    VarSet::iterator it_rowvars = columnVars.begin();
    Number r = 0.0;
    for (; it_rowvars != columnVars.end(); ++it_rowvars)
      {
      Variable v = * it_rowvars;
#ifdef CL_TRACE
      cout << "Checking " << v << endl;
#endif
      if ( v.IsPivotable()) 
        {
        P_LinearExpression pexpr = RowExpression( v);
        Number coeff = pexpr->CoefficientFor( entryVar);
        // only consider negative coefficients
        if ( coeff < 0.0)
          {
          r = - pexpr->Constant() / coeff;
          if ( r < minRatio)
            {
#ifdef CL_TRACE
            cout << "New minRatio == " << r << endl;
#endif
            minRatio = r;
            exitVar = v;
            }
          }
        }
      }
    // If minRatio is still nil at this point, it means that the
    // objective function is unbounded, i.e. it can become
    // arbitrarily negative.  This should never happen in this
    // application.
    if ( minRatio == DBL_MAX)
      {
      ostringstream ss;
      ss << "objective function is unbounded!" << ends;
      throw ExCLInternalError( ss.str() );
      }
    Pivot( entryVar, exitVar);
#ifdef CL_TRACE
    cout << "After Optimize:\n"
         << *this << endl;
#endif
    }
}

// Do a Pivot.  Move entryVar into the basis ( i.e. make it a basic variable),
// and move exitVar out of the basis ( i.e., make it a parametric variable)
void 
SimplexSolver::Pivot( const Variable & entryVar, const Variable & exitVar)
{
#ifdef CL_TRACE
  Tracer TRACER( __FUNCTION__);
  cout << "(" << entryVar << ", " << exitVar << ")" << endl;
#endif

  // the entryVar might be non-pivotable if we're doing a RemoveConstraint --
  // otherwise it should be a pivotable variable -- enforced at call sites,
  // hopefully
  
  // expr is the Expression for the exit variable ( about to leave the basis) -- 
  // so that the old tableau includes the equation:
  //   exitVar = expr
  P_LinearExpression pexpr = RemoveRow( exitVar);

  // Compute an Expression for the entry variable.  Since expr has
  // been deleted from the tableau we can destructively modify it to
  // build this Expression.
  pexpr->ChangeSubject( exitVar,entryVar);
  SubstituteOut( entryVar,pexpr);

  if ( entryVar.IsExternal())
    {
    // entry var is no longer a parametric variable since we're moving
    // it into the basis
    _externalParametricVars.erase( entryVar);
    }
  addRow( entryVar,pexpr);
}



// Each of the non-required stays will be represented by an equation
// of the form
//     v = c + eplus - eminus
// where v is the variable with the stay, c is the previous value of
// v, and eplus and eminus are slack variables that hold the error
// in satisfying the stay constraint.  We are about to change
// something, and we want to fix the constants in the equations
// representing the stays.  If both eplus and eminus are nonbasic
// they have value 0 in the current solution, meaning the previous
// stay was exactly satisfied.  In this case nothing needs to be
// changed.  Otherwise one of them is basic, and the other must
// occur only in the Expression for that basic error variable.
// Reset the Constant in this Expression to 0.
void 
SimplexSolver::ResetStayConstants()
{
#ifdef CL_TRACE
  Tracer TRACER( __FUNCTION__);
  cout << "()" << endl;
#endif
  VarVector::const_iterator 
    itStayPlusErrorVars = _stayPlusErrorVars.begin();
  VarVector::const_iterator 
    itStayMinusErrorVars = _stayMinusErrorVars.begin();

  for ( ; itStayPlusErrorVars != _stayPlusErrorVars.end();
        ++itStayPlusErrorVars, ++itStayMinusErrorVars )
    {
    P_LinearExpression pexpr = RowExpression(*itStayPlusErrorVars);
    if ( pexpr == NULL )
      {
      pexpr = RowExpression(*itStayMinusErrorVars);
      }
    if ( pexpr != NULL)
      {
      pexpr->Set_constant( 0.0);
      }
    }
}

// Set the external variables known to this solver to their appropriate values.
// Set each external basic variable to its value, and set each
// external parametric variable to 0.  ( It isn't clear that we will
// ever have external parametric variables -- every external
// variable should either have a stay on it, or have an equation
// that defines it in terms of other external variables that do have
// stays.  For the moment I'll put this in though.)  Variables that
// are internal to the solver don't actually store values -- their
// values are just implicit in the tableu -- so we don't need to set
// them."
void 
SimplexSolver::SetExternalVariables()
{
#ifdef CL_TRACE
  Tracer TRACER( __FUNCTION__);
  cout << "()\n"
       << *this << endl;
#endif

  // FIXGJB -- oughta check some invariants here

  // Set external parametric variables first
  // in case I've screwed up
  VarSet::iterator itParVars = _externalParametricVars.begin();
  for ( ; itParVars != _externalParametricVars.end(); ++itParVars )
    {
    Variable v = * itParVars;
#ifndef NDEBUG
    // defensively skip it if it is basic -- ChangeValue is virtual
    // so don't want to call it twice;  this should never
    // happen
    if ( FIsBasicVar( v))
      {
#ifndef CL_NO_IO
      // WARNING
      cout << __FUNCTION__ << "Error: variable " << v 
           << " in _externalParametricVars is basic" << endl;
      cout << "Row is: " << * RowExpression( v) << endl;
#endif
      continue;
      }
#endif
    Changev( v,0.0);
    }

  // Only iterate over the rows w/ external variables
  VarSet::iterator itRowVars = _externalRows.begin();
  for ( ; itRowVars != _externalRows.end() ; ++itRowVars )
    {
    const Variable & v = *itRowVars;
    P_LinearExpression pexpr = RowExpression( v);
    Changev( v,pexpr->Constant());
    }

  _fNeedsSolving = false;
  if ( _pfnResolveCallback)
    _pfnResolveCallback( this);
}

#ifndef CL_NO_IO
ostream & 
PrintTo( ostream & xo, const VarVector & varlist)
{
  VarVector::const_iterator it = varlist.begin();
  xo << varlist.size() << ":" << "[ ";
  if ( it != varlist.end())
    {
    xo << * it;
    ++it;
    }
  for (; it != varlist.end(); ++it) 
    {
    xo << ", " << * it;
    }
  xo << " ]";
  return xo;
}

ostream & operator<<( ostream & xo, const VarVector & varlist)
{ return PrintTo( xo,varlist); }


ostream & 
PrintTo( ostream & xo, const ConstraintToVarSetMap & mapCnToVarSet)
{
  ConstraintToVarSetMap::const_iterator it = mapCnToVarSet.begin();
  for ( ; it != mapCnToVarSet.end(); ++it) {
    const Constraint * pcn = (*it).first;
    const VarSet & set = (*it).second;
    xo << "CN: " << pcn << * pcn << ":: " << set << endl;
  }
  return xo;
}

ostream & operator <<( ostream & xo, const ConstraintToVarSetMap & mapCnToVarSet)
{ return PrintTo( xo,mapCnToVarSet); }



ostream & 
SimplexSolver::PrintOn( ostream & xo) const
{
  super::PrintOn( xo);

  xo << "_stayPlusErrorVars: "
     << _stayPlusErrorVars << endl;
  xo << "_stayMinusErrorVars: "
     << _stayMinusErrorVars << endl;
  xo << "_editInfoList:\n"
     << _editInfoList << endl;
  return xo;
}


ostream & 
SimplexSolver::PrintInternalInfo( ostream & xo) const
{
  super::PrintInternalInfo( xo);
  xo << "; edvars: " << _editInfoList.size();
  xo << endl;
  printExternalVariablesTo( xo);
  return xo;
}

ostream & operator<<( ostream & xo, const SimplexSolver & clss)
{
  return clss.PrintOn( xo);
}

#endif

bool 
SimplexSolver::FIsConstraintSatisfied( P_Constraint pcn) const
{
  ConstraintToVarMap::const_iterator it_marker = _markerVars.find( pcn);
  if ( it_marker == _markerVars.end())
    { // could not find the constraint
    throw ExCLConstraintNotFound( pcn);
    }

#ifndef CL_NO_IO
  bool fCnsays = pcn->FIsSatisfied();
#endif

  ConstraintToVarSetMap::const_iterator it_eVars = _errorVars.find( pcn);

  if ( it_eVars != _errorVars.end())
    {
    const VarSet & eVars = (*it_eVars).second;
    VarSet::const_iterator it = eVars.begin();
    for ( ; it != eVars.end(); ++it )
      {
      P_LinearExpression pexpr = RowExpression(*it);
      if ( pexpr != NULL && !Approx( pexpr->Constant(),0.0))
        {
#ifndef CL_NO_IO
        if ( fCnsays)
          cout << __FUNCTION__ << ": constraint says satisfiable, but solver does not" << endl;
#endif
        return false;
        }
      }
    }

#ifndef CL_NO_IO
  if (!fCnsays)
    cout << __FUNCTION__ << ": solver says satisfiable, but constraint does not" << endl;
#endif
  return true;
}



#ifndef CL_NO_IO

ostream & PrintTo( ostream & xo, const SimplexSolver::EditInfoList & listPEditInfo)
{
  SimplexSolver::EditInfoList::const_iterator it = listPEditInfo.begin();
  for ( ; it != listPEditInfo.end(); ++it) {
    xo << *(*it) << endl;
  }
  return xo;
}
  

ostream & operator<<( ostream & xo, const SimplexSolver::EditInfoList & listPEditInfo)
{ return PrintTo( xo,listPEditInfo); }

#endif

// A. Beurive' Tue Jul  6 17:03:32 CEST 1999
void
SimplexSolver::ChangeStrengthAndWeight( P_Constraint pcn, const Strength & strength, double weight)
{
  ConstraintToVarSetMap::iterator it_eVars = _errorVars.find( pcn);
  // Only for constraints that already have error variables ( i.e. non-required constraints)
  assert( it_eVars != _errorVars.end());

  P_LinearExpression pzRow = RowExpression( _objective);

  Number old_coeff = pcn->weight() * pcn->strength().symbolicWeight().AsDouble();
  pcn->setStrength( strength);
  pcn->setWeight( weight);
  Number new_coeff = pcn->weight() * pcn->strength().symbolicWeight().AsDouble();

  if ( new_coeff != old_coeff)
    {
#ifdef CL_TRACE
      cout << "Changing strength and/or weight for constraint: " << endl << * pcn << endl;
      cout << "Updating objective row from:" << endl << * pzRow << endl;
#endif
      VarSet & eVars = (*it_eVars).second;
      VarSet::iterator it = eVars.begin();
      for ( ; it != eVars.end(); ++it )
        {
          P_LinearExpression pexpr = RowExpression(*it);
          if ( pexpr == NULL )
            {
              pzRow->AddVariable(*it,-old_coeff,_objective,*this);
              pzRow->AddVariable(*it,new_coeff,_objective,*this);
            }
          else
            {
              pzRow->AddExpression(*pexpr,-old_coeff,_objective,*this);
              pzRow->AddExpression(*pexpr,new_coeff,_objective,*this);
            }
        }
#ifdef CL_TRACE
      cout << "to: " << endl << * pzRow << endl;
#endif

      if ( _fAutosolve)
        {
          Optimize( _objective);
          SetExternalVariables();
        }
    }
}

// A. Beurive' Tue Jul  6 17:03:42 CEST 1999
void
SimplexSolver::ChangeStrength( P_Constraint pcn, const Strength & strength)
{
  ChangeStrengthAndWeight( pcn,strength,pcn->weight());
}

// A. Beurive' Tue Jul  6 17:03:42 CEST 1999
void
SimplexSolver::ChangeWeight( P_Constraint pcn, double weight)
{
  ChangeStrengthAndWeight( pcn,pcn->strength(),weight);
}
