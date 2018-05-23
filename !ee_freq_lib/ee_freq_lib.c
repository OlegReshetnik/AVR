#include "ee_freq_lib.h"

uint16_t _ee_names[ EE_N + 1 ];

int16_t get_b( void )
{
	if( !serial_tx( AVR_GET ); ) return -1;
	return serial_rx();
}

uint8_t put_b( uint8_t b )
{
	if( serial_rx() != PC_GET ) return 0;
	return serial_tx( b );
}

uint16_t ee_max_pointer( void )
{
	uint16_t i = 0;
	uint8_t bb;

	while( ( bb = eeprom_read_byte( (const uint8_t *)i ) ) )
	{
		if( i > 1022 ) return 0;
		i += 18 + bb * 4;
	}

	return i;
}

uint16_t * ee_all_names( void )
{
	uint16_t i = 0, j = 0;
	uint8_t bb;

	while( ( bb = eeprom_read_byte( (const uint8_t *)i ) ) )
	{
		_ee_names[ j++ ] = i + 1;
		i += 18 + bb * 4;
		if( i > 1023 ) break;
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
		i += 18 + bb * 4;
		if( i > 1023 ) return 0;
	}
	return 0;
}

uint8_t * ee_name( uint8_t prog_number )
{
	return (uint8_t *) ( find_n( prog_number ) + 1 );
}

uint16_t ee_sec( uint8_t prog_number )
{
	return eeprom_read_word( (const uint16_t *) ( find_n( prog_number ) + 16 ) );
}

uint8_t ee_num( uint8_t prog_number )
{
	return eeprom_read_byte( (const uint8_t *) ( find_n( prog_number ) ) );
}

uint32_t * ee_freqs( uint8_t prog_number )
{
	return (uint32_t *) ( find_n( prog_number ) + 18 ) );
}

void ee_pc_communicate( void )
{
	uint8_t bb, nums;
	uint16_t n = ee_max_pointer();

	serial_init();

	serial_tx( EE_AVR ); // ask PC
	_delay_ms( 100 );
	
	if( serial_rx_ready() )
	{
		if( serial_rx() == EE_OK )
		{
			bb = get_b();
			if( bb == EE_SAVE )
			{
				nums = get_b();
				if( nums < 0 ) serial_tx( EE_ERR );
				else if( ( nums * 4 + 18 ) > ( 1022 - n ) ) put_b( EE_ERR );
				else
				{
					put_b( EE_OK );
					eeprom_write_byte( (const uint8_t *)n++, nums ); // N freqs
					uint8_t i = 15;
					while( i-- ) eeprom_write_byte( (const uint8_t *)n++, get_b() ); // Name
					while( nums-- )
					{
						eeprom_write_byte( (const uint8_t *)n++, get_b() ); // Freqs
						eeprom_write_byte( (const uint8_t *)n++, get_b() );
						eeprom_write_byte( (const uint8_t *)n++, get_b() );
						eeprom_write_byte( (const uint8_t *)n++, get_b() );
					}
					eeprom_write_byte( (const uint8_t *)n++, 0 );
				}
			}
			else if( bb == EE_CLEAR ) eeprom_write_byte( (const uint8_t *)(0), 0 );
		}
	}

	serial_disable();
}
