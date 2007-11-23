// $Id: Tests.cc,v 1.1 2003/08/21 15:34:29 SVILEN Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
// 
// Tests.cc

#include "Cl.h"
#include <stdlib.h>
#include "timer.h"
#include <iostream>
//#include <iomanip>

inline 
double UniformRandom()
{ return double(rand())/RAND_MAX; }

bool
simple1()
{
 try
   {
   bool fOkResult = true;
   Variable x(167);
   Variable y(2);
   SimplexSolver solver;
    solver.PrintOn( cout);
   P_Constraint eq = new LinearEquation(x,y+0.0);
   solver.AddStay(x);
   solver.AddStay(y);
   solver.AddConstraint(eq);
   cout << "x = " << x.Value() << endl
        << "y = " << y.Value() << endl
        << *eq << endl;
   fOkResult = (x.Value() == y.Value());
   return fOkResult;
   } 
 catch (ExCLError &error) 
   {
   cerr << "Exception! " << error.description() << endl;
   return(false);
   } 
 catch (...) 
   {
   cerr << "Unknown exception" << endl;
   return(false);
   }
}


/* Add an edit variable to an empty solver */
bool
simple2()
{
 try
   {
   Variable x(167);
   SimplexSolver solver;

   solver.AddEditVar(x);
   solver.BeginEdit();
   solver.SuggestValue(x,100);
   solver.EndEdit();

   cout << "x = " << x.Value() << endl;
   } 
 catch (ExCLEditMisuse &error)
   {
   cout << "Success: got the exception" << endl;
   return true;
   }
 catch (ExCLError &error) 
   {
   cerr << "Exception! " << error.description() << endl;
   return(false);
   } 
 catch (...) 
   {
   cerr << "Unknown exception" << endl;
   return(false);
   }
 cerr << "Should have gotten an exception!" << endl;
 return false;
}


bool
justStay1()
{
 try
   {
   bool fOkResult = true;
   Variable x(5);
   Variable y(10);
   SimplexSolver solver;

#if 0
   solver.AddPointStay(x,y,1);
#else
   solver.AddStay(x);
   solver.AddStay(y);
#endif
   fOkResult = fOkResult && Approx(x,5);
   fOkResult = fOkResult && Approx(y,10);
   cout << "x == " << x.Value() << endl;
   cout << "y == " << y.Value() << endl;

   return(fOkResult);
   } 
 catch (ExCLError &error) 
   {
   cerr << "Exception! " << error.description() << endl;
   return(false);
   } 
 catch (...) 
   {
   cerr << "Unknown exception" << endl;
   return(false);
   }
}



bool
addDelete1()
{
 try 
   {
   bool fOkResult = true; 
   Variable x("x");
   SimplexSolver solver;

   solver.AddConstraint(new LinearEquation( x, 100, sWeak() ));
    
   P_Constraint c10 = new LinearInequality( x,cnLEQ,10.0);
   P_Constraint c20 = new LinearInequality( x,cnLEQ,20.0);
   solver
     .AddConstraint(c10)
     .AddConstraint(c20);

   fOkResult = fOkResult && Approx(x,10.0);
   cout << "x == " << x.Value() << endl;

   cout << endl << solver << endl;

   solver.RemoveConstraint(c10);

   cout << endl << solver << endl;

   fOkResult = fOkResult && Approx(x,20.0);
   cout << "x == " << x.Value() << endl;

   solver.RemoveConstraint(c20);
   fOkResult = fOkResult && Approx(x,100.0);
   cout << "x == " << x.Value() << endl;

   P_Constraint c10again = new LinearInequality( x,cnLEQ,10.0);

   solver
     .AddConstraint(c10)
     .AddConstraint(c10again);

   fOkResult = fOkResult && Approx(x,10.0);
   cout << "x == " << x.Value() << endl;
    
   solver.RemoveConstraint(c10);
   fOkResult = fOkResult && Approx(x,10.0);
   cout << "x == " << x.Value() << endl;

   solver.RemoveConstraint(c10again);
   fOkResult = fOkResult && Approx(x,100.0);
   cout << "x == " << x.Value() << endl;

   return(fOkResult);
   } 
 catch (ExCLError &error) 
   {
   cerr << "Exception! " << error.description() << endl;
   return(false);
   } 
 catch (...) 
   {
   cerr << "Unknown exception" << endl;
   return(false);
   }
}

bool
addDelete2()
{
 try 
   {
   bool fOkResult = true; 
   Variable x("x");
   Variable y("y");
   SimplexSolver solver;

   solver
     .AddConstraint(new LinearEquation(x, 100.0, sWeak()))
     .AddConstraint(new LinearEquation(y, 120.0, sStrong()));

   P_Constraint c10 = new LinearInequality( x,cnLEQ,10.0);
   P_Constraint c20 = new LinearInequality( x,cnLEQ,20.0);

   solver
     .AddConstraint(c10)
     .AddConstraint(c20);
   fOkResult = fOkResult && Approx(x,10.0) && Approx(y,120.0);
   cout << "x == " << x.Value() << ", y == " << y.Value() << endl;

   solver.RemoveConstraint(c10);
   fOkResult = fOkResult && Approx(x,20.0) && Approx(y,120.0);
   cout << "x == " << x.Value() << ", y == " << y.Value() << endl;
   
   P_Constraint cxy = new LinearEquation( 2*x, y);
   solver.AddConstraint(cxy);
   fOkResult = fOkResult && Approx(x,20.0) && Approx(y,40.0);
   cout << "x == " << x.Value() << ", y == " << y.Value() << endl;

   solver.RemoveConstraint(c20);
   fOkResult = fOkResult && Approx(x,60.0) && Approx(y,120.0);
   cout << "x == " << x.Value() << ", y == " << y.Value() << endl;

   solver.RemoveConstraint(cxy);
   fOkResult = fOkResult && Approx(x,100.0) && Approx(y,120.0);
   cout << "x == " << x.Value() << ", y == " << y.Value() << endl;


   return(fOkResult);
   } 
 catch (ExCLError &error) 
   {
   cerr << "Exception! " << error.description() << endl;
   return(false);
   }
 catch (...) 
   {
   cerr << "Unknown exception" << endl;
   return(false);
   }
}

bool
casso1()
{
 try 
   {
   bool fOkResult = true; 
   Variable x("x");
   Variable y("y");
   SimplexSolver solver;

   solver
     .AddConstraint(new LinearInequality(x,cnLEQ,y))
     .AddConstraint(new LinearEquation(y, x+3.0))
     .AddConstraint(new LinearEquation(x,10.0,sWeak()))
     .AddConstraint(new LinearEquation(y,10.0,sWeak()))
     ;
   
   fOkResult = fOkResult && 
     ( Approx(x,10.0) && Approx(y,13.0) ||
       Approx(x,7.0) && Approx(y,10.0) );
     
   cout << "x == " << x.Value() << ", y == " << y.Value() << endl;

   return(fOkResult);
   } 
 catch (ExCLError &error) 
   {
   cerr << "Exception! " << error.description() << endl;
   return(false);
   }
 catch (...) 
   {
   cerr << "Unknown exception" << endl;
   return(false);
   }
}

bool
inconsistent1()
{
  SimplexSolver solver;
  Variable x("x");
  P_Constraint eq1 = new LinearEquation(x,10.0);
  P_Constraint eq2 = new LinearEquation(x,5.0);
  try 
    {
    
    solver.AddConstraint( eq1 );
    solver.AddConstraint( eq2 );
    
    // no exception, we failed!
    return(false);
    } 
  catch (ExCLRequiredFailure)
    {
    // we want this exception to get thrown
    cout << "Success -- got the exception" << endl;
    // solver.RemoveConstraint(eq2); this would throw a constraint not found exception
    //    cout << solver << endl;
    return(true);
    }
  catch (ExCLError &error) 
    {
    cerr << "Exception! " << error.description() << endl;
    return(false);
    }
  catch (...) 
    {
    cerr << "Unknown exception" << endl;
    return(false);
    }
}

bool
inconsistent2()
{
 try 
   {
   Variable x("x");
   SimplexSolver solver;

   solver
     .AddConstraint(new LinearInequality(x,cnGEQ,10.0))
     .AddConstraint(new LinearInequality(x,cnLEQ, 5.0));

   // no exception, we failed!
   return(false);
   } 
 catch (ExCLRequiredFailure &)
   {
   // we want this exception to get thrown
   cout << "Success -- got the exception" << endl;
   //    cout << solver << endl;
   return(true);
   }
 catch (ExCLError &error) 
   {
   cerr << "Exception! " << error.description() << endl;
   return(false);
   }
 catch (...) 
   {
   cerr << "Unknown exception" << endl;
   return(false);
   }
}

bool
inconsistent3()
{
 try 
   {
   Variable w("w");
   Variable x("x");
   Variable y("y");
   Variable z("z");
   SimplexSolver solver;

   solver
     .AddConstraint(new LinearInequality(w,cnGEQ,10.0))
     .AddConstraint(new LinearInequality(x,cnGEQ,w))
     .AddConstraint(new LinearInequality(y,cnGEQ,x))
     .AddConstraint(new LinearInequality(z,cnGEQ,y))
     .AddConstraint(new LinearInequality(z,cnLEQ,4.0));

   // no exception, we failed!
   return(false);
   } 
 catch (ExCLRequiredFailure &)
   {
   // we want this exception to get thrown
   cout << "Success -- got the exception" << endl;
   //    cout << solver << endl;
   return(true);
   }
 catch (ExCLError &error) 
   {
   cerr << "Exception! " << error.description() << endl;
   return(false);
   }
 catch (...) 
   {
   cerr << "Unknown exception" << endl;
   return(false);
   }
}


bool
multiedit()
{
 try
   {
   bool fOkResult = true;

   Variable x("x",0);
   Variable y("y",0);
   Variable w("w",0);
   Variable h("h",0);
   SimplexSolver solver;

   solver
     .AddStay(x)
     .AddStay(y)
     .AddStay(w)
     .AddStay(h);

   solver
     .AddEditVar(x)
     .AddEditVar(y)
     .BeginEdit();

   solver
     .SuggestValue(x,10)
     .SuggestValue(y,20)
     .Resolve();

   cout << "x = " << x.Value() << "; y = " << y.Value() << endl
        << "w = " << w.Value() << "; h = " << h.Value() << endl;

   fOkResult = fOkResult &&
     Approx(x,10) && Approx(y,20) && Approx(w,0) && Approx(h,0);

   solver
     .AddEditVar(w)
     .AddEditVar(h)
     .BeginEdit();

   solver
     .SuggestValue(w,30)
     .SuggestValue(h,40)
     .EndEdit();

   cout << "x = " << x.Value() << "; y = " << y.Value() << endl
        << "w = " << w.Value() << "; h = " << h.Value() << endl;

   fOkResult = fOkResult &&
     Approx(x,10) && Approx(y,20) && Approx(w,30) && Approx(h,40);

   solver
     .SuggestValue(x,50)
     .SuggestValue(y,60)
     .EndEdit();

   cout << "x = " << x.Value() << "; y = " << y.Value() << endl
        << "w = " << w.Value() << "; h = " << h.Value() << endl;

   fOkResult = fOkResult &&
     Approx(x,50) && Approx(y,60) && Approx(w,30) && Approx(h,40);

   return fOkResult;
   } 
 catch (ExCLError &error) 
   {
   cerr << "Exception! " << error.description() << endl;
   return(false);
   } 
 catch (...) 
   {
   cerr << "Unknown exception" << endl;
   return(false);
   }
 cerr << "Should have gotten an exception!" << endl;
 return false;
}


bool
multiedit2()
{
 try
   {
   bool fOkResult = true;

   Variable x("x",0);
   Variable y("y",0);
   Variable w("w",0);
   Variable h("h",0);
   SimplexSolver solver;

   solver
     .AddStay(x)
     .AddStay(y)
     .AddStay(w)
     .AddStay(h);

   solver
     .AddEditVar(x)
     .AddEditVar(y)
     .BeginEdit();

   solver
     .SuggestValue(x,10)
     .SuggestValue(y,20)
     .Resolve();

   cout << "x = " << x.Value() << "; y = " << y.Value() << endl
        << "w = " << w.Value() << "; h = " << h.Value() << endl;

   fOkResult = fOkResult &&
     Approx(x,10) && Approx(y,20) && Approx(w,0) && Approx(h,0);

   solver
     .AddEditVar(x)
     .AddEditVar(y)
     .AddEditVar(w)
     .AddEditVar(h)
     .BeginEdit();

   solver
     .SuggestValue(w,30)
     .SuggestValue(h,40)
     .EndEdit();

   cout << "x = " << x.Value() << "; y = " << y.Value() << endl
        << "w = " << w.Value() << "; h = " << h.Value() << endl;

   fOkResult = fOkResult &&
     Approx(x,10) && Approx(y,20) && Approx(w,30) && Approx(h,40);

   solver
     .SuggestValue(x,50)
     .SuggestValue(y,60)
     .EndEdit();

   cout << "x = " << x.Value() << "; y = " << y.Value() << endl
        << "w = " << w.Value() << "; h = " << h.Value() << endl;

   fOkResult = fOkResult &&
     Approx(x,50) && Approx(y,60) && Approx(w,30) && Approx(h,40);

   return fOkResult;
   } 
 catch (ExCLError &error) 
   {
   cerr << "Exception! " << error.description() << endl;
   return(false);
   } 
 catch (...) 
   {
   cerr << "Unknown exception" << endl;
   return(false);
   }
 cerr << "Should have gotten an exception!" << endl;
 return false;
}


// From a bug report from Steve Wolfman on his
// SAT project using "blackbox"
bool
blackboxsat()
{
  try
    {
    SimplexSolver solver;

    Variable r1("r1");
    Variable r2("r2");
    Variable r3("r3");
    Variable r4("r4");
    Variable r5("r5");
    Variable r6("r6");
    Variable r7("r7");
    Variable r8("r8");

    P_Constraint rgpcn[30];
    //for (int i=0; i<int(sizeof(rgpcn)/sizeof(rgpcn[0])); ++i) rgpcn[i] = NULL;

    rgpcn[1] = new LinearEquation(r1,60);
    rgpcn[2] = new LinearEquation(r2,30);
    rgpcn[12] = new LinearEquation(r3,2.5);
    rgpcn[13] = new LinearEquation(r6,0);
    rgpcn[14] = new LinearInequality(r5, cnGEQ, 0);
    rgpcn[15] = new LinearInequality(r8, cnLEQ, 2.5);
    rgpcn[16] = new LinearInequality(r7, cnGEQ, r6);
    rgpcn[17] = new LinearInequality(r8, cnGEQ, r7);
    rgpcn[18] = new LinearEquation(r4, r3 - r2/60.0);
    rgpcn[19] = new LinearEquation(r5, r4 - r1/60.0);
    rgpcn[20] = new LinearInequality(r4, cnGEQ, 0);
    rgpcn[21] = new LinearInequality(r5, cnGEQ, 0);
    rgpcn[22] = new LinearEquation(r7, r6 + r2/20.0);
    rgpcn[23] = new LinearEquation(r8, r7 + r1/20.0);
    rgpcn[24] = new LinearEquation(r4, r3 - r2/30.0);
    rgpcn[25] = new LinearEquation(r5, r4 - r1/30.0);
    rgpcn[26] = new LinearInequality(r4, cnGEQ, 0);
    rgpcn[27] = new LinearInequality(r5, cnGEQ, 0);
    rgpcn[28] = new LinearEquation(r7, r6 + r2/60.0);
    rgpcn[29] = new LinearEquation(r8, r7 + r1/60.0);

    while (true)
      {
      char szCmd[1000];
      int i;
      cin >> szCmd;
      if (!cin)
        break;
      if (szCmd[0] == '#')
        { 
        cin.getline(szCmd,900);
        continue;
        }
      if (strcasecmp(szCmd,"Add") == 0)
        {
        cin >> i;
        cout << "eq" << i << ": " << solver.AddConstraintNoException(rgpcn[i])
             << "\t" << *(rgpcn[i]) << endl;
        cout << r1 << " = " << r1.Value() << endl;
        }
      else if (strcasecmp(szCmd,"del") == 0)
        {
        cin >> i;
        cout << "REMeq" << i << ": " << solver.RemoveConstraintNoException(rgpcn[i])
             << "\t" << *(rgpcn[i]) << endl;
        cout << r1 << " = " << r1.Value() << endl;
        }
      else if (strcasecmp(szCmd,"dump") == 0)
        {
        cout << solver << endl;
        }
      else if (strcasecmp(szCmd,"val") == 0)
        {
        cout << r1 << " = " << r1.Value() << endl;
        }
      else if (strcasecmp(szCmd,"solve") == 0)
        {
        cout << solver.Solve() << endl;
        }
      else if (strcasecmp(szCmd,"autosolve") == 0)
        {
        solver.SetAutosolve(true);
        }
      else if (strcasecmp(szCmd,"noautosolve") == 0)
        {
        solver.SetAutosolve(true);
        }
      }

    cout << r1 << " = " << r1.Value() << endl
         << r2 << " = " << r2.Value() << endl
         << r3 << " = " << r3.Value() << endl
         << r4 << " = " << r4.Value() << endl
         << r5 << " = " << r5.Value() << endl
         << r6 << " = " << r6.Value() << endl
         << r7 << " = " << r7.Value() << endl
         << r8 << " = " << r8.Value() << endl;

    return false;
    }
  catch (ExCLError &error)
    {
   cerr << "Exception! " << error.description() << endl;
   return(true);
   }
 catch (...) 
   {
   cerr << "Unknown exception" << endl;
   return(false);
   }
}

#include "my/thingref.h"

bool addDel( int nCns = 900, int nVars = 900, int nResolves = 10000)
{
  Timer timer;
  // FIXGJB: from where did .12 come?
  static const double ineqProb = 0.12;
  static const int maxVars = 3;
	if (nVars < maxVars) nVars = maxVars;
  cout << "starting timing test. nCns = " << nCns
       << ", nVars = " << nVars << ", nResolves = " << nResolves << endl;

  timer.Start();
  SimplexSolver solver;
  solver.SetAutosolve(false);

  ThingArrayReference<Variable > rgpclv ( new Variable[nVars] );
  for (int i = 0; i < nVars; i++)
    {
    rgpclv[i] = Variable(i,"x");
    solver.AddStay(rgpclv[i]);
    }

  ThingArrayReference<P_Constraint> rgpcns( nCns>0 ? new P_Constraint[nCns] : 0);
  int nvs = 0;
  int k;
  int j;
  double coeff;
  for (j = 0; j < nCns; j++)
    {
    // number of variables in this constraint
    nvs = int(UniformRandom()*maxVars) + 1;
    LinearExpression expr = UniformRandom()*20.0 - 10.0;
    for (k = 0; k < nvs; k++)
       {
       coeff = UniformRandom()*10 - 5;
       expr.AddExpression((rgpclv[int(UniformRandom()*nVars)]) * coeff);
       }
    if (UniformRandom() < ineqProb)
       {
       rgpcns[j] = new LinearInequality(expr);
       }
    else
       {  
       rgpcns[j] = new LinearEquation(expr);
       }
#ifdef CL_SHOW_CNS_IN_BENCHMARK
    cout << "Cn[" << j << "]: " << *rgpcns[j] << endl;
#endif
    }

  cout << "done building data structures" << endl;
  cout << "time = " << timer.ElapsedTime() << endl;
  timer.Start();
  int cExceptions = 0;
#ifdef CL_SHOW_CNS_IN_BENCHMARK
  cout << "Exceptions on: ";
#endif
  for (j = 0; j < nCns; j++)
    {
    // Add the constraint -- if it's incompatible, just ignore it
    try
      {
      solver.AddConstraint(rgpcns[j]);
      }
    catch (ExCLRequiredFailure &)
      {
		cout << "failed "<< rgpcns[j].ptr() << endl;
      cExceptions++;
      rgpcns[j] = 0;
#ifdef CL_SHOW_CNS_IN_BENCHMARK
      cout << j << " ";
#endif
      }
    }
#ifdef CL_SHOW_CNS_IN_BENCHMARK
  cout << "\n" << endl;
#endif
  solver.Solve();
  cout << "done adding constraints [" << cExceptions << " exceptions]" << endl;
  cout << "time = " << timer.ElapsedTime() << endl;
  cout << "time per cn = " << timer.ElapsedTime()/nCns << endl;
  cout << "time per actual cn = " << timer.ElapsedTime()/(nCns - cExceptions) <<endl;
  timer.Start();

  int e1Index = int(UniformRandom()*nVars);
  int e2Index = int(UniformRandom()*nVars);

  Variable e1 = rgpclv[e1Index];
  Variable e2 = rgpclv[e2Index];

  solver
	.AddEditVar(e1)
	.AddEditVar(e2);

  cout << "done creating edit constraints -- about to start resolves" << endl;
  cout << "time = " << timer.ElapsedTime() << endl;
  timer.Start();

  solver.BeginEdit();
  // FIXGJB start = Timer.now();
  for (int m = 0; m < nResolves; ++m)
    {
//  		cout << "..resolve #"<< m << endl;
    	solver
			.SuggestValue(e1,e1->Value()*1.001)
    		.SuggestValue(e2,e2->Value()*1.001)
      		.Resolve();
    }
  cout << "..EndEdit" << endl;
  solver.EndEdit();
  // cout << "run time: " <<

  cout << "..done resolves -- now removing constraints" << endl;
  cout << "time = " << timer.ElapsedTime() <<endl;
  cout << "time per Resolve = " << timer.ElapsedTime()/nResolves <<endl; 
  timer.Start();

  for (j = 0; j < nCns; j++)
    if (rgpcns[j])
      solver.RemoveConstraint(rgpcns[j]);

  // FIXGJB end = Timer.now();
  // cout << "Total remove time: " 
  //      << "remove time per cn"
  cout << "done removing constraints and addDel timing test" << endl;
  cout << "time = " << timer.ElapsedTime() << endl;
  cout << "time per cn = " << timer.ElapsedTime()/nCns <<endl;
  cout << "time per actual cn = " << timer.ElapsedTime()/(nCns - cExceptions) <<endl;

  for (j = 0; j < nCns; j++) {
        rgpcns[j] = 0;
//        cerr << rgpcns[j].ptr();
  }

	Variable vvv("a1");
  for (j = 0; j < nVars; j++) {
//        cerr << "kill?" << rgpclv[j] << rgpclv[j].get_pclv() <<endl;
        rgpclv[j] = vvv;
//        cerr << rgpclv[j] << rgpclv[j].get_pclv() <<endl;
  }

  //cerr << solver;
    
  return true;
}

#include "DummyVariable.h"
#include "SlackVariable.h"

int
main( int argc, char **argv )
{
  try 
    {
    bool fAllOkResult = true;
    bool fResult;
    
    // seed the random number generator for reproducible results
    srand(123456789);

    cout << "Cassowary version: " << szCassowaryVersion << endl;

#define RUN_TEST(x) \
    cout << #x << ":" << endl; \
    fResult = x(); fAllOkResult &= fResult; \
    if (!fResult) cout << "Failed!" << endl;
#if 1
    RUN_TEST(simple1);
    RUN_TEST(simple2);
    RUN_TEST(justStay1);
    RUN_TEST(addDelete1);
    RUN_TEST(addDelete2);
    RUN_TEST(casso1);
    RUN_TEST(inconsistent1);
    RUN_TEST(inconsistent2);
    RUN_TEST(inconsistent3);
    RUN_TEST(multiedit);
    RUN_TEST(multiedit2);
    // RUN_TEST(blackboxsat);
#endif
    int cns = 90, vars = 90, resolves = 100;

    if (argc > 1)
      cns = atoi(argv[1]);

    if (argc > 2)
      vars = atoi(argv[2]);

    if (argc > 3)
      resolves = atoi(argv[3]);

    if (cns > 0) 
      {
      cout << "addDel" << ":" << endl;
      fResult = addDel(cns,vars,resolves); fAllOkResult &= fResult;
      if (!fResult) cout << "Failed!" << endl;
      }
      
#undef RUN_TEST

#ifdef CL_FIND_LEAK
    cout << "AbstractVariables: " << AbstractVariable::cAbstractVariables
         << "\nDummyVariables: " << DummyVariable::cDummyVariables
         << "\nSlackVariables: " << SlackVariable::cSlackVariables
         << endl;
#endif

    
    return (fAllOkResult? 0 : 255);
    
    } 

  catch (ExCLError &error)
    {
   cerr << "Exception! " << error.description() << endl;
	throw;
   }
  catch (...) 
    {
    cerr << "exception!" << endl;
    }
}
