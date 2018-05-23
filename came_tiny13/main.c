#define F_CPU 9600000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define SEND				1
#define SEND_DDR			DDRB
#define SEND_PORT			PORTB

#define LED					2
#define LED_DDR				DDRB
#define LED_PORT			PORTB

#define TT					200		// protocol interval

void send_bit( uint8_t b )
{
	if( b == 1 )					// send "1"
	{
		SEND_PORT |= (1 << SEND);
		_delay_us( TT );
		SEND_PORT &= ~(1 << SEND);
		_delay_us( TT*2 );
	}
	else							// send "0"
	{
		SEND_PORT |= (1 << SEND);
		_delay_us( TT*2 );
		SEND_PORT &= ~(1 << SEND);
		_delay_us( TT );
	}
}

int main(void)
{
	SEND_DDR |= (1 << SEND);		// send pin to output and set to 0
	SEND_PORT &= ~(1 << SEND);

	LED_DDR |= (1 << LED);			// led pin to output and set to 0
	LED_PORT &= ~(1 << LED);

	LED_PORT |= (1 << LED);
	//void send_came( void )
	{
		uint8_t i, j;

		unsigned long c1 = 3921214973UL;
		unsigned long c2 = 8346169UL;
		// cli();

		for( j = 0; j < 4; j++ )		// repeat 4
		{
			for( int i = 0; i < 48; i++ ) // send 48 synchro pulse
			{
				SEND_PORT |= (1 << SEND);
				_delay_us( TT );
				SEND_PORT &= ~(1 << SEND);
				_delay_us( TT );
			}

			SEND_PORT |= (1 << SEND);	// send start
			_delay_us( TT*4 );
			SEND_PORT &= ~(1 << SEND);
			_delay_us( TT );

			c2 = (c2 << 1);				// dirty hack,add last "0": we scan 55 bits, but protocol have 56 ( 32 + 24 )!
			for( i = 32; i > 0; i-- ) send_bit( (c1 >> (i-1)) & 1 );
			for( i = 24; i > 0; i-- ) send_bit( (c2 >> (i-1)) & 1 );

			_delay_us( TT*36 );			// end pause
		}
	}

	//send_came();
	LED_PORT &= ~(1 << LED);

    _delay_ms( 3000 );
	while (1)
    {
		LED_PORT |= (1 << LED);
		_delay_ms( 500 );
		LED_PORT &= ~(1 << LED);
		_delay_ms( 500 );
    }
}
