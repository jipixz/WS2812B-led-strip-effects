

#define NUM_COLORS 5

static const CRGB ChristmasColors [NUM_COLORS] =
{
    CRGB(20, 107, 58),
    CRGB(22, 91, 51),
    CRGB(248, 178, 41),
    CRGB(234, 70, 48),
    CRGB(187, 37, 40)
};

static const CRGB TwinkleColors [NUM_COLORS] =
{
    CRGB::Blue,
    CRGB::Red,
    CRGB::Aqua,
    CRGB::Violet,
    CRGB::Yellow
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
    const byte fadeAmt = 64;

    static int passCount = 0;
    passCount++;

    // Cada que el passCount pasa a un cuarto del total de leds, reseteamos la tira
    if (passCount == NUM_LEDS){
        passCount = 0;
    }

    int chosenLed = random(NUM_LEDS);
    g_LEDs[chosenLed] = TwinkleColors[random(NUM_COLORS)];
    
    for (int j = 0; j < NUM_LEDS; j++)
        if(random(10) > 5)
            g_LEDs[j] = g_LEDs[j].fadeToBlackBy(fadeAmt);

    delay(50);

    FastLED.show();
}