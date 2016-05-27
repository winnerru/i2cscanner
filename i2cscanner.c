#include "config.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include "twi.h"
#include "usart.h"


int main() {
    uint8_t result, addr;

    // Настраиваем все пины на вход
    DDRB  = 0b00000000;
    DDRC  = 0b00000000;
    DDRD  = 0b00000000;
    // Активируем внутренние резисторы pull-up на всех пинах
    PORTB = 0b11111111;
    PORTC = 0b11111111;
    PORTD = 0b11111111;

    SetUSARTAsTerm();

    printf("Starting...\n");

    printf("Initializing I2C interface...");

    TWIInit();

    printf("Done\n");

    for (addr = 0; addr <= 0x7f; addr++) {
        printf("Scanning address 0x%02x (0b"BYTETOBINARYPATTERN")... ", addr, BYTETOBINARY(addr));
        twi(TWI_START);
        // Выставляем адрес на шину + бит записи
        TWDR = (addr << 1) | 0;
        result = twi(TWI_RECEIVE_ACK);
        twi(TWI_STOP);
        printf("result code is 0x%02x", result);
        if (result == 0x18) {
            // Устройство отозвалось
            printf(" - device found. Full address is 0x%02x/0x%02x (R/W)", (addr << 1) | 1, (addr <<1));
        }
        printf("\n");
    }

    printf ("Terminating!\n");

    return 0;

}
