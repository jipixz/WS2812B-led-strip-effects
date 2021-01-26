#include <sys/time.h>                   // For time-of-day

#include <Arduino.h>
#define FASTLED_INTERNAL
#include <FastLED.h>

using namespace std;
#include <vector>

extern CRGB g_LEDs[];

static const CRGB ballColors [] =
{
    CRGB::OrangeRed,
    CRGB::White,
    CRGB::Red,
    CRGB::Blue,
    CRGB::Green,
    CRGB::Indigo
};

class BouncingBallEffect
{
  private:

    float InitialBallSpeed(float height) const
    {
        return sqrt(-2 * Gravity * height);         // Because MATH!
    }

    size_t  _cLength;           
    size_t  _cBalls;
    byte    _fadeRate;
    bool    _bMirrored;

    const float Gravity = -9.81;                   // Because PHYSICS!
    const float StartHeight = 1;                   // Drop balls from max height initially
    const float ImpactVelocity = InitialBallSpeed(StartHeight);
    const float SpeedKnob = 4.0;                   // Higher values will slow the effect

    vector<float> ClockTimeAtLastBounce, Height, BallSpeed, Dampening;
    vector<CRGB>   Colors;

    static float Time()
    {
        timeval tv = { 0 };
        gettimeofday(&tv, nullptr);
        return (float)(tv.tv_usec / 1000000.0 + (float) tv.tv_sec);
    }
    
  public:

    // BouncingBallEffect
    //
    // Caller specs strip length, number of balls, persistence level (255 is least), and whether the
    // balls should be drawn mirrored from each side.

    BouncingBallEffect(size_t cLength, size_t ballCount = 3, byte fade = 0, bool bMirrored = false)
        : _cLength(cLength - 1),
          _cBalls(ballCount),
          _fadeRate(fade),
          _bMirrored(bMirrored),
          ClockTimeAtLastBounce(ballCount),
          Height(ballCount),
          BallSpeed(ballCount),
          Dampening(ballCount),
          Colors(ballCount)
    {
        for (size_t i = 0; i < ballCount; i++)
        {
            Height[i]                = StartHeight;         // Current Ball Height
            ClockTimeAtLastBounce[i] = Time();              // When ball last hit ground state
            Dampening[i]             = 0.90 - i / pow(_cBalls, 2);  // Bounciness of this ball
            BallSpeed[i]             = InitialBallSpeed(Height[i]); // Don't dampen initial launch
            Colors[i]                = ballColors[i % ARRAYSIZE(ballColors) ];
        }
    }

    // Draw
    //
    // Draw each of the balls.  When any ball settles with too little energy, it it "kicked" to restart it

    virtual void Draw()
    {
        if (_fadeRate != 0)
        {
            for (size_t i = 0; i < _cLength; i++)
                g_LEDs[i].fadeToBlackBy(_fadeRate);
        }
        else
            FastLED.clear();
        
        // Draw each of the balls

        for (size_t i = 0; i < _cBalls; i++)
        {
            float TimeSinceLastBounce = (Time() - ClockTimeAtLastBounce[i]) / SpeedKnob;

            // Use standard constant acceleration function - https://en.wikipedia.org/wiki/Acceleration
            Height[i] = 0.5 * Gravity * pow(TimeSinceLastBounce, 2.0) + BallSpeed[i] * TimeSinceLastBounce;

            // Ball hits ground - bounce!
            if (Height[i] < 0)
            {
                Height[i] = 0;
                BallSpeed[i] = Dampening[i] * BallSpeed[i];
                ClockTimeAtLastBounce[i] = Time();

                if (BallSpeed[i] < 0.01)
                    BallSpeed[i] = InitialBallSpeed(StartHeight) * Dampening[i];
            }

            size_t position = (size_t)(Height[i] * (_cLength - 1) / StartHeight);

            g_LEDs[position]   += Colors[i];
            g_LEDs[position+1] += Colors[i];

            if (_bMirrored)
            {
                g_LEDs[_cLength - 1 - position] += Colors[i];
                g_LEDs[_cLength - position]     += Colors[i];
            }
        }
        delay(20);

        FastLED.show();
    }
};