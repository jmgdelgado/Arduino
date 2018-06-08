// FLAME SENSOR - SENSOR DE LLAMA
// Sensor que detecta una llama, el potenciometro sirve para calibrar la distancia
// Tiene una salida analogica y otra digital
// El sensor rojo de 4 pines devuelve 1 cuando detecta, 
// y el sensor azul de 3 pines devuelve 0 cuando detecta
/*
GND - GND
Vcc - 5v
A0  - A0
D0  - D9
*/

const int LED=13;
const int FLAME = 9;

void setup(){
  pinMode(LED, OUTPUT);
  pinMode(FLAME, INPUT);  
}


void loop(){
  digitalWrite(LED, digitalRead(FLAME));  
}
