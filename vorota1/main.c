/*
Проект Ворота.
Attiny13a, 9600000

#ifndef F_CPU
	#define F_CPU	9600000UL
#endif
*/

#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

#define CONTROL_PULSE	150		// длина "нажатия" кнопок milliseconds
#define ONE_OPEN_DELAY	200		// ms
#define VOR_OPEN_TIME	( 13 * ( 1000 / ONE_OPEN_DELAY ) ) // gate open time, 20 sec
#define VOR_CLOSE_TIME	( 3 * ( 1000 / ONE_OPEN_DELAY ) ) // gate close time, 3 sec


#define BUTTON_DELAY	5	// 5 milliseconds
#define DEBOUNCE		( 10 / BUTTON_DELAY ) // (ms)
#define LONG_PRESS		( 500 / BUTTON_DELAY ) // long time (ms)
#define OFF_CNT			( 5000 / BUTTON_DELAY ) // off time (ms)
#define GS				1	// short press code
#define GL				2	// long press code


#define BUTTON_IN_PORT		PORTB
#define BUTTON_IN_PIN		PINB
#define BUTTON_IN_DDR		DDRB
#define BUTTON_IN			1

#define BUTTON_OUT_PORT		PORTB
#define BUTTON_OUT_PIN		PINB
#define BUTTON_OUT_DDR		DDRB
#define BUTTON_OUT			0

#define CONTROL_OPEN_PORT	PORTB
#define CONTROL_OPEN_DDR	DDRB
#define OPEN_SG				3

#define CONTROL_CLOSE_PORT	PORTB
#define CONTROL_CLOSE_DDR	DDRB
#define CLOSE_SG			4

#define OUT_PRESS ( ( BUTTON_OUT_PIN & ( 1 << BUTTON_OUT ) ) == 0 )
#define IN_PRESS  ( ( BUTTON_IN_PIN & ( 1 << BUTTON_IN ) ) == 0 )

const uint8_t pass[] PROGMEM = { GL, GS, GS, GL, GS, GS, 0 }; // Tsss! Password :-)

void do_open( void )
{
	CONTROL_OPEN_PORT |= ( 1 << OPEN_SG ); // door open pulse
	_delay_ms( CONTROL_PULSE );
	CONTROL_OPEN_PORT &= ~( 1 << OPEN_SG );

	uint8_t del = VOR_OPEN_TIME;
	while( del -- ) _delay_ms( ONE_OPEN_DELAY ); // wait open
}

void do_close( void )
{
	CONTROL_CLOSE_PORT |= ( 1 << CLOSE_SG ); // door close pulse
	_delay_ms( CONTROL_PULSE );
	CONTROL_CLOSE_PORT &= ~( 1 << CLOSE_SG );

	uint8_t del = VOR_CLOSE_TIME;
	while( del -- ) _delay_ms( ONE_OPEN_DELAY ); // wait to close
}

void io_init( void )
{
	CONTROL_OPEN_DDR |= 1 << OPEN_SG; // set control pins to output
	CONTROL_CLOSE_DDR |= 1 << CLOSE_SG;

	BUTTON_IN_DDR &= ~( 1 << BUTTON_IN ); // set buttons pins to input
	BUTTON_OUT_DDR &= ~( 1 << BUTTON_OUT );

	BUTTON_IN_PORT |= 1 << BUTTON_IN; // pull up input pins
	BUTTON_OUT_PORT |= 1 << BUTTON_OUT;
}

int main( void )
{
	uint8_t in_cnt = 0, out_cnt = 0, in_deb = 0, out_deb = 0, i = 0;
	uint16_t off_cnt = 0;

	io_init();

	for(;;)
	{
		_delay_ms( BUTTON_DELAY );

		if( IN_PRESS )
		{
			if( in_cnt < LONG_PRESS ) in_cnt++;
			off_cnt = 0;
		}
		else if( in_cnt )
		{
			if( ++in_deb > DEBOUNCE )
			{
				in_deb = 0;
				
				if( in_cnt == LONG_PRESS )
				{
					do_open();
					while( !IN_PRESS && !OUT_PRESS );
					do_close();
				}
				else
				{
					do_open();
					do_close();
				}
				
				in_cnt = 0;
			}
		}

		if( OUT_PRESS ) // press out button, check password
		{
			if( out_cnt < LONG_PRESS ) out_cnt++;
			off_cnt = 0;
		}
		else if( out_cnt )
		{
			if( ++out_deb > DEBOUNCE )
			{
				out_deb = 0;
				
				if( out_cnt == LONG_PRESS )
				{
					if( pgm_read_byte( &pass[ i++ ] ) != GL ) i = 0;
				}
				else
				{
					if( pgm_read_byte( &pass[ i++ ] ) != GS ) i = 0;
				}
				
				if( ( i > 0 ) && ( pgm_read_byte( &pass[ i ] ) == 0 ) )
				{
					i = 0;
					do_open();
					do_close();
				}
				
				out_cnt = 0;
			}
		}
		
		if( ++off_cnt > OFF_CNT ) // idle
		{
			i = 0; off_cnt = 0; // reset counters
		}
	}
}
