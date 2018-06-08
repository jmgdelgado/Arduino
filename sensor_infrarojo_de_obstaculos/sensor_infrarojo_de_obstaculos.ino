// DETECTOR DE OBSTACULOS POR INFRAROJOS
// Cuando detecta presencia devuelve el valor 0 por el
// pin DATA y se enciende un led en el sensor,
// cuando no detecta nada devuelve el valor 1
// el potenciometro sirve para regular la sensibilidad de deteccion
// VCC 5 voltios

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
  pinMode(9,INPUT);    // Pin DATA del sensor
}

void loop() {
  // put your main code here, to run repeatedly:

  int valor = digitalRead(9);
  Serial.println(valor);
  
  if (valor == 0) 
  {
    Serial.println("Detectado");
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
  delay(200);
}
