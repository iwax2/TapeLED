#include <FastLED.h>

#define NUM_LEDS 141
#define DATA_PIN 9
#define CLOCK_PIN 13
#define COLOR_MAX 14

CRGB leds[NUM_LEDS];
int rgb [COLOR_MAX][3] = {
  { 255, 0, 0 },  // Red
  { 255, 82, 0 },
  { 255, 165, 0 }, // Orange
  { 255, 210, 0 },
  { 255, 255, 0 }, // Yellow
  { 127, 191, 0 },
  { 0, 127, 0 },  // Green
  { 0, 192, 127 },
  { 0, 255, 255 }, // Aqua
  { 0, 127, 255 },
  { 0, 0, 255 }, // Blue
  { 63, 0, 191 },
  { 127, 0, 127 }, // Purple
  { 191, 0, 63 }
};

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    for ( int j = 0; j < COLOR_MAX; j++ ) {
      int c = COLOR_MAX-j-1;
      int l = (i + j) % NUM_LEDS;;
      leds[l] = CRGB( rgb[c][0], rgb[c][1], rgb[c][2]);
      FastLED.show();
    }
    leds[i] = CRGB( 0, 0, 0);
    FastLED.show();
  }
}
