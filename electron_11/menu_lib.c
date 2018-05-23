#include "menu_lib.h"

const uint8_t _str_ret[] PROGMEM = " ^-ВОЗВРАТ";

void menu_redraw( uint16_t * items, uint8_t start, uint8_t menu_source )
{
	uint8_t i;
	uint16_t s;

	lcd_rus_clear();

	for( i = 0; i < MENU_HEIGHT; i++ )
	{
		lcd_gotoxy( 1, i );

		switch( menu_source )
		{
			case MENU_RAM:
							s = items[start+i];
							if( s ) lcd_rus_print_string( (const uint8_t *)s );
							else lcd_rus_print_flash( _str_ret );
							break;
			case MENU_PGM:
							s = pgm_read_word( (const uint16_t *)&items[start+i] );
							if( s ) lcd_rus_print_flash( (const uint8_t *)s );
							else lcd_rus_print_flash( _str_ret );
							break;

			case MENU_EEM:
							s = items[start+i]; // Массив указателей также в памяти
							if( s ) lcd_rus_print_eeprom( (const uint8_t *)s );
							else lcd_rus_print_flash( _str_ret );
							break;
		}
	}
}

void menu_mark( uint8_t y, uint8_t ch)
{
	lcd_gotoxy( 0, y );
	lcd_write( ch );
}

uint8_t menu_get( uint16_t * items, uint8_t menu_source )
{
	uint8_t start = 0, n = 0;
	signed char current = 0;

	if( menu_source == MENU_PGM ) while( pgm_read_word( &items[ n ] ) ) n++; // get n items
	else while( items[ n ] ) n++; // get n items

	if( n == 0 ) return MENU_RETURN;

	encoder_init();
	menu_redraw( items, start, menu_source );

	for(;;)
	{
		encoder_delay();

		switch( encoder_chek() )
		{
			case ENC_RIGHT : beep(); menu_mark( current - start, MENU_METKA_OFF ); current++; break;
			case ENC_LEFT  : beep(); menu_mark( current - start, MENU_METKA_OFF ); current--; break;
			case ENC_PRESS : beep(); menu_mark( current - start, MENU_METKA_OK ); return ( current == n ) ? MENU_RETURN : current;
		}

		if( current > n )
		{
			start = 0;
			current = 0;
			menu_redraw( items, 0, menu_source );
			menu_mark( 0, MENU_METKA_ON );
		}
		else if( current < 0 )
		{
			current = n;
			start = n - (MENU_HEIGHT - 1);
			menu_redraw( items, n - MENU_HEIGHT + 1, menu_source );
			menu_mark( MENU_HEIGHT - 1, MENU_METKA_ON );
		}
		else if( current == (start + MENU_HEIGHT) )
		{
			start++;
			menu_redraw( items, start, menu_source );
			menu_mark( MENU_HEIGHT - 1, MENU_METKA_ON );
		}
		else if( current < start )
		{
			start--;
			menu_redraw( items, start, menu_source );
			menu_mark( 0, MENU_METKA_ON );
		}
		else menu_mark( current - start, MENU_METKA_ON );

	}
}
