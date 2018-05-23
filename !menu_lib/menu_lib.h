#ifndef menu_lib_h
#define menu_lib_h

// lib use encoder lib

#include <stdint.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include "encoder_lib.h"
#include "lcd_lib.h"
#include "lcd_rus_lib.h"
#include "sound2.h"

#define MENU_HEIGHT		2
#define MENU_METKA_ON	'>'
#define MENU_METKA_OFF	' '
#define MENU_METKA_OK	'@'

#define MENU_RETURN		255
#define MENU_RAM		1
#define MENU_PGM		2
#define MENU_EEM		3


#define beep()	sound2_beep( 220, 80 )

uint8_t menu_get( uint16_t * items, , uint8_t menu_source );

#endif
