#include "new_dds_lib.h"

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

void print_process( uint16_t is, uint16_t as )
{
	lcd_gotoxy( 0, 1 );
	lcd_print_time( as - is, 1 );
	lcd_gotoxy( 9, 1 );
	lcd_print_int( (uint16_t)(  ( (uint32_t)is * (uint32_t)100 ) / (uint32_t)as  ), 2 );
	lcd_write( '%' );
}

void start_programm( const uint8_t * prog_name )
{
	lcd_rus_clear();
	lcd_rus_print_flash( msg_start1 );
	lcd_gotoxy( 0, 1 );
	lcd_rus_print_flash( msg_start2 );
	sound2_melody( sound_s1 );
	lcd_rus_clear();
	lcd_rus_print_eeprom( prog_name );
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

void play_programm( uint8_t razdel, uint8_t i_prog )
{
	uint32_t fq = 0, *freqs;
	uint16_t sec, i_sec, all_sec, freq_len;
	uint8_t num_freqs, *str;

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

	all_sec = freq_len  * num_freqs;
	i_sec = 0;

	start_programm( str );
	print_process( i_sec, all_sec );
	ad9833_init();

	while( num_freqs-- )
	{
		sec = freq_len;
		fq = eeprom_read_dword( &freqs[ num_freqs ] );
		ad9833_setfreq( fq, SIN );
		while( sec )
		{
			_delay_ms(1000);
			if( is_encoder_press() )
			{
				ad9833_reset();
				break_programm();
				return;
			}
			sec --;
			i_sec ++;
			print_process( i_sec, all_sec );
		}
	}

	ad9833_reset();
	end_programm();
}
