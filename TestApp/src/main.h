#ifndef MAIN_H__
#define MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

bool flash_read(size_t offset, size_t size_bytes, void* dst);
void mem_write(size_t addr, size_t size_bytes, const void* src);
void DumpHex(const void* data, size_t size);

#endif
