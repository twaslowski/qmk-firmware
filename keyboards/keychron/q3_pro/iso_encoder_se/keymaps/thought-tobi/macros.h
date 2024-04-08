// macro declarations
enum custom_keycodes {
    INTELLIJ_OPEN_RECENT = SAFE_RANGE,
    INTELLIJ_SWITCH_PROJECT_TAB_TAB,
    INTELLIJ_CLOSE_PROJECT_WINDOW,
    GIT_DIFF_BRANCH,
    GIT_DIFF_REVISION,
};

// macro definitions
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case INTELLIJ_OPEN_RECENT:
        if (record -> event.pressed) {
            SEND_STRING(SS_LCTL(SS_LCMD(SS_LALT(SS_LSFT(SS_TAP(X_I))))) SS_DELAY(10) SS_TAP(X_R));
            break;
        }
    case INTELLIJ_CLOSE_PROJECT_WINDOW:
        if (record -> event.pressed) {
            SEND_STRING(SS_LCMD(SS_LALT(SS_LSFT(SS_TAP(X_W)))));
            break;
        }
    case GIT_DIFF_BRANCH:
        if (record -> event.pressed) {
            SEND_STRING(SS_LCTL(SS_LCMD(SS_LALT(SS_LSFT(SS_TAP(X_G))))) SS_TAP(X_C));
            break;
        }
    case GIT_DIFF_REVISION:
        if (record -> event.pressed) {
            SEND_STRING(SS_LCTL(SS_LCMD(SS_LALT(SS_LSFT(SS_TAP(X_G))))) SS_TAP(X_V));
            break;
        }
    }
    return true;
};
