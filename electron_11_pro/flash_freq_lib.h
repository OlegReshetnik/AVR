#ifndef flash_freq_lib_h
#define flash_freq_lib_h

#include <avr/pgmspace.h>
#include <stdint.h>

extern const uint8_t * const pg_menu[];
extern const uint16_t pg_names[];
extern const uint16_t pg_freqs[];
extern const uint16_t pg_nums[];
extern const uint16_t pg_secs[];

#define pg_menu()			( (uint16_t *)&pg_menu[0] )

#define razdel_names( razdel )			( (uint16_t *)pgm_read_word( &pg_names[ razdel ] ) )
#define razdel_nums( razdel )			( (uint8_t *)pgm_read_word( &pg_nums[ razdel ] ) )
#define razdel_secs( razdel )			( (uint16_t *)pgm_read_word( &pg_secs[ razdel ] ) )
#define razdel_freqs( razdel )			( (uint16_t *)pgm_read_word( &pg_freqs[ razdel ] ) )


#define prog_name( razdel, i )			( (uint8_t *)pgm_read_word( &razdel_names( razdel )[i] ) )
#define prog_sec( razdel, i )			( (uint16_t)pgm_read_word( &razdel_secs( razdel )[i] ) )
#define prog_num( razdel, i )			( (uint8_t)pgm_read_byte( &razdel_nums( razdel )[i] ) )
#define prog_freqs( razdel, i )			( (uint32_t *)pgm_read_word( &razdel_freqs( razdel )[i] ) )


#endif
