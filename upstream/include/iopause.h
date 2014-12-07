/* ISC license. */

#ifndef IOPAUSE_H
#define IOPAUSE_H

#include <sys/types.h>
#include <poll.h>
#include "tai.h"

typedef struct pollfd iopause_fd, *iopause_fd_ref ;

#define IOPAUSE_READ (POLLIN|POLLHUP)
#define IOPAUSE_WRITE POLLOUT
#define IOPAUSE_EXCEPT (POLLERR|POLLHUP|POLLNVAL)

extern int iopause (iopause_fd *, unsigned int, struct taia const *, struct taia const *) ;
extern int iopause_stamp (iopause_fd *, unsigned int, struct taia const *, struct taia *) ;
#define iopause_g(x, n, deadline) iopause_stamp(x, n, (deadline), &STAMP)
extern void deepsleepuntil (struct taia const *, struct taia *) ;
#define deepsleepuntil_g(deadline) deepsleepuntil((deadline), &STAMP)

#endif
