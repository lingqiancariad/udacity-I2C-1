// @linmeng, include necessary header files...
#include <stdbool.h>
#include <stdint.h>
#include "fcn_vdInit_I2C.h"

// External declarations of volatile boolean flags
extern volatile bool UC_b_send_auto_ack;      // Flag to enable auto-acknowledge
extern volatile bool UC_b_enable_i2c;         // Flag to enable I2C engine

// External declarations for configuring I2C pins as open-drain
extern volatile bool UC_b_SDA_open_drain;     // Flag for SDA open-drain configuration
extern volatile bool UC_b_SCL_open_drain;     // Flag for SCL open-drain configuration
extern volatile bool UC_b_SDA_enable_internal_pull_up_resistor;     // Flag for SDA internal pull up resistor configuration
extern volatile bool UC_b_SCL_enable_internal_pull_up_resistor;          // Flag for SCL internal pull up resistor configuration


// External declaration for I2C baud rate register
extern volatile uint32_t UC_u32_I2C_BAUDRATE_REGISTER;  // Register to control the I2C clock rate

// Define the desired baud rate settings
#define SYSTEM_CLOCK_HZ 8000000           // Assume a system clock of 8 MHz
#define I2C_BAUD_RATE 100000              // Target I2C baud rate of 100 kHz

// Function to initialize I2C interface
void fcn_vdInit_I2C(void) {
    // Configure SDA and SCL as open-drain
    UC_b_SDA_open_drain = true;               // Enable SDA open-drain
    UC_b_SCL_open_drain = true;               // Enable SCL open-drain
    UC_b_SDA_enable_internal_pull_up_resistor = false;
    UC_b_SCL_enable_internal_pull_up_resistor = false;

    // Set the baud rate for 100 kHz
    UC_u32_I2C_BAUDRATE_REGISTER = SYSTEM_CLOCK_HZ / (2 * I2C_BAUD_RATE);  // Configure I2C clock rate

    // Enable auto-acknowledge
    UC_b_send_auto_ack = true;                // Enable auto-acknowledgment feature

    // Enable the I2C engine
    UC_b_enable_i2c = true;                   // Enable the I2C module
}