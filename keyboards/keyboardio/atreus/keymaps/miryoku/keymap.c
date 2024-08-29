#include QMK_KEYBOARD_H

enum layer_names {
    BASE,
    NAV,
    MOUSE,
    MEDIA,
    NUM,
    SYM,
    FUN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,
    LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F),   KC_G, KC_H,    
                                                                  LSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_QUOT),
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,   KC_NO,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH ,
    KC_NO,   KC_NO,   KC_NO,   LT(MEDIA, KC_ESC), LT(NAV, KC_SPC), LT(MOUSE, KC_TAB), 
                                     LT(SYM, KC_ENTER), LT(NUM, KC_BSPC), LT(FUN, KC_DEL), KC_NO,   KC_NO,   KC_NO),

  [NAV] = LAYOUT( 
    QK_BOOT, LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_NO,      LCTL(KC_Y), LCTL(KC_V), LCTL(KC_C), LCTL(KC_X), LCTL(KC_Z),
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,               KC_CAPS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                KC_NO, KC_INS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                KC_ENT, KC_BSPC, KC_DEL, KC_NO, KC_NO, KC_NO ),
  
  [MOUSE] = LAYOUT(
    QK_BOOT, LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_NO,      LCTL(KC_Y), LCTL(KC_V), LCTL(KC_C), LCTL(KC_X), LCTL(KC_Z),
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,               KC_NO, MS_LEFT, MS_DOWN, MS_UP, MS_RGHT,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                KC_NO, KC_NO, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                MS_BTN2, MS_BTN1, MS_BTN3, KC_NO, KC_NO, KC_NO ),

  [MEDIA] = LAYOUT(
    QK_BOOT, LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_NO,      LCTL(KC_Y), LCTL(KC_V), LCTL(KC_C), LCTL(KC_X), LCTL(KC_Z),
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,               KC_NO, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                KC_MSTP, KC_MPLY, KC_MUTE, KC_NO, KC_NO, KC_NO ),

  [NUM] = LAYOUT(
    KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC,                      KC_NO, LCTL(KC_V), LCTL(KC_C), LCTL(KC_X), QK_BOOT,
    KC_SCLN, KC_4, KC_5, KC_6, KC_EQUAL,                     KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,
    KC_GRAVE, KC_1, KC_2, KC_3, KC_BSLS, KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_DOT, KC_0, KC_MINUS,             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO ),

  [SYM] = LAYOUT(
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,             KC_NO, LCTL(KC_V), LCTL(KC_C), LCTL(KC_X), QK_BOOT,
    KC_COLN, KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,              KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,
    KC_TILDE, KC_EXLM, KC_AT, KC_HASH, KC_PIPE, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_LPRN, KC_RPRN, KC_UNDS,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO ),

  [FUN] = LAYOUT(
    KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,                     KC_NO, LCTL(KC_V), LCTL(KC_C), LCTL(KC_X), QK_BOOT,
    KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL,                     KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,
    KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUSE, KC_NO,             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_ESC, KC_SPC, KC_TAB,             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO ),
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case LGUI_T(KC_A):
    case LALT_T(KC_S):
    case LALT_T(KC_L):
    case LGUI_T(KC_QUOT):
      return 400;
    default:
      return 200;
  }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case LSFT_T(KC_F):
        case LSFT_T(KC_J):
        case LT(NAV, KC_SPC):
        case LT(NUM, KC_BSPC):
            return true;
        default:
            return false;
    }
}
