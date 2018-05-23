#include "encoder_lib.h"

#ifdef ROTARY_ENCODER

	void encoder_init(void)				// init encoder
	{
		ENC_A_DDR &= ~(1 << ENC_A);		// set encoder pins to input
		ENC_B_DDR &= ~(1 << ENC_B);
		ENC_BT_DDR &= ~(1 << ENC_BT);

		ENC_A_PORT |= 1 << ENC_A;		// pullup encoder pins
		ENC_B_PORT |= 1 << ENC_B;
		ENC_BT_PORT |= 1 << ENC_BT;
	}

	uint8_t encoder_chek(void)			// check encoder, call period - 1 ms
	{
		static uint8_t enc_A_prev = 0;
		static int8_t nn = 0;
		static uint8_t t_cnt = 0;
		uint8_t enc_A, ret = ENC_PASS;

		enc_A = ENC_A_PIN & (1 << ENC_A);

		if( (!enc_A) && (enc_A_prev) )
		{
			if( ENC_B_PIN & (1 << ENC_B) )
			{
				nn ++;
				if( nn == ENC_SENS )
				{
					nn = 0;
					ret = ENC_RET_LEFT;
				}
			}
			else
			{
				nn --;
				if( nn == -ENC_SENS )
				{
					nn = 0;
					ret = ENC_RET_RIGHT;
				}
			}
		}
		enc_A_prev = enc_A;

		if( (ENC_BT_PIN & (1 << ENC_BT)) ) // button off
		{
			if( t_cnt > LONG_CLK ) ret = ENC_LONG_PRESS;
			else if( t_cnt > SHORT_CLK ) ret = ENC_PRESS;
			t_cnt = 0;
		}
		else t_cnt++; // button on

		// if( !( ENC_BT_PIN & (1 << ENC_BT) ) ) ret = ENC_PRESS; // button on

		return ret;
	}

	uint8_t is_encoder_event(void)
	{
		return (!(ENC_BT_PIN & (1 << ENC_BT))) | (!(ENC_A_PIN & (1 << ENC_A))) | (!(ENC_B_PIN & (1 << ENC_B)));
	}

	uint8_t is_encoder_press(void)
	{
		return (  !( ENC_BT_PIN & (1 << ENC_BT) )  );
	}

#else

	void encoder_init(void)
	{
		BT1_DDR &= ~ ( 1 << BT1 ); // set BT1 dio input
		BT1_PORT |= 1 << BT1; // PULL UP
		BT2_DDR |= 1 << BT2; // set BT2 to output
		BT2_PORT &= ~ (1 << BT2 ); // set BT2 to 0
	}

	uint8_t encoder_chek(void)
	{
		static uint8_t t_cnt = 0;

		if( BT1_PIN & (1 << BT1) ) // button off
		{
			if( t_cnt > LONG_CLK ) { t_cnt = 0; return ENC_PRESS; }
			if( t_cnt > SHORT_CLK ) { t_cnt = 0; return ENC_RIGHT; }
			t_cnt = 0;
		}
		else t_cnt++; // button on

		return ENC_PASS;
	}

	uint8_t is_encoder_press(void)
	{
		return !( BT1_PIN & (1 << BT1) );
	}

#endif
