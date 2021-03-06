#ifndef new_dds_lib_h
#define new_dds_lib_h

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/eeprom.h>

#include "lcd_rus_lib.h"
#include "sound2.h"
#include "encoder_lib.h"
#include "ad9833.h"
#include "ee_freq_lib.h"

void play_programm( uint8_t razdel, uint8_t i_prog );

#endif
