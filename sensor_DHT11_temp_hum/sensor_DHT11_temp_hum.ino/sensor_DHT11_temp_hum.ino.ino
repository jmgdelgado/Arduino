// SENSOR DE TEMPERATURA Y HUMEDAD DHT11
// Sensor DHT11 de Temperatura y Humedad
//
// Se necesita la libreria de Adafruit DHT sensor library.
// ATENCION: Instalar la version 1.2.3 con la 1.3.0 no compila 
// 
// La pata DATA se conecta a una salida digital
// En Arduino Nano: Pin D2
// En NodeMCU: Pin D4
//
// VCC 5 voltios 

#include <DHT.h>

int SENSOR = 2;
int temp, humedad;

DHT dht (SENSOR, DHT11);

void setup(){
  Serial.begin(9600);
  dht.begin();
}

void loop(){
  humedad = dht.readHumidity();
  temp = dht.readTemperature();

  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.print("ºC Humedad: ");
  Serial.print(humedad);
  Serial.println("%");


  delay(500);
}
