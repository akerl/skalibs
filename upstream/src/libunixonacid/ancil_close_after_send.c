/* ISC license. */

#include "sysdeps.h"
#include "djbunix.h"
#include "ancillary.h"

void ancil_close_after_send (int const *fds, unsigned int n)
{
#ifdef HASANCILAUTOCLOSE
  (void)fds ;
  (void)n ;
#else
  register unsigned int i = 0 ;
  for (; i < n ; i++) fd_close(fds[i]) ;
#endif
}
