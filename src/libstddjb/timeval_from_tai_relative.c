/* ISC license. */

#include <sys/time.h>
#include <errno.h>
#include "sysdeps.h"
#include "uint64.h"
#include "tai.h"

int timeval_from_tai_relative (struct timeval *tv, struct tai const *t)
{
  if (tai_sec(t) >= (uint64)1 << 63) return (errno = EINVAL, 0) ;
#if SKALIBS_SIZEOFTIME < 8
  if (tai_sec(t) > 0xffffffffU) return (errno = ERANGE, 0) ;
#endif
  tv->tv_sec = (time_t)tai_sec(t) ;
  tv->tv_usec = 0 ;
  return 1 ;
}
