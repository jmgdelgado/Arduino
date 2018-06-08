// SENSOR HUMAN BODY TOUCH. 
// Sensor capacitivo que detecta cuando se toca el sensor 
// con la piel
// Cuando detecta presencia devuelve el valor 1 por el
// por el pin D0 del sensor llegan los datos,
// por el pin A0 del sensor llegan los datos invertidos
// cuando no detecta nada devuelve el valor 0
// 
// 
// VCC 5 voltios en el pin +


void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
  pinMode(A0,INPUT);    // Pin D0 del sensor
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
