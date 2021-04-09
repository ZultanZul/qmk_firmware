#pragma once
#define OLED_TIMEOUT 240000

#undef RGBLED_NUM
#define RGB_DI_PIN D3
#define RGBLED_NUM 23
#define RGBLED_SPLIT {12,11}
// #define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT