#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE
#include "features/achordion.h"

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRANSPARENT, 
                                                    MT(MOD_LCTL, KC_SPACE),MO(2),                                          MO(1),          KC_ENTER
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_QUOTE,       KC_MINUS,       KC_LBRC,        KC_RBRC,        KC_EQUAL,                                       KC_BSLS,        OSM(MOD_RSFT),  OSM(MOD_LALT),  OSM(MOD_LCTL),  OSM(MOD_LGUI),  KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_DQUO,        KC_UNDS,        KC_LCBR,        KC_RCBR,        KC_PLUS,                                        KC_PIPE,        KC_GRAVE,       KC_TILD,        KC_RABK,        KC_QUES,        KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, MO(3),                                          KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TAB,         ST_MACRO_0,     KC_ESCAPE,      ST_MACRO_1,     KC_AUDIO_VOL_UP,                                KC_DELETE,      KC_HOME,        KC_BSPC,        KC_END,         KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, OSM(MOD_LGUI),  OSM(MOD_LCTL),  OSM(MOD_LALT),  OSM(MOD_LSFT),  KC_AUDIO_VOL_DOWN,                                KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_CAPS,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,                                KC_ENTER,       KC_PAGE_UP,     KC_PAGE_UP,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 MO(3),          KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT, 
    KC_TRANSPARENT, OSM(MOD_LGUI),  OSM(MOD_LCTL),  OSM(MOD_LALT),  OSM(MOD_LSFT),  KC_F11,                                         KC_F12,         OSM(MOD_RSFT),  OSM(MOD_LALT),  OSM(MOD_LCTL),  OSM(MOD_LGUI),  KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_achordion(keycode, record)) { return false; }

  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_LEFT_SHIFT) SS_TAP(X_A) ));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_LEFT_SHIFT) SS_TAP(X_D) ));
    }
    break;

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}


void housekeeping_task_user(void) {
  achordion_task();
}

/*uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {*/
/*  // If you quickly hold a tap-hold key after tapping it, the tap action is*/
/*  // repeated. Key repeating is useful e.g. for Vim navigation keys, but can*/
/*  // lead to missed triggers in fast typing. Here, returning 0 means we*/
/*  // instead want to "force hold" and disable key repeating.*/
/*  switch (keycode) {*/
/*    case HOME_N:*/
/*    // Repeating is useful for Vim navigation keys.*/
/*    case QHOME_J:*/
/*    case QHOME_K:*/
/*    case QHOME_L:*/
/*      return QUICK_TAP_TERM;  // Enable key repeating.*/
/*    default:*/
/*      return 0;  // Otherwise, force hold and disable key repeating.*/
/*  }*/
/*}*/
