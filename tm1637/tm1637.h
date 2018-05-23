#pragma once

#include <stdint.h>

#define TM_OUT          PORTC
#define TM_IN           PINC
#define TM_DDR          DDRC
#define TM_BIT_CLK      ( 1 << 5 ) // PC5 clock
#define TM_BIT_DAT      ( 1 << 4 ) // PC4 data

#define TM1637_DIGITS   4
#define COLON_POS		1

void tm_init( void );
void tm_clear(void);
void tm_set_bright(const uint8_t brightness); // 0 to 7
void tm_set_byte(const uint8_t position, const uint8_t b);
void tm_set_digit(const uint8_t position, const uint8_t digit);
void tm_set_char(const uint8_t position, const char ch);
void tm_set_str(const char * value);
void tm_colon_on(void); // show ':'
void tm_colon_off(void); // hide ':'
void tm_time(uint16_t sec);
