//s.dobrev - oct'2k/jan2k2
// c++ defense programming and "utilita" macroses
// - disabling compiler-automatic constructors/operators
// - each class has own "sanity" probe, which fails if
//   wrong class; not constructed yet; already destructed; overwriten/garbled by smb.
//   for full memory-overwrite control, have one at begin and one at end of class.
//   check objects with virtual-methods before calling them!
//newer version - templates, fully automatic now

#ifndef _SANITY_H
#define _SANITY_H

#include <assert.h>

 //will need empty default constructor() if has none!
#define DISABLE_COPYCTOR(x)     private: x( const x & );
#define DISABLE_ASSIGN(x)       private: void operator = ( const x & );
#define DISABLE_AUTO(x)         DISABLE_COPYCTOR(x) DISABLE_ASSIGN(x)

#define PUTSaDTOR(name)         puts("dtor-"#name)
#ifndef PUTSDTOR
#define PUTSDTOR(name)          //PUTSaDTOR(name)
#endif

 //sanity:

/// inheriting this will make _all_ classes with same root - no no no no
template <int sane>
class TSanity {
    enum eSane { eSANE= sane, eINSANE= ~sane } _sane;
public:
    TSanity()                   { _sane= TSanity<sane>::eSANE; } // { _sane= eSANE; }
    TSanity( const TSanity & )  { _sane= TSanity<sane>::eSANE; } // { _sane= eSANE; }
    TSanity( int,int)           { _sane= TSanity<sane>::eSANE; } // { _sane= eSANE; }       //redundant; used in OBJSANECTOR( ) replacement below
    void operator = ( const TSanity & ) const {}
    ~TSanity()                  { assert(Sane()); _sane = eINSANE; }
    int Sane() const            { return eSANE == _sane; }
    operator int() const        { return Sane(); }
};

/*use:
class Any {
    TSanity<0x12345> _sane;
    ....
    void somefunc() { assert(_sane); ... }
    ~Any() { assert(_sane); ...... }
};

//but better use OBJSANEDEF(sane) macro and Sane() instead of just _sane
*/

#define OBJSANEDEF(sane)        \
private: TSanity<sane> _sane;   \
public: int Sane()      const   { return this && _sane; }

 //default dtor
#define OBJSANEDTOR( ctor )     ~ctor() { PUTSDTOR(ctor); assert(Sane()); }

 //for objs with default INLINE dtor
#define OBJSANEDEFdtor(sane,ctor)       OBJSANEDEF(sane) OBJSANEDTOR(ctor)

#endif  //SANITY_H
