int i;
int j;
int k;
int ledStatus[10];
const int numCols=4;
const int numRows=4;
const int debounceDelay=20;
const int led[]={10,11,12,13,14,15,16,17,18,19};
const int col[]={6,7,8,9};
const int row[]={2,3,4,5};
const int keyMap[numRows][numCols]=
{  {10,1,2,3},
   {11,4,5,6},
   {12,7,8,9},
   {13,15,0,14}  };

void setup() {
  // put your setup code here, to run once:
for(i=0;i<numCols;i++)
{
  pinMode(col[i],OUTPUT);
  digitalWrite(col[i],HIGH);
}
for(j=0;j<numRows;j++)
{
  pinMode(row[j],INPUT);
  digitalWrite(row[j],HIGH);
}
for(k=0;k<10;k++)
{
  pinMode(led[k],OUTPUT);
  digitalWrite(led[k],LOW);
  ledStatus[k]=LOW;
  }
}
void loop() {
  // put your main code here, to run repeatedly:
int key=getKey();
if(key>=0 && key<=9)
{
  ledStatus[key]=!ledStatus[key];
  digitalWrite(led[key],ledStatus[key]);
  }
}

int getKey()
{
  int i;
  int j;
  int key=-1;
  for(i=0;i<numCols;i++)
  {
    digitalWrite(col[i],LOW);
    for(j=0;j<numRows;j++)
    {
      if(digitalRead(row[j])==LOW)
      {
        delay(debounceDelay);
        while(digitalRead(row[j])==LOW)
        ;
        key=keyMap[j][i];
      }
    }
    digitalWrite(col[i],HIGH);
  }
  return(key);
}
