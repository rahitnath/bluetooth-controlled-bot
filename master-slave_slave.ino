#include<SoftwareSerial.h>
SoftwareSerial s(3,4);
int ledpin=11;
int p;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  s.begin(9600);
  pinMode(ledpin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(s.available()>0){
 p=s.read();
 Serial.println(p);
  if (p=='1')
  {
    digitalWrite(ledpin,HIGH);
  }
  if (p=='0')
  {
    
    digitalWrite(ledpin,LOW);
    //delay(200);
  }
  }
}
