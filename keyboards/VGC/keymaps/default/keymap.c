/* Copyright 2020 wherron01
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

uint16_t DPAD_LEFT[4] = {
        KC_F,
    KC_Z,   KC_C,
        KC_X
};
uint16_t DPAD_RIGHT[4] = {
        KC_1,
    KC_4,   KC_2,
        KC_3
};
uint16_t LEFT_BUMPER = KC_Q;
uint16_t LEFT_TRIGGER = KC_W;
uint16_t RIGHT_BUMPER = KC_MS_BTN1;
uint16_t RIGHT_TRIGGER = KC_MS_BTN2;
uint16_t BOTTOM_BUTTONS = {
    KC_LSHIFT,  KC_MS_WH_UP,
    KC_LCTRL,   KC_MS_WH_DOWN
};
uint16_t LEFT_STICK = {
        KC_W,
    KC_A,   KC_D,
        KC_S
};
uint16_t RIGHT_STICK = {
        MUP,
    MLEFT,  MRIGHT,
        MDOWN
};
uint16_t LEFT_STICK_BUTTON = KC_SPACE;
uint16_t RIGHT_STICK_BUTTON = KC_MS_BTN3;


// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE
};

// Defines the keycodes used by our macros in process_record_user
// For smooth mouse motion, uses custom mouse implementaion only usable by analog stick.  Proto-keycodes for this motion and scroll motion are below
enum custom_keycodes {
    MUP,
    MLEFT,
    MDOWN,
    MRIGHT,
    SUP,
    SLEFT,
    SDOWN,
    SRIGHT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = {DPAD_LEFT, DPAD_RIGHT, {LEFT_BUMPER, RIGHT_BUMPER, LEFT_TRIGGER, RIGHT_TRIGGER}, BOTTOM_BUTTONS}
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

    }
    return true;
}


/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
