#define FASTLED_ESP8266_RAW_PIN_ORDER
//#define FASTLED_INTERRUPT_RETRY_COUNT 3
#define FASTLED_ALLOW_INTERRUPTS 0
#include <FastLED.h>
 
// How many leds in your strip?
#define NUM_LEDS_A 64
#define NUM_LEDS_B 170
#define NUM_LEDS_C 150
#define NUM_LEDS_D 170

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN_A 12
#define DATA_PIN_B 13
#define DATA_PIN_C 14
#define DATA_PIN_D 15
 
// Define the array of leds
CRGB ledsA[NUM_LEDS_A];
CRGB ledsB[NUM_LEDS_B];
CRGB ledsC[NUM_LEDS_C];
CRGB ledsD[NUM_LEDS_D];
 
unsigned char a = 0;
unsigned char b = 0;
unsigned char c = 0;
unsigned char d = 0;
 
void setup() {
  Serial.begin(57600);
  Serial.println("resetting");
  LEDS.addLeds<WS2812B,DATA_PIN_A,RGB>(ledsA,NUM_LEDS_A);
  LEDS.addLeds<WS2812B,DATA_PIN_B,RGB>(ledsB,NUM_LEDS_B);
  LEDS.addLeds<WS2812B,DATA_PIN_C,RGB>(ledsC,NUM_LEDS_C);
  LEDS.addLeds<WS2812B,DATA_PIN_D,RGB>(ledsD,NUM_LEDS_D);
  LEDS.setBrightness(32);
}
 
void loop() {
  a++;
  if (a == NUM_LEDS_A) {
    a= 0;
  }
  Serial.print(a);
  Serial.print(" ");
  b++;
  if (b == NUM_LEDS_B) {
    b= 0;
  }
  Serial.print(b);
  Serial.print(" ");
  c++;
  if (c == NUM_LEDS_C) {
    c= 0;
  }
  Serial.print(c);
  Serial.print(" ");
  d++;
  if (d == NUM_LEDS_D) {
    d= 0;
  }
  Serial.print(d);
  Serial.print(" ");
  
  ledsA[a] = CRGB::Red;
  ledsB[b] = CRGB::Green;
  ledsC[c] = CRGB::Blue;
  ledsD[d] = CRGB::White;
 
  FastLED.show();
  Serial.println();
  delay(50);
 
  // Now turn the LED off, then pause
  ledsA[a] = CRGB::Black;
  ledsB[b] = CRGB::Black;
  ledsC[c] = CRGB::Black;
  ledsD[d] = CRGB::Black;
}
 
