//***************************************************************
// Breathing effect
// Color shifts from hueA to hueB as it pulses.
//
// Set A and B to the same hue if you don't want the color to
// change.  Saturation for the high and low can also be set.
//
// Marc Miller, 2015
// Updated Aug 2020 - removed delay, added dim8_video
//***************************************************************

#include "FastLED.h"

extern CRGB g_LEDs[];

static float pulseSpeed = 0.5;  // Larger value gives faster pulse.

uint8_t hueA = 180;  // Start hue at valueMin.
uint8_t satA = 150;  // Start saturation at valueMin.
float valueMin = 180.0;  // Pulse minimum value (Should be less then valueMax).

uint8_t hueB = 210;  // End hue at valueMax.
uint8_t satB = 255;  // End saturation at valueMax.
float valueMax = 255.0;  // Pulse maximum value (Should be larger then valueMin).

uint8_t hue = hueA;  // Do Not Edit
uint8_t sat = satA;  // Do Not Edit
float val = valueMin;  // Do Not Edit
uint8_t hueDelta = hueA - hueB;  // Do Not Edit
static float delta = (valueMax - valueMin) / 2.35040238;  // Do Not Edit

//---------------------------------------------------------------
void breathing(){
  float dV = ((exp(sin(pulseSpeed * millis()/2000.0*PI)) -0.36787944) * delta);
  val = valueMin + dV;
  hue = map(val, valueMin, valueMax, hueA, hueB);  // Map hue based on current val
  sat = map(val, valueMin, valueMax, satA, satB);  // Map sat based on current val

  for (int i = 0; i < NUM_LEDS; i++) {
    g_LEDs[i] = CHSV(hue, sat, val);

    // You can experiment with commenting out these dim8_video lines
    // to get a different sort of look.
    g_LEDs[i].r = dim8_video(g_LEDs[i].r);
    g_LEDs[i].g = dim8_video(g_LEDs[i].g);
    g_LEDs[i].b = dim8_video(g_LEDs[i].b);
  }

  FastLED.show();
   
} // end_main_loop