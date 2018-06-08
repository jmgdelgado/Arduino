// TRACKING MODULE - TRACING MODULE
// Modulo que detecta el contraste entre zona clara y oscura
// muy usado en robots para el seguimiento de lineas
// Poner el Pin D0 en una entrada digital
// VCC 5 voltios
// 


const int sensorPin = 9;
 
void setup() {
  Serial.begin(9600);   //iniciar puerto serie
  pinMode(sensorPin, INPUT);  //definir pin como entrada
}
 
void loop(){
  int value = 0;
  value = digitalRead(sensorPin );  //lectura digital de pin
 
  if (value == LOW) {
      Serial.println("TCRT5000L activado");  //zona oscura
  }
  delay(1000);
}
