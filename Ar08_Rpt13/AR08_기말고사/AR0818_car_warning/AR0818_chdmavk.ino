#define TRIG 4

#define ECHO 3

#define BUZ  9

 

unsigned long distance = 0;

 

void setup() {

  Serial.begin(9600);

  pinMode(BUZ, OUTPUT);  // 피에조 부저 출력 설정  

  pinMode(TRIG, OUTPUT);  // 초음파 출력 설정

  pinMode(ECHO, INPUT);   // 초음파 입력 설정

} 

 

void loop() {  

  digitalWrite(TRIG, LOW);

  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);

  delayMicroseconds(5);

  digitalWrite(TRIG, LOW);      

  

  distance = pulseIn(ECHO, HIGH) / 29 / 2;  // cm 단위로 변경

  Serial.println( distance );

    

  if (distance < 3)         // 10cm보다 가까우면...

    tone(BUZ, 330, 200);    // 330Hz(미), 시간 0.2초    

  else if (distance < 5)   // 20cm보다 가까우면...

    tone(BUZ, 294, 200);    // 294Hz(레)   

  else if (distance < 10)    // 30cm보다 가까우면...

    tone(BUZ, 262, 200);    // 262Hz(도) 

 

  delay(300);  

}
