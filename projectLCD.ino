#include <LiquidCrystal.h>
LiquidCrystal lcd(//pins to use//);

void setup() {
  // put your setup code here, to run once:
lcd.begin(16, 2);
lcd.print("Firewall Enagage!");
}

void loop() {
  // put your main code here, to run repeatedly:
lcd.setCursor(0, 1);
lcd.print("Temp C ");
lcd.setCursor(6, 1);
if //danger signal recieved//
  {
    lcd.begin(16, 2);
    lcd.print("Danger!");
  }
else
  {
    lcd.begin(16, 2);
    lcd.print("Searching!");
  }
}
