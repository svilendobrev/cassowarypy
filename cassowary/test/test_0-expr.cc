// $Id: Test40-exprs.cc
//
// Cassowary Incremental Constraint Solver

#include "Cl.h"
#include <iostream>

int test_0_minus_expr()
{
	LinearExpression a(0);
	for (int i=1000; i--; ) {
		a = 0 - a;
		cout << i <<':'<< a << endl;
	}
	return 0;
}

int main() {
	return test_0_minus_expr();
}
