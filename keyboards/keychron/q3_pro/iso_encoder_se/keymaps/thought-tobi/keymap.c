/* Copyright 2023 @ Keychron (https://www.keychron.com)
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
#include <macros.h>
#include <tapdance.h>

// clang-format off
enum layers{
  MAC_BASE,
  INTELLIJ,
  COPILOT,
  WIN_FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_93_iso(
        KC_MUTE,  KC_ESC,             KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  KC_SNAP,  KC_SIRI,  RGB_MOD,
                  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        LCTL(LSFT(KC_C)),  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,              KC_DEL,   KC_END,   KC_PGDN,
        _______,  MO(INTELLIJ),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,    KC_ENT,
        _______,  KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,
        LCTL(LCMD(KC_Q)),  KC_LCTL,  KC_LOPT,  KC_LCMD,                                KC_SPC,                                 KC_RCMD,  KC_ROPT, MO(INTELLIJ), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [INTELLIJ] = LAYOUT_93_iso(
        RGB_TOG,  _______,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    LSFT(KC_F6),    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   _______,  _______,  _______,
                  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  LCMD(LALT(KC_TAB)),  _______,  INTELLIJ_CLOSE_PROJECT_WINDOW, _______,  INTELLIJ_OPEN_RECENT,  LALT(KC_F12),  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,  _______,  _______,
        _______,  _______,  _______, _______,  _______,  LCMD(KC_1),  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,
        _______,  _______,  _______,  _______,  _______,  DIFF_WITH_CLIPBOARD,  GIT_DIFF_REVISION,  GIT_DIFF_BRANCH,  _______,  _______,  _______,  _______,  _______,              _______,                LCMD(LOPT(KC_TAB)),
        _______,  _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  LCMD(LCTL(LSFT(KC_LEFT))),  LCMD(LOPT(LSFT(KC_TAB))),  LCMD(LCTL(LSFT(KC_RIGHT)))),

    [COPILOT] = LAYOUT_93_iso(
        _______,  _______,             _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______,     _______,   _______,  _______, RGB_MOD,
                  _______,   _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,  _______,     _______,  _______,   _______,  _______,
        _______,  _______,   _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,  _______,              _______,   _______,   _______,
        _______,  _______,  _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,  _______,  _______,    _______,
        _______,  _______,  _______,  _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,  _______,   _______,              _______,            COPILOT_SUGGESTIONS_WINDOW,
        _______,  _______,  _______,  _______,                                _______,                                 _______,  _______, _______, _______,  COPILOT_ACCEPT_LINE,  COPILOT_PREV_SUGGESTION, COPILOT_PREV_LINE),

    [WIN_FN] = LAYOUT_93_iso(
        RGB_TOG,  _______,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    _______,  _______,  RGB_TOG,
                  _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,  _______,
        _______,  _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = { ENCODER_CCW_CW(LCMD(KC_Y), LCMD(LSFT(KC_Y)))},  // undo/redo time wizardry
    [INTELLIJ]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [COPILOT] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
};
#endif // ENCODER_MAP_ENABLE

void keyboard_post_init_user(void) {
  // Set RGB effect here
  rgblight_mode(RGB_MATRIX_TYPING_HEATMAP);
}
