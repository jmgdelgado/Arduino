// LIGHT BLOCKING - PHOTO INTERRUPTOR - OPTICAL BROKEN MODULE - KY-010
// Sensor fotoelectrico que se activa cuando se interrumpe el sensor optico
// cuando se interpone un objeto entre su emisor y receptor
//
// La pata S se conecta a una salida digital
//
// VCC 5 voltios 

// Example code for KY-010
// photo interrupter module
 
int Led = 13 ;// define LED Interface
int buttonpin = 3; // define the photo interrupter sensor interface
int val ;// define numeric variables val
void setup ()
{
  Serial.begin(9600);
  pinMode (Led, OUTPUT) ;// define LED as output interface
  pinMode (buttonpin, INPUT) ;// define the photo interrupter sensor output interface   
}
void loop ()
{
  val = digitalRead (buttonpin) ;// digital interface will be assigned a value of 3 to read val
  Serial.println(val);
  if (val == HIGH) // When the light sensor detects a signal is interrupted, LED flashes
  {
    digitalWrite (Led, HIGH);
  }
  else
  {
    digitalWrite (Led, LOW);
  }
}
