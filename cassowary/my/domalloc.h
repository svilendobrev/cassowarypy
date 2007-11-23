#ifdef TRACE_MALLOC
#include <stdlib.h>
extern "C" void * zmalloc( size_t x,const char *f,int l);
extern "C" void   zfree( void * x,const char *f,int l);
extern "C" void * zrealloc(void *x, size_t y,const char *f,int l);

#ifndef malloc  
#define malloc(x)    zmalloc(x,__FILE__,__LINE__)
#define free(x)      zfree(x,__FILE__,__LINE__)
#define realloc(x,y) zrealloc(x,y,__FILE__,__LINE__)
#endif

#endif
