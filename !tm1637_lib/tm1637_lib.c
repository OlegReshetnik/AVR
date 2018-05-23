#include <avr/io.h>
#include <util/delay.h>
#include "tm1637_lib.h"
#include "tm1637font.h"

#define TM_CLK_LOW()            (TM_OUT &= ~TM_BIT_CLK)
#define TM_CLK_HIGH()           (TM_OUT |= TM_BIT_CLK)
#define TM_DAT_LOW()            (TM_OUT &= ~TM_BIT_DAT)
#define TM_DAT_HIGH()           (TM_OUT |= TM_BIT_DAT)

// Instructions
#define TM_DATA_CMD             0x40
#define TM_DISP_CTRL            0x80
#define TM_ADDR_CMD             0xC0

// Data command set
#define TM_WRITE_DISP           0x00
#define TM_READ_KEYS            0x02
#define TM_FIXED_ADDR           0x04

// Display control command
#define TM_DISP_PWM_MASK        0x07 // First 3 bits are brightness (PWM controlled)
#define TM_DISP_ENABLE          0x08

#define DELAY_US                3

uint8_t _colon_mask = 0;
uint8_t _byte_colon = 0;

void _port_setup(void)
{
	TM_DDR |= TM_BIT_CLK | TM_BIT_DAT;
	TM_OUT |= TM_BIT_CLK;
}

void _start(void)
{
	TM_CLK_HIGH();
	TM_DAT_HIGH();
	_delay_us(DELAY_US);
	TM_DAT_LOW();
	_delay_us(DELAY_US);
}

void _stop(void)
{
	TM_CLK_LOW();
	_delay_us(DELAY_US);
	TM_CLK_HIGH();
	TM_DAT_LOW();
	_delay_us(DELAY_US);
	TM_DAT_HIGH();
}

void _send(uint8_t b)
{
	for( uint8_t i = 8; i; --i, b >>= 1) // Clock data bits
	{
		TM_CLK_LOW();
		if (b & 1) TM_DAT_HIGH(); else TM_DAT_LOW();
		_delay_us(DELAY_US);
		TM_CLK_HIGH();
		_delay_us(DELAY_US);
	}

	TM_CLK_LOW(); // Clock out ACK bit; not checking if it worked...
	TM_DAT_LOW();
	_delay_us(DELAY_US);
	TM_CLK_HIGH();
	_delay_us(DELAY_US);
}

void _send_cmd(const uint8_t cmd)
{
	_start();
	_send(cmd);
	_stop();
}

void _send_data(const uint8_t addr, const uint8_t data)
{
	_send_cmd(TM_DATA_CMD | TM_FIXED_ADDR);
	_start();
	_send(TM_ADDR_CMD | addr);
	_send(data);
	_stop();
	_delay_us(DELAY_US);
}
// ***************************************

void tm_clear(void)
{
	for( uint8_t a = 0; a != TM1637_DIGITS; ++a ) _send_data( a, 0 );
}

void tm_init( void )
{
	_port_setup();
	_send_cmd(TM_DATA_CMD | TM_WRITE_DISP);
	_send_cmd(TM_DISP_CTRL | TM_DISP_ENABLE | TM_DISP_PWM_MASK);
	tm_clear();
}

void tm_set_bright( const uint8_t brightness )
{
	_send_cmd( TM_DISP_CTRL | TM_DISP_ENABLE | (brightness & TM_DISP_PWM_MASK));
}

void tm_set_byte(const uint8_t position, const uint8_t b)
{
	_send_data( position, b | _colon_mask );
	if( position == COLON_POS ) _byte_colon = b;
}

void tm_set_digit(const uint8_t position, const uint8_t digit)
{
	tm_set_byte( position, pgm_read_byte( &TM_DIGITS[digit & 0xF] ) );
}

void tm_set_char(const uint8_t position, const char ch)
{
	const uint8_t b = TM1637_map_char( ch );

	if( b || ch == ' ' ) tm_set_byte( position, b );

	else if( ch >= 'a' && ch <= 'z' ) tm_set_byte( position, pgm_read_byte( &TM_DIGITS[ch - 'a' + 10] ) );

	else if( ch >= 'A' && ch <= 'Z' ) tm_set_byte( position, pgm_read_byte( &TM_DIGITS[ch - 'A' + 10] ) );

	else if( ch >= '0' && ch <= '9' ) tm_set_byte(position, pgm_read_byte( &TM_DIGITS[ch - '0'] ) );
}

void tm_set_str(const char * value)
{
	uint8_t offset = 0;

	while( *value ) tm_set_char( offset++, *value++ );
}

void tm_colon_on(void)
{
	_colon_mask = TM_DOT;
	_send_data( COLON_POS, _byte_colon | _colon_mask );
}

void tm_colon_off(void)
{
	_colon_mask = 0;
	_send_data( COLON_POS, _byte_colon );
}

void tm_time(uint16_t sec)
{
	uint8_t mm = sec / 60, ss = sec % 60;
	
	_colon_mask = TM_DOT;
	tm_set_digit( 0, mm / 10 );
	tm_set_digit( 1, mm % 10 );
	tm_set_digit( 2, ss / 10 );
	tm_set_digit( 3, ss % 10 );
}
