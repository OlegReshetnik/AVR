#include "sound2.h"

const uint16_t sound2_freqs[] PROGMEM = { 0, 4186, 4435, 4698, 4978, 5274, 5588, 5920, 6272, 6665, 6880, 7458, 7902 }; // 5 октава

void sound2_play( uint16_t freq )
{
	uint8_t clok_div = 1;
	uint32_t ctc = ( F_CPU / 2 ) / freq;		// 1

	if( ctc > 256 ) { ++clok_div; ctc >>= 3; }	// 8
	if( ctc > 256 ) { ++clok_div; ctc >>= 2; }	// 32
	if( ctc > 256 ) { ++clok_div; ctc >>= 1; }	// 64
	if( ctc > 256 ) { ++clok_div; ctc >>= 1; }	// 128
	if( ctc > 256 ) { ++clok_div; ctc >>= 1; }	// 256
	if( ctc > 256 ) { ++clok_div; ctc >>= 2; }	// 1024

	DDRB |= 1 << 3; // PB3 (OC2A) на выход
	OCR2A = ( (uint8_t)( ctc - 1 ) ) & 0xFF; // до куда считаем

	TCCR2A = (1 << COM2A0) | (WGM21 << 1); // toggle OC2A, CTC to OC2A
	TCCR2B = clok_div & 7; // делитель
}

void sound2_mute( void )
{
	TCCR2A = 0;
	PORTB &= ~( 1 << 3 );
}

void sound2_delay1ms( uint16_t len )
{
	while( len-- ) _delay_ms(1);
}

void sound2_beep( uint16_t freq, uint16_t len )
{
	if( freq != 0 ) sound2_play( freq );
	sound2_delay1ms( len );
	sound2_mute();
	sound2_delay1ms( MIN_NOT/2 ); // pause between notes
}

void sound2_melody( const uint16_t *melody )
{
	uint16_t note;

	while( ( note = pgm_read_word( melody++ ) ) != 0 )
	{
		// частоту 5-й октавы делим на 2 в степени (7-номер октавы). Напр: малая октава - 2, частоту нужно разделить на 32
		sound2_beep( pgm_read_word( &sound2_freqs[ note & 0xF ] ) >> ( 7 - ( ( note >> 4 ) & 7 ) ), (note >> 7) * MIN_NOT );
	}
}
