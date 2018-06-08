// SENSOR PIR piroelectrico DETECTOR DE MOVIMIENTO
// sensor infrarrojo pasivo o piro electrico
// Cuando detecta presencia devuelve el valor 1 por el
// pin DATA,
// cuando no detecta nada devuelve el valor 0
// los dos potenciometros sirven para ajustar la sensibilidad
// de la medicion y el tiempo entre mediciones
// VCC 5 voltios


void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
  pinMode(A0,INPUT);    // Pin DATA del sensor
}

void loop() {
  // put your main code here, to run repeatedly:

  int valor = digitalRead(A0);
  Serial.println(valor);
  
  if (valor == 1) 
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
