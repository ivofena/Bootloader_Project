#include "main.h"
#include "Bootloader.h"


FILE *ptr;
uint8_t *bin_buffer;

int main(int argc, char const *argv[])
{
	uint32_t size = 0;
	bool code = false;
	
	//Open the binary file
	ptr = fopen("../bin.bin","rb");  // r for read, b for binary
	//Get size of binary file
	fseek(ptr, 0L, SEEK_END);
	size = ftell(ptr);
	//We need to manually adjust for all the extra not written into RAM ex. headers
	//test file has 5 headers 16 bytes each plus 32byte sha256
	size -= ((5*16)+32);
	//allocate memory to the buffer to write data
	bin_buffer = malloc(size);

	printf("Bin buffer addr: 0x%X\n", bin_buffer );


	code = bootloader_main();
	printf("Err code from bootloader_main : 0x%X\n", code);
	DumpHex(bin_buffer, size);

	return 0;
}



bool flash_read(size_t offset, size_t size_bytes, void* dst){
	//memcpy(dst, (bin_file + offset), size_bytes);
	fseek(ptr, offset, SEEK_SET);
	fread(dst,size_bytes,1,(ptr)); // read 10 bytes to our buffer
	printf("Reading from bin_file: offset: 0x%X, size: 0x%X\n",offset, size_bytes);
	return false;
}


void mem_write(size_t addr, size_t size_bytes, const void* src){
	printf("Address: 0x%X\n", addr);
	uint32_t offset = addr - 0x2002EFD9; //simulating actual memory location
	memcpy(bin_buffer + offset, src, size_bytes);
}


void DumpHex(const void* data, size_t size) {
	char ascii[17];
	size_t i, j;
	ascii[16] = '\0';
	for (i = 0; i < size; ++i) {
		printf("%02X ", ((unsigned char*)data)[i]);
		if (((unsigned char*)data)[i] >= ' ' && ((unsigned char*)data)[i] <= '~') {
			ascii[i % 16] = ((unsigned char*)data)[i];
		} else {
			ascii[i % 16] = '.';
		}
		if ((i+1) % 8 == 0 || i+1 == size) {
			printf(" ");
			if ((i+1) % 16 == 0) {
				printf("|  %s \n", ascii);
			} else if (i+1 == size) {
				ascii[(i+1) % 16] = '\0';
				if ((i+1) % 16 <= 8) {
					printf(" ");
				}
				for (j = (i+1) % 16; j < 16; ++j) {
					printf("   ");
				}
				printf("|  %s \n", ascii);
			}
		}
	}
}