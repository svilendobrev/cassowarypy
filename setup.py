#$Id$
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

print ' warn: re-building this works on gcc 3.3* and gcc-4.1; strip the result lib when ready'

setup( name = 'cassowarypy',
    description = 'cassowarypy: python-wrap of Cassowary linear constraint solver',
    version = '0.26unleak',
    py_modules  = pys,
    ext_modules = [ csw ],
    author = 'svilen dobrev',
    author_email= 'svilen_dobrev at users point sourceforge point net',
    url= 'http://dbcook.sourceforge.net/readme-cassowarypy',
    license = 'MIT',
    classifiers='''
Development Status :: 5 - Production/Stable
Intended Audience :: Developers
License :: OSI Approved :: MIT License
Programming Language :: Python
Topic :: Scientific/Engineering :: Mathematics
Topic :: Software Development :: Libraries :: Python Modules
'''.strip().split('\n'),

    long_description= '''\
This is a python wrapper over the (famous) Cassowary incremental constraint solver.
It uses the c++ implementation (0.6) as backend.

The original c++ code is somewhat refactored to remove memory leaks
by using reference counting, and is usable alone.

The refactoring was done somewhen in 2002, and the code is not touched much since then.
Last changes are workarounding recent template-things in new (gcc-4.x) c++ compilers.
The Finite-domain part (using GTL graph library) is not tried/tested; it might or might not work.

repository: svn co https://dbcook.svn.sf.net/svnroot/dbcook/cassowarypy

how to compile/install for python:
 * the c++ code now compiles on both g++ 3.3.3 and g++ 4.1.3.
   it also compiles on some MSVC.
 * 'swig' is also needed
 * if the default C++ compiler is one of those, just 'python setup.py install' would do.
   Then run python test.py to see if all works.
 * else, u have to install one of these compilers and fight with distutils to make it use that one.
   e.g. "CC=g++-3.3 python setup.py install" might work; also check the link'ing part

My code is under MIT-license.
Original Cassowary code is licensed under LGPL.

Original cassowary Web Page: (last update about year 2000)
http://www.cs.washington.edu/research/constraints/cassowary
''',
)
# vim:ts=4:sw=4:expandtab
