CL_DEFs = HAVE_CONFIG_H #TRACE_NEWDEL #CL_FIND_LEAK #CL_HAVE_GTL #CL_NO_IO CL_NO_DEPRECATED
INC = -I. -I..
# -Imy
CFLAGS += -pg -DNDEBUG -O2 $(INC) $(CL_DEFs:%=-D%)
CXXFLAGS += $(CFLAGS)
SRCcpp += $(wildcard my/*.cpp)
SRCcc += $(filter-out FD%,$(wildcard *.cc))
SRCc  += $(wildcard *.c)
LIB = libcsw.a

now: dirs lib test
dirs:
	@mkdir -p o o/my
.PRECIOUS: o/%.o
#TESTS = ParseTest SubgraphTest CTest LeakTest test-Constraint test-LinearExpression test-SimplexSolver test-Strength test-Variable 	FDTests
#TESTS = Tests
TESTS = z leak test_0-expr Tests leak	Bug0 Bug1 Bug2#CTest

SRC = $(SRCcc) $(SRCc) $(SRCcpp) $(TESTS:%=test/%.cc) $(TESTS:%=test/%.cpp)

test: $(TESTS:%=%.test)
%.test: %.exe
	./$<

%.exe: o/%.o $(LIB) #-lcsw
	$(CXX) $(CXXFLAGS) -o $@ $+
# -lGTL

o/%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<
o/%.o: test/%.cpp
	$(CXX) $(CXXFLAGS:-O2=) -c -o $@ $<
o/%.o: test/%.cc
	$(CXX) $(CXXFLAGS:-O2=) -c -o $@ $<
o/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
o/%.o: %.c
	$(CXX) $(CXXFLAGS) -c -o $@ $<

lib: $(LIB)
$(LIB): $(SRCcc:%.cc=o/%.o) $(SRCc:%.c=o/%.o) $(SRCcpp:%.cpp=o/%.o)
	ar r $@ $?
clean:
	-rm o/*.o o/*/*.o

.PHONY: tag tags
ctags tags tag:
	ctags -R .

MDEPS= _makedep.dep
#MDEPPFX=/home/_bin/cc/
dep $(MDEPS):	#\$$O/
#	@$(MDEPPFX)mdep.pl -s $(INC) -r='s,\.cc :,o/\.o :,; ' $(MDEPFLAGS) *.cc my/*.cpp $(MDEPENDENTS) > $(MDEPS)
	@$(MDEPPFX)mdep.pl -s $(INC) -r='s/\.(c|cc|cpp) :/\.o :/; s,^([^/]+/)*([^/]+) :,o/$$2 :,' $(MDEPFLAGS) $(SRC) $(MDEPENDENTS) > $(MDEPS)
include $(MDEPS)

new: clean now


SWIG = swig -c++ -python -keyword

swig: py/csw.py py/csw_wrap.cxx

py/%.py py/%_wrap.cxx: py/%.i #-o py/csw
	$(SWIG) -ignoremissing  $(DEFS:%=-D%) $<
py/%.o: py/%.cxx
	$(CXX) $(CXXFLAGS) -I/usr/include/python2.1 -c -o $@ $<

CSWs = Variable SimplexSolver LinearEquation LinearInequality Errors

csws: csw0 $(CSWs:%=py/%.py)
csw0:
#	echo "import $(CSWs:%=%,)" 		> py/__init__.py
	echo "##" 						> py/setup.py
	echo "srcs  = [ $(SRCcc:%='%',) ]" 			>> py/setup.py
	echo "wraps = [ $(CSWs:%='py/%_wrap.cc',) ]" 	>> py/setup.py
	echo "pys   = [ 'py/__init__.py', $(CSWs:%='py/%.py',) ]" >> py/setup.py
	echo "defs  = [ $(CL_DEFS:%=('%',None),) ]" >> py/setup.py
	cat py/setup.in 	>> py/setup.py

py/%.py py/%_wrap.cc: %.h
	$(SWIG) -c -module $* -o py/$*_wrap.cc -ignoremissing $(DEFS:%=-D%) $<
#	echo "import $*" >>py/__init__.py

csws-new:
	rm $(CSWs:%=py/%.py) py/*_wrap.cc

