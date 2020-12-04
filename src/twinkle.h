

#define NUM_COLORS 5
static const CRGB TwinkleColors [NUM_COLORS] =
{
    CRGB::Red,
    CRGB::Blue,
    CRGB::Purple,
    CRGB::Green,
    CRGB::Orange
};

void DrawTwinkleOld(){
    FastLED.clear(true);

    for (int i = 0; i < NUM_LEDS; i++){
        g_LEDs[random(NUM_LEDS)] = TwinkleColors[random(NUM_COLORS)];
        FastLED.show(g_Brightness);
        delay(100);
    }
}

void DrawTwinkle(){
    static int passCount = 0;
    passCount++;

    // Cada que el passCount pasa a un cuarto del total de leds, reseteamos la tira
    if (passCount == NUM_LEDS){
        passCount = 0;
        FastLED.clear(false);
    }

    g_LEDs[random(NUM_LEDS)] = TwinkleColors[random(NUM_COLORS)];
    delay(50);
}