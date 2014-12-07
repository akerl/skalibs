/* ISC license. */

#include <errno.h>
#include "tai.h"
#include "unix-timed.h"

int timed_ancil_fd_sandwiched_recv (int fdsock, char const *before, unsigned int beforelen, char const *after, unsigned int afterlen, struct taia const *deadline, struct taia *stamp)
{
  int fdpipe ;
  int r = timed_ancil_fds_sandwiched_recv(fdsock, &fdpipe, 1, before, beforelen, after, afterlen, deadline, stamp) ;
  return r < 0 ? -1 : !r ? (errno = EPIPE, -1) : fdpipe ;
}
