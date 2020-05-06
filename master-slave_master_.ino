#include<SoftwareSerial.h>
SoftwareSerial s(3,4);
//int ledpin=11;
//int p;
void setup() {
  Serial.begin(9600);
  s.begin(9600);
  //pinMode(ledpin,OUTPUT);

}

void loop() {
   char c = Serial.read();
            int readString; 
            readString +=c;
            delay(2);
 s.write(c);
 Serial.println(readString);
 delay (200);
}
