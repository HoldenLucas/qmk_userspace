#pragma once

#define DYNAMIC_KEYMAP_LAYER_COUNT 8

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE

/* Home row mods: bilateral combinations (manna-harbour/qmk_firmware#56)
 * Tames accidental HRM misfires from rollover. Requires the
 * quantum/action.c patch applied to the QMK firmware tree and
 * DEFERRED_EXEC_ENABLE = yes in rules.mk. */
#define BILATERAL_COMBINATIONS
#define BILATERAL_COMBINATIONS_LIMIT_CHORD_TO_N_KEYS 4  /* GUI, Alt, Ctrl, Shift */
#define BILATERAL_COMBINATIONS_DELAY_MODS_THAT_MATCH MOD_MASK_GUI
#define BILATERAL_COMBINATIONS_DELAY_MATCHED_MODS_BY 120   /* ms */
#define BILATERAL_COMBINATIONS_ALLOW_CROSSOVER_AFTER 80    /* ms */
#define BILATERAL_COMBINATIONS_ALLOW_SAMESIDED_AFTER 3000  /* ms */
#define BILATERAL_COMBINATIONS_TYPING_STREAK_TIMEOUT 160   /* ms */
#define BILATERAL_COMBINATIONS_TYPING_STREAK_MODMASK (~MOD_MASK_SHIFT)

/* Combo idle-gating (urob-style require-prior-idle): suppress the home row
 * combos (ENTER, ESCAPE) if another key was pressed within this many ms, so
 * fast e/i or r/s rolls don't misfire them mid-typing. Fire them by pausing
 * briefly first. See combo_should_trigger() in keymap.c. */
#define COMBO_SHOULD_TRIGGER
#define COMBO_HRM_IDLE_MS 150
