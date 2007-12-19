%module csw

%include "std_string.i"     //gets exceptions.i
using namespace std;

%exception {
    try {
        $action;
    } catch( ExCLError & e) {
        PyErr_SetObject( PyExc_RuntimeError, explanation_list( &e ));
        return 0;
    }
}

%{
#include "cassowary/Variable.h"
#include "cassowary/SimplexSolver.h"
#include "cassowary/LinearEquation.h"
#include "cassowary/LinearInequality.h"
#include "cassowary/Errors.h"
#include "cassowary/EditConstraint.h"
#include "cassowary/StayConstraint.h"
#ifdef CL_BUILD_FD_SOLVER
#include "cassowary/FDBinaryOneWayConstraint.h"
#include "cassowary/FDSolver.h"
#endif

#include "explan.cpp"
#include <sstream>
%}

#ifdef TRACE_NEWDEL
%inline %{
extern int trace_newdel;
%}
#endif

#ifdef TRACE_MALLOC
%inline %{
extern int trace_malloc;
%}
#endif

#define REFCOUNT_DEF

%ignore incref;
%ignore decref;
%ignore ReverseInequality;
%ignore StrCnRelation;
%ignore PrintOn;
%ignore PrintTo;
%ignore PrintInternalInfo;
%ignore PrintOnVerbose;
%ignore SimplexSolver::SetResolveCallback;
%ignore SimplexSolver::SetCnSatCallback;
%ignore SimplexSolver::Resolve( const vector<Number> & );
%ignore SimplexSolver::Resolve( Number x, Number y);
%ignore SimplexSolver::AddLowerBound;
%ignore SimplexSolver::AddUpperBound;
%ignore SimplexSolver::AddBounds;
%ignore SimplexSolver::AddPointStay;
%ignore SimplexSolver::AddPointStays;

%ignore *::operator =;
%ignore RefCountPtr::RefCountPtr;
%ignore RefCountPtr::ptr;
%ignore RefCountPtr::__deref__;

%include "cassowary/my/refcntp.h"

%ignore Constraint;
%template( P_Constraint )   RefCountPtr<Constraint> ;
#define P_Constraint        RefCountPtr<Constraint> 
%ignore P_AbstractVariable;
%ignore AbstractVariable;
%ignore EditOrStayConstraint;
%ignore StayConstraint;

%include "cassowary/Cassowary.h"
%include "cassowary/Typedefs.h"

%ignore Variable::operator ->;
%ignore Variable::Variable( AbstractVariable *);
%ignore Variable::Variable( AbstractVariable &);
%ignore Variable::Variable( P_AbstractVariable);
%ignore Variable::get_pclv;
%ignore Variable::SetVarMap;
%ignore Variable::VarMap;
%ignore Variable::pmapStrPclv;
%ignore clvNil;
%ignore operator <;
%ignore operator <<;
%ignore operator >>;
%ignore operator +;
%ignore operator -;
%ignore operator *;
%ignore operator /;
%ignore operator ==;

%include "cassowary/Variable.h"

%include "cassowary/LinearExpression.h"
//%include "cassowary/LinearExpression_fwd.h"

#define GLE GenericLinearExpression<Number>
%template( LinearExpression )   GLE;
typedef GLE* P_LinearExpression ;


#define LinearExpression GLE
%include "cassowary/Strength.h"

%include "cassowary/Constraint.h"
%include "cassowary/Constraint_P.h"

%include "cassowary/Solver.h"
%ignore Tableau;
%include "cassowary/SimplexSolver.h"

#ifdef CL_BUILD_FD_SOLVER
%include "cassowary/FDBinaryOneWayConstraint.h"
%include "cassowary/FDSolver.h"
#endif

#define DEF__str__(x) string __str__() const { ostringstream ss; (x)->PrintOn(ss); ss << ends; return ss.str(); }

%extend GLE { //LinearExpression
    DEF__str__(self)

      //epxr+var is expr; expr+const is expr
    GLE operator+( Variable e2 ) const { return GLE( *self). Plus(e2); }
    GLE operator-( Variable e2 ) const { return GLE( *self). Minus(e2); }
    GLE operator*( Variable e2 ) const { return GLE( *self). Times(e2); }
    GLE operator/( Variable e2 ) const { return GLE( *self). Divide(e2); }
    GLE operator+( Number   e2 ) const { return GLE( *self). Plus(e2); }
    GLE operator-( Number   e2 ) const { return GLE( *self). Minus(e2); }
    GLE operator*( Number   e2 ) const { return GLE( *self). Times(e2); }
    GLE operator/( Number   e2 ) const { return GLE( *self). Divide(e2); }

    bool operator == (const GLE &e2) const {
        return (*self).Constant() == e2.Constant() && (*self).Terms() == e2.Terms(); }
    bool operator != (const GLE &e2) const {
        return (*self).Constant() != e2.Constant() || (*self).Terms() != e2.Terms(); }

    %pythoncode %{
        def __radd__(self,e2): return self.__add__(e2)
        def __rsub__(self,e2): return LinearExpression(e2).__sub__(self)
         #Expr(e2)-self dies : cant get __sub__ and loops forever for new-type class-object
         # and is slower anyway
        def __rmul__(self,e2): return self.__mul__(e2)
        def __rdiv__(self,e2): return LinearExpression(e2).__div__(self)
    %}

/*
  PyObject * getTerms() const {
    PyObject * m = PyList_New();
    GenericLinearExpression::VarToCoeffMap::const_iterator it = self->Terms().begin();
    while (it != self->Terms().end()) {
        PyObject *p = PyTuple_New(2);
        PyTuple_SetItem( p, 0, SWIG_NewPointerObj( (void *) &(*it).first,  SWIGTYPE_p_Variable, 1) );
        PyTuple_SetItem( p, 1, PyFloat_FromDouble( (*it).second) );
        PyList_Append( m, p);
        ++it;
    }
    return m;
  }
*/
};

%extend Strength {
    DEF__str__(self)
}
%extend RefCountPtr<Constraint> {   //P_Constraint
    DEF__str__(*self)
};


%extend Variable {
    DEF__str__(self)
    //var+var is expr; var+const is expr
    LinearExpression operator+( const LinearExpression & e2 ) const { return LinearExpression( *self). Plus(e2); }
    LinearExpression operator-( const LinearExpression & e2 ) const { return LinearExpression( *self). Minus(e2); }
    LinearExpression operator*( const LinearExpression & e2 ) const { return LinearExpression( *self). Times(e2); }
    LinearExpression operator/( const LinearExpression & e2 ) const { return LinearExpression( *self). Divide(e2); }
    LinearExpression operator+( Variable e2 ) const { return LinearExpression( *self). Plus(e2); }
    LinearExpression operator-( Variable e2 ) const { return LinearExpression( *self). Minus(e2); }
    LinearExpression operator*( Variable e2 ) const { return LinearExpression( *self). Times(e2); }
    LinearExpression operator/( Variable e2 ) const { return LinearExpression( *self). Divide(e2); }
    LinearExpression operator+( Number   e2 ) const { return LinearExpression( *self). Plus(e2); }
    LinearExpression operator-( Number   e2 ) const { return LinearExpression( *self). Minus(e2); }
    LinearExpression operator*( Number   e2 ) const { return LinearExpression( *self). Times(e2); }
    LinearExpression operator/( Number   e2 ) const { return LinearExpression( *self). Divide(e2); }
    bool operator==( Number e2 ) const { return self->Value() == e2; }
    bool operator!=( Number e2 ) const { return self->Value() != e2; }
    %pythoncode %{
        def __radd__(self,e2): return self.__add__(e2)
        def __rsub__(self,e2): return LinearExpression(e2).__sub__(self)
         #Expr(e2)-self dies : cant get __sub__ and loops forever for new-type class-object
         # and is slower anyway
        def __rmul__(self,e2): return self.__mul__(e2)
        def __rdiv__(self,e2): return LinearExpression(e2).__div__(self)
    %}
};



%rename( LinearEquation) newLinearEquation;
%rename( LinearInequality) newLinearInequality;
%rename( StayConstraint) newStayConstraint;
%inline %{
#define PQ1(what,x) P_Constraint   new##what( x a,                      \
        const Strength & strength = sRequired(), double weight = 1.0)   \
        { return new what( a,strength, weight); }
#define PQ2(what,x,y) P_Constraint    new##what( x a,y b,                \
        const Strength & strength = sRequired(), double weight = 1.0)   \
        { return new what( LinearExpression(a),(b),strength, weight); }
#define PQ3(what,x,y,z) P_Constraint   new##what( x a,y b, z c,         \
        const Strength & strength = sRequired(), double weight = 1.0)   \
        { return new what( LinearExpression(a),b,LinearExpression(c),strength, weight); }

#define PEQ1(x)     PQ1(LinearEquation,x)
#define PEQ2(x,y)   PQ2(LinearEquation,x,y)
#define PNE1(x)     PQ1(LinearInequality,x)
#define PNE2(x,y)   PQ3(LinearInequality,x, CnRelation, y)

    PEQ1( const LinearExpression & )
    PEQ2( const Variable & , const LinearExpression & )
    PEQ2( const LinearExpression & , const Variable & )
    PEQ2( const LinearExpression & , const LinearExpression & )

    //AMBIGUOUS in c++
    //var is expr; const is expr
    PEQ1( Number )
    PEQ1( const Variable & )
    PEQ2( Number , Number )                     //amb
    PEQ2( const Variable & , const Variable & ) //amb
    PEQ2( const Variable & , Number )
    PEQ2( const LinearExpression &, Number )    //amb
    PEQ2( Number , const Variable & )
    PEQ2( Number , const LinearExpression & )   //amb

#if 10
    PNE1( const LinearExpression & )
    PNE2( const LinearExpression &, const LinearExpression & )
    //AMBIGUOUS in c++
    PNE2( const LinearExpression &, const Variable & )
    PNE2( const Variable &, const LinearExpression & )
    PNE2( const Variable &, const Variable & )
    //var is expr; const is expr
    PNE1( const Variable & )
    PNE2( const Variable & , Number )
    PNE2( const LinearExpression &, Number )
    PNE2( Number , const Variable & )
    PNE2( Number , const LinearExpression & )
#endif

    PQ1( StayConstraint, const Variable &)

%}

#if 10
%extend SimplexSolver {
    DEF__str__(self)

/*
    SimplexSolver & AddLowerBound( Variable v, Variable lower) {
        return self->AddConstraint( new LinearInequality(LinearExpression(v - lower)) ); }
    SimplexSolver & AddUpperBound( Variable v, Variable upper) {
        return self->AddConstraint( new LinearInequality(LinearExpression(upper - v)) ); }
    SimplexSolver & AddBounds( Variable v, Variable lower, Variable upper) {
        self->AddConstraint( new LinearInequality(LinearExpression(v - lower)) );
        return self->AddConstraint( new LinearInequality(LinearExpression(upper - v)) ); }
    SimplexSolver & AddBounds( Variable v, Number   lower, Variable upper) {
        self->AddLowerBound(v,lower);
        return self->AddConstraint( new LinearInequality(LinearExpression(upper - v)) ); }
    SimplexSolver & AddBounds( Variable v, Variable lower, Number   upper) {
        self->AddConstraint( new LinearInequality(LinearExpression(v - lower)) );
        return self->AddUpperBound(v,upper); }
*/

};
#endif

#if 0
%extend Constraint {
    bool operator==( Constraint * c ) const { return self == c; }
};
#endif

