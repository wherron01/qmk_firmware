#include "engine.h"

// Configuration options for the engine

#define C_SIZE uint16_t             // type for chord
#define COMBO_MAX 4                     // Longest Combo

// Key Aliases, must fit within C_SIZE!
// These are for Ginni + Asetniop
#define AA      STN(0)
#define AR      STN(1)
#define AS      STN(2)
#define AT      STN(3)
#define AN      STN(4)
#define AE      STN(5)
#define AI      STN(6)
#define AO      STN(7)
#define AB      STN(8)                  // Left/Right thumbs
#define AK      STN(9)
#define NUM     STN(10)                 // Sticky Layer 1
#define NAV     STN(11)                 // Sticky Layer 2
#define FUN     STN(12)                 // Sticky Layer 3
#define USR     STN(13)
#define RGT     STN(14)                 // Right Hand chord

// Chord to start buffering strokes
#define COMMAND_MODE    (AE | AN | AT | AS)
#define IN_CHORD_MASK (0xFFFF & ~(AB))      // Special keys that are used for mods

// Mapping of QMK Keycodes to chord positions
#define ENGINE_CONFIG               \
        ENGINE_HOOK(KC_A, AA)       \
        ENGINE_HOOK(KC_R, AR)       \
        ENGINE_HOOK(KC_S, AS)       \
        ENGINE_HOOK(KC_T, AT)       \
        ENGINE_HOOK(KC_N, AN)       \
        ENGINE_HOOK(KC_E, AE)       \
        ENGINE_HOOK(KC_I, AI)       \
        ENGINE_HOOK(KC_O, AO)       \
        ENGINE_HOOK(KC_B, AB)       \
        ENGINE_HOOK(KC_K, AK)
