int LedPin[8]={6,7,8,9,10,11,12,13};
int i=0;

void setup() 
{
for(i=0;i<8;i++)
pinMode(LedPin[i],OUTPUT);
pinMode(3, INPUT);
}

void loop() 
{
while(digitalRead(3)!=1);
while(1)
{
  for(i=0;i<8;i++);
  {
    digitalWrite(LedPin[i],HIGH);
    delay(1000);
    digitalWrite(LedPin[i],LOW);
  }
  tone(4,1047,1000);
  delay(1000);
  
  }
}
