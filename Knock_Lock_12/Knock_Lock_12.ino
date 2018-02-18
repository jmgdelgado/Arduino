#include <Servo.h>
Servo myServo;
const int piezo = A0;
const int switchPin = 2;
const int yellowLed = 3;
const int greenLed  = 4;
const int redLed    = 5;

int knockVal;
int switchVal;
int prevKnockval = 0;
int prevNumberOfKnocks = 0;
int prevSwitchVal = -1;

const int quietKnock = 10;
const int loudKnock  = 1023;
boolean locked = false;
int numberOfKnocks = 0;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
  pinMode(yellowLed,OUTPUT);
  pinMode(redLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(switchPin,INPUT);
  Serial.begin(9600);
  digitalWrite(greenLed,HIGH);
  myServo.write(0);
  Serial.println("The box is unlocked!");
  
}

void loop() {
  // put your main code here, to run repeatedly:

  if (locked == false){
    switchVal = digitalRead(switchPin);
    if (switchVal != prevSwitchVal) {
      Serial.print("valor del switch: ");
      Serial.println(switchVal);
      prevSwitchVal = switchVal;
    }  
    
    if(switchVal == HIGH){
      locked = true;
      digitalWrite(greenLed,LOW);
      digitalWrite(redLed,HIGH);
      myServo.write(90);
      Serial.println("The box is locked!");
      delay(1000);
    }
  }

  if (locked == true){
    knockVal = analogRead(piezo);
    if (numberOfKnocks < 3 && knockVal > 0){
      if (checkForKnock(knockVal) == true){
        numberOfKnocks++;
      }
      if (numberOfKnocks != prevNumberOfKnocks){
        Serial.print(3-numberOfKnocks);
        Serial.println(" more knocks to go");
        prevNumberOfKnocks = numberOfKnocks;
        delay(200);
      }  
    }

    if (numberOfKnocks >= 3){
      locked = false;
      myServo.write(0);
      delay(20);
      digitalWrite(greenLed,HIGH);
      digitalWrite(redLed,LOW);
      Serial.println("The box is unlocked!");
      numberOfKnocks = 0;
    }
  }
}

boolean checkForKnock(int value){
  if (value > quietKnock && value < loudKnock){
    digitalWrite(yellowLed, HIGH);
    delay(0);
    digitalWrite(yellowLed, LOW);
    Serial.print("Valid knock of value ");
    Serial.println(value);
    return true;
  }
  else {
    if (value != prevKnockval){
      Serial.print("Bad knock value ");
      Serial.println(value);
      prevKnockval = value;
    }  
    return false;
  }
}

