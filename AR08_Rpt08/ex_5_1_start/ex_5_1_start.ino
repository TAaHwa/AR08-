#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2); // 0x27 또는 0x3F 둘다 안될경우에는 확인해봐야함

#define Button_pin 2
bool Button_flag = false;
int Button_value = 0;

void setup()
{
  lcd.begin();
  pinMode(Button_pin, INPUT);
  // Turn on the blacklight and print a message.
}

void loop()
{
    if (digitalRead(Button_pin) == 0)Button_flag = true;
    if (digitalRead(Button_pin) == 1 && Button_flag == true)
    {
      Button_flag = false;
      Button_value++;
    }
  lcd.setCursor(0, 0);
  lcd.print("Push the Button");
  lcd.setCursor(0, 1);
  lcd.print("value : ");
  lcd.print(Button_value);
  delay(10);
}
