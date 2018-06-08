// SENSOR DE HUMEDAD DEL SUELO YL-69
// Sensor que mide la humedad del suelo midiendo la conductividad de la tierra humeda
// 
// Tiene una entrada digital D0 que devuelve 0 o 1 dependiendo de si pasa el umbral
// que se puede modificar con el potenciometro
// Tambien tiene una entrada analogica que devuelve un valor entre 0 y 1024,
// cuanto mas bajo sea el valor mas humedad tiene la tierra
//
// VCC 3.3 a 5 voltios. En este ejemplo, la corriene de VCC del sensor se proporciona
// mediante una salida digital, de este modo el sensor solo consume energía cuando 
// realiza la medicion, de este modo consume menos y no se estropea con tasas de 
// humedad muy alta

// YL-69 humidity sensor
byte humidity_sensor_pin = A0;
byte humidity_sensor_vcc = 6;   // Pin que suministrara la corriente VCC al sensor
byte humidity_sensor_Dpin = 9;  // Pin digital de lectura

void setup() {
  // Init the humidity sensor board
  pinMode(humidity_sensor_vcc, OUTPUT);
  pinMode(humidity_sensor_Dpin,INPUT);
  digitalWrite(humidity_sensor_vcc, LOW);

  // Setup Serial
  while (!Serial);
  delay(1000);
  Serial.begin(9600);
}

int read_humidity_sensor() {
  digitalWrite(humidity_sensor_vcc, HIGH);
  delay(500);
  int value = analogRead(humidity_sensor_pin);
  int dig_value = digitalRead(humidity_sensor_Dpin);
  // Serial.print("Dig: ");
  // Serial.println(dig_value);
  digitalWrite(humidity_sensor_vcc, LOW);
  return 1023 - value;
}

void loop() {
  Serial.print("Humidity Level (0-1023): ");
  Serial.println(read_humidity_sensor()); 
  delay(3000);
}
