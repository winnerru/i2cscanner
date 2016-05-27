#include "usart.h"
#include <avr/io.h>
#include <stdio.h>

void USARTInit() {
    UBRRH = UBRRH_VALUE;
    UBRRL = UBRRL_VALUE;
    UCSRA &= ~(1 << U2X);
    // Разрешение работы передатчика
    UCSRB=(1<<TXEN);
    //Установка формата посылки: 8 бит данных, 1 стоп-бит
    UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
}

static int USARTPutChar(char c, FILE *stream) {
    if (c == '\n') {
        USARTPutChar('\r', stream);
    }
    //ждем окончания передачи предыдущего байта
    while ((UCSRA & (1 << UDRE)) == 0);
    UDR = c;
    return 0;
}

static FILE USARTOut = FDEV_SETUP_STREAM(USARTPutChar, NULL, _FDEV_SETUP_WRITE);

void SetUSARTAsTerm() {
    USARTInit();
    stdout = &USARTOut;
}
