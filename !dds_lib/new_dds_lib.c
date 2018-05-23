#include "new_dds_lib.h"

const uint16_t sound_start[] PROGMEM = {
	DO|OKT_1|DL_025,
	SO|OKT_1|DL_025,
	DO|OKT_2|DL_1,
	SO|OKT_1|DL_025,
	DO|OKT_2|DL_1,
	0
};

const uint16_t sound_end[] PROGMEM = {
	DO|OKT_2|DL_025,
	SO|OKT_1|DL_025,
	DO|OKT_1|DL_1,
	SO|OKT_1|DL_025,
	DO|OKT_1|DL_1,
	0
};

const uint8_t msg_start1[] PROGMEM = " ������������,";
const uint8_t msg_start2[] PROGMEM = "������ ���������";

const uint8_t msg_end1[] PROGMEM = "���������";
const uint8_t msg_end2[] PROGMEM = "���������";


const uint8_t __sine256[] PROGMEM = {
	127,130,133,136,139,143,146,149,152,155,158,161,164,167,170,173,
	176,179,182,184,187,190,193,195,198,200,203,205,208,210,213,215,
	217,219,221,224,226,228,229,231,233,235,236,238,239,241,242,244,
	245,246,247,248,249,250,251,251,252,253,253,254,254,254,254,254,
	255,254,254,254,254,254,253,253,252,251,251,250,249,248,247,246,
	245,244,242,241,239,238,236,235,233,231,229,228,226,224,221,219,
	217,215,213,210,208,205,203,200,198,195,193,190,187,184,182,179,
	176,173,170,167,164,161,158,155,152,149,146,143,139,136,133,130,
	127,124,121,118,115,111,108,105,102,99,96,93,90,87,84,81,
	78,75,72,70,67,64,61,59,56,54,51,49,46,44,41,39,
	37,35,33,30,28,26,25,23,21,19,18,16,15,13,12,10,
	9,8,7,6,5,4,3,3,2,1,1,0,0,0,0,0,
	0,0,0,0,0,0,1,1,2,3,3,4,5,6,7,8,
	9,10,12,13,15,16,18,19,21,23,25,26,28,30,33,35,
	37,39,41,44,46,49,51,54,56,59,61,64,67,70,72,75,
	78,81,84,87,90,93,96,99,102,105,108,111,115,118,121,124
};

// uint8_t * _sine_table = (uint8_t *)0x200;

void dds_set_sinus( void )
{
	uint8_t b;

	for( uint16_t i = 0; i < 256; i ++ )
	{
		b = pgm_read_byte( __sine256 + i );
		
		#ifdef ARDUINO_SWAP
			b = ( b & (~3) ) | ( ( b & 1 ) << 1 ) | ( ( b & 2 ) >> 1 ); // swap 0 and 1 bits
		#endif
		
		*( (uint8_t *)( 0x200 + i ) ) = b; // � ������ ������ ����� ��������� �� ������ 0x0200
	}
}

void dds_set_meandr( void )
{
	uint8_t b;

	for( uint16_t i = 0; i < 128; i ++ )
	{
		*( (uint8_t *)( 0x200 + i ) ) = 0;
	}

	for( uint16_t i = 128; i < 256; i ++ )
	{
		*( (uint8_t *)( 0x200 + i ) ) = 255;
	}
}

void hack_4s_dds_sinus( uint32_t delta )
{
	// r25:r24:r23:r22 - delta - �� ���������� � �������� ���������� ( r25 - r8 ) 
	// � ������� Z ���������� ����� sinus ������ �� 256 �������� ������� ������
	// ����� ������ ������ ���� �������� �� 0x100
	// � ������ ������ ����� ��������� �� ������ 0x0200
	// �������� r18, r19, zl ���������� 24������ ������� �����������
	// ������� 8 �������� ����� �������� �������� � ������� �������
	// � ��������� r22, r23, r24 ��������� 24������ �������� ���������� ���� - delta
	// �������� r18-r27, r30, r31 ����� �������� ������������� � ����. z ��� (r31:r30)

	asm volatile (
	"ldi	zh, 2" "\n\t" // z = ����� _sin_table = 0x0200
	"eor	zl, zl" "\n\t"
	"eor	r18, r18" "\n\t"
	"eor	r19, r19" "\n\t"

	"1: add	r18, r22" "\n\t" // 1                    --+ 8 cycles -> 16 000 000 / 8 = 2 000 000 Hz
	"adc	r19, r23" "\n\t" // 1                      |
	"adc	zl, r24" "\n\t" // 1                       |
	"ld		r20, z" "\n\t" // 2                        |
	"out	0x0b, r20" "\n\t" // _SFR_IO_ADDR(PORTD) 1 |
	"rjmp	1b" "\n\t" // 2                          --+
	);
}

void hack_4s_dds_meandr( uint32_t delta )
{
	// r25:r24:r23:r22 - delta - �� ���������� � �������� ����������
	// r24:r23:r22 - ��� 24������ �������� ���������� ���� - delta
	// �������� r18-r27, r30, r31 ����� �������� ������������� � ����, (r31:r30) - ��� z

	// �������� r20:r19:r18 ���������� 24������ ������� ����������
	// ������� 8 �������� ����� �������� �������� � ������� �������
	// �� �� ���������� ������ ������� ������, ������� �� 256 ������: 128 ������ - 0, � 128 ������ - 1

	asm volatile (
	"eor	r18, r18" "\n\t"
	"eor	r19, r19" "\n\t"
	"eor	r20, r20" "\n\t"

	"1: add	r18, r22" "\n\t"// 1     --+ 6 cycles -> 16 000 000 / 6
	"adc	r19, r23" "\n\t"// 1       |
	"adc	r20, r24" "\n\t"// 1       |
	"out	0x0b, r20""\n\t"// 1 PORTD |
	"rjmp	1b" "\n\t"      // 2     --+
	);
}

ISR(TIMER1_OVF_vect, ISR_NAKED )
{
	asm volatile (
	"pop	r25" "\n\t"
	"pop	r25" "\n\t"
	"ret" "\n\t" // HACK!!! - ������� � ���������� ������� !!!
	);
}

void print_process( uint16_t i_sec, uint16_t all_sec )
{
	lcd_gotoxy( 0, 1 );
	lcd_print_time( all_sec - i_sec, 1 );
	lcd_gotoxy( 9, 1 );
	lcd_print_int( i_sec * 100 / all_sec , 2 );
	lcd_write( '%' );
}

void start_programm( const uint8_t * prog_name )
{
	lcd_rus_clear();
	lcd_rus_print_flash( msg_start1 );
	lcd_gotoxy( 0, 1 );
	lcd_rus_print_flash( msg_start2 );
	sound2_melody( sound_start );
	_delay_ms( 5000 );
	lcd_rus_clear();
	lcd_rus_print_flash( prog_name );
	sound2_melody( sound_start );
}

void end_programm( void )
{
	lcd_rus_clear();
	lcd_rus_print_flash( msg_end1 );
	lcd_gotoxy( 0, 1 );
	lcd_rus_print_flash( msg_end2 );
	sound2_melody( sound_end );
	_delay_ms( 5000 );
}

void play_ee_programm( const uint8_t * prog_name, const float * prog_freqs, uint16_t freq_len, uint8_t num_freqs )
{
	uint16_t f_sec, i_sec, all_sec;
	uint32_t delta;

	freq_len &= 0xFFFC; // ��������� �� 4 �������

	all_sec = ( freq_len & 0x7FFF ) * num_freqs; // ������� ��� - ��� ���� �������
	i_sec = 0;
	
	start_programm( prog_name );
	print_process( i_sec, all_sec );

	DDRD = 0xFF; // ���� ��� �� �����
	TCCR1B = ( 1 << WGM12 ) | ( 1 << CS12 ) | ( 1 << CS10 ); // FastPWM to ICR1, clk_io / 1024
	OCR1A = 62499; // 62500 - 1 - ��� ����� 1 ��� � 4 �������
	TIMSK1 = 1 << OCIE1A; // enable Timer1 overflov Interrupt;
	sei(); // enable interrupt

	if( (freq_len & 0x8000) ) // Meandr
	{
		freq_len &= 0x7FFF;
		dds_set_meandr();
		while( num_freqs-- )
		{
			sec = freq_len;
			delta = pgm_read_float( &prog_freqs[ num_freqs ] ) * DDS_K_SINUS + 0.5;
			while( sec )
			{
				hack_4s_dds_sinus( delta ); // ������ ���������� sinus ��-�� ���������� ������������
				sec -= 4;
				i_sec += 4;
				print_process( i_sec, all_sec );
			}
		}
	}
	else
	{
		dds_set_sinus();
		while( num_freqs-- )
		{
			sec = freq_len;
			delta = pgm_read_float( &prog_freqs[ num_freqs ] ) * DDS_K_SINUS + 0.5;
			while( sec )
			{
				hack_4s_dds_sinus( delta );
				sec -= 4;
				i_sec += 4;
				print_process( i_sec, all_sec );
			}
		}
	}

	cli();
	TIMSK1 = 0; // disable Timer1 overflov Interrupt;
	PORTD = 127; // set output to zero
	end_programm();
}
