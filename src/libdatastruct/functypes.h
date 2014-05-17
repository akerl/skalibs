/* ISC license. */

#ifndef FUNCTYPES_H
#define FUNCTYPES_H

typedef int uintcmpfunc_t (unsigned int, unsigned int, void *) ;
typedef uintcmpfunc_t *uintcmpfunc_t_ref ;

typedef int cmpfunc_t (void const *, void const *, void *) ;
typedef cmpfunc_t *cmpfunc_t_ref ;

typedef void *dtokfunc_t (unsigned int, void *) ;
typedef dtokfunc_t *dtokfunc_t_ref ;

typedef int iterfunc_t (char *, void *) ;
typedef iterfunc_t *iterfunc_t_ref ;

#endif
