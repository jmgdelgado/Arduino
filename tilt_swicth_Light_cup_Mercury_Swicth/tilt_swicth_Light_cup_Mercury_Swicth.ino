// TILT SWITCH - LIGHT CUP - MERCURY SWITCH - TILT SENSOR MODULE (SENSOR DE ANGULO)
// Son interruptores de Mercurio, unos tienen un Led incorporado
// y otros no, pero tienen el mismo funcionamiento
// Si el mercurio esta abajo, tocando los dos conductores 
// devuelve el valor 0 por la entrada digital, sino devuelve 0
// Los que tienen LED, se activa con la senial en el pin L
// VCC 5 voltios
// 


const int INTERRUPTOR1 = 2;
const int LED1 = 3;

const int INTERRUPTOR2 = 4;
const int LED2 = 13;

void setup(){
  pinMode(INTERRUPTOR1, INPUT);
  pinMode(INTERRUPTOR2, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop(){
  digitalWrite(LED1, digitalRead(INTERRUPTOR1)); 
  digitalWrite(LED2, digitalRead(INTERRUPTOR2));  
}
