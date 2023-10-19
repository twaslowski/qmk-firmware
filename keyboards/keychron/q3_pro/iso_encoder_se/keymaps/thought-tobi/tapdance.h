// Tap Dance declarations
enum {
    TD_UNDO_REDO,
    TD_COPY_PASTE,
    TD_OPEN_TERMINAL,
    TD_BRACKETS,
    TD_CURLY_BRACKETS,
    TD_SQUARE_BRACKETS,
    TD_DIAMOND_BRACKETS,
    TD_EGG,
};

void dance_brackets(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_H);
    }
    if (state->count == 2) {
        tap_code16(KC_ASTR);
    }
    if (state->count == 3) {
        tap_code16(KC_LPRN);
    } else {
        reset_tap_dance(state);
    }
}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_UNDO_REDO] = ACTION_TAP_DANCE_DOUBLE(LCMD(KC_Y), LCMD(LSFT(KC_Y))),
    [TD_COPY_PASTE] = ACTION_TAP_DANCE_DOUBLE(LCMD(KC_C), LCMD(KC_V)),
    [TD_OPEN_TERMINAL] = ACTION_TAP_DANCE_DOUBLE(LALT(KC_F12), INTELLIJ_OPEN_ITERM),
    [TD_BRACKETS] = ACTION_TAP_DANCE_FN(dance_brackets),
};
