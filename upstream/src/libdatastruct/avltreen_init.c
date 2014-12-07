/* ISC license. */

#include "functypes.h"
#include "genset.h"
#include "avlnode.h"
#include "avltreen.h"

void avltreen_init (avltreen_ref t, avlnode_ref storage, unsigned int *freelist, unsigned int size, dtokfunc_t_ref dtok, cmpfunc_t_ref f, void *p)
{
  GENSET_init(&t->x, avlnode, storage, freelist, size) ;
  t->root = size ;
  t->dtok = dtok ;
  t->kcmp = f ;
  t->external = p ;
}