/* $Id$
 * Cassowary Incremental Constraint Solver
 * Original Smalltalk Implementation by Alan Borning
 * This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
 * http://www.cs.washington.edu/homes/gjb
 * (C) 1998, 1999 Greg J. Badros and Alan Borning
 * See ../LICENSE for legal details regarding this software
 *
 * C.h
 * Top-level include file for C clients
 */

#ifndef _CLC_H__
#define _CLC_H__

#if defined(HAVE_CONFIG_H) && !defined(CONFIG_H_INCLUDED) && !defined(CONFIG_INLINE_H_INCLUDED)
#include "cassowary/config-inline.h"
#define CONFIG_INLINE_H_INCLUDED
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <limits.h>


#define boolean int

typedef double Number;

struct Variable;

typedef struct Variable *CL_Variable;

typedef CL_Variable CLV; /* synonym, for brevity */

struct Solver;
typedef struct Solver *CL_Solver;

struct SimplexSolver;
typedef struct SimplexSolver *CL_SimplexSolver;

struct Tableau;
typedef struct SimplexSolver *CL_Tableau; // SimplexSolver * on purpose

struct Constraint;
typedef struct Constraint *CL_Constraint;

#ifndef CLC_IMPL
struct StringToVarMap;
typedef struct StringToVarMap *CL_VarMap;


CL_VarMap CL_SetVarMap(CL_VarMap varmap_);

CL_VarMap CL_GetVarMap();

CL_VarMap CL_VarMapNew();

#endif

/* return true iff the variable did exist
   in the current global varmap, else return false */
boolean CL_VarMapDelete(const char *sz);

/* Must call this before any others */
void CL_Init();

/* Must call this when done */
void CL_Shutdown();

/* Return a new Variable with name and initial Value
   Also adds a stay for the newly-created variable in solver if
   solver is non null */
CLV CL_vNew(const char *szName, double Value, CL_SimplexSolver solver);

boolean CL_FCnOkayForSimplexSolver(CL_Constraint cn);

void CL_VariableSetPv(CLV var, void *pv);

void *CL_VariablePv(CLV var);

const char *CL_VariableName(CLV var);

#if defined(CL_HAVE_GTL) && defined(CL_BUILD_FD_SOLVER)
#ifndef FDN_EOL
#define FDN_EOL LONG_MIN
#endif
typedef long FDNumber;

struct FDSolver;
typedef struct FDSolver *CL_FDSolver;

/* Return a new FDSolver object */
CL_FDSolver CL_FDSolverNew();
/* return true iff cn can be added to the FD solver */
boolean CL_FDCanConvertCn(CL_Constraint cn);

CL_Constraint CL_FDCnFromCn(CL_Constraint cn);

/* Create a FD variable */
CLV CL_dvNew(const char *szName, ...);

boolean CL_vIsFD(const CLV clv);
#endif

/* Return a new SimplexSolver object */
CL_SimplexSolver CL_SimplexSolverNew();

/* Print the Variable out to the given FILE * */
void CL_vPrint(CLV clv, FILE *out);

/* Print the Solver object out to the given FILE * */
void CL_SolverPrint(CL_Solver solver, FILE *out);

void CL_ConstraintPrint(CL_Constraint pcn, FILE *out);

/* FIXGJB: do not use Variable -- use AbstractVariable, perhaps? */
typedef void (*PfnChangevCallback)(CLV clv, CL_Solver solver);

void CL_SolverSetChangevCallback(CL_Solver solver, PfnChangevCallback pfn);

void CL_SimplexSolverAddStrongStay(CL_SimplexSolver solver, CLV var, double weight);

void CL_SimplexSolverAddStay(CL_SimplexSolver solver, CLV var, double weight);

void CL_TableauPrintExternalVariables(CL_Tableau tableau, FILE *out);

/* Return a clvariable with the given name, or NULL if not found */
CLV CL_vLookup(const char *szName);

CLV CL_vLookupTrim(const char *szNameConst);


/* Return the Value of clv */
double CL_vValue(const CLV clv);

boolean CL_vIsNil(const CLV clv);

/* Return a new constraint from parsing the strings */
CL_Constraint CL_ParseConstraint(const char *szConstraintRule, const char *szConstraintStrength);

boolean CL_FIsSatisfied(CL_Constraint pcn);

/* Add a constraint to the solver */
int CL_AddConstraint(CL_Solver solver, CL_Constraint cn);

int CL_RemoveConstraint(CL_Solver solver, CL_Constraint cn);

void CL_Solve(CL_Solver solver);

void CL_Resolve(CL_Solver solver);

void CL_SimplexSolverSetEditedValue(CL_SimplexSolver solver, CLV var, double n);

#undef boolean

#ifdef __cplusplus
}
#endif


#endif
