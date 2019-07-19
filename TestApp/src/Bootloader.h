#ifndef BOOTLOADER_H__
#define BOOTLOADER_H__
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
//Extern functions
// extern bool flash_read(size_t , size_t , void* );
// extern void mem_write(size_t , size_t , const void* );
//Local Functions

extern bool bootloader_main(void);

#endif