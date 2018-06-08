// BALL SWITCH - TILT SWITCH - MODULO DE INCLINACION - KY-020
// Sensor de inclinacion, cuando se mueve el sensor se activa el interruptor
// PARECE QUE ESTE SENSOR NO FUNCIONA
//
// La pata S se conecta a una salida digital
//
// VCC 5 voltios 

// Example code for KY-020
// Ball switch module - Tilt switch
 
int Led = 13 ;// define LED Interface
int buttonpin = 3; // define the tilt switch sensor interfaces
int val ;// define numeric variables val
void setup ()
{
  Serial.begin(9600);
  pinMode (Led, OUTPUT) ;// define LED as output interface
  pinMode (buttonpin, INPUT) ;//define the output interface tilt switch sensor
}
void loop ()
{
  val = digitalRead (buttonpin) ;// digital interface will be assigned a value of 3 to read val
  Serial.println(val);
  if (val == HIGH) //When the tilt sensor detects a signal when the switch, LED flashes
  {
    digitalWrite (Led, HIGH);
  }
  else
  {
    digitalWrite (Led, LOW);
  }
}
