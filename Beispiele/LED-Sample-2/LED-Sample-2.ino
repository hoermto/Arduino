// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#ifdef DEBUG_ESP_PORT
#define DEBUG_MSG(...) DEBUG_ESP_PORT.printf( __VA_ARGS__ )
#else
#define DEBUG_MSG(...)
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 64 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.
  Serial.begin(115200);
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}


void loop() {
  pixels.clear(); // Set all pixel colors to 'off'
  DEBUG_MSG("loop ...\n");
  uint8_t LEDgreen = NUMPIXELS / 10;
  uint8_t pause = .5 * 1000 / NUMPIXELS;
  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.

  for(int i=0; i<NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 10));
  }
  pixels.show();
   
    for(int i=0; i<NUMPIXELS; i++) {
      for(int c=0; c<LEDgreen; c++) {
        pixels.setPixelColor(i+c, pixels.Color(0, 255, 0));
      }
//        pixels.setPixelColor(i+0, pixels.Color(0, 255, 0));
//        pixels.setPixelColor(i+1, pixels.Color(0, 255, 0));
//        pixels.setPixelColor(i+2, pixels.Color(0, 255, 0));
//        pixels.setPixelColor(i+3, pixels.Color(0, 255, 0));
//        pixels.setPixelColor(i+4, pixels.Color(0, 255, 0));
        pixels.show();
        delay(pause);
        pixels.setPixelColor(i, pixels.Color(10, 0, 0));
    }
    for(int i=NUMPIXELS; i>0; i--) {
       for(int c=0; c<LEDgreen; c++) {
        pixels.setPixelColor(i-c, pixels.Color(0, 255, 0));
      }
        pixels.show();
        delay(pause);
        pixels.setPixelColor(i, pixels.Color(0, 0, 10));
    }
  
} /** Ende of programm  **/
