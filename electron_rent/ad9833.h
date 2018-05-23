#ifndef ad9833_h
#define ad9833_h

#include <avr/io.h>
#include <util/delay.h>
#include <inttypes.h>

#define AD_FSYNC		PB2		// Arduino D10 SS
#define AD_SCK			PB5		// Arduino D13
#define AD_MOSI			PB3		// Arduino D11
#define AD_FSYNC_PORT	PORTB
#define AD_FSYNC_DDR	DDRB
#define AD_SPI_PORT		PORTB
#define AD_SPI_DDR		DDRB

void spi_init(void);
void spi_write16(uint16_t data);	// 	send a 16bit word and use fsync

#define SIN 0x2000	// sinus
#define SQR 0x2028	// meandr
#define TRG 0x2002	// triangle

void ad9833_init(void);	// init ad9833 module

void ad9833_reset(void);

void ad9833_setfreq( uint32_t freq, uint16_t form );

#endif
