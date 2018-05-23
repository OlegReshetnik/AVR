#ifndef serial_lib_h
#define serial_lib_h

#include <avr/pgmspace.h>
#include <avr/io.h>
#include <stdint.h>
#define BAUD	115200
#include <util/setbaud.h>

#define PULLED_SERIAL // ������ ��� ���������� �� �������, ����� �� �����������

#define SERIAL_TIMEOUT		0xFFFF

#ifdef PULLED_SERIAL

	#define serial_rx_ready()	( UCSR0A & ( 1 << RXC0 ) ) // ���� ����� ?

	#define serial_tx_ready()	( UCSR0A & ( 1 << UDRE0 ) ) // ����� ���������� ?

#else

	#include <avr/interrupt.h>

	#define RX_BUFFER_SIZE		32 // 250 max
	#define TX_BUFFER_SIZE		16 // 250 max

	uint8_t serial_rx_ready( void ); // ����� ���� �� ������� �������

	uint8_t serial_tx_ready( void ); // ����� ���� � �������� �������

#endif

void serial_init( void );

void serial_disable( void );

int16_t serial_rx( void ); // ������ ��������� ����, ���� ������, �� ������� -1

void serial_clear_rx( void ); // �������� ������� ������

uint8_t serial_tx( uint8_t data ); // �������� ���� � �������� ������, ���� ������, �� ������� 0

uint8_t serial_print_string( uint8_t * str );

uint8_t serial_print_flash( const uint8_t * str );

#endif
