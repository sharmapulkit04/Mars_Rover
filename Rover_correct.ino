//int brk[6],dir[6],pwm[6];
//f 24-29,b 32-37,pwm 2-7,s 8,9,10,11
#include<Servo.h>
int pwm[6];
int b[6];

int f[6]={24,23,26,27,28,29};
Servo S1,S2;
void setup() {
  // put your setup code here, to run once:



Serial.begin(9600);

Serial3.begin(9600);
//int j=0;
/*for(int i=22;i<28;i++)
{
  pinMode(i,OUTPUT);
  //brk[j]=i;//pin decide
  //j++;
}
//j=0;*/
/*for(int i=28;i<34;i++)
{
  pinMode(i,OUTPUT);
  //dir[j]=i;//pin decide
  //j++;
}*/

pinMode(53,OUTPUT);
pinMode(52,OUTPUT);


  digitalWrite(52,LOW);
  digitalWrite(53,LOW);
  

int j=0;
for(int i=2;i<8;i++)
{
  pinMode(i,OUTPUT);
  pwm[j]=i;//pin decide
  j++;
}
j=0;
for(int i=0;i<6;i++)
{
  pinMode(f[i],OUTPUT);
  //pin decide
  j++;
}
j=0;
for(int i=32;i<37;i++)
{
  pinMode(i,OUTPUT);
  b[j]=i;//pin decide
  j++;
}
S1.attach(8);  // attaches the servo on pin 9 to the servo object
S2.attach(9);
}
void forward()
{
      for(int i=0;i<6;i++)
    {
      digitalWrite(f[i],HIGH);
      digitalWrite(b[i],LOW);
      analogWrite(pwm[i],127);
    }
     
    
}
void reverse()
{
     for(int i=0;i<6;i++)
    {
      digitalWrite(f[i],LOW);
      digitalWrite(b[i],HIGH);
      analogWrite(pwm[i],127);
    }
    
}
int s1=90,s2=90;
char c;
void sweepRight()
{
  if((s1<=180&&s1>=0)&&(s2<=180&&s2>=0))
  {
  S1.write(s1++);
  S2.write(s2++);
  return;
  }
  if(s1>180)
  s1=180;
  if(s2>180)
  s2=180;
  if(s2<0)
  s2=0;
}
void sweepLeft()
{
  if((s1<=180&&s1>=0)&&(s2<=180&&s2>=0))
  {
  S1.write(s1--);
  S2.write(s2--);
  return;
  }
  if(s1>180)
  s1=180;
  if(s2>180)
  s2=180;
  if(s1<0)
  s1=0;
  if(s2<0)
  s2=0;
}
/*void Break()
{
   for(int i=0;i<6;i++)
    {
      digitalWrite(brk[i],1);
    } 
}*/
void loop() {
  // put your main code here, to run repeatedly:
if(Serial3.available()>0)
{
  digitalWrite(52,HIGH);
  digitalWrite(53,HIGH);
  
  Serial.print(1);
  char c=Serial3.read();
  if(c=='F')
  {
      forward();
  }
  else if(c=='B')
  {
    reverse();
  }
  else if(c=='R')
  {
     sweepRight();
  }
  else if(c=='L')
  {
    sweepLeft();
  }
}
}
