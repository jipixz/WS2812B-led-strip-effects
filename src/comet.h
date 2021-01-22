#include <Arduino.h>
#define FASTLED_INTERNAL
#include <FastLED.h>

extern CRGB g_LEDs[];

bool flag {true};

void DrawComet(){    
    const byte fadeAmt = 64;        // Fracción de 256 para degradar un pixel si es elegido para degradarse
    const int cometSize = 3;         // Tamaño del cometa en pixeles
    const int deltaHue = 1;         // Que tan lejos para escalonar el ciclo del matiz cada llamada
    const double cometSpeed = .5;  // Que tan lejos avanza el cometa cada frame

    static byte hue = 160;      // Color actual
    static int iDirection = 1;      // Dirección actual (-1 o +1)
    static double iPos = 0.0;            // Positición actual del cometa en la tira 

    if (hue >= 240){
        flag = false;
    }else if(hue <= 128){
        flag = true;
    }

    if(flag == true){
        hue += deltaHue;
    }else if(flag == false){
        hue -= deltaHue;
    }

    iPos += iDirection * cometSpeed;             // Actualizar la posición del cometa

    // Girar la dirección del cometa cuando toca el final
    if (iPos == (NUM_LEDS - cometSize) || iPos == 0)
        iDirection *= -1;

    // Dibuja el cometa en su posicion actual
    for (int i = 0; i < cometSize; i++)
        g_LEDs[(int)iPos + i].setHue(hue);

    // Degradar aleatoriamente los LEDs
    for (int j = 0; j < NUM_LEDS; j++)
        if(random(10) > 5)
            g_LEDs[j] = g_LEDs[j].fadeToBlackBy(fadeAmt);

    delay(20);
}