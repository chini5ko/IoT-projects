// NeoPixel Ring simple sketch (c)
// Modify by Hector Liang
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
//This program will light up all led in red and then in Green one by one.
//Keep Lighting Green and Green.

//*********
//The Ring's bright will increase and decrease in a loop
//*********

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            3

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      24

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 30; // delay for half a second
int red = 0;
int  blue = 0;
int green = 0;

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  int circleTime = 188;
  pixels.begin(); // This initializes the NeoPixel library.
  //RED CIRCLE
  delay(50);

  red = 0;
  green = 0;
  blue = 150;
  for (int i = 0, delaytime = circleTime; i < NUMPIXELS ; i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(red, green, blue)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delaytime); // Delay for a period of time (in milliseconds).
  }


}

void loop() {
  int beepTime = 50;
  red = 0;
  green = 0;
  blue = 15;
  int numberIncDec = 12;
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  for (int count = 0; count < 15; count++)
  {

    for (int i = 0, delaytime = 240; i < NUMPIXELS ; i++) { //all color to one
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(i, pixels.Color(red, green, blue)); // Moderately bright green color.
    }
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(beepTime);
    //  red= red+numberIncDec;
    //green = green +numberIncDec;
    blue = blue + numberIncDec;
  }
  /////////////////////////////////going down

  for (int count = 0; count < 15; count++)
  {

    for (int i = 0, delaytime = 240; i < NUMPIXELS ; i++) { //all color to one
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(i, pixels.Color(red, green, blue)); // Moderately bright green color.
    }
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(beepTime);
    //red= red-numberIncDec;
    //green = green -numberIncDec;
    blue = blue - numberIncDec;
  }

  //green= green + 1;
  // blue = blue +1;
}
