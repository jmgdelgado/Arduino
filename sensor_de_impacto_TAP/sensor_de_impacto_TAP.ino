// TAP SENSOR - SENSOR DE IMPACTO O SENSOR DE GOLPES KY-031
// Sensor de impacto que recoge los golpes que se dan a en 
// la superficie en la que esta el sensor
//
// El sensor es muy poco sensible, tienen que ser golpes muy fuertes
// se ve mejor la variacion del impacto con una entrada digital y 
// el Serial Ploter
//
// La pata S se conecta a una salida digital
//
// VCC 5 voltios 

int Led = 13 ; // define LED Interface
int Shock = 3; // define the percussion Sensor Interface
int val ; // define numeric variables val
 
void setup ()
{
  Serial.begin(9600);
  pinMode (Led, OUTPUT) ; // define LED as output interface
  pinMode (Shock, INPUT) ; // define knock sensor output interface
}
void loop ()
{
  val = digitalRead (Shock) ; // read digital interface is assigned a value of 3 val
  Serial.println(val);
  if (val == HIGH) // When the percussion when the sensor detects a signal, LED flashes
  {
    digitalWrite (Led, LOW);
  }
  else
  {
    digitalWrite (Led, HIGH);
  }
  delay(200);
}
