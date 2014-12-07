/* ISC license. */

/* MT-unsafe */

#define _BSD_SOURCE
#include <sys/types.h>
#include <unistd.h>
#include <grp.h>
#include <limits.h>
#include "setgroups.h"
#include "djbunix.h"

int prot_grps (char const *name)
{
  gid_t tab[NGROUPS_MAX] ;
  int n = prot_readgroups(name, tab, NGROUPS_MAX) ;
  return n < 0 ? -1 : setgroups(n, tab) ;
}
