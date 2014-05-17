/* ISC license. */

#include <sys/time.h>
#include "tai.h"

int timeval_from_taia (struct timeval *tv, struct taia const *a)
{
  struct timeval tmp ;
  if (!timeval_from_tai(&tmp, taia_secp(a))) return 0 ;
  tv->tv_sec = tmp.tv_sec ;
  tv->tv_usec = a->nano / 1000 ;
  return 1 ;
}
