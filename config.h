#define F_CPU 8000000UL      // Частота работы ЦП
#define BAUD 38400           // Скорость UART
#define F_I2C 100000UL       // Частота шины I2C

#define BYTETOBINARYPATTERN "%d%d%d%d%d%d%d%d"
#define BYTETOBINARY(byte) (byte & 0x80 ? 1 : 0), (byte & 0x40 ? 1 : 0), (byte & 0x20 ? 1 : 0), (byte & 0x10 ? 1 : 0), (byte & 0x08 ? 1 : 0), (byte & 0x04 ? 1 : 0), (byte & 0x02 ? 1 : 0), (byte & 0x01 ? 1 : 0) 
