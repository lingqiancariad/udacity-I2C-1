#ifndef FCN_STREADDATA_H
#define FCN_STREADDATA_H

#include <stdint.h>
#include "i2c.h"

/* Function prototype to allow other .c files 
 * to call the read data function.
 */
STATUS fcn_stReadData(uint8_t au8_secondary_address, uint8_t u8_secondary_subaddress, uint8_t* pu8_allocatedArrayToFill, uint8_t u8_length);

#endif /* FCN_STREADDATA_H */