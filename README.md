# WS2812B Led Strip Effects

This repo contains some LED effects modified for a 120 WS2812B LED strip implementation and modifications in some of the effects. They have been tested with an ESP32 (NodeMCU) and using PlatformIO IDE to upload the code. Most of the effects are in separate header files and imported to main. The effects has to be changed hardcoded, haven't implemented an input detection or something else to change the effect yet.

Most of the effects contained here have been taken from David Plummer's repo.

> Youtube Channel: https://www.youtube.com/c/DavesGarage

> LED series repo: https://github.com/davepl/DavesGarageLEDSeries

Flicker taken from chemdoc77's repo.

> Repo: https://github.com/chemdoc77/CD77_FastLED/tree/master/CD77_Halloween_Fun_2019

Breathing taken from Marc Miller repo.

> Repo: https://github.com/marmilicious/FastLED_examples/blob/master/breath_effect_v2.ino

## Things to improve
- [ ] Move all the effects variables, declarations and functions to their header file completely.
- [ ] Add an optional input detection (by pulsing a button, etc.) to change the effect.
- [ ] Refactor code.
- [ ] Add missing coments in some of the effects header files.
- [ ] Remove trash code.
- [ ] Add more thing to improve that I'll be thinking.

## List of effects

- Marquee.
- Comet.
- Rainbow (usign FastLED library built in function).
- Twinkle.
- RGB (no fade).
- Flicker.
- Fill grad (setting the two colors hardcoded).
- Breathing.
- Bounce.
