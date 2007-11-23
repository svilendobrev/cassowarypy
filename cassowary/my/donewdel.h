#ifdef TRACE_NEWDEL

#ifndef new //#EWDEL_H
//#define NEWDEL_H

//#include <stdio.h>
//#define new     !printf("new %s,%d\n",__FILE__,__LINE__)?0:new
//#define delete  printf("del %s,%d\n",__FILE__,__LINE__);delete
extern const char* _z_file;
extern int _z_line;
#if 1
////#
////#define new     !printf("new %s,%d\n", _z_file=__FILE__, _z_line=__LINE__)?0:new
////#define delete  printf("del %s,%d\n",_z_file=__FILE__, _z_line=__LINE__);delete
# define new        !(_z_file=__FILE__, _z_line=__LINE__,1)?0:new
# define delete     (_z_file=__FILE__, _z_line=__LINE__,1), delete
#endif
//#include "domalloc.h"

#endif   //NEWDEL_H
#endif
