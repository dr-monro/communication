#ifndef CRC32CALC_H
#define CRC32CALC_H
#include <stdlib.h>           /* For size_t                 */
#include "sniptype.h"         /* For BYTE, WORD, DWORD      */
#define UPDC32(octet,crc) (crc_32_tab[((crc)\
     ^ ((BYTE)octet)) & 0xff] ^ ((crc) >> 8))

DWORD updateCRC32(unsigned char ch, DWORD crc);
//Boolean_T crc32file(char *name, DWORD *crc, long *charcnt);
DWORD crc32buf(char *buf, size_t len);



#endif // CRC32CALC_H
