#include <SPI.h>
const int slaveSelect=10;
const int decodeMode=9;
const int intensity=10;
const int scanLimit=11;
const int shutDown=12;
const int dispTest=15;
byte i;
int j;
const byte character[8]=
{ B00000000, B11111100,
  B00010010, B00010001,
  B00010001, B00010010,
  B11111100, B00000000 };
  
void setup() {
  // put your setup code here, to run once:
SPI.begin();
pinMode(slaveSelect,OUTPUT);
digitalWrite(slaveSelect,HIGH);
sendCommand(shutDown,1);
sendCommand(dispTest,0);
sendCommand(intensity,1);
sendCommand(scanLimit,7);
sendCommand(decodeMode,0);
for(i=0;i<8;i++)
  sendCommand(i+1,0);
}

void loop() {
  // put your main code here, to run repeatedly:
for(j=0;j<2;i++){
  sendCommand(shutDown,1);
  for(i=0;i<8;i++){
sendCommand(i+1,character[i]);
  }
  delay(500);
  sendCommand(shutDown,0);
  delay(500);
  j--;
}
}
void sendCommand(byte command,byte value)
{
  
  digitalWrite(slaveSelect,LOW);
  SPI.transfer(command);
  SPI.transfer(value);
  digitalWrite(slaveSelect,HIGH);
}
