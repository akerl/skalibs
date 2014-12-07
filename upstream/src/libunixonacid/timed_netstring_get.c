/* ISC license. */

#include <errno.h>
#include "buffer.h"
#include "stralloc.h"
#include "netstring.h"
#include "tai.h"
#include "iopause.h"
#include "unix-timed.h"

int timed_netstring_get (buffer *b, stralloc *sa, struct taia const *deadline, struct taia *stamp)
{
  iopause_fd x = { .fd = buffer_fd(b), .events = IOPAUSE_READ } ;
  unsigned int w = 0 ;
  for (;;)
  {
    register int r = netstring_get(b, sa, &w) ;
    if (r) return r ;
    r = iopause_stamp(&x, 1, deadline, stamp) ;
    if (r < 0) return -1 ;
    else if (!r) return (errno = ETIMEDOUT, -1) ;
  }
}
