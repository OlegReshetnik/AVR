#ifndef new_dds_lib_h
#define new_dds_lib_h

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

#include "lcd_rus_lib.h"
#include "sound2.h"


//#define ARDUINO_SWAP // у Arduino Nano поменяны местами 0 и 1 биты

#define DDS_DIV_SINUS	8
#define DDS_DIV_MEANDR	6

#define POW_2_24		16777216.0

#define DDS_K_SINUS		( POW_2_24 * (float)DDS_DIV_SINUS / (float)F_CPU )
#define DDS_K_MEANDR	( POW_2_24 * (float)DDS_DIV_MEANDR / (float)F_CPU )

void play_ee_programm( const uint8_t * prog_name, const float * prog_freqs, uint16_t freq_len, uint8_t num_freqs );

#endif
