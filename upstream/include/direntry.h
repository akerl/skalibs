/* ISC license. */

#ifndef DIRENTRY_H
#define DIRENTRY_H

#include <sys/types.h>
#include <dirent.h>
#define direntry struct dirent

extern int dir_close (DIR *) ;

#endif
