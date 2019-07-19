#ifndef BOOTLOADER_H__
#define BOOTLOADER_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
//ToDo: Add include for crc 
#include "crc32.h"
//ToDo: Add include for SHA256
#include "sha256.h"

/*#defines & macros*/
#define ALIGN_TO(algn, num) (((num) - 1) + (algn) - (((num) - 1) % (algn)))
#define CEILING_DIV(a, b)  (((a) + (b) - 1) / (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ERR_CHECK(a) \
                        if(a){\
                            printf("Error Code Received: Function : %s Line: %d ERR_CODE: 0x%X\n", __func__, __LINE__, a);\
                            return true;\
                        }else{}
#define MBEDTLS_SHA256_C
#define MAX_BUFFER_SIZE             512
#define MAX_DEVICE_RAM              64000
#define SHA256                      0
#define MAGIC_NUMBER                0xB004100D

//Change to 1 to display debug information
#if 0
#define DEBUG
#endif

typedef struct file_header
{
    uint32_t magic_number;
    uint32_t num_sections;
    uint32_t entry_point;
    uint32_t crc;
}
t_file_header;

typedef struct section_header
{
    uint32_t section_size;
    uint32_t sec_dest_addr;
    uint32_t flags;
    uint32_t crc;
}
t_section_header;

/*FUNCTION DECLARATIONS */
//Extern functions
extern bool flash_read(size_t , size_t , void* );
extern void mem_write(size_t , size_t , const void* );
//Local Functions
bool bootloader_main(void);



#endif