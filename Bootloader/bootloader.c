#include "bootloader.h"


/*Bootloader main Function */
bool bootloader_main(void){

    printf("Bootloader Entered\n");
    //We need a variable to store any error codes returned form functions
    uint32_t err_code = 0x00; //In this example I am assuming that 0x00 is a SUCCESS and non-zero are ERROR 
    //local variable to store ram crc
    uint32_t l_ram_crc = 0x1234;
    //We need to know how much data was in the file to properly calculate the SHA256
    uint32_t l_total_section_bytes = 0x00;
    //we need to store the calculated crc somewhere
    uint32_t calcd_crc = 0x1234;
    //It is assumed the application is located at address 0 in Flash otherwise get from header file
    uint32_t l_start_address = 0x00000000;
    //It would make it simpler to keep a current address variable
    uint32_t l_curr_offset = 0x00000000;
    //Create the local structs for the data we are about to read in
    t_file_header l_main_header;
    t_section_header l_sec_header;
    //Create the local sha256 struct
    mbedtls_sha256_context l_hash_context;
    //Create a temporary data buffer for calculating the hash and to move to ram after
    uint8_t l_data_buff[MAX_BUFFER_SIZE];
    uint32_t l_data_sets_left = 0;
    uint32_t l_bytes = 0;
    //Create a buffer for final SHA256 value
    uint8_t l_sha256sum_calc[32];
    uint8_t l_sha256sum_bin[32];

    /************************************/
    /********HASH FUNCTION INITS*********/
    /************************************/
    //Initialize the hash struct
    mbedtls_sha256_init(&l_hash_context);
    //Init the data buffer
    memset(&l_data_buff, 0, sizeof(l_data_buff));
    //Start the hash routine
    err_code = mbedtls_sha256_starts_ret( &l_hash_context, SHA256 );
    ERR_CHECK(err_code);

    /************************************/
    /****BEGIN MAIN HEADER FLASH READ****/
    /************************************/
    //We need to pull the heeader file from the initial flash location at addr 0x00000000 which is 16 bytes
    err_code = flash_read(0x00, sizeof(l_main_header), &l_main_header);
#ifdef DEBUG
    printf("File header l_File_header.magic_number: 0x%X\n", l_main_header.magic_number);
    printf("File header l_File_header.num_sections: 0x%X\n", l_main_header.num_sections);
    printf("File header l_File_header.crc: 0x%X\n", l_main_header.crc);
    printf("File header calcd_crc: 0x%X\n", calcd_crc);
#endif
    ERR_CHECK(err_code);
    //Update current address
    l_curr_offset += sizeof(l_main_header);
    
    /************************************/
    /*********CHECK MAGIC NUMBER*********/
    /************************************/
    //Once we have all the info from the main header we can now check the magic number then calc the crc
    ERR_CHECK(l_main_header.magic_number != MAGIC_NUMBER)
    /************************************/
    /**********CHECK CRC VALUE***********/
    /************************************/
    //We now calculate the CRC to see if the rest of the data is correct
    calcd_crc = CalculateBufferCRC32(sizeof(l_main_header), 0xFFFFFFFF, (uint8_t*)&l_main_header);
    //Since we are calculating the crc of the header file including the value, it should return 0
    ERR_CHECK(calcd_crc);

    /************************************/
    /*KEEP THE RUNNING HASH CALCULATION */
    /************************************/
    err_code = mbedtls_sha256_update_ret( &l_hash_context, (const uint8_t*)&l_main_header, sizeof(l_main_header));
    ERR_CHECK(err_code);

    /************************************/
    /*****BEGIN SECTION HEADER READ******/
    /************************************/
    //The magic number and the crc check out, we now need to pull each section calculate the crc, match it and if passing store data to RAM location
    //Nested for loops are one way of going through without knowing the limits on the section size or using malloc for each section;
    for(uint32_t sec_cnt = 0; sec_cnt < l_main_header.num_sections; sec_cnt++)
    {
        if(l_curr_offset >= MAX_DEVICE_RAM){
            printf("Memory Overflow, bin file too large to fit in RAM\n Exiting..\n");
            ERR_CHECK(1);
        }
        //Read the first section header
        err_code = flash_read(l_curr_offset, sizeof(l_sec_header), &l_sec_header);
        ERR_CHECK(err_code);

        //Update current address 
        l_curr_offset += sizeof(l_sec_header);

        /************************************/
        /**********CHECK CRC VALUE***********/
        /************************************/
        //We now calculate the CRC to see if the rest of the data is correct
        calcd_crc = CalculateBufferCRC32(sizeof(l_sec_header), 0xFFFFFFFF, (uint8_t*)&l_sec_header);
        //Since we are calculating the crc of the header file including the value, it should return 0
#ifdef DEBUG       
        printf("Section header[%d] l_sec_header.section_size: 0x%X\n",sec_cnt, l_sec_header.section_size);
        printf("Section header[%d] l_sec_header.sec_dest_addr: 0x%X\n",sec_cnt, l_sec_header.sec_dest_addr);
        printf("Section header[%d] l_sec_header.crc: 0x%X\n",sec_cnt, l_sec_header.crc);
        printf("Section header[%d] calcd_crc: 0x%X\n",sec_cnt, calcd_crc);
#endif
        ERR_CHECK(calcd_crc);
        
        /************************************/
        /*KEEP THE RUNNING HASH CALCULATION */
        /************************************/
        err_code = mbedtls_sha256_update_ret( &l_hash_context, (const uint8_t*)&l_sec_header, sizeof(l_sec_header));
        ERR_CHECK(err_code);

        /************************************/
        /**LOAD DATA FROM SECTION IN BUFFER**/
        /************************************/
        //We need to read multiple times and store to ram if section is larger than the data buffer
        l_data_sets_left = CEILING_DIV(l_sec_header.section_size , MAX_BUFFER_SIZE);
        
        while(l_sec_header.section_size > 0)
        {
            l_bytes = MIN(l_sec_header.section_size,MAX_BUFFER_SIZE);
            
            err_code = flash_read(l_curr_offset, l_bytes , l_data_buff);
            ERR_CHECK(err_code);


            /************************************/
            /*KEEP THE RUNNING HASH CALCULATION */
            /************************************/
            err_code = mbedtls_sha256_update_ret(&l_hash_context, (const uint8_t*)l_data_buff, l_bytes);
            ERR_CHECK(err_code);

            /************************************/
            /**********LOAD INTO RAM*************/
            /************************************/
            if(l_sec_header.sec_dest_addr != 0x00){
                mem_write(l_sec_header.sec_dest_addr, ALIGN_TO(sizeof(uint32_t),l_bytes), l_data_buff);
            }

            l_sec_header.section_size   -= l_bytes;     //Decrement size of section thats left
            l_sec_header.sec_dest_addr  += l_bytes;     //Increment destination address
            l_curr_offset              += l_bytes;     //Increment current memory location
            
        }
#ifdef VERIFY_RAM
        /************************************/
        /*********VERIFY RAM DATA************/
        /************************************/
        //We now calculate the CRC to see if the rest of the data is correct
        calcd_crc = CalculateBufferCRC32(l_sec_header.section_size, 0xFFFFFFFF, (uint8_t*)l_data_buff);
        l_ram_crc = CalculateBufferCRC32(l_sec_header.section_size, 0xFFFFFFFF, (uint8_t*)&l_sec_header.sec_dest_addr);
        //Since we are calculating the crc of the header file including the value, it should return 0
        ERR_CHECK(calcd_crc != l_ram_crc)
#endif
        /************************************/
        /***********NEXT SECTION*************/
        /************************************/

    }
    /************************************/
    /************LOAD SHA256*************/
    /************************************/ 
    //Final load from flash is the 32 byte SHA256 value
    err_code = flash_read(l_curr_offset, sizeof(l_sha256sum_bin), l_sha256sum_bin);
    ERR_CHECK(err_code);
    /************************************/
    /************CALC SHA256*************/
    /************************************/    
    err_code = mbedtls_sha256_finish_ret( &l_hash_context, l_sha256sum_calc );
    ERR_CHECK(err_code);
    /************************************/
    /**********COMPARE SHA256************/
    /************************************/
#ifdef DEBUG  
    printf("SHAbin: \n");
    for(int i = 0; i< 32; i++){
        printf("0x%X ",l_sha256sum_bin[i]);
    }
    printf("\n");
    printf("SHAcalc: \n");
    for(int i = 0; i< 32; i++){
        printf("0x%X ",l_sha256sum_calc[i]);
    }
    printf("\n");
#endif
    err_code = memcmp(l_sha256sum_bin, l_sha256sum_calc, sizeof(l_sha256sum_bin));
    ERR_CHECK(err_code);
    /************************************/
    /************FINAL STEPS*************/
    /************************************/  
    // Return FALSE signifying the application has been loaded into RAM
    printf("Bootloader succesfully loaded binary into RAM\n");
    return false;
}


