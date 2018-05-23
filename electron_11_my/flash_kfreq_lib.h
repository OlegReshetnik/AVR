#ifndef flash_kfreq_lib_h
#define flash_kfreq_lib_h

#include <avr/pgmspace.h>
#include <stdint.h>

extern const uint8_t * const kpg_menu[];
extern const uint16_t kpg_names[];
extern const uint16_t kpg_freqs[];
extern const uint16_t kpg_nums[];
extern const uint16_t kpg_secs[];

#define kpg_menu()			( (uint16_t *)&kpg_menu[0] )

#define razdel_knames( razdel )		( (uint16_t *)pgm_read_word( &kpg_names[ razdel ] ) )
#define razdel_knums( razdel )		( (uint8_t *)pgm_read_word( &kpg_nums[ razdel ] ) )
#define razdel_ksecs( razdel )		( (uint16_t *)pgm_read_word( &kpg_secs[ razdel ] ) )
#define razdel_kfreqs( razdel )		( (uint16_t *)pgm_read_word( &kpg_freqs[ razdel ] ) )


#define prog_kname( razdel, i )		( (uint8_t *)pgm_read_word( &razdel_knames( razdel )[i] ) )
#define prog_ksec( razdel, i )		( (uint16_t)pgm_read_word( &razdel_ksecs( razdel )[i] ) )
#define prog_knum( razdel, i )		( (uint8_t)pgm_read_byte( &razdel_knums( razdel )[i] ) )
#define prog_kfreqs( razdel, i )	( (uint32_t *)pgm_read_word( &razdel_kfreqs( razdel )[i] ) )


#endif
