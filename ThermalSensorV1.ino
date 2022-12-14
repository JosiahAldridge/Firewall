/***************************************************************************
  This is a library for the AMG88xx GridEYE 8x8 IR camera

  This sketch tries to read the pixels from the sensor

  Designed specifically to work with the Adafruit AMG88 breakout
  ----> http://www.adafruit.com/products/3538

  These sensors use I2C to communicate. The device's I2C address is 0x69

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Dean Miller for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/

#include <Wire.h>
#include <Adafruit_AMG88xx.h>

Adafruit_AMG88xx amg;
int dangerTemp;
int dangerCount;
int dangerLimit;
bool combatState = LOW;
bool searchState = HIGH;
float pixels[AMG88xx_PIXEL_ARRAY_SIZE];

void setup() {
    
    bool status;
    
    // default settings
    status = amg.begin();
    if (!status) {
        Serial.println("Could not find a valid AMG88xx sensor, check wiring!");
        while (1);
    }
    delay(100); // let sensor boot up
}


void loop() 
{
  if (searchState = HIGH) 
  {
    //read all the pixels
    amg.readPixels(pixels);
    dangerCount = 0;
    for(int i=1; i<=AMG88xx_PIXEL_ARRAY_SIZE; i++){
      if (pixels[i-1] >= dangerTemp)
      {
        dangerCount += 1;
      }
    }
    if (dangerCount >= dangerLimit)
    {
      searchState = LOW;
      combatState = HIGH;
    }
    //delay a second
    delay(1000);
  }
}
