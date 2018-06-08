// MODULO RGB LED - 3 COLOR LED - KY-016
// Modulo actuador que consiste en un led con 3 entradas para color R,G,B
// 
// En este modulo no hace falta poner resistencia, ya que las lleva puestas
// La pata R: rojo
// La pata G: verde
// La pata V: verde
//
// VCC 5 voltios (en este caso los pines de color)

//KY016 3-color LED module
int redpin = 11; // select the pin for the red LED
int bluepin = 10; // select the pin for the blue LED
int greenpin = 9 ;// select the pin for the green LED
int val;
void setup () {
  pinMode (redpin, OUTPUT);
  pinMode (bluepin, OUTPUT);
  pinMode (greenpin, OUTPUT);
  Serial.begin (9600);
}
void loop ()
{
  for (val = 255; val> 0; val --)
  {
    analogWrite (11, val);
    analogWrite (10, 255-val);
    analogWrite (9, 128-val);
    delay (10);
    Serial.println (val, DEC);
  }
  for (val = 0; val <255; val ++)
  {
    analogWrite (11, val);
    analogWrite (10, 255-val);
    analogWrite (9, 128-val);
    delay (10);
    Serial.println (val, DEC);
  }
}
