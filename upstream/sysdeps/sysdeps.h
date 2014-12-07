/* ISC license. */

#ifndef SYSDEPS_H
#define SYSDEPS_H

#undef HASDEVTCP
/* sysdep: -devtcp */
#undef HASDEVPTC
/* sysdep: -devptc */
#define HASDEVPTMX
/* sysdep: +devptmx */
#define HASDEVRANDOM
/* sysdep: +devrandom */
#define HASDEVURANDOM
/* sysdep: +devurandom */
#define HASDIRENT
/* sysdep: +dirent */
#define HASEPROTO
/* sysdep: +eproto */
#define HASFLOCK
/* sysdep: +flock */
#define HASGETPT
/* sysdep: +getpt */
#undef HASGETPEEREID
/* sysdep: -getpeereid */
#define HASSO_PEERCRED
/* sysdep: +SO_PEERCRED */
#define HASMALLOC0
/* sysdep: +malloc0 */
#define HASMKFIFO
/* sysdep: +mkfifo */
#undef HASNPBG1
/* sysdep: -npbg1 */
#define HASPOLLH
/* sysdep: +pollh */
#define HASSYSPOLLH
/* sysdep: +syspollh */
#define HASPOLL
/* sysdep: +poll */
#define HASSIGACTION
/* sysdep: +sigaction */
#define HASSIGPROCMASK
/* sysdep: +sigprocmask */
#define HASPPOLL
/* sysdep: +ppoll */
#define HASSETGROUPS
/* sysdep: +setgroups */
#define HASSYSSELECT
/* sysdep: +sysselect */
#define HASREVOKE
/* sysdep: +revoke */
#define HASWAITPID
/* sysdep: +waitpid */
#undef HASULONG32
/* sysdep: -ulong32 */
#define HASULONG64
#define SKALIBS_SIZEOFULONG 8
#define SKALIBS_ULONG_BITS 64
/* sysdep: +ulong64 */
/* sysdep: sizeofulong: 8 */
#undef HASUTILH
/* sysdep: -utilh */
#undef HASLIBUTILH
/* sysdep: -libutilh */
#define HASPTYH
/* sysdep: +ptyh */
#undef HAS_GETPTY
/* sysdep: -_getpty */
#define HASOPENPTY
/* sysdep: +openpty */
#undef HASUNIXH
/* sysdep: -unixh */
#define HASSTREAMS
/* sysdep: +streams */
#define HASLITTLE_ENDIAN
/* sysdep: +little_endian */
#undef HASBIG_ENDIAN
/* sysdep: -big_endian */
#undef HASEGD
/* sysdep: -egd */
#undef HASTIOCREMOTE
/* sysdep: -tiocremote */
#define HASPOSIXGLOB
/* sysdep: +posixglob */
#define HASSTDINTH
/* sysdep: +stdinth */
#define HASINTTYPESH
/* sysdep: +inttypesh */
#define HASUINT64T
/* sysdep: +uint64t */
#define HASOPENAT
/* sysdep: +openat */
#define HASRDTSC
/* sysdep: +rdtsc */
#undef HASGETHRTIME
/* sysdep: -gethrtime */
#define HASSENDFILE
/* sysdep: +sendfile */
#define HASSPLICE
/* sysdep: +splice */
#define HASPIPE2
/* sysdep: +pipe2 */
#define HASACCEPT4
/* sysdep: +accept4 */
#define HASGETTIMEOFDAY
/* sysdep: +gettimeofday */
#define HASSETTIMEOFDAY
/* sysdep: +settimeofday */
#define HASEVENTFD
/* sysdep: +eventfd */
#define HASSIGNALFD
/* sysdep: +signalfd */
#define HASREGEX
/* sysdep: +regex */
#define HASCLOCKRT
/* sysdep: +clockrt */
#define HASCLOCKMON
/* sysdep: +clockmon */
#define HASIPV6
/* sysdep: +ipv6 */
#undef HASANCILAUTOCLOSE
/* sysdep: -ancilautoclose */
#define SKALIBS_SIZEOFUSHORT 2
#define SKALIBS_USHORT_BITS 16
/* sysdep: sizeofushort: 2 */
#define SKALIBS_SIZEOFUINT 4
#define SKALIBS_UINT_BITS 32
/* sysdep: sizeofuint: 4 */
#define SKALIBS_SIZEOFGID 4
#define SKALIBS_GID_BITS 32
/* sysdep: sizeofgid: 4 */
#define SKALIBS_SIZEOFTIME 8
#define SKALIBS_TIME_BITS 64
/* sysdep: sizeoftime: 8 */

#endif
