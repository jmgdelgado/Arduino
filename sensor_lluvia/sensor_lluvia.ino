// SENSOR DE LLUVIA DEL KIT 16 en 1
// Sensor lluvia que detecta las gotas de lluvia en la placa
// tiene una salida digital D0 y una analogica A0
// la salida analogica no es muy util. Se puede usar el potenciometro
// para regular el umbral de deteccion
// En seco devuelve el valor 0 y en mojado el valor 1
//
// La pata S se conecta a una salida digital
//
// VCC 5 voltios 



const int sensorPin = 9;
 
void setup() {
  Serial.begin(9600);   //iniciar puerto serie
  pinMode(sensorPin, INPUT);  //definir pin como entrada
}
 
void loop(){
  int value = 0;
  value = digitalRead(sensorPin );  //lectura digital de pin
 
  if (value == LOW) {
      Serial.println("Detectada lluvia");
  }
  else {
      Serial.println("Seco");
  }
  delay(1000);
}
