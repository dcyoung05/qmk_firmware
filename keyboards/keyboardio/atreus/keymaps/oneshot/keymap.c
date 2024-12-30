#include QMK_KEYBOARD_H

enum layer_names {
    BASE,
    GAME,
    NAV,
    NUM,
    SYM,
    FUN,
};

enum my_keycodes {
    CLEAR = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,   
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,   KC_NO,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH ,
    KC_NO,   DF(GAME),   CLEAR,  MO(SYM), MO(NAV), KC_LSFT,         KC_SPC, MO(NUM), MO(FUN), KC_NO,   KC_NO,   KC_NO),

  [GAME] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_NO,    KC_PGUP,    KC_UP,    KC_PGDN,    KC_NO,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_NO,    KC_LEFT,    KC_DOWN,    KC_RIGHT,    KC_NO,
    KC_LALT, KC_LCTL, KC_LSFT, KC_NO,   KC_NO,    KC_NO,   KC_NO,    MO(FUN),  MO(NUM),    KC_LSFT,    KC_LCTL,    KC_LALT,
    KC_NO,   DF(BASE),   KC_TRNS,   KC_ESC,  KC_SPC,  KC_TAB,  KC_ENTER, KC_BSPC,  KC_DEL,   KC_NO,    KC_NO,    KC_NO),

  [NAV] = LAYOUT( 
    KC_TAB, LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_ESC,      KC_BSPC, LCTL(KC_V), LCTL(KC_C), LCTL(KC_X), KC_DEL,
    OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT), KC_ENTER,  KC_CAPS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                KC_NO, KC_INS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
    KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO ),

  [NUM] = LAYOUT(
    KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC,                      KC_NO, LCTL(KC_V), LCTL(KC_C), LCTL(KC_X), QK_BOOT,
    KC_0, KC_4, KC_5, KC_6, KC_EQUAL,                     KC_NO, OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI),
    KC_SCLN, KC_1, KC_2, KC_3, KC_BSLS, KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO ),

  [SYM] = LAYOUT(
    KC_ESC, KC_LBRC, KC_LCBR, KC_LPRN, KC_TILD,            KC_CIRC, KC_RPRN, KC_RCBR, KC_RBRC, KC_GRV,
    OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT), KC_DLR,      
                                                             KC_HASH, KC_UNDS, KC_EQL, KC_ASTR, KC_MINS,
    KC_PLUS, KC_PIPE, KC_AT, KC_SLSH, KC_PERC, KC_NO,       KC_NO, KC_COLN, KC_BSLS, KC_AMPR, KC_QUES, KC_EXLM,
    KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO ),

  [FUN] = LAYOUT(
    KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,                     KC_NO, LCTL(KC_V), LCTL(KC_C), LCTL(KC_X), QK_BOOT,
    KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL,                     KC_NO, OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI),
    KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUSE, KC_NO,             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == CLEAR && record->event.pressed) {
        bool rc = true;
        uint8_t mods = 0;
        if ((mods = get_oneshot_mods()) && !has_oneshot_mods_timed_out()) {
            clear_oneshot_mods();
            unregister_mods(mods);
            rc = false;
        }
        if ((mods = get_oneshot_locked_mods())) {
            clear_oneshot_locked_mods();
            unregister_mods(mods);
            rc = false;
        }
        if (is_oneshot_layer_active()) {
            layer_clear();
            rc = false;
        }
        return rc;
    }
    return true;
}