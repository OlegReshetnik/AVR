#include <avr/io.h>
#include <stdint.h>
#include <avr/pgmspace.h>
#include <avr/eeprom.h>

#include "lcd_rus_lib.h"
#include "menu_lib.h"
#include "new_dds_lib.h"
#include "ee_freq_lib.h"

const uint8_t s1[] PROGMEM = "вюярнрмши опханп";
const uint8_t s2[] PROGMEM = "щкейрпнм 7-RENT";

const uint8_t n1[] PROGMEM = "нямнбмшу";
const uint8_t n2[] PROGMEM = "опнцпюлл мер";

const uint8_t m1[] PROGMEM = "ням. опнцпюллш";
const uint8_t m2[] PROGMEM = "дно. опнцпюллш";
const uint8_t * const main_menu[] PROGMEM = { m1, m2, (uint8_t *)0 };
#define MainMenu()			( (uint16_t *)&main_menu[0] )

const uint16_t start_gorn[] PROGMEM = {
	DO|OKT_1|DL_025,
	MI|OKT_1|DL_025,
	SO|OKT_1|DL_1,
	NO|OKT_1|DL_01,
	MI|OKT_2|DL_025,
	DO|OKT_2|DL_025,
	SO|OKT_1|DL_1,
	NO|OKT_1|DL_01,
	0
};

const uint16_t oops_m[] PROGMEM = {
	FA|OKT_1|DL_05,
	MI|OKT_1|DL_05,
	RE|OKT_1|DL_05,
	DO|OKT_1|DL_05,
	SI|OKT_SMALL|DL_05,
	NO|OKT_1|DL_15,
	0
};

void no_prog( void )
{
	lcd_clear();
	lcd_rus_print_flash( n1 );
	lcd_gotoxy( 0, 1 );
	lcd_rus_print_flash( n2 );
	sound2_melody( oops_m );
}

void splash( void )
{
	lcd_clear();
	lcd_rus_print_flash( s1 );
	lcd_gotoxy( 0, 1 );
	lcd_rus_print_flash( s2 );
	sound2_melody( start_gorn );
}

int main(void)
{
	uint8_t ret_i;

	ee_pc_communicate();
	lcd_init();
	splash();
	ad9833_init();

    while(1)
    {
		switch( menu_get( MainMenu(), MENU_PGM ) )
		{
			case 0: no_prog(); break;

			case 1:
			{
				ret_i = menu_get( ee_all_names(), MENU_EEM );
				if( ret_i != MENU_RETURN ) play_programm( 0, ret_i );
				else sound2_beep( 880, 500 );
			}
			break;

			default: sound2_beep( 220, 500 ); _delay_ms(500); break;
		}
    }
}
