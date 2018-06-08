/*
 Stepper Motor Control 28BYJ-48- one revolution
 
This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.
 
The motor should revolve one revolution in one direction, then
 one revolution in the other direction.
 
Jorge De León Rivas. February 2016
 paletosdelaelectronica.wordpress.com
 
*/
 
#include <Stepper.h>
 
const int stepsPerRevolution = 2048; // change this to fit the number of steps per revolution
// for your motor
 
// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);  //IN1,IN2,IN3,IN4
 
void setup() {
 pinMode(13, OUTPUT);
 // set the speed at 2 rpm:
 myStepper.setSpeed(20);
}
 
void loop() {
 // step one revolution in one direction:
 digitalWrite(13, HIGH);
 myStepper.step(stepsPerRevolution);
 delay(500);
 
// step one revolution in the other direction:
 digitalWrite(13, LOW);
 myStepper.step(-stepsPerRevolution);
 delay(500);
}
