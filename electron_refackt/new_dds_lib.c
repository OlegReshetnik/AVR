#include "new_dds_lib.h"
#include "flash_freqs.h"

const uint16_t sound_s1[] PROGMEM = {
	DO|OKT_1|DL_025,
	MI|OKT_1|DL_025,
	SO|OKT_1|DL_025,
	DO|OKT_2|DL_1,
	SO|OKT_1|DL_025,
	DO|OKT_2|DL_1,
	0
};

const uint16_t sound_s2[] PROGMEM = {
	DO|OKT_2|DL_05,
	SO|OKT_1|DL_05,
	MI|OKT_1|DL_05,
	DO|OKT_1|DL_15,
	NO|OKT_2|DL_025,
	0
};

const uint16_t oops[] PROGMEM = {
	FA|OKT_1|DL_05,
	MI|OKT_1|DL_05,
	RE|OKT_1|DL_05,
	DO|OKT_1|DL_05,
	SI|OKT_SMALL|DL_05,
	0
};

const uint8_t msg_start1[] PROGMEM = "СТАРТ ПРОГРАММЫ,";
const uint8_t msg_start2[] PROGMEM = "ПРИГОТОВТЕСЬ!";

const uint8_t msg_end1[] PROGMEM = "ПРОГРАММА";
const uint8_t msg_end2[] PROGMEM = "ЗАВЕРШЕНА";

const uint8_t msg_brk[] PROGMEM = "СБРОС ПРОГРАММЫ";

const uint8_t to[] PROGMEM = "СЧЕТЧИК ИСТЕК!";

void print_process( uint16_t is, uint16_t as )
{
	lcd_gotoxy( 0, 1 );
	lcd_print_time( as - is, 1 );
	lcd_gotoxy( 9, 1 );
	lcd_print_int( (uint16_t)(  ( (uint32_t)is * (uint32_t)100 ) / (uint32_t)as  ), 2 );
	lcd_write( '%' );
}

void start_programm( const uint8_t * prog_name, uint8_t prog_source )
{
	lcd_rus_clear();
	lcd_rus_print_flash( msg_start1 );
	lcd_gotoxy( 0, 1 );
	lcd_rus_print_flash( msg_start2 );
	sound2_melody( sound_s1 );
	lcd_rus_clear();
	if( prog_source == PROG_PGM ) lcd_rus_print_flash( prog_name );
	else lcd_rus_print_eeprom( prog_name );
	sound2_melody( sound_s2 );
}

void end_programm( void )
{
	_delay_ms( 500 );
	lcd_rus_clear();
	lcd_rus_print_flash( msg_end1 );
	lcd_gotoxy( 0, 1 );
	lcd_rus_print_flash( msg_end2 );
	sound2_melody( sound_s2 );
}

void break_programm( void )
{
	lcd_rus_clear();
	lcd_rus_print_flash( msg_brk );
	sound2_melody( sound_s2 );
}

void time_out_programm( void )
{
	lcd_rus_clear();
	lcd_rus_print_flash( to );
	sound2_melody( oops );
}

void hack_init( void )
{
	DDRD = 0xC0; // Порт D 7 и 6 на выход
	PORTD = 0;
	for( uint16_t i = 0; i < 128; i ++ ) { *( (uint8_t *)( 0x200 + i ) ) = 0x40; }
	for( uint16_t i = 128; i < 256; i ++ ) { *( (uint8_t *)( 0x200 + i ) ) = 0x80; }
}

uint32_t hack_set_delta( uint32_t freq )
{
	uint32_t dds_word = (uint32_t)(  ( (uint64_t)freq * (uint64_t)838860800 + (uint64_t)5000000000 ) / (uint64_t)10000000000  );	// freq * ( 2^24 / (16 000 000 / 8)
	if( dds_word == 0 ) *( (uint8_t *)( 0x200 ) ) = 0; // установить 0 на выходе
	else *( (uint8_t *)( 0x200 ) ) = 0x40;

	TCCR1B = ( 1 << WGM12 ) | ( 1 << CS12 ) | ( 1 << CS10 ); // CTC to OC1A, clk_io / 1024
	OCR1A = 62499; // 62500 - 1 - это будет 1 раз в 4 секунды
	TIMSK1 = 1 << OCIE1A; // enable Timer1 COMP1A;
	TCNT1 = 0;
	sei();

	return dds_word;
}

void hack_reset(void)
{
	cli();
	TIMSK1 = 0;
	TCNT1 = 0;
	TCCR1B = 0;
	PORTD = 0;
}

void hack_4s_dds( uint32_t delta )
{
	// r25:r24:r23:r22 - delta - по соглашению о передаче параметров ( r25 - r8 )
	// в регистр Z загружаетс¤ адрес буфера таблицы из 256 значений
	// адрес буфера должен быть выровнен на 0x100
	// в данном случае буфер находится по адресу 0x0200
	// регистры r18, r19, zl составляют 24битный фазовый аккумулятор
	// старшие 8 разрядов также являются индексом в таблице сигнала
	// в регистрах r22, r23, r24 находитьс¤ 24битное значение приращения фазы - delta
	// регистры r18-r27, r30, r31 могут свободно использоватьс¤ в коде. z это (r31:r30)

	asm volatile (
	"ldi	zh, 2" "\n\t" // z = адрес _sin_table = 0x0200
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

void play_programm( uint8_t razdel, uint8_t i_prog, uint8_t prog_source )
{
	uint32_t delta, fq = 0, *freqs;
	uint16_t sec, i_sec, all_sec, freq_len;
	uint8_t num_freqs, *str;

	if( prog_source == PROG_PGM )
	{
		freqs = prog_freqs( razdel, i_prog );
		freq_len = prog_sec( razdel, i_prog );
		num_freqs = prog_num( razdel, i_prog );
		str = prog_name( razdel, i_prog );
	}
	else
	{
		if( ( num_freqs = ee_count( i_prog ) ) == 0 )
		{
			time_out_programm();
			return;
		}
		if( num_freqs < 253 ) ee_dec_count( i_prog );
		freqs = ee_freqs( i_prog );
		freq_len = ee_sec( i_prog );
		num_freqs = ee_num( i_prog );
		str = ee_name( i_prog );
	}

	freq_len &= 0xFFFC; // Выровнять на 4 секунды
	all_sec = freq_len  * num_freqs;
	i_sec = 0;

	start_programm( str, prog_source );
	print_process( i_sec, all_sec );
	hack_init();

	while( num_freqs-- )
	{
		sec = freq_len;
		if( prog_source == PROG_PGM ) fq = pgm_read_dword( &freqs[ num_freqs ] );
		else fq = eeprom_read_dword( &freqs[ num_freqs ] );
		delta = hack_set_delta( fq );
		while( sec )
		{
			hack_4s_dds( delta );
			if( is_encoder_press() )
			{
				hack_reset();
				break_programm();
				return;
			}
			sec -= 4;
			i_sec += 4;
			print_process( i_sec, all_sec );
		}
		hack_reset();
	}

	hack_reset();
	end_programm();
}

ISR(TIMER1_COMPA_vect, ISR_NAKED )
{
	asm volatile (
	"pop	r25" "\n\t"
	"pop	r25" "\n\t"
	"reti" "\n\t" // HACK!!! - возврат в вызываемую функцию !!!
	);
}
