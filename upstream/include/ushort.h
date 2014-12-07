/* ISC license. */

#ifndef USHORT_H
#define USHORT_H

#include "uint16.h"

#define USHORT_PACK 2
#define ushort_pack uint16_pack
#define ushort_pack_big uint16_pack_big
#define ushort_unpack(s, u) uint16_unpack(s, (uint16 *)(char *)(u))
#define ushort_unpack_big(s, u) uint16_unpack_big(s, (uint16 *)(char *)(u))

#define ushort_reverse uint16_reverse
#define ushort_big_endian uint16_big_endian
#define ushort_little_endian uint16_little_endian

#define USHORT_FMT UINT16_FMT
#define USHORT_OFMT UINT16_OFMT
#define USHORT_XFMT UINT16_XFMT
#define USHORT_BFMT UINT16_BFMT

#define ushort_fmt_base uint16_fmt_base
#define ushort0_fmt_base uint160_fmt_base
#define ushort_fmt uint16_fmt
#define ushort0_fmt uint160_fmt
#define ushort_ofmt uint16_ofmt
#define ushort0_ofmt uint160_ofmt
#define ushort_xfmt uint16_xfmt
#define ushort0_xfmt uint160_xfmt
#define ushort_bfmt uint16_bfmt
#define ushort0_bfmt uint160_bfmt

#define ushort_fmtlist(s, tab, n) uint16_fmtlist(s, tab, n)

#define ushort_scan_base(s, u, b) uint16_scan_base(s, (uint16 *)(char *)(u), b)
#define ushort0_scan_base(s, u, b) uint160_scan_base(s, (uint16 *)(char *)(u), b)

#define ushort_scanlist(tab, max, s, num) uint16_scanlist(tab, max, s, num)
#define ushort_scan(s, u) ushort_scan_base(s, (u), 10)
#define ushort0_scan(s, u) ushort0_scan_base(s, (u), 10)
#define ushort_oscan(s, u) ushort_scan_base(s, (u), 8)
#define ushort0_oscan(s, u) ushort0_scan_base(s, (u), 8)
#define ushort_xscan(s, u) ushort_scan_base(s, (u), 16)
#define ushort0_xscan(s, u) ushort0_scan_base(s, (u), 16)
#define ushort_bscan(s, u) ushort_scan_base(s, (u), 2)
#define ushort0_bscan(s, u) ushort0_scan_base(s, (u), 2)

#endif