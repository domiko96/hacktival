#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 118
// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 11
//#define CLOCK_PIN 13

int rValue = 0;
int gValue = 0;
int bValue = 0;

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {
      FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
      Serial.begin(115200);
}

void loop() {

  size_t i = 0;
  while (i < NUM_LEDS) {
    if (Serial.available() >= 11) {
              // read the incoming byte:
              rValue = Serial.parseInt();
              gValue = Serial.parseInt();
              bValue = Serial.parseInt();

              // say what you got:
              Serial.print("I received: ");
              Serial.print(rValue);
              Serial.print(gValue);
              Serial.print(bValue);

              leds[i].r = rValue;
              leds[i].g = gValue;
              leds[i].b = bValue;
               //go to next line
              i++;

      }
  }
  FastLED.show();
  Serial.println("Called show");
  i=0;





  // Turn the LED on, then pause
  //for (size_t i = 0; i < NUM_LEDS; i++) {
  //  leds[i] = CRGB::Red;
  //  FastLED.show();
  //  delay(10);
  //}

  //for (size_t i = NUM_LEDS; i != 0; i--) {
  //  leds[i] = CRGB::Black;
  //  FastLED.show();
  //  delay(10);
  //}
}
