/*
 BYJ48 Stepper motor code for half-step mode
 Connect :
 IN1 >> D8
 IN2 >> D9
 IN3 >> D10
 IN4 >> D11
 Jorge De León Rivas. February 2016
 paletosdelaelectronica.wordpress.com
*/
 
// Define motor pins
#define IN1 8
#define IN2 10
#define IN3 9
#define IN4 11
 
int Steps = 0; //Inital steps count
boolean Direction = true; // clockwise turn
unsigned long last_time; 
unsigned long currentMillis ;

const int step_vuelta =4096;
 
int steps_left = step_vuelta; //steps for turn
long time;
 
void setup(){
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
}
 
void loop(){
 while (steps_left > 0) { //If the motor isn't in the end position
 currentMillis = micros();
 if (currentMillis - last_time >= 1000) { //If 1 millisecond pass, next step
 stepper(1);
 time = time + micros() - last_time;
 last_time = micros();
 steps_left--;
 }
 }
 delay(2000);
 Direction = !Direction;
 steps_left = step_vuelta;
}
 
void stepper(int xw) {
 for (int x = 0; x < xw; x++) {
 switch (Steps) {
 case 0:
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, HIGH);
 break;
 case 1:
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, HIGH);
 break;
 case 2:
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
 break;
 case 3:
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
 break;
 case 4:
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW);
 break;
 case 5:
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, HIGH);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW);
 break;
 case 6:
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW);
 break;
 case 7:
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, HIGH);
 break;
 default:
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW);
 break;
 }
 SetDirection();
 }
}
void SetDirection() {
 if (Direction == 1) {
 Steps++;
 }
 if (Direction == 0) {
 Steps--;
 }
 if (Steps > 7) {
 Steps = 0;
 }
 if (Steps < 0) {
 Steps = 7;
 }
}
