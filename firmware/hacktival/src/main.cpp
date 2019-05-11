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

byte frameBufferR[NUM_LEDS];
byte frameBufferG[NUM_LEDS];
byte frameBufferB[NUM_LEDS];



// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {
      FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
      Serial.begin(115200);
}

void loop() {
  if(Serial.available()){
    for(int i = 0; i < NUM_LEDS; i++) {
      if (Serial.available() >= 11) {
                // read the incoming byte:
                rValue = Serial.parseInt();
                gValue = Serial.parseInt();
                bValue = Serial.parseInt();

                // say what you got:
                //Serial.print("I received: ");
                //Serial.print(rValue);
                //Serial.print(gValue);
                //Serial.print(bValue);
                frameBufferR[i] = rValue;
                frameBufferG[i] = gValue;
                frameBufferB[i] = bValue;
                 //go to next line

        }
        for(int i = 0; i < NUM_LEDS; i++){
          leds[i].r = frameBufferR[i];
          leds[i].g = frameBufferG[i];
          leds[i].b = frameBufferB[i];
        }


          FastLED.show();
          Serial.println("Called show");
    }
    }
}


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
