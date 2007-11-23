#include "SimplexSolver.h"
#include "LinearEquation.h"
#include <iostream>

#include "DummyVariable.h"
#include "SlackVariable.h"

int
main( int argc, char **argv ) {
	int cns=1;
    if (argc > 1)
      cns = atoi(argv[1]);
	for (int i=0; i<cns; i++) {
		try {
			FloatVariable v("aaa");	P_AbstractVariable_holder _hv(&v);
			Variable vv(v);//("bb");
#define EQ 10	
#define SOLV 10	
			
		#if EQ
			LinearExpression e(v,1.5);
			e.AddExpression( LinearExpression(v,3.2) );
			LinearEquation eq(v,2.5); P_Constraint_holder _heq(&eq);
		#endif		
		#if SOLV
			{
			SimplexSolver solver;
			#if 10
				solver.AddStay(vv);
			#if 10
				solver.AddEditVar(vv);
				//cerr << solver <<endl;
				solver.BeginEdit();
				solver.SuggestValue(vv,100);
				solver.EndEdit();
			#endif	
			#endif	
			cerr << vv << endl;

			#if EQ
				solver.AddConstraint(&eq);
			#endif	
			}
			cerr << vv << endl;
		#endif	
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
}
