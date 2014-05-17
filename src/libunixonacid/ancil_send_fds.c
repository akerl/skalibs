/* ISC license. */

#include "nonposix.h"
#include <sys/socket.h>
#include <sys/uio.h>
#include "ancillary.h"

int ancil_send_fds (int sock, int const *fds, unsigned int n)
{
  struct msghdr msghdr ;
  struct iovec nothing_vec ;
  struct cmsghdr *cmsg ;
  char buf[CMSG_SPACE(n * sizeof(int))] ;
  char nothing = '!' ;
  register unsigned int i = 0 ;
  
  nothing_vec.iov_base = &nothing ;
  nothing_vec.iov_len = 1 ;
  msghdr.msg_name = 0 ;
  msghdr.msg_namelen = 0 ;
  msghdr.msg_iov = &nothing_vec ;
  msghdr.msg_iovlen = 1 ;
  msghdr.msg_flags = 0 ;
  msghdr.msg_control = buf ;
  msghdr.msg_controllen = sizeof(buf) ;
  cmsg = CMSG_FIRSTHDR(&msghdr) ;
  cmsg->cmsg_level = SOL_SOCKET ;
  cmsg->cmsg_type = SCM_RIGHTS ;
  cmsg->cmsg_len = CMSG_LEN(n * sizeof(int)) ;
  for (; i < n ; i++) ((int *)CMSG_DATA(cmsg))[i] = fds[i] ;
 /*
   XXX: sendmsg's return value doesn't include the cmsg's len,
   so it's useless. Sigh.
 */
  if (sendmsg(sock, &msghdr, 0) < 1) return -1 ;
  return n ;
}
