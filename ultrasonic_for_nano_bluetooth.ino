//slave
#include <SoftwareSerial.h>
SoftwareSerial s(10, 11);
int trigPin = 4;      // trig pin of HC-SR04
int echoPin = 3;     // Echo pin of HC-SR04

int revleft4 = 6;       //REVerse motion of Left motor
int fwdleft5 = 7;       //ForWarD motion of Left motor
int revright6 = 8;      //REVerse motion of Right motor
int fwdright7 = 9;     //ForWarD motion of Right motor
int ledpin = 12;

long duration, distance;

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

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);     // send waves for 10 us
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH); // receive reflected waves
  distance = duration / 58.2;   // convert to distance
  delay(10);
  Serial.println(distance);

 //remote control
//...............................................................................................................................
  if(s.available()>=-1)
   {
            char c = s.read();
            Serial.println(c);
            int readString; 
            readString +=c;
            delay(micros);

                   if (c == '1')
                    {
                     //delay(100);
    digitalWrite(fwdright7, HIGH);                    // move forward
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, HIGH);                                
    digitalWrite(revleft4, LOW);  
    digitalWrite(ledpin, HIGH);                                                     
                 delay(micros);  
                     c = "";        
                    }

    if (c == '2')
    {
         
         digitalWrite(fwdright7, LOW);      //movebackword         
         digitalWrite(revright6, HIGH);
         digitalWrite(fwdleft5, LOW);                                
         digitalWrite(revleft4, HIGH);
         digitalWrite(ledpin, HIGH);
         //delay(100);
         digitalWrite(ledpin, LOW);
         digitalWrite(ledpin, HIGH);
         digitalWrite(ledpin, LOW);
         delay(micros);
         c = "";
     }
     if (c == 'S')
    {
         //delay(100);
         digitalWrite(fwdright7, LOW);      //stop         
         digitalWrite(revright6, LOW);
         digitalWrite(fwdleft5, LOW);                                
         digitalWrite(revleft4, LOW);
    delay(micros);
    c = "";
     }       
    if (c == 'R')
    {
         delay(micros);
         digitalWrite(fwdright7, HIGH);      //RIGHT        
         digitalWrite(revright6, LOW);
         digitalWrite(fwdleft5, LOW);                                
         digitalWrite(revleft4, LOW);
    delay(micros);
    c = "";
    digitalWrite(fwdright7, HIGH);      //RIGHT FWD         
         digitalWrite(revright6, HIGH);
         digitalWrite(fwdleft5, HIGH);                                
         digitalWrite(revleft4, HIGH);
    delay(micros);
    c = "";
     }   
     if (c == 'L')
    {
         digitalWrite(fwdright7, LOW);      //LEFT       
         digitalWrite(revright6, LOW);
         digitalWrite(fwdleft5, HIGH);                                
         digitalWrite(revleft4, LOW);
    delay(micros);
    c = "";
    digitalWrite(fwdright7, HIGH);      //LEFT FWD         
         digitalWrite(revright6, HIGH);
         digitalWrite(fwdleft5, HIGH);                                
         digitalWrite(revleft4, HIGH);
    delay(micros);
    c = "";
     }                
     
  }
  //no remote
 //........................................................................................................................................

  /*else
  {
  if (distance > 19)            
 {
    digitalWrite(fwdright7, HIGH);                    // move forward
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, HIGH);                                
    digitalWrite(revleft4, LOW);                                                       
  }

  if (distance < 18)
  {
    digitalWrite(fwdright7, LOW);  //Stop                
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, LOW);                                
    digitalWrite(revleft4, LOW);
    delay(500);
    digitalWrite(fwdright7, LOW);      //movebackword         
    digitalWrite(revright6, HIGH);
    digitalWrite(fwdleft5, LOW);                                
    digitalWrite(revleft4, HIGH);
    delay(500);
    digitalWrite(fwdright7, LOW);  //Stop                
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, LOW);                                
    digitalWrite(revleft4, LOW);  
    delay(100);  
    digitalWrite(fwdright7, HIGH);       
    digitalWrite(revright6, LOW);   
    digitalWrite(revleft4, LOW);                                 
    digitalWrite(fwdleft5, LOW);  
    delay(500);
  }

}*/
}
