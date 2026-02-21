#ifndef FCN_STSENDDATA_H
#define FCN_STSENDDATA_H

#include <stdint.h>
#include "i2c.h"

/* Function prototype to allow other .c files 
 * to call the send data function.
 */
STATUS fcn_stSendData(uint8_t u8_secondary_address, uint8_t u8_secondary_subaddress, uint8_t* pu8_dataArrayToSend, uint8_t u8_length);

#endif /* FCN_STSENDDATA_H */