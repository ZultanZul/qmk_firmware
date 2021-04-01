/* Copyright 2018 Jack Humbert
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

#define _BASE 0
#define _FN1 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*	 RGB_TOG, RGB_MOD, RGB_HUI, \
*	RGB_SAI, RGB_VAI, KC_RBRACKET, \
*
*	KC_MINUS, KC_EQUAL, KC_GRAVE, \
*	KC_LBRACKET, KC_UP, KC_RBRACKET, \
*/
	[_BASE] = LAYOUT(
		KC_MINUS, KC_EQUAL, KC_GRAVE, \
		KC_LBRACKET, KC_UP, KC_RBRACKET, \
		KC_LEFT, KC_DOWN, KC_RIGHT, \
		KC_RSHIFT, TG(1), KC_ENTER \
	),

	[_FN1] = LAYOUT(
		KC_7, KC_8, KC_9, \
		KC_4, KC_5, KC_6, \
		KC_1, KC_2, KC_3, \
		KC_0, TG(1), KC_ENT \
	)
};



#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
}

void oled_task_user(void) {
  // Host Keyboard Layer Status
//   oled_write_P(PSTR("something\nLet's\nbuild\nsome-\nthing\nto-\nget-\nher!"), false);
  oled_write_P(PSTR("Did you ever hear the Tragedy of Darth Plagueis the wise? I thought not. It's not a story the Jedi would tell you. It's a Sith legend. "), false);

//   Did you ever hear the Tragedy of Darth Plagueis the wise? I thought not. It's not a story the Jedi would tell you. It's a Sith legend. Darth Plagueis was a Dark Lord of the Sith, so powerful and so wise he could use the Force to influence the midichlorians to create life...


//   switch (get_highest_layer(layer_state)) {
//     case _BASE:
//       oled_write_ln_P(PSTR("\nARROWS"), false);
//       break;
//     case _FN1:
//       oled_write_ln_P(PSTR("\nNUMPAD"), false);
//       break;
//     default:
//       // Or use the write_ln shortcut over adding '\n' to the end of your string
//       oled_write_ln_P(PSTR("Undef"), false);
//   }

  // Host Keyboard LED Status
  uint8_t led_usb_state = host_keyboard_leds();
  oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NLCK ") : PSTR("     "), false);
  oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPS ") : PSTR("       "), false);
  oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLK") : PSTR("       "), false);
}
#endif
