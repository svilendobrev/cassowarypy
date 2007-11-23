#!/usr/bin/perl
print "#include \"SimplexSolver.h\"\n";
print "#include \"LinearEquation.h\"\n";
print "#include \"LinearInequality.h\"\n";
print "\n";
print "void model( SimplexSolver & s) {\n";

%vars = {};
%values = {};
$v = 0;
while (<>) {
    last if /SOLVERalfa/;
    s/\s+$//g;
    s/^ *: //g;
	$line = $_;
    if (s/^v //) {
        $v+=1;
        $vn = 'v'.$v;
		$fullname = $_;
		s/[^:]+:([-0-9.+]+)//; 
		$value_ = $value = $1;
		$value_ =~ s/[-\.+]/_/g;
		$vn.= 'V_'.$value_;
        $vars{ $fullname } = $vn;
		$values{ $vn} = $value;
        print "Variable $vn"."( \"$vn\" ); //$fullname\n";
        print " s.AddStay($vn);\n";
        next;
    }
    if (s/^v= Eq0\((\[[^]]+\]),([-0-9.+]+)//) {
		$v = $1; $value = $2;
		$v = $vars{$v};
		print "s.AddConstraint( new LinearEquation( $v, $value)); //$line\n";
		next;
	}
    if (s/^= Eq(Var)?\(([^,]+),([^,]+)//) {
		$v1 = $2; $v2 = $3;
		$v1 =~ s/(\[[^]]+\])/$vars{$1}/eg;
		$v2 =~ s/(\[[^]]+\])/$vars{$1}/eg;
		print "s.AddConstraint( new LinearEquation( LinearExpression( $v1), $v2)); //$line\n";
		next;
	}
    if (s/^= Positive0\(([^,]+),//) {
		$v1 = $1; 
		$v1 =~ s/(\[[^]]+\])/$vars{$1}/eg;
		print "s.AddConstraint( new LinearInequality( $v1)); //$line\n";
		next;
	}
	
}

#print "	  test(s);\n";
#print "} //void model()\n";
#
#print "void test() {\n";

print "\n";
print "#define EQ(x,y) (x<y?(y-x):(x-y))<1e-6\n";
foreach $k (sort keys %values) {
	$v = $values{$k};
    next if $v eq '';
    #print "  if (!Approx($k,$v))  cout << \"diff \" << $k << $v <<endl;\n";
    print "  if (!EQ($k.Value(),$v))  cout << \"diff \" << $k <<" "<< $v <<endl;\n";
}
print "}\n";

print 
 "void main() {\n"
."  for (int i=10;i--;) { cout<<i<<endl;\n"
."    SimplexSolver s;\n"
."	  model(s);\n"
."  }\n"
."}\n";
