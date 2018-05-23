#ifndef sound2_h
#define sound2_h

#include <avr/io.h>
#include <stdint.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

// Использует TC2, PB3 (OC2A)

// формат записи
// xxxxxxxxx        xxx             xxxx
// длительность 9   номер октавы 3  код ноты 4
// если код ноты 0xF - это пауза
// если все слово 0x0000 - это конец

#define OKT_KONTR	(0 << 4)	// Контpоктава
#define OKT_BIG		(1 << 4)	// Большая октава
#define OKT_SMALL	(2 << 4)	// Малая октава
#define OKT_1		(3 << 4)	// Первая октава
#define OKT_2		(4 << 4)	// Вторая октава
#define OKT_3		(5 << 4)	// Третья октава
#define OKT_4		(6 << 4)	// Четвертая октава
#define OKT_5		(7 << 4)	// Пятая октава

#define DO		1
#define DOd		2
#define RE		3
#define REd		4
#define MI		5
#define FA		6
#define FAd		7
#define SO		8
#define SOd		9
#define LA		10
#define SIb		11
#define SI		12
#define NO		0

#define MIN_NOT	10 // одна единица длительности - 10 ms
#define DL_15	((1500 / MIN_NOT) << 7)
#define DL_1	((1000 / MIN_NOT) << 7)
#define DL_05	((500 / MIN_NOT) << 7)
#define DL_025	((250 / MIN_NOT) << 7)
#define DL_01	((100 / MIN_NOT) << 7)


void sound2_play( uint16_t freq );
void sound2_mute( void );
void sound2_delay1ms( uint16_t len ); // len millisecond
void sound2_beep( uint16_t freq, uint16_t len );
void sound2_melody( const uint16_t *melody );

#endif
