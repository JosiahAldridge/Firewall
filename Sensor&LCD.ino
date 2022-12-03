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
#include <LiquidCrystal.h>

Adafruit_AMG88xx amg;
int dangerTemp = 69;
int dangerCount;
int dangerLimit = 1;
bool combatState = LOW;
bool searchState = HIGH;
float pixels[AMG88xx_PIXEL_ARRAY_SIZE];
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int maxTemp;
int maxTempF;


void setup() {
    
    bool status;
    
    // default settings
    status = amg.begin();
    if (!status) {
        Serial.println("Could not find a valid AMG88xx sensor, check wiring!");
        while (1);
    }
    delay(100); // let sensor boot up
    lcd.begin(16, 2);
    lcd.print("Firewall Enagage!");
    delay(2000);
}


void loop() 
{
  maxTemp = 0;
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
    for(int i=1; i<=AMG88xx_PIXEL_ARRAY_SIZE; i++){
      if (pixels[i-1] > maxTemp)
      {
        maxTemp = pixels[i-1];
      }
    }
    lcd.setCursor(1, 1);
    lcd.print("Temp       F");
    lcd.setCursor(6, 1);
    maxTempF = (maxTemp*1.8)+32;
    lcd.print(maxTempF);
    lcd.setCursor(0, 0);
    if (dangerCount >= dangerLimit)
    {
      searchState = LOW;
      combatState = HIGH;
      lcd.print("Danger!      ");
    }
    else
    {
      lcd.print("Searching!       ");
    }
    //delay a second
    delay(500);
  }
}
