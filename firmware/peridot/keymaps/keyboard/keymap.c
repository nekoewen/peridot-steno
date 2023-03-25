#include "peridot.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT(
		KC_1, KC_2, KC_3, KC_4, 
		      KC_W, KC_E, KC_R, KC_T, KC_U, KC_I, KC_O, KC_P,    KC_LBRC,
		KC_Q, KC_S, KC_D, KC_F,       KC_J, KC_K, KC_L, KC_SCLN, KC_SCLN, 
		KC_C, KC_V, KC_G, KC_N, KC_M),
};

void matrix_scan_user(void) {
}
