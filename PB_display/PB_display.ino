
// Neopixel
#include <Adafruit_NeoPixel.h>

// Neopixel Config
#define NeoPIN D4
#define NUM_LEDS 100
#define ADDRESS_PB 1

int brightness = 250;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, NeoPIN, NEO_RGB + NEO_KHZ800);


void setup() {
  Serial.begin(115200);
  // ##############
  // NeoPixel start
  Serial.println();
  strip.setBrightness(brightness);
  strip.begin();
  strip.show();
  delay(50);
  Serial.println("NeoPixel started");

  // setting whole strip to the given color
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, strip.Color( 100, 0, 0 ) );
  }
  // init
  strip.show();
  delay(1000);
}

void loop() {
  test();
}

void test() {
  setPB(255, 0, 0);
  strip.show();
  delay(500);

  setPB(0, 255, 0);
  strip.show();
  delay(500);

  setPB(0, 0, 255);
  strip.show();
  delay(500);

  setPB(0, 0, 0);
  strip.show();
  delay(500);

  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, strip.Color( 255, 255, 255 ) );
    strip.show();
    delay(100);
    strip.setPixelColor(i, strip.Color( 0, 0, 0 ) );
  }
}

void setPB(int r, int g, int b) {
  // setting whole strip to the given color
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, strip.Color( r, g, b ) );
  }
}

void setLED(int a, int r, int g, int b) {
  strip.setPixelColor(a, strip.Color( r, g, b ) );
}
