// SENSOR HALL MAGNETIC KY-003
// Sensor Magnetico DIGITAL que se activa con un campo magnetico, 
// por ejemplo acercando un iman
//
// No confundir con el Analog Hall KY-035
//
// Cuando detecta un campo magnetico se ilumina el led del sensor
// y devuelve el estado 0, en estado de reposo devuelve 1
// 
// La pata S se conecta a una salida digital
//
// VCC 5 voltios 

/*
KY-003 Hall magnetic switch
*/
 
int Led = 13 ; // define LED Interface
int SENSOR = 10 ; // define the Hall magnetic sensor interface
int val ; // define numeric variables val
 
void setup ()
{
  Serial.begin(9600);
  pinMode (Led, OUTPUT) ;    // define LED as output interface
  pinMode (SENSOR, INPUT) ;  // define the Hall magnetic sensor line as input
}
 
void loop ()
{
  val = digitalRead (SENSOR) ; // read sensor line
  Serial.println(val);
  if (val == LOW) // when the Hall sensor detects a magnetic field, Arduino LED lights up
  {
    digitalWrite (Led, HIGH);
  }
  {
    digitalWrite (Led, LOW);
  }
}
