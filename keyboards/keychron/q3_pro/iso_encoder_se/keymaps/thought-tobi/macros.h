// macro declarations
enum custom_keycodes {
    INTELLIJ_OPEN_RECENT = SAFE_RANGE,
    INTELLIJ_CLOSE_PROJECT_WINDOW,
    GIT_DIFF_BRANCH,
    GIT_DIFF_REVISION,
    NONE, // cursed slot, registers cmd+tab
    DIFF_WITH_CLIPBOARD,
    COPILOT_ACCEPT_LINE,
    COPILOT_SUGGESTIONS_WINDOW,
    NONE_2, // cursed slot, opens siri
    COPILOT_PREV_SUGGESTION,
    COPILOT_PREV_LINE
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
            SEND_STRING(SS_LCTL(SS_LCMD(SS_LALT(SS_LSFT(SS_TAP(X_G))))) SS_TAP(X_B));
            break;
        }
    case GIT_DIFF_REVISION:
        if (record -> event.pressed) {
            SEND_STRING(SS_LCTL(SS_LCMD(SS_LALT(SS_LSFT(SS_TAP(X_G))))) SS_TAP(X_V));
            break;
        }
    case DIFF_WITH_CLIPBOARD:
        if (record -> event.pressed) {
            SEND_STRING(SS_LCTL(SS_LCMD(SS_LALT(SS_LSFT(SS_TAP(X_I))))) SS_TAP(X_C));
            break;
        }
    case COPILOT_SUGGESTIONS_WINDOW:
        if (record -> event.pressed) {
            SEND_STRING(SS_LCTL(SS_LCMD(SS_LALT(SS_LSFT(SS_TAP(X_C))))) SS_TAP(X_UP));
            break;
        }
    case COPILOT_PREV_SUGGESTION:
        if (record -> event.pressed) {
            SEND_STRING(SS_LCTL(SS_LCMD(SS_LALT(SS_LSFT(SS_TAP(X_C))))) SS_TAP(X_DOWN));
            break;
        }
    case COPILOT_ACCEPT_LINE:
        if (record -> event.pressed) {
            SEND_STRING(SS_LCTL(SS_LCMD(SS_LALT(SS_LSFT(SS_TAP(X_C))))) SS_TAP(X_LEFT));
            break;
        }
    case COPILOT_PREV_LINE:
        if (record -> event.pressed) {
            SEND_STRING(SS_LCTL(SS_LCMD(SS_LALT(SS_LSFT(SS_TAP(X_C))))) SS_TAP(X_RIGHT));
            break;
        }
    case NONE:
        break;
    }
    return true;
};
