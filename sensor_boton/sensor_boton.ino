// BUTTON SWITCH - INTERRUPTOR BOTON - KY-004
// Sensor con un interruptor de tipo boton
// En reposo devuelve el valor 1 por la entrada digital
// cuando se pulsa devuelve el valor 0
//
// La pata S se conecta a una salida digital
//
// VCC 5 voltios 

// Example code for KY-004
// Button switch module - Button

int Led = 13 ;// define LED Interface
int buttonpin = 10; // define the key switch sensor interface
int val ;// define numeric variables val
void setup ()
{
  Serial.begin(9600);
  pinMode (Led, OUTPUT); // define LED as output interface
  pinMode (buttonpin, INPUT); // define the key switch sensor output interface
}
void loop ()
{
  val = digitalRead (buttonpin); // digital interface will be assigned a value of 3 to read val
  Serial.println(val);
  if (val == HIGH)  // When the key switch when the sensor detects a signal, LED flashes
  {
    digitalWrite (Led, LOW);
  }
  else
  {
    digitalWrite (Led, HIGH);
  }
}
