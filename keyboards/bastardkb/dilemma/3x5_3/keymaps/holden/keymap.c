#include QMK_KEYBOARD_H

enum dilemma_keymap_layers {
    LAYER_BASE = 0,
    LAYER_SYM,
    LAYER_NAV,
    LAYER_FUN,
    LAYER_PNT,
};

enum custom_keycodes {
    QEXCL = SAFE_RANGE, // tap: ? | shift+tap: !  (urob's qexcl mod-morph)
};

#define DILEMMA_AUTO_SNIPING_ON_LAYER LAYER_PNT

// custom keys
#define SPC_NAV LT(LAYER_NAV, KC_SPC)
#define BSP_SYM LT(LAYER_SYM, KC_BSPC)
#define PT_Z LT(LAYER_PNT, KC_Z)
#define CUSTOM_1 OSL(LAYER_FUN)

#include "combos.h" // define combos from combos.def

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌───────────┬───────────┬───────────┬───────────┬─────────┐   ┌─────────┬───────────┬───────────┬───────────┬───────────┐
//    │     q     │     w     │     f     │     p     │    b    │   │    j    │     l     │     u     │     y     │     '     │
//    ├───────────┼───────────┼───────────┼───────────┼─────────┤   ├─────────┼───────────┼───────────┼───────────┼───────────┤
//    │ LGUI_T(a) │ LALT_T(r) │ LCTL_T(s) │ LSFT_T(t) │    g    │   │    m    │ RSFT_T(n) │ RCTL_T(e) │ RALT_T(i) │ RGUI_T(o) │
//    ├───────────┼───────────┼───────────┼───────────┼─────────┤   ├─────────┼───────────┼───────────┼───────────┼───────────┤
//    │   PT_Z    │     x     │     c     │     d     │    v    │   │    k    │     h     │     ,     │     .     │     /     │
//    └───────────┴───────────┼───────────┼───────────┼─────────┤   ├─────────┼───────────┼───────────┼───────────┴───────────┘
//                            │    no     │    tab    │ SPC_NAV │   │ BSP_SYM │    no     │    no     │
//                            └───────────┴───────────┴─────────┘   └─────────┴───────────┴───────────┘
[LAYER_BASE] = LAYOUT_split_3x5_3(
  KC_Q         , KC_W         , KC_F         , KC_P         , KC_B    ,     KC_J    , KC_L         , KC_U         , KC_Y         , KC_QUOT     ,
  LGUI_T(KC_A) , LALT_T(KC_R) , LCTL_T(KC_S) , LSFT_T(KC_T) , KC_G    ,     KC_M    , RSFT_T(KC_N) , RCTL_T(KC_E) , RALT_T(KC_I) , RGUI_T(KC_O),
  PT_Z         , KC_X         , KC_C         , KC_D         , KC_V    ,     KC_K    , KC_H         , KC_COMM      , KC_DOT       , QEXCL       ,
                                XXXXXXX      , KC_TAB       , SPC_NAV ,     BSP_SYM , XXXXXXX      , XXXXXXX
),

//    ┌──────┬───────────┬───────────┬──────┬─────┐   ┌────┬──────┬──────┬──────┬──────┐
//    │  no  │  C(tab)   │  A(tab)   │  no  │ no  │   │ no │  no  │  no  │  no  │  no  │
//    ├──────┼───────────┼───────────┼──────┼─────┤   ├────┼──────┼──────┼──────┼──────┤
//    │ lgui │   lalt    │   lctl    │ lsft │ no  │   │ no │ left │ down │  up  │ rght │
//    ├──────┼───────────┼───────────┼──────┼─────┤   ├────┼──────┼──────┼──────┼──────┤
//    │  no  │ S(C(tab)) │ S(A(tab)) │  no  │ no  │   │ no │ home │ pgdn │ pgup │ end  │
//    └──────┴───────────┼───────────┼──────┼─────┤   ├────┼──────┼──────┼──────┴──────┘
//                       │    no     │  no  │     │   │ no │  no  │  no  │
//                       └───────────┴──────┴─────┘   └────┴──────┴──────┘
[LAYER_NAV] = LAYOUT_split_3x5_3(
  XXXXXXX , C(KC_TAB)    , A(KC_TAB)    , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  KC_LGUI , KC_LALT      , KC_LCTL      , KC_LSFT , XXXXXXX ,     XXXXXXX , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT,
  XXXXXXX , S(C(KC_TAB)) , S(A(KC_TAB)) , XXXXXXX , XXXXXXX ,     XXXXXXX , KC_HOME , KC_PGDN , KC_PGUP , KC_END ,
                           XXXXXXX      , XXXXXXX , _______ ,     XXXXXXX , XXXXXXX , XXXXXXX
),

//    ┌──────┬──────┬──────┬──────┬─────┐   ┌──────┬────┬────┬────┬─────┐
//    │  no  │  no  │  no  │  no  │ no  │   │ pscr │ f7 │ f8 │ f9 │ f12 │
//    ├──────┼──────┼──────┼──────┼─────┤   ├──────┼────┼────┼────┼─────┤
//    │ lgui │ lalt │ lctl │ lsft │ no  │   │ sCRL │ f4 │ f5 │ f6 │ f11 │
//    ├──────┼──────┼──────┼──────┼─────┤   ├──────┼────┼────┼────┼─────┤
//    │  no  │  no  │  no  │  no  │ no  │   │ paus │ f1 │ f2 │ f3 │ f10 │
//    └──────┴──────┼──────┼──────┼─────┤   ├──────┼────┼────┼────┴─────┘
//                  │  no  │  no  │     │   │      │ no │ no │
//                  └──────┴──────┴─────┘   └──────┴────┴────┘
[LAYER_FUN] = LAYOUT_split_3x5_3(
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     KC_PSCR , KC_F7   , KC_F8   , KC_F9 , KC_F12,
  KC_LGUI , KC_LALT , KC_LCTL , KC_LSFT , XXXXXXX ,     KC_SCRL , KC_F4   , KC_F5   , KC_F6 , KC_F11,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     KC_PAUS , KC_F1   , KC_F2   , KC_F3 , KC_F10,
                      XXXXXXX , XXXXXXX , _______ ,     _______ , XXXXXXX , XXXXXXX
),

//    ┌──────┬────────┬──────┬──────┬──────┐   ┌──────┬──────┬──────┬──────┬──────┐
//    │  no  │ EE_CLR │  no  │  no  │  no  │   │  no  │  no  │  no  │  no  │  no  │
//    ├──────┼────────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┤
//    │ lgui │  lalt  │ lctl │ lsft │  no  │   │  no  │ lsft │ lctl │ lalt │ lgui │
//    ├──────┼────────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┤
//    │      │   no   │  no  │  no  │  no  │   │  no  │  no  │  no  │  no  │  no  │
//    └──────┴────────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┴──────┘
//                    │ btn3 │ btn2 │ btn1 │   │ btn1 │ btn2 │ btn3 │
//                    └──────┴──────┴──────┘   └──────┴──────┴──────┘
[LAYER_PNT] = LAYOUT_split_3x5_3(
  XXXXXXX , EE_CLR  , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  KC_LGUI , KC_LALT , KC_LCTL , KC_LSFT , XXXXXXX ,     XXXXXXX , KC_LSFT , KC_LCTL , KC_LALT , KC_LGUI,
  _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
                      MS_BTN3 , MS_BTN2 , MS_BTN1 ,     MS_BTN1 , MS_BTN2 , MS_BTN3
),

//    ┌───┬───┬────┬───┬───┐   ┌─────┬───────────┬───────────┬───────────┬───────────┐
//    │ [ │ @ │ *  │ $ │ ] │   │ no  │     7     │     8     │     9     │    no     │
//    ├───┼───┼────┼───┼───┤   ├─────┼───────────┼───────────┼───────────┼───────────┤
//    │ ! │ = │ _  │ - │ % │   │  /  │ RSFT_T(4) │ RSFT_T(5) │ RCTL_T(6) │ RALT_T(,) │
//    ├───┼───┼────┼───┼───┤   ├─────┼───────────┼───────────┼───────────┼───────────┤
//    │ + │ ` │ #  │ & │ ^ │   │  0  │     1     │     2     │     3     │     .     │
//    └───┴───┼────┼───┼───┤   ├─────┼───────────┼───────────┼───────────┴───────────┘
//            │ no │ ( │ ) │   │     │    no     │    no     │
//            └────┴───┴───┘   └─────┴───────────┴───────────┘
[LAYER_SYM] = LAYOUT_split_3x5_3(
  KC_LBRC , KC_AT  , KC_ASTR , KC_DLR  , KC_RBRC ,     XXXXXXX , KC_7         , KC_8         , KC_9         , XXXXXXX        ,
  KC_EXLM , KC_EQL , KC_UNDS , KC_MINS , KC_PERC ,     KC_SLSH , RSFT_T(KC_4) , RSFT_T(KC_5) , RCTL_T(KC_6) , RALT_T(KC_COMM),
  KC_PLUS , KC_GRV , KC_HASH , KC_AMPR , KC_CIRC ,     KC_0    , KC_1         , KC_2         , KC_3         , KC_DOT         ,
                     XXXXXXX , KC_LPRN , KC_RPRN ,     _______ , XXXXXXX      , XXXXXXX
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
    }
    return true;
}
#endif // COMBO_SHOULD_TRIGGER

#ifdef POINTING_DEVICE_ENABLE
#    ifdef DILEMMA_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    dilemma_set_pointer_sniping_enabled(layer_state_cmp(state, DILEMMA_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // DILEMMA_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE
