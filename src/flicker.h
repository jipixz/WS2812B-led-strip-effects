#include <Arduino.h>
#define FASTLED_INTERNAL
#include <FastLED.h>

extern CRGB g_LEDs[];

//Definir el color para el efecto 
CRGB color1 = CRGB::Blue;

//Definir el color para el efecto con colores aleatorios
CRGB color2 [NUM_COLORS] = {
    CRGB::Red,
    CRGB::Blue,
    CRGB::Purple,
    CRGB::Green,
    CRGB::Orange
};

//Mínimo delay
uint16_t Ran_min = 10;

//Máximo delay
uint16_t Ran_Max = 25;

void flicker() {

  if (random8(2) == 1){
  for (int i = 0; i < NUM_LEDS; i++) {
        g_LEDs[i] = color1;
      }
   FastLED.show();
  }
    else {
      FastLED.clear();
      FastLED.show();
    }
    delay(random16(Ran_min,Ran_Max));
}//flicker()


void flicker_random() {

  if (random8(2) == 1){
  for (int j = 0; j < NUM_LEDS; j++) {
        g_LEDs[j] = color2[random(NUM_COLORS)];
      }
   FastLED.show();
  }
    else {
      FastLED.clear();
      FastLED.show();
    }
    delay(random16(Ran_min,Ran_Max));
}//flicker_random()