from distutils.core import setup, Extension
import os

FD = 0

srcp = 'cassowary'
include_path= [ '.', ]

#wraps = [ 'csw.cpp' ]
wraps = [ 'csw.i' ]
pys   = [ 'csw', ]
src = [
 'AbstractVariable.cc',
 'Constraint.cc',
 'DummyVariable.cc',
 'FloatVariable.cc',
 'LinearExpression.cc',
 'SimplexSolver.cc',
 'SlackVariable.cc',
 'Solver.cc',
 'Strength.cc',
 'SymbolicWeight.cc',
 'Tableau.cc',
 'Variable.cc',
 'Errors.cc',
]
defs = [ 'HAVE_CONFIG_H',
    #    'TRACE_NEWDEL',        #put this to trace memallocs
    #    'TRACE_REFCOUNT_DIE',  #put this to trace refcounting
]
if 'TRACE_NEWDEL' in defs: src+= [ 'my/new_del.cpp' ]

#defs += [ 'CL_NO_IO' ]
    #+ CL_NO_DEPRECATED

libs = [ 'stdc++' ]
if (FD):
    src += [ 'FDBinaryOneWayConstraint.cc',
             'FDConnectorVariable.cc', 'FDSolver.cc', 'FDVariable.cc',
            ]
    libs += [ 'GTL' ]
    defs += [ 'CL_HAVE_GTL', 'CL_BUILD_FD_SOLVER' ]

sources = map( lambda s: os.path.join( srcp,s),src) + wraps

#how else to control sdist...?
this = 'setup.py'
manf = 'MANIFEST.in'
manifest = [
    srcp+'/*.h'
    ,'test.py'
    ,'explan.cpp'
]

def manifest_template( setupf,manf,manifest):
    from distutils.dep_util import newer
    if (newer(setupf,manf)):
        print '..creating', manf
        f = open( manf, "w")
        for name in [ setupf, manf ] + manifest :
            f.write( 'include '+name + '\n')
        f.close()

manifest_template( this,manf,manifest)


csw = Extension( name = '_csw'
        ,sources = sources
        ,include_dirs = include_path
        ,define_macros = map( lambda s: (s,None), defs )
        ,libraries = libs
        ,extra_compile_args = []#'-pedantic-errors' ] #'-O5',
        ,swig_opts = [ '-c++', ] + [ '-D'+s for s in defs ]
        )
#csw.swig_cpp = [ '-c++', '-keyword', '-ignoremissing' ] + map(...)
#csw.swig_opts = [ '-c++', ] + [ '-D'+s for s in defs ]

#############
## XXX distutils is still stupid and broken;
## only the old --swig-cpp works for build_ext, the new --swig-opts=-c++ does not!

swigcpp = '--swig-cpp'
import sys
argv = sys.argv
if swigcpp not in argv:
    #forced to run with setup.py build --swig-cpp
    #dont use swig-opts - disables extention.swig_opts above
    if 'install' in argv and 'build_ext' not in argv:
        argv.insert( argv.index( 'install' ), 'build_ext')
    if 'build' in argv and 'build_ext' not in argv:
        argv.insert( argv.index( 'build' ), 'build_ext')
    if 'build_ext' in argv:
        argv.insert( 1+argv.index( 'build_ext' ), swigcpp)

print ' warn: re-building this works on g++ 3.3*; strip the result lib when ready'

setup( name = 'csw', description = 'cassowrapy: py-wrap of cassowary linear constraint solver',
    author = 'svilen dobrev',
    author_email= 'svilen_dobrev at users point sourceforge point net',
    license = 'MIT',
    version = '0.25unleak',
    py_modules  = pys,
    ext_modules = [ csw ]
)
