#include "ad9833.h"

void spi_init(void)
{
	AD_FSYNC_DDR |= 1 << AD_FSYNC;
	AD_SPI_DDR |= ( 1 << AD_SCK ) | ( 1 << AD_MOSI );	// set SCK,MOSI,Fsync as output

	AD_FSYNC_PORT |= 1 << AD_FSYNC;
	AD_SPI_PORT |= 1 << AD_SCK;							// SCK and Fsync high

	SPCR  = ( 1<< SPE ) | ( 1 << MSTR )| ( 1 << CPOL );	// Enable SPI // Set Master mode // Set clk to inv.

	// SPCR |= 1 << SPR0;			//	Clk speed = fck/4, SPR0,SPR1 = 0,0 // uncomment for fck/16
}

void spi_write16(uint16_t data)				// 	send a 16bit word and use fsync
{
	uint8_t MSdata = (data >> 8) & 0x00FF; 	//filter out MS
	uint8_t LSdata = data & 0x00FF;			//filter out LS

	AD_FSYNC_PORT &= ~( 1 << AD_FSYNC );	// 	Fsync Low --> begin frame
	_delay_us(1);

	SPDR = MSdata;							// 	send First 8 MS of data
	while( !( SPSR & ( 1 << SPIF ) ) );		//	while busy

	SPDR = LSdata;							// 	send Last 8 LS of data
	while( !( SPSR & ( 1 << SPIF ) ) );		//	while busy

	AD_FSYNC_PORT |= 1 << AD_FSYNC;			// 	Fsync High --> End of frame
}

void ad9833_reset(void)
{
  spi_write16(0x100);   // Write '1' to AD9833 Control register bit D8.
  _delay_us(10);
}

void ad9833_init(void)
{
	spi_init();
	ad9833_reset();
}

void ad9833_setfreq( uint32_t freq, uint16_t form) // freq * 100, float:12.56 -> uint32_t:1256
{
	if( freq == 0 ) ad9833_reset();
	else
	{
		uint32_t dds_word = (uint32_t)(  ( (uint64_t)freq * (uint64_t)1073741824 + (uint64_t)5000000000 ) / (uint64_t)10000000000  );	// freq * ( 2^28 / 25 000 000 )

		uint16_t MSB = (dds_word >> 14) & 0x3FFF;	//Only lower 14 bits are used for data
		uint16_t LSB = dds_word & 0x3FFF;

		//Set control bits 15 ande 14 to 0 and 1, respectively, for frequency register 0
		LSB |= 0x4000;
		MSB |= 0x4000;

		spi_write16(0x2100);
		spi_write16(LSB);						// Write lower 16 bits to AD9833 registers
		spi_write16(MSB);						// Write upper 16 bits to AD9833 registers.
		spi_write16(0xC000);					// Phase register
		spi_write16(form);					// Exit & Reset to SINE, SQUARE or TRIANGLE
	}
}
