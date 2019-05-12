#include <FastLED.h>
#include "lidar.cpp"

// How many leds in your strip?
#define NUM_LEDS 118
// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN

//Pin 11 am Arduino
#define DATA_PIN D4
#define GND_PIN D6
#define SENSE_PIN 12
#define MODE_PIN 14


#define FASTLED_ESP8266_NODEMCU_PIN_ORDER
//#define CLOCK_PIN 13

int rValue = 0;
int gValue = 0;
int bValue = 0;

bool autoMode = false;
//bool triggered = false;

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {
      FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
      Serial.begin(115200);
      pinMode(MODE_PIN, INPUT);
      if(!digitalRead(MODE_PIN)){
        autoMode = true;
      }
}

void waitHere(){

  for(int z = 0; z < NUM_LEDS; z++){
     leds[z].r = 0;
     leds[z].g = 0;
     leds[z].b = 0;
  }
  FastLED.show();

  while(!digitalRead(MODE_PIN)){
    delay(1);
  }

}

void loop() {

  #define yMax 1
  #define xMax 91



  if(autoMode){
    leds[1].r = 50;
    leds[1].g = 50;
    leds[1].b = 50;
  }
  else{
    leds[1].r = 50;
    leds[1].g = 0;
    leds[1].b = 0;
  }
  FastLED.show();
  delay(2000);

  leds[1].r = 50;
  leds[1].g = 20;
  leds[1].b = 0;
  FastLED.show();
  delay(2000);

  leds[1].r = 0;
  leds[1].g = 50;
  leds[1].b = 0;
  FastLED.show();
  delay(500);

  leds[1].r = 0;
  leds[1].g = 0;
  leds[1].b = 0;
  FastLED.show();
  delay(1500);

  waitHere();

  for(int y = 0; y < yMax; y++){
    for(int x = 0; x < xMax; x++){
      for(int z = 0; z < NUM_LEDS; z++){
         leds[z].r = pgm_read_byte_near(image0 + x*(3*NUM_LEDS) + (z*3));
         leds[z].g = pgm_read_byte_near(image0 + x*(3*NUM_LEDS) + (z*3) + 1);
         leds[z].b = pgm_read_byte_near(image0 + x*(3*NUM_LEDS) + (z*3) + 2);
      }
      //image7;
      FastLED.show();
      Serial.println(x);
      //delay(33);
      if(autoMode){
        delay(100);
      }
      else{
          while(digitalRead(SENSE_PIN) == LOW) {delay(1);}
          while(digitalRead(SENSE_PIN) == HIGH) {delay(1);}
      }
    }
  }

  waitHere();

/*

  for(int y = 0; y < yMax; y++){
    for(int x = 0; x < xMax; x++){
      for(int z = 0; z < NUM_LEDS; z++){
         leds[z].r = pgm_read_byte_near(image2 + x*(3*NUM_LEDS) + (z*3));
         leds[z].g = pgm_read_byte_near(image2 + x*(3*NUM_LEDS) + (z*3) + 1);
         leds[z].b = pgm_read_byte_near(image2 + x*(3*NUM_LEDS) + (z*3) + 2);
      }
      //image7;
      FastLED.show();
      Serial.println(x);
      //delay(33);
      if(autoMode){
        delay(100);
      }
      else{
          while(digitalRead(SENSE_PIN) == LOW) {delay(1);}
          while(digitalRead(SENSE_PIN) == HIGH) {delay(1);}
      }
    }
  }

waitHere();

  for(int y = 0; y < yMax; y++){
    for(int x = 0; x < xMax; x++){
      for(int z = 0; z < NUM_LEDS; z++){
         leds[z].r = pgm_read_byte_near(image3 + x*(3*NUM_LEDS) + (z*3));
         leds[z].g = pgm_read_byte_near(image3 + x*(3*NUM_LEDS) + (z*3) + 1);
         leds[z].b = pgm_read_byte_near(image3 + x*(3*NUM_LEDS) + (z*3) + 2);
      }
      //image7;
      FastLED.show();
      Serial.println(x);
      //delay(33);
      if(autoMode){
        delay(100);
      }
      else{
          while(digitalRead(SENSE_PIN) == LOW) {delay(1);}
          while(digitalRead(SENSE_PIN) == HIGH) {delay(1);}
      }
    }
  }

waitHere();

  for(int y = 0; y < yMax; y++){
    for(int x = 0; x < xMax; x++){
      for(int z = 0; z < NUM_LEDS; z++){
         leds[z].r = pgm_read_byte_near(image4 + x*(3*NUM_LEDS) + (z*3));
         leds[z].g = pgm_read_byte_near(image4 + x*(3*NUM_LEDS) + (z*3) + 1);
         leds[z].b = pgm_read_byte_near(image4 + x*(3*NUM_LEDS) + (z*3) + 2);
      }
      //image7;
      FastLED.show();
      Serial.println(x);
      //delay(33);
      if(autoMode){
        delay(100);
      }
      else{
          while(digitalRead(SENSE_PIN) == LOW) {delay(1);}
          while(digitalRead(SENSE_PIN) == HIGH) {delay(1);}
      }
    }
  }

  */

  leds[1].r = 0;
  leds[1].g = 0;
  leds[1].b = 0;
  FastLED.show();
  delay(1500);

  for(int z = 0; z < NUM_LEDS; z++){
     leds[z].r = 0;
     leds[z].g = 0;
     leds[z].b = 0;
  }


  FastLED.show();
  delay(1000);

  leds[1].r = 0;
  leds[1].g = 50;
  leds[1].b = 0;
  FastLED.show();
  delay(5000);
}
