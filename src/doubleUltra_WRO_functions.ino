#include <Servo.h>

Servo servo1;
int servoPin = 8;

int TRIG = 13;
int ECHO = 12;
int DURATION;
int DISTANCE;

int IN1 = 7;
int IN2 = 6;
int ENA = 5;

int IN3 = 2;
int IN4 = 4;
int ENB = 3;

int ECHO2 = 9;
int TRIG2 = 10;
int DURATION2;
int DISTANCE2;

int ECHO3 = 11;
int TRIG3 = 22;
int DURATION3;
int DISTANCE3;
void setup() {
  // put your setup code here, to run once:
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT);

  pinMode(TRIG3, OUTPUT);
  pinMode(ECHO3, INPUT);

  Serial.begin(9600);

  servo1.attach(servoPin);
  servo1.write(90);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  delay(5000);
}

void forwards(){
  servo1.write(90);
  analogWrite(ENA, 100);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENB, 100);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft(){

  servo1.write(170);
  analogWrite(ENA, 200);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENB, 200);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnRight(){

  servo1.write(10);
  analogWrite(ENA, 200);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENB, 200);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void backwards(){

  servo1.write(90);
  analogWrite(ENA, 100);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENB, 100);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  DURATION = pulseIn(ECHO, HIGH);
  DISTANCE = DURATION / 58.2;
  Serial.print("DISTANCE");
  Serial.println(DISTANCE);
  delay(20);

  if(DISTANCE <= 40 && DISTANCE >= 0){

    digitalWrite(ENA, LOW);
    digitalWrite(ENB, LOW);
    delay(DISTANCE * 10);

    digitalWrite(TRIG3, HIGH);
    delay(1);
    digitalWrite(TRIG3, LOW);
    DURATION3 = pulseIn(ECHO3, HIGH);
    DISTANCE3 = DURATION3 / 58.2;
    Serial.print("            DISTANCEleft");
    Serial.println(DISTANCE3);
    delay(20);
    
    digitalWrite(TRIG2, HIGH);
    delay(1);
    digitalWrite(TRIG2, LOW);
    DURATION2 = pulseIn(ECHO2, HIGH);
    DISTANCE2 = DURATION2 / 58.2;
    Serial.print("            DISTANCEright");
    Serial.println(DISTANCE2);
    delay(20);

    if (DISTANCE3 <= 30 && DISTANCE3 >= 1){
      Serial.print("          DE_LEFT");
      
      backwards();
      delay(1000);

      turnRight();
      delay(1100);

    }else if (DISTANCE2 <= 30 && DISTANCE2 >= 1){
      Serial.print("          DE-RIGHT");
      
      backwards();
      delay(1000);

      turnLeft();
      delay(1100);

    }else{
      
      backwards();
      delay(1000);

      turnLeft();
      delay(1100);
      
    }
  }else{
    forwards();
  }
}