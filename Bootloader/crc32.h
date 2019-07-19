#ifndef CRC32_H__
#define CRC32_H__

#include "bootloader.h"

#define CRC32_POLYNOMIAL 0xEDB88320


uint32_t CRC32Value(uint32_t c);
uint32_t CalculateBufferCRC32(uint32_t length, uint32_t crc, uint8_t *buffer);


#endif