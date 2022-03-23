int LedPin[8]={6,7,8,9,10,11,12,13};
int i,j;
void setup() {
  // put your setup code here, to run once:
for(i=0;i<8;i++)
pinMode(LedPin[i],OUTPUT);
pinMode(3, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
while(digitalRead(3)!=1);
while(1)
{
  for(i=0;i<5;i++)
  {
    for(j=0;j<8;j++)
    digitalWrite(LedPin[j],HIGH);
    delay(800);
    for(j=0;j<8;j++) 
    digitalWrite(LedPin[j],LOW);
    delay(800);
      }
      tone(4,1568,2000);
      delay(2000);
}
}