#include"crc32.h"


uint32_t CRC32Value(uint32_t c)
{
    int i;
    for (i=8;i>0;i--)
    {
        if (c & 1)
            c = (c >> 1)^CRC32_POLYNOMIAL;
        else
            c >>= 1;
    }
    return c;
} 

uint32_t CalculateBufferCRC32(uint32_t length, uint32_t crc, uint8_t *buffer)
{
    uint8_t datum;

    while (length-- != 0)
    {
        datum = *buffer++;
        crc = ((crc >> 8) & 0x00FFFFFFL)^CRC32Value((crc^datum)&0xff);
    }
    return (crc);
}