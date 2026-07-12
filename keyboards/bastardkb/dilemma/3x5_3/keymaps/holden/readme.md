# Dilemma `via` keymap

The Dilemma `via` keymap is based on a QWERTY layout with [home row mods](https://precondition.github.io/home-row-mods) and [Miryoku-inspired layers](https://github.com/manna-harbour/miryoku), and some features and changes specific to the Dilemma.

This layout also supports VIA.

## Bilateral combinations (home row mods)

This keymap enables [sunaku's bilateral combinations patch](https://github.com/manna-harbour/qmk_firmware/pull/56)
to tame accidental home row mod misfires from rollover. See
[Taming home row mods with Bilateral Combinations](https://sunaku.github.io/home-row-mods.html).

**This is a core firmware patch**, not a pure userspace change. It has two parts:

1. **Firmware** — `quantum/action.c` must be patched in your `qmk_firmware`
   checkout (the tree pointed to by `qmk config user.qmk_home`). The patch is
   committed on the `bilateral-combinations` branch of that repo. Reapply it if
   you re-clone or reset QMK:

   ```sh
   cd "$(qmk config -ro user.qmk_home | cut -d= -f2)"
   curl -sL https://github.com/qmk/qmk_firmware/compare/master...sunaku:miryoku_bilateral.diff \
     | patch -p1 --fuzz=5
   ```

2. **Userspace** — `#define BILATERAL_COMBINATIONS` (plus tuning) lives in
   `config.h`, and `DEFERRED_EXEC_ENABLE = yes` in `rules.mk`. The feature is
   inert without part 1.

Tuning values in `config.h` are the PR author's defaults; adjust
`BILATERAL_COMBINATIONS_ALLOW_CROSSOVER_AFTER` and
`BILATERAL_COMBINATIONS_TYPING_STREAK_TIMEOUT` to your own typing speed.

## Customizing the keymap

### Dynamic DPI scaling

Use the following keycodes to change the default DPI:

-   `POINTER_DEFAULT_DPI_FORWARD`: increases the DPI; decreases when shifted;
-   `POINTER_DEFAULT_DPI_REVERSE`: decreases the DPI; increases when shifted.

There's a maximum of 16 possible values for the sniping mode DPI. See the [Dilemma documentation](../../README.md) for more information.

Use the following keycodes to change the sniping mode DPI:

-   `POINTER_SNIPING_DPI_FORWARD`: increases the DPI; decreases when shifted;
-   `POINTER_SNIPING_DPI_REVERSE`: decreases the DPI; increases when shifted.

There's a maximum of 4 possible values for the sniping mode DPI. See the [Dilemma documentation](../../README.md) for more information.

### Drag-scroll

Use the `DRAGSCROLL_MODE` keycode to enable drag-scroll on hold. Use the `DRAGSCROLL_TOGGLE` keycode to enable/disable drag-scroll on key press.

### Circular scroll

By default, the firmware is configured to enable the circular scroll feature on Cirque trackpad.

To disable this, add the following to your keymap:

```c
#undef POINTING_DEVICE_GESTURES_SCROLL_ENABLE
```

### Sniping

Use the `SNIPING_MODE` keycode to enable sniping mode on hold. Use the `SNIPING_MODE_TOGGLE` (aliased as `SNP_TOG`) keycode to enable/disable sniping mode on key press.

Change the value of `DILEMMA_AUTO_SNIPING_ON_LAYER` to automatically enable sniping mode on layer change. By default, sniping mode is enabled on the pointer layer:

```c
#define DILEMMA_AUTO_SNIPING_ON_LAYER LAYER_POINTER
```