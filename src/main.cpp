#include <Arduino.h>
#define FASTLED_INTERNAL
#include <FastLED.h>

#define ONBOARD_LED 1

#define NUM_LEDS    120          // FastLED definitions
#define LED_PIN     5

#define TIMES_PER_SECOND(x) EVERY_N_MILLISECONDS(1000/x)
#define ARRAYSIZE(x) (sizeof(x)/sizeof(x[0]))  

CRGB g_LEDs[NUM_LEDS] = {0};    // Frame buffer for FastLED

int g_Brightness = 255;

#include "marquee.h"
#include "twinkle.h"
#include "comet.h"
#include "bounce.h"
#include "breathing.h"
#include "rgb.h"

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

  FastLED.clear();
}

void loop() 
{
  bool bLED = 0;

  uint8_t initialHue = 0;
  const uint8_t deltaHue = 1;
  const uint8_t hueDensity = 1;

  BouncingBallEffect balls(NUM_LEDS,1,150);

  while (true)
  {
    bLED = !bLED;                                                         // Blink the LED off and on  
    //digitalWrite(ONBOARD_LED, bLED);

    // Handle LEDs
    
    //fill_rainbow(g_LEDs, NUM_LEDS, initialHue += hueDensity, deltaHue);

    fill_solid(g_LEDs, NUM_LEDS, CRGB::Red);

    /*for (int i = 0; i < NUM_LEDS; i++)
      g_LEDs[i] = CRGB::DarkOrange;*/

    //DrawMarquee();

    //DrawTwinkle();

    //DrawComet();

    //balls.Draw();

    //breathing();

    //rgb();

    FastLED.setBrightness(g_Brightness);
    
    FastLED.show();

  }
}