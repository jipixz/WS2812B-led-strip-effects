#include "FastLED.h"

extern CRGB g_LEDs[];

void fill_grad() {
  
  uint8_t starthue = beatsin8(0, 0, 255);
  uint8_t endhue = beatsin8(2, 0, 255);
  
  if (starthue < endhue) {
    fill_gradient(g_LEDs, NUM_LEDS, CHSV(starthue,255,255), CHSV(endhue,255,255), FORWARD_HUES);    // If we don't have this, the colour fill will flip around. 
  } else {
    fill_gradient(g_LEDs, NUM_LEDS, CHSV(starthue,255,255), CHSV(endhue,255,255), BACKWARD_HUES);
  }

  FastLED.show();
  
} // fill_grad()