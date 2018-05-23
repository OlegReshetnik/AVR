#ifndef ee_freq_lib_h
#define ee_freq_lib_h

#include <util/delay.h>
#include <inttypes.h>
#include <avr/eeprom.h>
#include "serial_lib.h"


#define EE_PC			'P'
#define EE_AVR			'A'
#define EE_OK			'O'
#define EE_ERR			'R'
#define EE_SAVE			'S'
#define EE_CLEAR		'C'

#define EE_MAX_N		16

#define EE_FREQ_MEANDR		0x8000

// eprom record structure
#define	EE_CNT			0 // - N freqs
#define	EE_NAME			1 // Name - 15 butes
#define	EE_FREQ_SECONDS	16 // Freq Len - 2 bytes, seconds, hight bit - meandr: AA | EE_FLAG_MEANDR
#define	EE_FREQS		18 // 4*N bytes, (freqs * 100)

void ee_pc_communicate( void ); // update eeprom


uint16_t * ee_all_names( void );

uint8_t * ee_name( uint8_t prog_number );

uint16_t ee_sec( uint8_t prog_number );

uint8_t ee_num( uint8_t prog_number );

uint32_t * ee_freqs( uint8_t prog_number );

#endif
