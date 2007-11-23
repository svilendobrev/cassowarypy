#if defined( TRACE_NEWDEL) || defined( TRACE_MALLOC)
#include "unnewdel.h"
#include <new>

#include <stdlib.h>
#include <stdio.h>
#define N 1000000+0
void * p0;
static struct ptrInfo {
    void * p;
    int    size;
    const char * file;
    int    line;
} ptrs[N];

void add( void * p,int n,const char * file, int line) {
    if (!p) {
        printf("p %p NULL alloc! %s/%d\n",p,file,line);
        return;
    }
    for (int i=0; i<N; i++)
        if (ptrs[i].p==p) { printf("p %p -exist!\n",p); }
        else
        if (ptrs[i].p==p0) { ptrInfo a = { p,n,file,line }; ptrs[i]=a; return ; }
    printf("p %p -no space! %s/%d\n",p,file,line);
}
void del( void * p) {
    for (int i=0; i<N; i++)
        if (p==ptrs[i].p) { ptrs[i].p=p0; return ; }
    printf("p %p -not found!\n",p);
}
void dump() {
    printf("p-checking\n");
    for (int i=0; i<N; i++)
        if (ptrs[i].p!=p0) { ptrInfo * p = ptrs+i;
            printf("p %p -not freed! ([%d],%s,%d)\n",p->p,p->size,p->file,p->line);
        }
}
static struct aa {
     aa() { printf("p-init\n");
        p0 = (void*)'boza';
        for (int i=0; i<N; i++)
            ptrs[i].p = p0;
     }
    ~aa() { dump(); }
} aaa;

#define printf if (10) printf

const char* _z_file;
int _z_line;

#define EOL ""

#ifdef TRACE_NEWDEL
int trace_newdel =0;
void *operator new (size_t n) {
    if (trace_newdel) printf("new[%d] "EOL,n);
    void * p = malloc(n);
    if (trace_newdel) printf(" %p %s/%d\n",p, _z_file?_z_file:"?",_z_line);
    add(p,n,_z_file,_z_line);
    _z_file="?",_z_line=-1;
    return p;
}//throw (std::bad_alloc);
//void *operator new[] (size_t n) { }//throw (std::bad_alloc);
void operator delete (void * p) {
    if (trace_newdel) printf("del %p %s/%d\n",p, _z_file?_z_file:"?",_z_line);
    if (p) {
        del(p);
        free(p);
    _z_file="?",_z_line=-1;
    }
}//throw();
//void operator delete[] (void * p) { }//throw();
#endif

#ifdef TRACE_MALLOC
int trace_malloc =1;
extern "C" void * zmalloc(size_t n,const char *_z_file,int _z_line)
{
    if (trace_malloc) printf("mall[%d] "EOL,n);
    void * p = malloc(n);
    if (trace_malloc) printf(" %p %s/%d\n",p, _z_file?_z_file:"?",_z_line);
    add(p,n,_z_file,_z_line);
    return p;
}
extern "C" void zfree(void *p,const char *_z_file,int _z_line)
{
    if (trace_malloc) printf("free %p %s/%d\n",p, _z_file?_z_file:"?",_z_line);
    if (p) free(p);
    del(p);
}
extern "C" void * zrealloc( void * p, size_t n,const char *_z_file,int _z_line)
{
    if (trace_malloc) printf("reall[%d] "EOL,n);
    void * q = realloc(p,n);
    if (trace_malloc) printf(" %p->%p %s/%d\n",p,q, _z_file?_z_file:"?",_z_line);
    del(p);
    add(q,n,_z_file,_z_line);
    return q;
}
#endif
#endif
