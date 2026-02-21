#include <stdint.h>
#include "fcn_vdInit_I2C.h"
#include "fcn_stSendData.h"
#include "fcn_stReadData.h"
#include "i2c.h"

// Addresses
#define UC_u8_ad_I2C_RD         0x16
#define UC_u8_ad_sb_I2C_RD      0x2B
#define UC_u8_ad_I2C_SD         0x17
#define UC_u8_ad_sb_I2C_SD      0x1A

// Global variables for data transmission
#define I2C_MEMORY_DATA_LENGTH (8) 
uint8_t Global_au8_DataReceived[I2C_MEMORY_DATA_LENGTH] = {0};
//uint8_t Global_au8_DataToSend[I2C_MEMORY_DATA_LENGTH] = {10, 20, 30, 40, 50, 60, 70, 80};

int main() {
    // Initialize I2C
    fcn_vdInit_I2C();  

    // Read and Send on I2C
    if (fcn_stReadData(UC_u8_ad_I2C_RD, UC_u8_ad_sb_I2C_RD, Global_au8_DataReceived, I2C_MEMORY_DATA_LENGTH) == STATUS_OK) {
        if (fcn_stSendData(UC_u8_ad_I2C_SD, UC_u8_ad_sb_I2C_SD, Global_au8_DataReceived, I2C_MEMORY_DATA_LENGTH) == STATUS_OK) {
            return 0;
        } else {
            return 1;
        }
    } else {
        return 1;
    }

    return 0;
}

