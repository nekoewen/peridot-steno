#include "peridot.h"
#include "keymap_steno.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT(
		           STN_N1, STN_N2,                            STN_N3, STN_N4, 
		        STN_TL, STN_PL, STN_HL, STN_ST1, STN_FR, STN_PR, STN_LR, STN_TR, STN_DR, 
		STN_S1, STN_KL, STN_WL, STN_RL,          STN_RR, STN_BR, STN_GR, STN_SR, STN_ZR, 
		                STN_A,  STN_O,  STN_ST2, STN_E,  STN_U),
};

void matrix_scan_user(void) {
}
