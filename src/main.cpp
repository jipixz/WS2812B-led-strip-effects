#include <Arduino.h>
#include <FastLED.h>

#define ONBOARD_LED 1

#define NUM_LEDS    120          // FastLED definitions
#define LED_PIN     5

CRGB g_LEDs[NUM_LEDS] = {0};    // Frame buffer for FastLED

// FramesPerSecond
//
// Tracks a weighted average to smooth out the values that it calcs as the simple reciprocal
// of the amount of time taken specified by the caller.  So 1/3 of a second is 3 fps, and it
// will take up to 10 frames or so to stabilize on that value.

void setup() 
{
  pinMode(ONBOARD_LED, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  FastLED.addLeds<WS2812B, LED_PIN, GRB>(g_LEDs, NUM_LEDS);               // Add our LED strip to the FastLED library
  FastLED.setBrightness(255);
}

void loop() 
{
  bool bLED = 0;

  uint8_t initialHue = 0;
  const uint8_t deltaHue = 10;
  const uint8_t hueDensity = 1;

  for (;;)
  {
    bLED = !bLED;                                                         // Blink the LED off and on  
    digitalWrite(ONBOARD_LED, bLED);

    // Handle LEDs

    fill_rainbow(g_LEDs, NUM_LEDS, initialHue += hueDensity, deltaHue);

    /*for (int i = 0; i < NUM_LEDS; i++)
      g_LEDs[i] = CRGB::DarkOrange;*/

    FastLED.show();

  }
}