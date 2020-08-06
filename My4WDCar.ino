#include <Servo.h>

Servo Ultra_Servo;

int trig = A0;
int echo = A1;
float distance;
float duration;
int motorA_IN1 = 2;
int motorA_IN2 = 3;
int motorB_IN3 = 4;
int motorB_IN4 = 5;
int motorA_ENA_PWM = 9;
int motorB_ENB_PWM = 10;
int buzzer = 11;
char input;
//int speed = 150;

void setup() {
    
  Serial.begin(9600);
  
  Ultra_Servo.attach(12);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(motorA_IN1, OUTPUT);
  pinMode(motorA_IN2, OUTPUT);
  pinMode(motorB_IN3, OUTPUT);
  pinMode(motorB_IN4, OUTPUT);
  pinMode(motorA_ENA_PWM, OUTPUT);
  pinMode(motorB_ENB_PWM, OUTPUT);
  pinMode(buzzer, OUTPUT);
 }

void loop() { 
    
  if(Serial.available()!=0)  
  {
   input=Serial.read(); 
  }  
  
  if(input == 'f'){
    
    analogWrite(motorA_ENA_PWM, 255);
    analogWrite(motorB_ENB_PWM, 255);
     
    digitalWrite(motorA_IN1, HIGH);
    digitalWrite(motorA_IN2, LOW);
    digitalWrite(motorB_IN3, HIGH);
    digitalWrite(motorB_IN4, LOW);
    delay(1);
    }    

    else if(input == 'b'){
    
    analogWrite(motorA_ENA_PWM, 255);
    analogWrite(motorB_ENB_PWM, 255);
     
    digitalWrite(motorA_IN1, LOW);
    digitalWrite(motorA_IN2, HIGH);
    digitalWrite(motorB_IN3, LOW);
    digitalWrite(motorB_IN4, HIGH);
    }

    else if(input == 'r'){
    
    analogWrite(motorA_ENA_PWM, 255);
    analogWrite(motorB_ENB_PWM, 255);
     
    digitalWrite(motorA_IN1, HIGH);
    digitalWrite(motorA_IN2, LOW);
    digitalWrite(motorB_IN3, LOW);
    digitalWrite(motorB_IN4, LOW);
    }

    else if(input == 'l'){
    
    analogWrite(motorA_ENA_PWM, 255);
    analogWrite(motorB_ENB_PWM, 255);
     
    digitalWrite(motorA_IN1, LOW);
    digitalWrite(motorA_IN2, LOW);
    digitalWrite(motorB_IN3, HIGH);
    digitalWrite(motorB_IN4, LOW);
    }

    else if(input == 's'){
    
    analogWrite(motorA_ENA_PWM, 0);
    analogWrite(motorB_ENB_PWM, 0);
     
    digitalWrite(motorA_IN1, LOW);
    digitalWrite(motorA_IN2, LOW);
    digitalWrite(motorB_IN3, LOW);
    digitalWrite(motorB_IN4, LOW);
    }
    delay(1);

    if(input == 'h'){
      digitalWrite(buzzer, HIGH);
      delay(50);
      digitalWrite(buzzer, LOW);
      delay(50);
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      delay(50);
      digitalWrite(buzzer, HIGH);
      delay(50);
      digitalWrite(buzzer, LOW);
      delay(50);
    }
    delay(1);


    for(int i=0; i<=0; i=i+2){
          
      Ultra_Servo.write(i);
      delay(1);

      digitalWrite(trig, LOW);
      delay(2);
      digitalWrite(trig, HIGH);
      delayMicroseconds(10);
      digitalWrite(trig, LOW);
  
      duration=pulseIn(echo, HIGH);
      distance=(duration*.034)/2;
      Serial.print("The Distance is = ");
      Serial.print(distance);
      Serial.println("cm");
      delay(1);  
    }

    for(int i=0; i>=0; i=i-2){
      Ultra_Servo.write(i);
      delay(1);
    
      digitalWrite(trig, LOW);
      delay(2);
      digitalWrite(trig, HIGH);
      delayMicroseconds(10);
      digitalWrite(trig, LOW);

      duration=pulseIn(echo, HIGH);
      distance=(duration*.034)/2;
      Serial.print("The Distance is = ");
      Serial.print(distance);
      Serial.println("cm");
      delay(1);
  }

  if ((distance<=15))
  {
    analogWrite(motorA_ENA_PWM, 0);
    analogWrite(motorB_ENB_PWM, 0);
     
    digitalWrite(motorA_IN1, LOW);
    digitalWrite(motorA_IN2, LOW);
    digitalWrite(motorB_IN3, LOW);
    digitalWrite(motorB_IN4, LOW);
  }






      

    
}
