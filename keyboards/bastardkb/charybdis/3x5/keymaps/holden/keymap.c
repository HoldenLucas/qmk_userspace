#include QMK_KEYBOARD_H

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_SYM,
    LAYER_NAV,
    LAYER_FUN,
    LAYER_PNT,
};

enum custom_keycodes {
    QEXCL = SAFE_RANGE, // tap: ? | shift+tap: !  (urob's qexcl mod-morph)
    U_CUT,              // OS-aware: Cmd+X (macOS) / Ctrl+X (other)
    U_COPY,             // OS-aware: Cmd+C (macOS) / Ctrl+Ins (other)
    U_PASTE,            // OS-aware: Cmd+V (macOS) / Shift+Ins (other)
};

// urob-style shifted punctuation via key overrides (NOT custom keycodes, so
// the comma/dot keys stay KC_COMM/KC_DOT and still work as combo triggers):
//   Shift + ,  ->  ;      Shift + .  ->  :
const key_override_t comma_semi_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN);
const key_override_t dot_colon_override  = ko_make_basic(MOD_MASK_SHIFT, KC_DOT,  KC_COLN);

const key_override_t *key_overrides[] = {
    &comma_semi_override,
    &dot_colon_override,
};

// Automatically enable sniping-mode on the pointer layer.
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_PNT

// custom keys
#define SPC_NAV LT(LAYER_NAV, KC_SPC)
#define BSP_SYM LT(LAYER_SYM, KC_BSPC)
#define PT_Z LT(LAYER_PNT, KC_Z)

#include "combos.h" // define combos from combos.def

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

// Charybdis Nano (3x5) LAYOUT: 3x5 + 5 thumbs (3 left, 2 right; trackball is
// on the right half). Thumb order per layer: L_out, L_mid, L_in, R_in, R_out.
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌───────────┬───────────┬───────────┬───────────┬─────────┐   ┌─────────┬───────────┬───────────┬───────────┬───────────┐
//    │     q     │     w     │     f     │     p     │    b    │   │    j    │     l     │     u     │     y     │     '     │
//    ├───────────┼───────────┼───────────┼───────────┼─────────┤   ├─────────┼───────────┼───────────┼───────────┼───────────┤
//    │ LGUI_T(a) │ LALT_T(r) │ LCTL_T(s) │ LSFT_T(t) │    g    │   │    m    │ RSFT_T(n) │ RCTL_T(e) │ RALT_T(i) │ RGUI_T(o) │
//    ├───────────┼───────────┼───────────┼───────────┼─────────┤   ├─────────┼───────────┼───────────┼───────────┼───────────┤
//    │   PT_Z    │     x     │     c     │     d     │    v    │   │    k    │     h     │    ,/;    │    ./:    │   ?/!     │
//    └───────────┴───────────┼───────────┼───────────┼─────────┤   ├─────────┼───────────┼───────────┴───────────┴───────────┘
//                            │    no     │    tab    │ SPC_NAV │   │ BSP_SYM │    no     │
//                            └───────────┴───────────┴─────────┘   └─────────┴───────────┘
[LAYER_BASE] = LAYOUT(
  KC_Q         , KC_W         , KC_F         , KC_P         , KC_B    ,     KC_J    , KC_L         , KC_U         , KC_Y         , KC_QUOT     ,
  LGUI_T(KC_A) , LALT_T(KC_R) , LCTL_T(KC_S) , LSFT_T(KC_T) , KC_G    ,     KC_M    , RSFT_T(KC_N) , RCTL_T(KC_E) , RALT_T(KC_I) , RGUI_T(KC_O),
  PT_Z         , KC_X         , KC_C         , KC_D         , KC_V    ,     KC_K    , KC_H         , KC_COMM      , KC_DOT       , QEXCL       ,
                                XXXXXXX      , KC_TAB       , SPC_NAV ,     BSP_SYM , XXXXXXX
),

[LAYER_NAV] = LAYOUT(
  XXXXXXX , C(KC_TAB)    , A(KC_TAB)    , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  KC_LGUI , KC_LALT      , KC_LCTL      , KC_LSFT , XXXXXXX ,     XXXXXXX , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT,
  XXXXXXX , S(C(KC_TAB)) , S(A(KC_TAB)) , XXXXXXX , XXXXXXX ,     XXXXXXX , KC_HOME , KC_PGDN , KC_PGUP , KC_END ,
                           XXXXXXX      , XXXXXXX , _______ ,     XXXXXXX , XXXXXXX
),

[LAYER_FUN] = LAYOUT(
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     KC_PSCR , KC_F7   , KC_F8   , KC_F9 , KC_F12,
  KC_LGUI , KC_LALT , KC_LCTL , KC_LSFT , XXXXXXX ,     KC_SCRL , KC_F4   , KC_F5   , KC_F6 , KC_F11,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     KC_PAUS , KC_F1   , KC_F2   , KC_F3 , KC_F10,
                      XXXXXXX , XXXXXXX , _______ ,     _______ , XXXXXXX
),

[LAYER_PNT] = LAYOUT(
  XXXXXXX , EE_CLR  , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  KC_LGUI , KC_LALT , KC_LCTL , KC_LSFT , DRGSCRL ,     XXXXXXX , KC_LSFT , KC_LCTL , KC_LALT , KC_LGUI,
  _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
                      MS_BTN3 , MS_BTN2 , MS_BTN1 ,     MS_BTN1 , MS_BTN2
),

[LAYER_SYM] = LAYOUT(
  KC_LBRC , KC_AT  , KC_ASTR , KC_DLR  , KC_RBRC ,     XXXXXXX , KC_7         , KC_8         , KC_9         , XXXXXXX        ,
  XXXXXXX , KC_EQL , KC_UNDS , KC_MINS , KC_PERC ,     XXXXXXX , RSFT_T(KC_4) , RSFT_T(KC_5) , RCTL_T(KC_6) , RALT_T(KC_COMM),
  KC_PLUS , KC_GRV , KC_HASH , KC_AMPR , KC_CIRC ,     KC_0    , KC_1         , KC_2         , KC_3         , KC_DOT         ,
                     XXXXXXX , KC_LPRN , KC_RPRN ,     _______ , XXXXXXX
)
};
// clang-format on

// Track the time of the last key press so we can gate combos that overlap the
// home row. combo_should_trigger() below rejects those combos when a key was
// pressed within COMBO_HRM_IDLE_MS, i.e. you're mid-typing.
static uint16_t last_keypress_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        last_keypress_timer = record->event.time;

        if (keycode == QEXCL) {
            if (get_mods() & MOD_MASK_SHIFT) {
                tap_code(KC_1);      // shift already held -> '!'
            } else {
                tap_code16(KC_QUES); // shift+/ -> '?'
            }
            return false;
        }

        // OS-aware clipboard: macOS uses Cmd, everything else uses the
        // Windows/Linux Ctrl+X / Ctrl+Ins / Shift+Ins bindings.
        if (keycode == U_CUT || keycode == U_COPY || keycode == U_PASTE) {
            bool mac;
            switch (detected_host_os()) {
                case OS_MACOS:
                case OS_IOS:
                    mac = true;
                    break;
                default:
                    mac = false;
                    break;
            }
            switch (keycode) {
                case U_CUT:
                    tap_code16(mac ? G(KC_X) : C(KC_X));
                    break;
                case U_COPY:
                    tap_code16(mac ? G(KC_C) : C(KC_INS));
                    break;
                case U_PASTE:
                    tap_code16(mac ? G(KC_V) : S(KC_INS));
                    break;
            }
            return false;
        }
    }
    return true;
}

#ifdef COMBO_SHOULD_TRIGGER
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        // Home row combos: only fire after a brief idle so fast rolls
        // (e/i -> Enter, r/s -> Escape) don't misfire while typing.
        case C_ENTER:
        case C_ESCAPE:
            return timer_elapsed(last_keypress_timer) >= COMBO_HRM_IDLE_MS;
        // Clipboard combos sit on adjacent typing keys (x/c/d); gate them too
        // so fast rolls don't misfire cut/copy/paste.
        case C_CUT:
        case C_COPY:
        case C_PASTE:
            return timer_elapsed(last_keypress_timer) >= COMBO_HRM_IDLE_MS;
    }
    return true;
}
#endif // COMBO_SHOULD_TRIGGER

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE
