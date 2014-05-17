/* ISC license. */

#include "nonposix.h"
#include <errno.h>
#include <sys/socket.h>
#include <sys/uio.h>
#include "ancillary.h"

int ancil_recv_fds (int sock, int *fds, unsigned int n)
{
  struct msghdr msghdr ;
  struct iovec nothing_vec ;
  struct cmsghdr *cmsg ;
  unsigned int r ;
  char buf[CMSG_SPACE(n * sizeof(int))] ;
  char nothing ;
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
  if (recvmsg(sock, &msghdr, 0) < 0) return -1 ;
  if (nothing != '!') return (errno = EPROTO, -1) ;
  cmsg = CMSG_FIRSTHDR(&msghdr) ; 
  if ((cmsg->cmsg_level != SOL_SOCKET) || (cmsg->cmsg_type != SCM_RIGHTS))
    return (errno = EPROTO, -1) ;
  r = (unsigned int)(cmsg->cmsg_len - (CMSG_DATA(cmsg) - (unsigned char *)cmsg)) / sizeof(int) ;
  if (r > n) return (errno = ERANGE, -1) ;
  for (; i < r ; i++) fds[i] = ((int *)CMSG_DATA(cmsg))[i] ;
  return (int)r ;
}
