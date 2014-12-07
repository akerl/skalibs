/* ISC license. */

#include <errno.h>
#include "tai.h"
#include "iopause.h"

extern int iopause_stamp (iopause_fd *x, unsigned int n, struct taia const *deadline, struct taia *stamp)
{
  register int r ;
  do
  {
    r = iopause(x, n, deadline, stamp) ;
    if (stamp)
    {
      int e = errno ;
      taia_now(stamp) ;
      errno = e ;
    }
  }
  while ((r < 0) && (errno == EINTR)) ;
  return r ;
}
