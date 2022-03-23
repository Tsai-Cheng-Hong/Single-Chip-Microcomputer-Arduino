#include <Servo.h>
Servo servoLeft;
Servo servoRight;


void setup() {
  
pinMode(4, INPUT);
pinMode(7, INPUT);
pinMode(5, INPUT);
pinMode(10, INPUT); pinMode(9, OUTPUT);
pinMode(3, INPUT);  pinMode(2, OUTPUT);


servoLeft.attach(13);
servoRight  .attach(12);
}

void loop() {
  
while(digitalRead(4)!=0);

while(1)
{
  byte wLeft = digitalRead(5);
  byte wRight = digitalRead(7);
  int irLeft = irDetect(9, 10, 38000);
  int irRight = irDetect(2, 3, 38000);
  
  if(irLeft == 1)
  {
    forward(450);
    turnLeft(520);
    forward(600);
}
else if(irRight == 1)
{
  forward(450);
  turnRight(520);
  forward(600);
}
 else if(wLeft == 0)
  {
    backward(300);
    turnRight(120);
}
else if(wRight == 0)
{
  backward(300);
  turnLeft(120);
}
else 
{
  forward(20);
}
}
}

int irDetect(int irLedPin, int irReceiverPin, long frequency)
{
  tone(irLedPin, frequency, 8);
  delay(1);
  int ir = digitalRead(irReceiverPin);
  delay(1);
  return ir;
}
void forward(int time)
{
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1300);
  delay(time);
}
void turnLeft(int time)
{
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1300);
  delay(time);
}
void turnRight(int time)
{
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1700);
  delay(time);
}
void backward(int time)
{
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1700);
  delay(time);
}
