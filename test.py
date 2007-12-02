#$Id$
import csw as c
if 0:
    print c.cvar.trace_newdel
    c.cvar.trace_newdel = 0

def test_expression():
    print "..var"
    x = c.Variable("x",7)
    y = c.Variable("y",8)
    print "x:", x.Value(), x
    print "y:", y.Value(), y

    print "..expr"
    l0 = c.LinearExpression(0)
    l1 = c.LinearExpression(x)
    print l0 +1
    print l1 /2
    print l1+y
    print (l1+2)/3
    print l0+y+1.5
    print y+3
    l2 = l1+(y+1)/2
    print l2

#def z():
#    print l2.getTerms()

    print "..strength"
    s= c.sWeak()
    print s
    s= c.sStrong()
    print s
    s = c.Strength('boza', 1,1,1)
    print s

    if 10:
        print "..equation"
        leq = c.LinearEquation( x,23 )
        print '1',leq.this
    #    print '1',leq.this.Expression()
        print '1',leq.Expression()
        print '1',leq, "\n-----"
    if 10:
        leq = c.LinearEquation( l2,100 )
        print '2',leq.this
        print '2',leq
        leq = c.LinearEquation( l2, 100, c.sWeak() )
        print '3',leq.this
        print '3',leq
        leq = c.LinearEquation( x, 100, c.sWeak() )
        print '4',leq.this
        print '4',leq
        leq = c.LinearEquation( x, y, c.sWeak() )
        print leq

    if 10:
        print "..inequation"
        leq = c.LinearInequality( l2 )
        print leq
        leq = c.LinearInequality( l2,c.cnLEQ,100 )
        print leq
        leq = c.LinearInequality( l2,c.cnLEQ,x )
        print leq
        leq = c.LinearInequality( x, c.cnGEQ, y, c.sStrong() )
        print leq
        leq = c.LinearInequality( x, c.cnGEQ, y+1)
        print leq

    print '====='
    return
    print "..bounds"
    solver = c.SimplexSolver()
    solver.AddBounds( x, 1, 5)
    solver.AddBounds( x, 1, y)
    solver.AddBounds( x, y, 7)

def simple1():
    solver = c.SimplexSolver()
    x = c.Variable("x",7)
    y = c.Variable("y",8)

    l0 = c.LinearExpression(0)
    print "x=y+1"
    eq = c.LinearEquation(x,l0+y+1)
    print eq
    eq=0
    solver=0
    if 0:
        solver.AddStay(x);
        solver.AddStay(y);
        print ">> x=",x.Value(), "y=", y.Value()
        solver.AddConstraint(eq);
        print "<< x=",x.Value(), "y=", y.Value()
        print x,y,"aa"

def simple1a():
    solver = c.SimplexSolver()
    x = c.Variable("x",7)
    y = c.Variable("y",8)

    l0  = c.LinearExpression(0)
    print "x=(y+1)/2 ",
    eq = c.LinearEquation(x,l0+(l0+y+1)/2)
    print eq

    solver.AddStay(x);
    solver.AddStay(y);
    print ">> x=",x.Value(), "y=", y.Value()
    solver.AddConstraint(eq);
    print "<< x=",x.Value(), "y=", y.Value()

#/* Add an edit variable to an empty solver */
def simple2_Add_edit_var( do_exception =False):
    x = c.Variable(167)
    solver = c.SimplexSolver()
    if not do_exception:
        solver.AddStay(x)
    try:
        solver.AddEditVar(x)
        solver.BeginEdit()
        solver.SuggestValue(x,100)
        solver.EndEdit()
    except RuntimeError: # ExCLEditMisuse:
        import traceback,sys
        traceback.print_exception( *sys.exc_info() )
        if do_exception:
            print "OK, got exception"
        else: raise
    else:
        if do_exception:
            print "err, wrong exception or no exception"
        else:
            print x
            assert x.Value()==100

def simple2_Add_edit_var_to_empty_solver():
    simple2_Add_edit_var( True)

def justStay1():
    x = c.Variable(5);
    y = c.Variable(10);
    solver = c.SimplexSolver();

    if 0:
        solver.AddPointStay(x,y,1);
    else:
        solver.AddStay(x);
        solver.AddStay(y);

    print ">> x=",x.Value(), "y=", y.Value()


def addDelete1():
    err = 0
    x = c.Variable("x");
    solver = c.SimplexSolver();

    solver.AddConstraint( c.LinearEquation( x, 100, c.sWeak() ));

    c10 = c.LinearInequality(x,c.cnLEQ,10.0);
    c20 = c.LinearInequality(x,c.cnLEQ,20.0);
    solver .AddConstraint(c10) .AddConstraint(c20);

    err |= x.Value()!=10
    print ">> x=",x.Value()

    print "-"
    print solver ;
    print "-"
    solver.RemoveConstraint(c10);
    print solver ;
    print "-"

    err |= x.Value()!=20
    print ">> x=",x.Value()

    solver.RemoveConstraint(c20);
    err |= x.Value()!=100
    print ">> x=",x.Value()

    c10again = c.LinearInequality(x, c.cnLEQ,10.0);

    solver .AddConstraint(c10) .AddConstraint(c10again);

    err |= x.Value()!=10
    print ">> x=",x.Value()

    solver.RemoveConstraint(c10);
    err |= x.Value()!=10
    print ">> x=",x.Value()

    solver.RemoveConstraint(c10again);
    err |= x.Value()!=100
    print ">> x=",x.Value()

    print "err:",err or "OK"

def addDelete2():
    err = 0
    x = c.Variable();
    y = c.Variable();
    solver = c.SimplexSolver();

    solver .AddConstraint( c.LinearEquation(x, 100.0, c.sWeak()))
    solver .AddConstraint( c.LinearEquation(y, 120.0, c.sStrong()));

    c10 = c.LinearInequality (x,c.cnLEQ,10.0);
    c20 = c.LinearInequality (x,c.cnLEQ,20.0);

    solver .AddConstraint(c10) .AddConstraint(c20);
    err |= not (x==10 and y==120)
    print ">> x=",x.Value(), "y=", y.Value()

    solver.RemoveConstraint(c10);
    err |= x!=20 or y!=120
    print ">> x=",x.Value(), "y=", y.Value()

    cxy = c.LinearEquation ( 2*x, y);
    solver.AddConstraint(cxy);
    err |= x!=20 or y!=40
    print ">> x=",x.Value(), "y=", y.Value()

    solver.RemoveConstraint(c20);
    err |= x!=60 or y!=120
    print ">> x=",x.Value(), "y=", y.Value()

    solver.RemoveConstraint(cxy);
    err |= x!=100 or y!=120
    print ">> x=",x.Value(), "y=", y.Value()

    print "err:",err or "OK"

def casso1():
    err = 0;
    x = c.Variable("x");
    y = c.Variable("y");
    solver = c.SimplexSolver ();

    solver .AddConstraint( c.LinearInequality(x,c.cnLEQ,y))
    solver .AddConstraint( c.LinearEquation(y, x+3.0))
    solver .AddConstraint( c.LinearEquation(x,10.0,c.sWeak()))
    solver .AddConstraint( c.LinearEquation(y,10.0,c.sWeak()))

    err |= not (x==10 and y==13 or x==7 and y==10)
    print ">> x=",x.Value(), "y=", y.Value()

    print "err:",err or "OK"

"""
def inconsistent1():
  SimplexSolver solver;
  Variable x("x");
  LinearEquation eq1(x,10.0);
  LinearEquation eq2(x,5.0);
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

def inconsistent2():
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

def inconsistent3():
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


def multiedit():
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


def multiedit2():
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
"""


if 0:
    solver = c.SimplexSolver()
    print " here11"
    solver.AddEditVar(x)
    print " here2"
    solver.AddEditVar(y)
    solver.AddEditVar(z)

    solver.BeginEdit()

    solver.SuggestValue(x,1)
    solver.SuggestValue(z,2)

    solver.RemoveEditVar(y)

    solver.SuggestValue(x,3)
    solver.SuggestValue(z,4)

    solver.EndEdit()
    print " here3"

    print x
    print y
    print z

def solver():
    s = c.SimplexSolver()
    x = c.Variable("x",7)
    s.AddStay(x)
    s.AddStay(x)
    print x
    print s


def test():
    for a in [
        test_expression,
                simple1, #simple1a,
                addDelete1, addDelete2, casso1,
        solver,
        justStay1,
        simple2_Add_edit_var,
        #simple2_Add_edit_var_to_empty_solver,
            ]:
        print '========', a.__name__
        a()
test()
# vim:ts=4:sw=4:expandtab
