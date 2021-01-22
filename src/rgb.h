#include <Arduino.h>
#define FASTLED_INTERNAL
#include <FastLED.h>

extern CRGB g_LEDs[];

void rgb () {
    fill_solid(g_LEDs, NUM_LEDS, CRGB::Blue);
    delay(100);
    FastLED.show();
    fill_solid(g_LEDs, NUM_LEDS, CRGB::Red);
    delay(100);
    FastLED.show();
    fill_solid(g_LEDs, NUM_LEDS, CRGB::Green);
    delay(100);
    FastLED.show();
}