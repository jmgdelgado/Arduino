// SENSOR ULTRASONICO HC-SR04
// sensor ultrasonico que mide las distancias
// rango de 2 cm a 400 cm, en un angulo de 30º
// Se lanza una senial por el pin TRIG(er) del sensor y
// se recoge en el pin ECHO del sensor, se calcula la
// Una senial digital de salida por el TRIG
// y una entrada digital por el ECHO
// distancia por la duracion de la recepcion de la senial
// VCC 5 voltios (4.5V - 5.5V)

int Trig = 8;
int Echo = 9;


void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
  pinMode(Trig,OUTPUT);   // Se activa el lanzamiento de la onda de sonido
  pinMode(Echo,INPUT);    // Se recive el eco de la onda
}

void loop() {
  // put your main code here, to run repeatedly:

  long duracion;
  long distancia;

  digitalWrite(Trig,LOW);  // se limpia la salida
  delayMicroseconds(4);
  digitalWrite(Trig,HIGH);  // se lanza la onda
  delayMicroseconds(10);    // duracion de la onda
  digitalWrite(Trig,LOW);   // fin de la onda

  // la funcion pulseIn da la duracion que tarda el pin Echo
  // en pasar de High a Low
  duracion = pulseIn(Echo,HIGH);  //Tiempo de ida y vuelta de la onda

  duracion = duracion / 2;  // Interesa el tiempo de ida

  // 343 metros por segundo:  1 cm por 29.2 microsegundos
  distancia = duracion / 29.2 ;  // Calculamos los centimetros recorridos

  Serial.println(distancia);
}
