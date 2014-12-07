/* ISC license. */

#include <errno.h>
#include "error.h"
#include "tai.h"
#include "iopause.h"
#include "ancillary.h"
#include "unix-timed.h"

int timed_ancil_fds_send (int fdsocket, int const *fds, unsigned int n, struct taia const *deadline, struct taia *stamp)
{
  iopause_fd x = { fdsocket, IOPAUSE_WRITE, 0 } ;
  for (;;)
  {
    register int r = iopause_stamp(&x, 1, deadline, stamp) ;
    if (r < 0) return -1 ;
    else if (!r) return (errno = ETIMEDOUT, -1) ;
    else if (x.revents & IOPAUSE_WRITE)
    {
      r = ancil_send_fds(fdsocket, fds, n) ;
      if ((r >= 0) || !error_isagain(errno)) return r ;
    }
  }
}
