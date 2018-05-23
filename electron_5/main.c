#include <avr/io.h>
#include <stdint.h>
#include <avr/pgmspace.h>
#include <avr/eeprom.h>

#include "lcd_rus_lib.h"
#include "menu_lib.h"
#include "new_dds_lib.h"
#include "ee_freq_lib.h"
#include "flash_freq_lib.h"

const uint8_t s1[] PROGMEM = "◊¿—“Œ“Õ€… œ–»¡Œ–";
const uint8_t s2[] PROGMEM = "›À≈ “–ŒÕ 5";

const uint8_t m1[] PROGMEM = "Œ—Õ. œ–Œ√–¿ÃÃ€";
const uint8_t m2[] PROGMEM = "ƒŒœ. œ–Œ√–¿ÃÃ€";
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
	uint8_t ret_i, ret_flash;

	DDRD = 0xFF; PORTD = 127; // zero out
	ee_pc_communicate();
	lcd_init();
	splash();

    while(1)
    {
		switch( menu_get( MainMenu(), MENU_PGM ) )
		{
			case 0:
			{
				ret_flash = menu_get( pg_menu(), MENU_PGM );
				if( ret_flash != MENU_RETURN )
				{
					ret_i = menu_get( razdel_names( ret_flash ), MENU_PGM );
					if( ret_i != MENU_RETURN ) play_programm( ret_flash, ret_i, PROG_PGM );
					else sound2_beep( 880, 500 );
				}
				else sound2_beep( 880, 500 );
			}
			break;

			case 1:
			{
				ret_i = menu_get( ee_all_names(), MENU_EEM );
				if( ret_i != MENU_RETURN ) play_programm( 0, ret_i, PROG_EEM );
				else sound2_beep( 880, 500 );
			}
			break;

			default: sound2_beep( 220, 500 ); _delay_ms(500); break;
		}
    }
}
