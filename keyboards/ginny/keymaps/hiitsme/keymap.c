/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * This is a very different layout based off this table
 * http://asetniop.com/combinations
 *
 * Unlike standard Asetniop there are a few concessions that must be
 * made. Namely we don't do partials and if a chord has multiple left/
 * right words we go with the most common of the two.
 *
 * Also note, All Combos _must_ be done through Command Mode! If you
 * use a combo enough add it to your dictionary!
 *
 * Two 'layers' are avalible, CMD and USR. Just add these into a chord.
 * You'll enter/exit these layers with SET_STICKY(CMD) and SET_STICKY(0)
 *
 * Note: The engine optimizes for the longest chord it can find, every
 * now and again this makes conflicts! If you have a better dictionary
 * or come up with improvements, please submit a PR!
 */


#include QMK_KEYBOARD_H
#include "sten.h"

//#define USE_COMMON 1

// Asetniop aliases, to Ginny Fingers
#define AA		GLP
#define AR		GLR
#define AS		GLM
#define AT		GLI
#define AN		GRI
#define AE		GRM
#define AI		GRR
#define AO		GRP

#define AB		GLT							// Left/Right thumbs
#define AK		GRT

#define NUM		RES1						// Sticky Layer 1
#define USR   RES2						// Sticky Layer 2
#define CMD		RES2 | RES1			// Sticky Layer 3

// Asetniop layout see above link
uint32_t processQwerty(bool lookup) {
	// Layer Switches
	P(AA | AT | AN | AO,								SET_STICKY(NUM));
	P(AR | AS | AE | AI,								SET_STICKY(CMD));
	P(AA | AR | AS | AT | AN | AE | AI | AO,			SET_STICKY(USR));

	// Base defs
	P(AB,												SEND(KC_LSFT));
	P(AK,												SEND(KC_SPC));

	P(AA,												SEND(KC_A));
	P(AR,												SEND(KC_R));
	P(AS,												SEND(KC_S));
	P(AT,												SEND(KC_T));
	P(AN,												SEND(KC_N));
	P(AE,												SEND(KC_E));
	P(AI,												SEND(KC_I));
	P(AO,												SEND(KC_O));

	P(AT | AN,											SEND(KC_B));
	P(AA | AN,											SEND(KC_J));
	P(AE | AO,											SEND(KC_LSFT); SEND(KC_1));
	P(AR | AS,											SEND(KC_F));
	P(AT | AI,											SEND(KC_G));
	P(AA | AT,											SEND(KC_P));
	P(AN | AO,											SEND(KC_L));
	P(AR | AE,											SEND(KC_Z));
	P(AR | AN,											SEND(KC_K));
	P(AE | AI,											SEND(KC_U));
	P(AA | AR,											SEND(KC_W));
	P(AS | AO,											SEND(KC_QUOT));
	P(AS | AT,											SEND(KC_D));
	P(AN | AE,											SEND(KC_H));
	P(AR | AT,											SEND(KC_C));
	P(AN | AI,											SEND(KC_Y));
	P(AA | AS,											SEND(KC_X));
	P(AT | AO,											SEND(KC_SLSH));
	P(AT | AE,											SEND(KC_V));
	P(AS | AN,											SEND(KC_M));
	P(AA | AE,											SEND(KC_Q));
	P(AI | AO,											SEND(KC_SCLN));
	P(AS | AE,											SEND(KC_COMM));
	P(AR | AI,											SEND(KC_DOT));
	P(AA | AO,											SEND(KC_BSPC));
	P(AA | AI,											SEND(KC_LSFT); SEND(KC_9));
	P(AR | AO,											SEND(KC_LSFT); SEND(KC_0));
	P(AS | AI,											SEND(KC_MINS));
	P(AA | AR | AS | AT,								SEND(KC_TAB));
	P(AN | AE | AI | AO,								SEND(KC_ENT));

	// Num Defs
	P(NUM | AA | AT | AN | AO,  						SET_STICKY(0));
	P(NUM | AB,											SEND(KC_LSFT));
	P(NUM | AK,											SEND(KC_SPC));

	P(NUM | AA,											SEND(KC_1));
	P(NUM | AR,											SEND(KC_2));
	P(NUM | AS,											SEND(KC_3));
	P(NUM | AT,											SEND(KC_4));
	P(NUM | AN,											SEND(KC_7));
	P(NUM | AE,											SEND(KC_8));
	P(NUM | AI,											SEND(KC_9));
	P(NUM | AO,											SEND(KC_0));

	P(NUM | AS | AT,									SEND(KC_5));
	P(NUM | AN | AE,									SEND(KC_6));
	P(NUM | AA | AN,									SEND(KC_GRV));
	P(NUM | AE | AO,									SEND(KC_LSFT); SEND(KC_1));
	P(NUM | AR | AS,									SEND_STRING("¢"));
	//P(NUM | AT | AO,									SEND(KC_CHANGE ME --------------));
	P(NUM | AA | AT,									SEND_STRING("≤"));
	P(NUM | AN | AO,									SEND_STRING("≥"));
	P(NUM | AR | AE,									SEND(KC_BRIU));
	P(NUM | AR | AN,									SEND(KC_BRID));
	//P(NUM | AE | AE,									SEND(KC_CHANGE ME --------------));
	//P(NUM | AA | AR,									SEND(KC_CHANGE ME --------------));
	P(NUM | AS | AO,									SEND(KC_QUOT));
	P(NUM | AT | AN,									SEND(KC_EQL));
	P(NUM | AR | AT,									SEND(KC_VOLD));
	P(NUM | AN | AI,									SEND(KC_VOLU));
	P(NUM | AA | AS,									SEND(KC_MPLY));
	P(NUM | AT | AO,									SEND(KC_SLSH));
	P(NUM | AT | AE,									SEND(KC_MNXT));
	P(NUM | AS | AN,									SEND(KC_MPRV));
	P(NUM | AA | AE,									SEND(KC_BSLS));
	P(NUM | AI | AO,									SEND(KC_SCLN));
	P(NUM | AS | AE,									SEND(KC_COMM));
	P(NUM | AR | AI,									SEND(KC_DOT));
	P(NUM | AA | AO,									SEND(KC_BSPC));
	P(NUM | AA | AI,									SEND(KC_LBRC));
	P(NUM | AR | AO,									SEND(KC_RBRC));
	P(NUM | AS | AI,									SEND(KC_MINS));
	P(NUM | AA | AR | AS | AT,							SEND(KC_TAB));
	P(NUM | AN | AE | AI | AO,							SEND(KC_ENT));

	// Command defs
	P(CMD | AR | AS | AE | AI,							SET_STICKY(0));
	P(CMD | AB,											SEND(KC_LSFT));
	P(CMD | AK,											SEND(KC_SPC));
	P(CMD | AN,											SEND(KC_LEFT));
	P(CMD | AE,											SEND(KC_DOWN));
	P(CMD | AI,											SEND(KC_UP));
	P(CMD | AO,											SEND(KC_RGHT));
	P(CMD | AA,											SEND(KC_MS_L));
	P(CMD | AR,											SEND(KC_MS_D));
	P(CMD | AS,											SEND(KC_MS_U));
	P(CMD | AT,											SEND(KC_MS_R));
	P(CMD | AA | AR,									SEND(KC_BTN1));
	P(CMD | AR | AS,									SEND(KC_BTN3));
	P(CMD | AS | AT,									SEND(KC_BTN2));
	P(CMD | AA | AS,									SEND(KC_WH_D));
	P(CMD | AR | AT,									SEND(KC_WH_U));

	// User defs
	P(USR | AA | AR | AS | AT | AN | AE | AI | AO,		SET_STICKY(0));
	P(USR | AB,											SEND(KC_LSFT));
	P(USR | AK,											SEND(KC_SPC));
	P(USR | AA,											SEND(KC_F1));
	P(USR | AR,											SEND(KC_F2));
	P(USR | AA | AR,									SEND(KC_F3));
	P(USR | AS,											SEND(KC_F4));
	P(USR | AA | AS,									SEND(KC_F5));
	P(USR | AR | AS,									SEND(KC_F6));
	P(USR | AA | AR | AS,								SEND(KC_F7));
	P(USR | AT,											SEND(KC_F8));
	P(USR | AA | AT,									SEND(KC_F9));
	P(USR | AR | AT,									SEND(KC_F10));
	P(USR | AA | AR | AT,								SEND(KC_F11));
	P(USR | AS | AT,									SEND(KC_F12));
	P(USR | AA | AS | AT,								SEND(KC_F13));
	P(USR | AR | AS | AT,								SEND(KC_F14));
	P(USR | AA | AR | AS | AT,							SEND(KC_F15));

#ifdef USE_COMMON
	// Word Defs

#endif
	return 0;
}

// QMK layout, Make all your changesw in processQwerty!
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_ginny(
		STN_S1, STN_S2, STN_TL, STN_KL, STN_PL, STN_WL, STN_HL, STN_RL, STN_ST1, STN_ST2
)};

// Don't fuck with this, thanks.
size_t keymapsCount  = sizeof(keymaps)/sizeof(keymaps[0]);
