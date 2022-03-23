int i;
int KeyData;
int numKeys=0;
int val=0;
const int debounceDelay=20;
const byte num[10]=
{ B11000000, B11111001,
  B10100100, B10110000,
  B10011001, B10010010,
  B10000010, B11111000,
  B10000000, B10010000 };
  const int seg[]={2,3,4,5,6,7,8,9};
  const int sw=10;

void setup() {
  // put your setup code here, to run once:
pinMode(sw,INPUT_PULLUP);
for(i=0;i<8;i++)
pinMode(seg[i],OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  KeyData=digitalRead(sw);
  if(KeyData==LOW)
  {
    delay(debounceDelay);
    while(digitalRead(sw)==LOW)
    ;
    numKeys++;
  }
  if(numKeys%2==0)
  {
    val++;
    if(val>9)
    val=0;
  }
  else 
  {
    val--;
    if(val<0)
    val=9;
  }
  for(i=0;i<8;i++)
  {
    if(bitRead(num[val],i))
    digitalWrite(seg[i],HIGH);
    else
    digitalWrite(seg[i],LOW);
  }
  delay(1000);
}
