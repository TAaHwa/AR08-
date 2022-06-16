#include <Servo.h>
  int i;
  int LED = 12;
  Servo myservo;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(13);
  pinMode(8,INPUT);
  pinMode(9,OUTPUT);
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  delayMicroseconds(2);
  digitalWrite(9,HIGH);
  delayMicroseconds(10);
  digitalWrite(9,LOW);

  unsigned long duration = pulseIn(8,HIGH);
  float distance = ((float)(340*duration)/10000)/2; 

  Serial.print(distance);
  Serial.println("cm");
  myservo.write(90);
  if(distance < 10){
    for(i = 8; i > 0; i--){
      myservo.write(0);
      digitalWrite(LED,1);
      delay(500);
      digitalWrite(LED,0);
      delay(100);
      Serial.print(distance);
      Serial.println("cm");
    }
          
  }
  else{
    myservo.write(90);
    digitalWrite(LED,0);
  }
}
