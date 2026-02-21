#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "udacity_microcontroller.h"  // Include MCU specific definitions
#include "i2c.h" // enum STATUS

#define I2C_WRITE_REQ_BIT 0

// Function to send data to I2C bus
STATUS fcn_stSendData(uint8_t u8_secondary_address, uint8_t u8_secondary_subaddress, uint8_t* pu8_dataArrayToSend, uint8_t u8_length) {
    if (pu8_dataArrayToSend == NULL || u8_length == 0) {
        return STATUS_ERROR;
    }

    UC_b_start_session = true;
    while (!UC_b_start_session_done);

    UC_u8_Tx_byte = (u8_secondary_address << 1) | I2C_WRITE_REQ_BIT;
    while (!UC_b_Tx_done);
    UC_b_Tx_done = false;

    UC_u8_Tx_byte = u8_secondary_subaddress;
    while (!UC_b_Tx_done);
    UC_b_Tx_done = false;

    for (uint8_t u8_index = 0; u8_index < u8_length; u8_index++) {
        UC_u8_Tx_byte = pu8_dataArrayToSend[u8_index];
        while (!UC_b_Tx_done);
        UC_b_Tx_done = false;
    }

    UC_b_stop_session = true;
    while (!UC_b_stop_session_done);
    return STATUS_OK;
}