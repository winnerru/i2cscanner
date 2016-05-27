#include <stdint.h>
#include <avr/io.h>
#include "config.h"

#define TWI_START           0
#define TWI_RESTART         1
#define TWI_STOP            2
#define TWI_TRANSMIT        3
#define TWI_RECEIVE_ACK     4
#define TWI_RECEIVE_NACK    5

#define TWBR_VALUE (((F_CPU)/(F_I2C)-16)/2)

#if ((TWBR_VALUE > 255) || (TWBR_VALUE == 0))
    #error "TWBR value is not correct"
#endif

uint8_t twi(uint8_t action);
void TWIInit();