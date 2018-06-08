// MODULO SMD LED RGB - KY-009
// Modulo actuador que consiste en un led con 3 entradas para color R,G,B
// 
// La pata R: rojo, hay que conectar una resistencia de 180 ohmios
// La pata G: verde, hay que conectar una resistencia de 100 ohmios
// La pata V: verde, hay que conectar una resistencia de 100 ohmios
//
// VCC 5 voltios (en este caso los pines de color)

int redpin = 11; // select the pin for the red LED
int bluepin = 10; // select the pin for the blue LED
int greenpin = 9; // select the pin for the green LED
int val=0;
void setup () {
  pinMode (redpin, OUTPUT);
  pinMode (bluepin, OUTPUT);
  pinMode (greenpin, OUTPUT);
  Serial.begin (9600);
}
 
void loop () {
  for (val=255; val>0; val--)
  {
    analogWrite (redpin, val);
    analogWrite (bluepin, 255-val);
    analogWrite (greenpin, 128-val);
    delay (1);
  }
  for (val = 0; val <255; val++)
  {
    analogWrite (redpin, val);
    analogWrite (bluepin, 255-val);
    analogWrite (greenpin, 128-val);
    delay (1);
  }
  Serial.println (val, DEC);
}
