// (c) SvD 1997...
// T.h : general purpose templates
// ThingReference : self-destructable thing *
// SvD '97

#ifndef __TEMPL_DEF_H
#define __TEMPL_DEF_H
#include "sanity.h"  //DISABLE_AUTO CLASS_AUTOCOPY

//use: typedef ThingReference<xxx> xxxRef;
// xxxRef xr( new xxx )

template<class T>
class ThingReference {
public:
        ThingReference( T* xx )         { _ptr = xx; }
        ~ThingReference()               { delete _ptr; }
        T* operator -> ()               { return _ptr; }
           operator T* ()               { return _ptr; }
        T* unOwn()                      { T* p = _ptr; _ptr=0; return p; }
private:
        T* _ptr;
        DISABLE_AUTO( ThingReference )
};

template<class T>
class ThingArrayReference {
public:
        ThingArrayReference( T* xx )         { _ptr = xx; }
        ~ThingArrayReference()               { delete [] _ptr; }
        T* operator -> ()               { return _ptr; }
           operator T* ()               { return _ptr; }
//        T  operator [] ( int i)         { return _ptr[i]; }
        T* unOwn()                      { T* p = _ptr; _ptr=0; return p; }
private:
        T* _ptr;
        DISABLE_AUTO( ThingArrayReference)
};

#endif  //__TEMPL_DEF_H
