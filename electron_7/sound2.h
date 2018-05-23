#ifndef sound2_h
#define sound2_h

#include <avr/io.h>
#include <stdint.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

// ���������� TC2, PB3 (OC2A)

// ������ ������
// xxxxxxxxx        xxx             xxxx
// ������������ 9   ����� ������ 3  ��� ���� 4
// ���� ��� ���� 0xF - ��� �����
// ���� ��� ����� 0x0000 - ��� �����

#define OKT_KONTR	(0 << 4)	// ����p������
#define OKT_BIG		(1 << 4)	// ������� ������
#define OKT_SMALL	(2 << 4)	// ����� ������
#define OKT_1		(3 << 4)	// ������ ������
#define OKT_2		(4 << 4)	// ������ ������
#define OKT_3		(5 << 4)	// ������ ������
#define OKT_4		(6 << 4)	// ��������� ������
#define OKT_5		(7 << 4)	// ����� ������

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

#define MIN_NOT	10 // ���� ������� ������������ - 10 ms
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
