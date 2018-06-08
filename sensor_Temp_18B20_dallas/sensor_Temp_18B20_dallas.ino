
// SENSOR DE TEMPERATURA BASADO EN 18B20 KY-001
// Sensor de Temperatura 18B20
//
// Se necesita la libreria OneWire que biene en el gestor de librerias de arduino
// Tambien se necesita la libreria DallasTemperatura para convertir los datos
// que envia el sensor. La libreria viene en el gestor de librerias de arduino.
// Cuidado con no equivocar las patas de VCC y GND
// Precision de 0.5 grados
// 
// La pata S se conecta a una salida digital
//
// VCC 5 voltios 
/*
  KY-001
  Toma la temperatura ambiente usando un módulo KY001 de Keyes,
  conectado al pin 2 de una placa Arduino.

  La descripción completa del proyecto se encuentra disponible en
  http://soloarduino.blogspot.com.es/2013/12/k001-sensor-de-temperatura.html

  Este código es de uso público.

  Preparado el 1 de septiembre del 2016
  por Manuel Dominguez */


// Lo primero que hacemos es definir qué librerías necesitamos usar

#include <OneWire.h>
#include <DallasTemperature.h>

// En este ejemplo vamos a conectar la salida del sensor al pin número 2 de nuestro Arduino
// El esquema de conexión se puede ver en la entrada asociada del blog SoloArduino.Blogspot.com

#define ONE_WIRE_BUS 10

// Ahora crearemos una conexión oneWire para poder comunicarnos con este protocolo
// con cualquier sensor que tengamos montado en nuestra placa que admita este tipo de comunicación
 
OneWire oneWire(ONE_WIRE_BUS);

// Ahora Le decimos a nuestro/s sensor/es de Dallas, que nos vamos a comunicar con él usando
// el protocolo oneWire.

DallasTemperature sensors(&oneWire);

// Ahora vamos a configurar nuestro proyecto
// En este caso solo usaremos la comunicación serie y
// obviamente el sensor

void setup(void)
{
  // Arrancamos el puerto serie y mandamos un mensajito a la consola para que lo sepamos
  // Gracias al puerto serie, podemos leer lo que Arduino recibe por sus canales 
  // Abre un puerto de comunicacion serie 
  // y espera a que se abra y le estable la velocidad de transmision 
  // de esta informacion en baudios. Un baudio es un bit por segundo 
  // En este caso a 9600 baudios
  Serial.begin(9600);
  Serial.println("Libreria de control para el sensor de temperatura de Dallas - Demo");
  // arrancamos el sensor
  sensors.begin();
}

void loop(void)
{
  // le preguntamos al sensor cuál es la temperatatura con sensors.requestTemperatures()  y la mostramos por el puerto serie

  Serial.print("Solicitando temperatura..."); //Sacamos un mensajito de lo que pretendemos hacer
  sensors.requestTemperatures();              // Solicitamos la temperatura 
  Serial.println("DONE");                     // Una vez obtenida la temperatura, pintamos un mensajito de que lo hemos hecho

  Serial.print("La temperatura del sensor numero 1 es: ");// como puede que tengamos muchos sensores idénticos en nuestro proyecto,
                                              //a cada uno se le asigna un número, al número 1, el 0, al número 2, el 1, etc.
  Serial.print(sensors.getTempCByIndex(0));   // y la pintamos a continuación del mensaje anterior
  Serial.println(" C ");
} 
