// SENSOR ANALOG HALL KY-035
// Sensor Magnetico ANALOGICO que se activa con un campo magnetico, 
// por ejemplo acercando un iman
//
// No confundir con el Hall KY-003
//
// En estado de reposo devuelve un valor alrededor de 540
// cuando se acerca un iman el valor aumenta o disminuye
// dependiendo el polo del iman que se acerque
// 
// La pata S se conecta a una entrada ANALOGICA
//
// VCC 5 voltios 
/* 
KY-035 Hall analog sensor
*/
 
int sensorPin = A5;    // select the input pin
int ledPin = 13;       // select the pin for the LED
int sensorValue = 0;   // variable to store the value coming from the sensor
 
void setup () {
  pinMode (ledPin, OUTPUT);
  Serial.begin (9600);
}
 
void loop () {
  sensorValue = analogRead (sensorPin);
  digitalWrite (ledPin, HIGH);
  delay (sensorValue);
  digitalWrite (ledPin, LOW);
  delay (sensorValue);
  Serial.println (sensorValue, DEC);
}
