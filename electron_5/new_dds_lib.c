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

const uint8_t msg_start1[] PROGMEM = "—“¿–“ œ–Œ√–¿ÃÃ€,";
const uint8_t msg_start2[] PROGMEM = "œ–»√Œ“Œ¬“≈—‹!";

const uint8_t msg_end1[] PROGMEM = "œ–Œ√–¿ÃÃ¿";
const uint8_t msg_end2[] PROGMEM = "«¿¬≈–ÿ≈Õ¿";

const uint8_t msg_brk[] PROGMEM = "—¡–Œ— œ–Œ√–¿ÃÃ€";

const uint8_t to[] PROGMEM = "—◊≈“◊»  »—“≈ !";

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
	DDRD = 0xFF;
	for( uint16_t i = 0; i < 256; i ++ ) *( (uint8_t *)( 0x200 + i ) ) = pgm_read_byte( __sine256 + i ); //·ÛÙÂ Ì‡ıÓ‰ËÚÒˇ ÔÓ ‡‰ÂÒÛ 0x0200
}

uint32_t hack_set_delta( uint32_t freq )
{
	uint32_t dds_word = (uint32_t)(  ( (uint64_t)freq * (uint64_t)838860800 + (uint64_t)5000000000 ) / (uint64_t)10000000000  );	// freq * ( 2^24 / (16 000 000 / 8)

	TCCR1B = ( 1 << WGM12 ) | ( 1 << CS12 ) | ( 1 << CS10 ); // CTC to OC1A, clk_io / 1024
	OCR1A = 62499; // 62500 - 1 - ˝ÚÓ ·Û‰ÂÚ 1 ‡Á ‚ 4 ÒÂÍÛÌ‰˚
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
	PORTD = 127; // zero out
}

void hack_4s_dds( uint32_t delta )
{
	asm volatile (
	"ldi	zh, 2" "\n\t"
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

	freq_len &= 0xFFFC; // ¬˚Ó‚ÌˇÚ¸ Ì‡ 4 ÒÂÍÛÌ‰˚
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
	"reti" "\n\t" // HACK!!! - ‚ÓÁ‚‡Ú ‚ ‚˚Á˚‚‡ÂÏÛ˛ ÙÛÌÍˆË˛ !!!
	);
}
