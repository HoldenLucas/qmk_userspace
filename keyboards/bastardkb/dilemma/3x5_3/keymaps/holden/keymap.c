#include QMK_KEYBOARD_H

enum dilemma_keymap_layers {
    LAYER_BASE = 0,
    LAYER_NAVIGATION,
    LAYER_FUNCTION,
    LAYER_MEDIA,
    LAYER_POINTER,
    LAYER_NUMERAL,
    LAYER_SYMBOLS,
};

// Automatically enable sniping-mode on the pointer layer.
#define DILEMMA_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#define ESC_MED LT(LAYER_MEDIA, KC_ESC)
#define SPC_NAV LT(LAYER_NAVIGATION, KC_SPC)
#define TAB_FUN LT(LAYER_FUNCTION, KC_TAB)
#define ENT_SYM LT(LAYER_SYMBOLS, KC_ENT)
#define BSP_NUM LT(LAYER_NUMERAL, KC_BSPC)
#define PT_Z LT(LAYER_POINTER, KC_Z)
#define PT_SLSH LT(LAYER_POINTER, KC_SLSH)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌───────────┬───────────┬───────────┬───────────┬─────────┐   ┌─────────┬───────────┬─────────┬───────────┬───────────┐
//    │     q     │     w     │     f     │     p     │    b    │   │    j    │     l     │    u    │     y     │     '     │
//    ├───────────┼───────────┼───────────┼───────────┼─────────┤   ├─────────┼───────────┼─────────┼───────────┼───────────┤
//    │ LGUI_T(a) │ LALT_T(r) │ LCTL_T(s) │ LSFT_T(t) │    g    │   │    m    │ RSFT_T(n) │  RCTL   │ RALT_T(i) │ RGUI_T(o) │
//    ├───────────┼───────────┼───────────┼───────────┼─────────┤   ├─────────┼───────────┼─────────┼───────────┼───────────┤
//    │   PT_Z    │     x     │     c     │     d     │    v    │   │    k    │     h     │    ,    │     .     │  PT_SLSH  │
//    └───────────┴───────────┼───────────┼───────────┼─────────┤   ├─────────┼───────────┼─────────┼───────────┴───────────┘
//                            │  ESC_MED  │  SPC_NAV  │ TAB_FUN │   │ ENT_SYM │     e     │ BSP_NUM │
//                            └───────────┴───────────┴─────────┘   └─────────┴───────────┴─────────┘
[LAYER_BASE] = LAYOUT_split_3x5_3(
  KC_Q         , KC_W         , KC_F         , KC_P         , KC_B    ,     KC_J    , KC_L         , KC_U    , KC_Y         , KC_QUOT     ,
  LGUI_T(KC_A) , LALT_T(KC_R) , LCTL_T(KC_S) , LSFT_T(KC_T) , KC_G    ,     KC_M    , RSFT_T(KC_N) , RCTL    , RALT_T(KC_I) , RGUI_T(KC_O),
  PT_Z         , KC_X         , KC_C         , KC_D         , KC_V    ,     KC_K    , KC_H         , KC_COMM , KC_DOT       , PT_SLSH     ,
                                ESC_MED      , SPC_NAV      , TAB_FUN ,     ENT_SYM , KC_E         , BSP_NUM
),

//    ┌──────┬──────┬──────┬──────┬────┐   ┌──────┬──────┬──────┬──────┬──────┐
//    │  no  │  no  │  no  │  no  │ no │   │  no  │  no  │  no  │  no  │  no  │
//    ├──────┼──────┼──────┼──────┼────┤   ├──────┼──────┼──────┼──────┼──────┤
//    │ lgui │ lalt │ lctl │ lsft │ no │   │ caps │ left │ down │  up  │ rght │
//    ├──────┼──────┼──────┼──────┼────┤   ├──────┼──────┼──────┼──────┼──────┤
//    │  no  │  no  │  no  │  no  │ no │   │ ins  │ home │ pgdn │ pgup │ end  │
//    └──────┴──────┼──────┼──────┼────┤   ├──────┼──────┼──────┼──────┴──────┘
//                  │  no  │      │ no │   │ ent  │ bspc │ del  │
//                  └──────┴──────┴────┘   └──────┴──────┴──────┘
[LAYER_NAVIGATION] = LAYOUT_split_3x5_3(
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  KC_LGUI , KC_LALT , KC_LCTL , KC_LSFT , XXXXXXX ,     KC_CAPS , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     KC_INS  , KC_HOME , KC_PGDN , KC_PGUP , KC_END ,
                      XXXXXXX , _______ , XXXXXXX ,     KC_ENT  , KC_BSPC , KC_DEL
),

//    ┌──────┬──────┬──────┬──────┬─────┐   ┌──────┬────┬────┬────┬─────┐
//    │  no  │  no  │  no  │  no  │ no  │   │ pscr │ f7 │ f8 │ f9 │ f12 │
//    ├──────┼──────┼──────┼──────┼─────┤   ├──────┼────┼────┼────┼─────┤
//    │ lgui │ lalt │ lctl │ lsft │ no  │   │ sCRL │ f4 │ f5 │ f6 │ f11 │
//    ├──────┼──────┼──────┼──────┼─────┤   ├──────┼────┼────┼────┼─────┤
//    │  no  │  no  │  no  │  no  │ no  │   │ paus │ f1 │ f2 │ f3 │ f10 │
//    └──────┴──────┼──────┼──────┼─────┤   ├──────┼────┼────┼────┴─────┘
//                  │  no  │  no  │     │   │  no  │ no │ no │
//                  └──────┴──────┴─────┘   └──────┴────┴────┘
[LAYER_FUNCTION] = LAYOUT_split_3x5_3(
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     KC_PSCR , KC_F7   , KC_F8   , KC_F9 , KC_F12,
  KC_LGUI , KC_LALT , KC_LCTL , KC_LSFT , XXXXXXX ,     KC_SCRL , KC_F4   , KC_F5   , KC_F6 , KC_F11,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     KC_PAUS , KC_F1   , KC_F2   , KC_F3 , KC_F10,
                      XXXXXXX , XXXXXXX , _______ ,     XXXXXXX , XXXXXXX , XXXXXXX
),

//    ┌──────┬──────────┬─────────┬─────────┬──────┐   ┌──────┬──────────┬─────────┬─────────┬──────┐
//    │  no  │ RGB_RMOD │ RGB_TOG │ RGB_MOD │  no  │   │  no  │ RGB_RMOD │ RGB_TOG │ RGB_MOD │  no  │
//    ├──────┼──────────┼─────────┼─────────┼──────┤   ├──────┼──────────┼─────────┼─────────┼──────┤
//    │ mprv │   vold   │  mute   │  volu   │ mnxt │   │ mprv │   vold   │  mute   │  volu   │ mnxt │
//    ├──────┼──────────┼─────────┼─────────┼──────┤   ├──────┼──────────┼─────────┼─────────┼──────┤
//    │  no  │    no    │   no    │   no    │  no  │   │  no  │    no    │   no    │   no    │  no  │
//    └──────┴──────────┼─────────┼─────────┼──────┤   ├──────┼──────────┼─────────┼─────────┴──────┘
//                      │         │  mply   │ mstp │   │ mstp │   mply   │  mute   │
//                      └─────────┴─────────┴──────┘   └──────┴──────────┴─────────┘
[LAYER_MEDIA] = LAYOUT_split_3x5_3(
  XXXXXXX , RGB_RMOD , RGB_TOG , RGB_MOD , XXXXXXX ,     XXXXXXX , RGB_RMOD , RGB_TOG , RGB_MOD , XXXXXXX,
  KC_MPRV , KC_VOLD  , KC_MUTE , KC_VOLU , KC_MNXT ,     KC_MPRV , KC_VOLD  , KC_MUTE , KC_VOLU , KC_MNXT,
  XXXXXXX , XXXXXXX  , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX  , XXXXXXX , XXXXXXX , XXXXXXX,
                       _______ , KC_MPLY , KC_MSTP ,     KC_MSTP , KC_MPLY  , KC_MUTE
),

//    ┌─────────┬─────────┬─────────┬─────────┬─────────┐   ┌─────────┬─────────┬─────────┬─────────┬─────────┐
//    │ QK_BOOT │ EE_CLR  │   no    │ DPI_MOD │ S_D_MOD │   │ S_D_MOD │ DPI_MOD │   no    │ EE_CLR  │ QK_BOOT │
//    ├─────────┼─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┤
//    │  lgui   │  lalt   │  lctl   │  lsft   │   no    │   │   no    │  lsft   │  lctl   │  lalt   │  lgui   │
//    ├─────────┼─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┤
//    │         │ DRGSCRL │ SNIPING │  btn3   │   no    │   │   no    │  btn3   │ SNIPING │ DRGSCRL │         │
//    └─────────┴─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┴─────────┘
//                        │  btn3   │  btn2   │  btn1   │   │  btn1   │  btn2   │  btn3   │
//                        └─────────┴─────────┴─────────┘   └─────────┴─────────┴─────────┘
[LAYER_POINTER] = LAYOUT_split_3x5_3(
  QK_BOOT , EE_CLR  , XXXXXXX , DPI_MOD , S_D_MOD ,     S_D_MOD , DPI_MOD , XXXXXXX , EE_CLR  , QK_BOOT,
  KC_LGUI , KC_LALT , KC_LCTL , KC_LSFT , XXXXXXX ,     XXXXXXX , KC_LSFT , KC_LCTL , KC_LALT , KC_LGUI,
  _______ , DRGSCRL , SNIPING , KC_BTN3 , XXXXXXX ,     XXXXXXX , KC_BTN3 , SNIPING , DRGSCRL , _______,
                      KC_BTN3 , KC_BTN2 , KC_BTN1 ,     KC_BTN1 , KC_BTN2 , KC_BTN3
),

//    ┌───┬───┬───┬───┬───┐   ┌────┬──────┬──────┬──────┬──────┐
//    │ [ │ 7 │ 8 │ 9 │ ] │   │ no │  no  │  no  │  no  │  no  │
//    ├───┼───┼───┼───┼───┤   ├────┼──────┼──────┼──────┼──────┤
//    │ ; │ 4 │ 5 │ 6 │ = │   │ no │ lsft │ lctl │ lalt │ lgui │
//    ├───┼───┼───┼───┼───┤   ├────┼──────┼──────┼──────┼──────┤
//    │ ` │ 1 │ 2 │ 3 │ \ │   │ no │  no  │  no  │  no  │  no  │
//    └───┴───┼───┼───┼───┤   ├────┼──────┼──────┼──────┴──────┘
//            │ . │ 0 │ - │   │ no │      │  no  │
//            └───┴───┴───┘   └────┴──────┴──────┘
[LAYER_NUMERAL] = LAYOUT_split_3x5_3(
  KC_LBRC  , KC_7 , KC_8   , KC_9 , KC_RBRC ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  KC_SCLN  , KC_4 , KC_5   , KC_6 , KC_EQL  ,     XXXXXXX , KC_LSFT , KC_LCTL , KC_LALT , KC_LGUI,
  KC_GRAVE , KC_1 , KC_2   , KC_3 , KC_BSLS ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
                    KC_DOT , KC_0 , KC_MINS ,     XXXXXXX , _______ , XXXXXXX
),

//    ┌───┬───┬───┬───┬───┐   ┌─────┬──────┬──────┬──────┬──────┐
//    │ { │ & │ * │ ( │ } │   │ no  │  no  │  no  │  no  │  no  │
//    ├───┼───┼───┼───┼───┤   ├─────┼──────┼──────┼──────┼──────┤
//    │ : │ $ │ % │ ^ │ + │   │ no  │ lsft │ lctl │ lalt │ lgui │
//    ├───┼───┼───┼───┼───┤   ├─────┼──────┼──────┼──────┼──────┤
//    │ ~ │ ! │ @ │ # │ | │   │ no  │  no  │  no  │  no  │  no  │
//    └───┴───┼───┼───┼───┤   ├─────┼──────┼──────┼──────┴──────┘
//            │ ( │ ) │ _ │   │     │  no  │  no  │
//            └───┴───┴───┘   └─────┴──────┴──────┘
[LAYER_SYMBOLS] = LAYOUT_split_3x5_3(
  KC_LCBR , KC_AMPR , KC_ASTR , KC_LPRN , KC_RCBR ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  KC_COLN , KC_DLR  , KC_PERC , KC_CIRC , KC_PLUS ,     XXXXXXX , KC_LSFT , KC_LCTL , KC_LALT , KC_LGUI,
  KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_PIPE ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
                      KC_LPRN , KC_RPRN , KC_UNDS ,     _______ , XXXXXXX , XXXXXXX
)
};
// clang-format on

#ifdef POINTING_DEVICE_ENABLE
#    ifdef DILEMMA_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    dilemma_set_pointer_sniping_enabled(layer_state_cmp(state, DILEMMA_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // DILEMMA_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE
