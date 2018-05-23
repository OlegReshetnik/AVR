#ifndef encoder_lib_h
#define encoder_lib_h

#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>

//#define ENC_INVERT_ROTATION
//#define SIMPLE_ENCODER

#define ENC_PULL_TIME	5		// pull time, 1 ms

#define LONG_CLK		200
#define SHORT_CLK		5

#define ENC_PASS		0		// encoder states
#define ENC_RIGHT		1
#define ENC_LEFT		2
#define ENC_PRESS		4
#define ENC_LONG_PRESS	5


#ifdef SIMPLE_ENCODER

	#define BT1_DDR			DDRB	// one button wire
	#define BT1_PORT		PORTB
	#define BT1_PIN			PINB
	#define BT1				3

	#define BT2_DDR			DDRD	// two button wire
	#define BT2_PORT		PORTD
	#define BT2_PIN			PIND
	#define BT2				3

#else
	
	#ifdef ENC_INVERT_ROTATION
		#define ENC_RET_RIGHT	2
		#define ENC_RET_LEFT	1
	#else
		#define ENC_RET_RIGHT	1
		#define ENC_RET_LEFT	2
	#endif

	#define ENC_A_DDR		DDRC	// encoder A
	#define ENC_A_PORT		PORTC
	#define ENC_A_PIN		PINC
	#define ENC_A			0

	#define ENC_B_DDR		DDRC	// encoder B
	#define ENC_B_PORT		PORTC
	#define ENC_B_PIN		PINC
	#define ENC_B			1

	#define ENC_BT_DDR		DDRC	// encoder button
	#define ENC_BT_PORT		PORTC
	#define ENC_BT_PIN		PINC
	#define ENC_BT			2

	#define ENC_SENS		2		// encoder sens

#endif

#define encoder_delay()	_delay_ms( ENC_PULL_TIME )

void encoder_init(void);		// init encoder

uint8_t encoder_chek(void);		// check encoder, call period - 1 ms

uint8_t is_encoder(void);		// true, if enc press or rotate

#endif
