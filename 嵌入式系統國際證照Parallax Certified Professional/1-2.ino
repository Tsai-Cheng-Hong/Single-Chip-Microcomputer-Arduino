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
  for(i=7;i>=0;i--)
  {
    digitalWrite(LedPin[i],HIGH);
    delay(600);
    digitalWrite(LedPin[i],LOW);
      }
      tone(4,1319,1500);
      delay(1500);
}
}