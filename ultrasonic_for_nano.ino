#include <SoftwareSerial.h>
int ledpin=12;
int trigPin = 2;      // trig pin of HC-SR04
int echoPin = 3;     // Echo pin of HC-SR04

int revleft4 = 6;       //REVerse motion of Left motor
int fwdleft5 = 7;       //ForWarD motion of Left motor
int revright6 = 8;      //REVerse motion of Right motor
int fwdright7 = 9;     //ForWarD motion of Right motor

long duration, distance;
SoftwareSerial s(10, 11);

void setup() {
  
  delay(random(500,2000));   // delay for random time
  Serial.begin(9600);
  s.begin(9600);
  pinMode(revleft4, OUTPUT);      // set Motor pins as output
  pinMode(fwdleft5, OUTPUT);
  pinMode(revright6, OUTPUT);
  pinMode(fwdright7, OUTPUT);
  
  pinMode(trigPin, OUTPUT);         // set trig pin as output
 pinMode(echoPin, INPUT);          //set echo pin as input to capture reflected waves
 pinMode(ledpin,OUTPUT);
}

void loop() {
       char c = s.read();
            int readString; 
            readString +=c;
            delay(2);

                   if (c == '1')
                    {
                     delay(1000);
    digitalWrite(fwdright7, HIGH);                    // move forward
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, HIGH);                                
    digitalWrite(revleft4, LOW); 
    digitalWrite(ledpin, HIGH);                                                       

                     c = "";           
                    }
                      if (c == '2')
                                  {
                                    delay(1000);
                                    digitalWrite(fwdright7, LOW);      //movebackword         
    digitalWrite(revright6, HIGH);
    digitalWrite(fwdleft5, LOW);                                
    digitalWrite(revleft4, HIGH);
    digitalWrite(ledpin, LOW);
   // delay(500);
                                    
                                    c = "";
                                  } 
}
