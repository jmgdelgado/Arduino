// PHOTORESISTOR - KY-018
// Sensor photoresistor
// 
// No da una temperatura correcta, da 92.5 grados y poniendo la mano
// en el sensor "baja" la temperatura
//
// La pata S se conecta a una entrada analogica
//
// VCC 5 voltios 

// Example code for KY-018
// Photoresistor

//KY018 Photo resistor module
 
int sensorPin = A5; // select the input pin for the potentiometer
int ledPin = 13; // select the pin for the LED
int sensorValue = 0; // variable to store the value coming from the sensor
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  sensorValue = analogRead(sensorPin);
  digitalWrite(ledPin, HIGH);
  delay(sensorValue);
  digitalWrite(ledPin, LOW);
  delay(sensorValue);
  Serial.println(sensorValue, DEC);
}
