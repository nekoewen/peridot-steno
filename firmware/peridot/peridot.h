#ifndef KB_H
#define KB_H

#include "quantum.h"

#define LAYOUT( \
	K000,       K002,             K005,       K007,             \
	      K101, K102, K103, K104, K105, K106, K107, K108, K109, \
	K200, K201, K202, K203,       K205, K206, K207, K208, K209, \
	            K302, K303, K304, K305, K306  \
) { \
	{ K000,  KC_NO, K002,  KC_NO, KC_NO, K005,  KC_NO, K007,  KC_NO, KC_NO }, \
	{ KC_NO, K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109 }, \
	{ K200,  K201,  K202,  K203,  KC_NO, K205,  K206,  K207,  K208,  K209 }, \
	{ KC_NO, KC_NO, K302,  K303,  K304,  K305,  K306,  KC_NO, KC_NO, KC_NO }  \
}

#endif