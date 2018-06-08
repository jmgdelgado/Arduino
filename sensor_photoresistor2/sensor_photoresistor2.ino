// PHOTORESISTOR - KY-018
// Sensor photoresistor
// 
// Cuanto mas luminosidad haya el valor devuelto por la 
// entrada analogica es menor.
// El otro sensor, del kit de 16, funciona igual y ademas 
// tiene una entrada digital que devuelve 0 con luminosidad y 1 con oscuridad
//
// La pata S se conecta a una entrada analogica
//
// VCC 5 voltios 

// Example code for KY-018
// Photoresistor

//KY018 Photo resistor module
 
int sensorPin = 10; // select the input pin for the potentiometer
int ledPin = 13; // select the pin for the LED
int sensorValue = 0; // variable to store the value coming from the sensor
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  sensorValue = digitalRead(sensorPin);
  digitalWrite(ledPin, HIGH);
  delay(sensorValue);
  digitalWrite(ledPin, LOW);
  delay(sensorValue);
  Serial.println(sensorValue, DEC);
}
