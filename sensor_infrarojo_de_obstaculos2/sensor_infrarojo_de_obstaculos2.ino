// DETECTOR DE OBSTACULOS POR INFRAROJOS
// Cuando detecta presencia devuelve el valor 0 por el
// pin OUT y se enciende un led en el sensor,
// cuando no detecta nada devuelve el valor 0
// el potenciometro sirve para regular la sensibilidad de deteccion
// VCC 5 voltios
// El pin EN no se para que sirve, no hace falta en principio


const int LED = 13;
const int SENSOR = 2;
int valor;

void setup(){
  pinMode(LED, OUTPUT);
  pinMode(SENSOR, INPUT);  
}

void loop(){
  valor = digitalRead(SENSOR);
  digitalWrite(LED, !valor);

  delay(500);
}
