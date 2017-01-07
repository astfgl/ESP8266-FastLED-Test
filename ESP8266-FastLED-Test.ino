#define FASTLED_ESP8266_RAW_PIN_ORDER
//#define FASTLED_INTERRUPT_RETRY_COUNT 3
#define FASTLED_ALLOW_INTERRUPTS 0
#include <FastLED.h>
 
// How many leds in each strip?
#define NUM_LEDS_A 64
#define NUM_LEDS_B 170
#define NUM_LEDS_C 150
#define NUM_LEDS_D 170

// GPIO line for each strip
#define DATA_PIN_A 12
#define DATA_PIN_B 13
#define DATA_PIN_C 14
#define DATA_PIN_D 15
 
// Define the arrays of leds
CRGB ledsA[NUM_LEDS_A];
CRGB ledsB[NUM_LEDS_B];
CRGB ledsC[NUM_LEDS_C];
CRGB ledsD[NUM_LEDS_D];

// Counter for each array 
unsigned char a = 0;
unsigned char b = 0;
unsigned char c = 0;
unsigned char d = 0;
 
void setup() {
  // Show some debugging data
  Serial.begin(57600);
  Serial.println("resetting");
  
  // Add the led strings to FastLED
  LEDS.addLeds<WS2812B,DATA_PIN_A,RGB>(ledsA,NUM_LEDS_A);
  LEDS.addLeds<WS2812B,DATA_PIN_B,RGB>(ledsB,NUM_LEDS_B);
  LEDS.addLeds<WS2812B,DATA_PIN_C,RGB>(ledsC,NUM_LEDS_C);
  LEDS.addLeds<WS2812B,DATA_PIN_D,RGB>(ledsD,NUM_LEDS_D);
  
  // Not too bright for testing
  LEDS.setBrightness(32);
}
 
void loop() {
  // Increment the counter
  a++;
  if (a == NUM_LEDS_A) {
    // Reset to zero if it overflows
    a = 0;
  }
  //	Show the current value
  Serial.print(a);
  Serial.print(" ");
  
  // ...and again...
  b++;
  if (b == NUM_LEDS_B) {
    b = 0;
  }
  Serial.print(b);
  Serial.print(" ");
  
  // ...and again...
  c++;
  if (c == NUM_LEDS_C) {
    c = 0;
  }
  Serial.print(c);
  Serial.print(" ");
  
  // ...and again.
  d++;
  if (d == NUM_LEDS_D) {
    d = 0;
  }
  Serial.print(d);
  Serial.print(" ");
  
  // Set the current LED to a unique color
  ledsA[a] = CRGB::Red;
  ledsB[b] = CRGB::Green;
  ledsC[c] = CRGB::Blue;
  ledsD[d] = CRGB::White;
 
  // Show the change.
  FastLED.show();

  // Wait a certain amount of time
  delay(50);
 
  // Now turn the LEDs off
  ledsA[a] = CRGB::Black;
  ledsB[b] = CRGB::Black;
  ledsC[c] = CRGB::Black;
  ledsD[d] = CRGB::Black;

  // CRLF to set up the new loop
  Serial.println();
}
