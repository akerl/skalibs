/* ISC license. */

#include <errno.h>
#include "allreadwrite.h"
#include "uint.h"
#include "bytestr.h"
#include "buffer.h"
#include "stralloc.h"
#include "netstring.h"

int netstring_okeof (buffer_ref b, unsigned int w)
{
  return (errno == EPIPE) && !w && buffer_isempty(b) ? (errno = 0, 1) : 0 ;
}

int netstring_get (buffer_ref b, stralloc *sa, unsigned int *state)
{
  unsigned int w = 0 ;
  int ok = 1 ;
  if (!*state)
  {
    char *x ;
    unsigned int n ;
    unsigned int len ;
    for (;;)
    {
      register int r ;
      x = buffer_RPEEK(b) ;
      n = byte_chr(x, buffer_len(b), ':') ;  /* XXX: accepts :, as a valid netstring */
      if (n >= b->a) return (errno = EINVAL, -1) ;
      if (n < buffer_len(b)) break ;
      r = sanitize_read(buffer_fill(b)) ;
      if (r <= 0) return r ;
      ok = 2 ;
    }
    if (n != uint_scan(x, &len)) return (errno = EINVAL, -1) ;
    if (!stralloc_readyplus(sa, len+1)) return -1 ;
    buffer_SEEK(b, n+1) ;
    *state = len + 1 ;
  }
  {
    register int r = buffer_getall(b, sa->s + sa->len, *state, &w) ;
    sa->len += w ;
    *state -= w ;
    if (r <= 0) return r ;
    if (r == 2) ok = 2 ;
  }
  return (sa->s[--sa->len] == ',') ? ok : (errno = EINVAL, -1) ;
}
