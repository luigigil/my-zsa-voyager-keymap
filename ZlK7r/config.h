/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#undef DEBOUNCE
#define DEBOUNCE 3

#define USB_SUSPEND_WAKEUP_DELAY 0
#define SERIAL_NUMBER "ZlK7r/5WWqDB"
#define LAYER_STATE_8BIT

#define RGB_MATRIX_STARTUP_SPD 60

// Tap-hold configuration for home row mods.
#define TAPPING_TERM 175
#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM_PER_KEY
