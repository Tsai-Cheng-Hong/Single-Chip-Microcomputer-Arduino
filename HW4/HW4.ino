#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,10,5,4,3,2); 
byte yearChar[8]=
{B10000,B11111,B00010,B01111,B01010,B11111,B00010,B00000};
byte moonChar[8]=
{B01111,B01001,B01111,B01001,B01111,B01001,B11101,B00000};
byte dayChar[8]=
{B01111,B01001,B01001,B01111,B01001,B01001,B01111,B00000};
byte smileChar[8]=
{B00000,B01010,B11111,B11111,B01110,B00100,B00000,B00000};
byte loveChar[8]=
{B00000,B10001,B00000,B00000,B10001,B01110,B00000,B00000};
int year=2017;
byte moons=12;
byte days=26;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.createChar(0,yearChar);
  lcd.createChar(1,moonChar);
  lcd.createChar(2,dayChar);
  lcd.createChar(3,smileChar);
  lcd.createChar(4,loveChar);
}

void loop() {
  // put your main code here, to run repeatedly:
lcd.setCursor(2,0);
lcd.print(year);
lcd.write(byte(0));
lcd.print(moons);
lcd.write(byte(1));
lcd.print(days);
lcd.write(byte(2));
lcd.setCursor(2,1);
lcd.print(110510216);
lcd.write(byte(3));
lcd.write(byte(4));
}

