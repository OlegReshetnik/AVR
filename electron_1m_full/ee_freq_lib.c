#include "ee_freq_lib.h"

uint16_t _ee_names[ EE_MAX_N + 1 ];

uint8_t get_b( void )
{
	uint8_t b1, b2;

	serial_tx( EE_OK );
	while( !serial_rx_ready() );
	b1 = (uint8_t)serial_rx();

	serial_tx( EE_OK );
	while( !serial_rx_ready() );
	b2 = (uint8_t)serial_rx();

	return ( (b1 << 4) | b2 );
}

uint16_t ee_max_pointer( void )
{
	uint16_t i = 0;
	uint8_t bb;

	while( ( i < EE_MAX ) && ( bb = eeprom_read_byte( (const uint8_t *)i ) ) )
	{
		i += (EE_FREQS + (uint16_t)bb * EE_FREQ_SIZE);
	}

	return i;
}

uint16_t * ee_all_names( void )
{
	uint16_t i = 0, j = 0;
	uint8_t bb;

	while( ( i < EE_MAX ) && ( bb = eeprom_read_byte( (const uint8_t *)i ) ) )
	{
		_ee_names[ j++ ] = i + 1;
		i += (EE_FREQS + (uint16_t)bb * EE_FREQ_SIZE);
	}

	_ee_names[ j ] = 0;

	return &_ee_names[0];
}

uint16_t find_n( uint8_t n )
{
	uint16_t i = 0;
	uint8_t j = 0, bb;

	while( ( bb = eeprom_read_byte( (const uint8_t *)i ) ) )
	{
		if( j == n ) return i;
		j++;
		i += (EE_FREQS + (uint16_t)bb * EE_FREQ_SIZE);
		if( i > (EE_MAX-1) ) return 0;
	}
	return 0;
}

uint8_t * ee_name( uint8_t prog_number )
{
	return (uint8_t *) ( find_n( prog_number ) + EE_NAME );
}

uint16_t ee_sec( uint8_t prog_number )
{
	return eeprom_read_word( (const uint16_t *) ( find_n( prog_number ) + EE_SECONDS ) );
}

uint8_t ee_num( uint8_t prog_number )
{
	return eeprom_read_byte( (const uint8_t *) ( find_n( prog_number ) + EE_CNT ) );
}

uint32_t * ee_freqs( uint8_t prog_number )
{
	return (uint32_t *) ( find_n( prog_number ) + EE_FREQS );
}

uint8_t ee_count( uint8_t prog_number )
{
	return eeprom_read_byte( (const uint8_t *) ( find_n( prog_number ) + EE_COUNT ) );
}

void ee_dec_count( uint8_t prog_number )
{
	uint8_t * p, b;
	p = (uint8_t *) ( find_n( prog_number ) + EE_COUNT );
	b = eeprom_read_byte( p );
	if( b > 0 ) b--;
	eeprom_write_byte( p, b );
}


void ee_pc_communicate( void ) // return 0 if No communicate
{
	uint8_t bb, nums, i;
	uint8_t * pp = (uint8_t *)ee_max_pointer();

	serial_init();

	serial_tx( EE_OK ); // ask PC
	_delay_ms( 500 );

	if( serial_rx_ready() )
	{
		if( serial_rx() == EE_OK )
		{
			bb = get_b(); // get command
			if( bb == EE_SAVE )
			{
				nums = get_b();
				if( ( (int)nums * EE_FREQ_SIZE + EE_FREQS ) > ( EE_MAX - (int)pp ) ) serial_tx( EE_ERR );
				else
				{
					serial_tx( EE_OK );
					eeprom_write_byte( pp++, nums ); // N freqs
					for( i=0; i<15; i++ ) eeprom_write_byte( pp++, get_b() ); // Name

					eeprom_write_byte( pp++, get_b() ); // time
					eeprom_write_byte( pp++, get_b() );

					eeprom_write_byte( pp++, get_b() ); // play counter

					for( i=0; i<nums; i++ )
					{
						eeprom_write_byte( pp++, get_b() ); // Freqs
						eeprom_write_byte( pp++, get_b() );
						eeprom_write_byte( pp++, get_b() );
						eeprom_write_byte( pp++, get_b() );
					}

					eeprom_write_byte( pp, get_b() ); // 0 - end of sequence - see ee_max_pointer();
					eeprom_write_byte( pp++, get_b() );
				}
			}
			else if( bb == EE_CLEAR ) eeprom_write_byte( (uint8_t *)(0), 0 );
		}
	}
	serial_disable();
}
