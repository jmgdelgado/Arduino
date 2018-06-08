// EMISOR LASER 
// Diodo Laser 
// Al ser de baja potencia se puede alimentar con el Arduino
// si necesitara mas de 20 miliamperios seria mejor una fuente externa
// Tiene una entrada digital SIG que se activa 
// con una salida digital del Arduino
//
// VCC 5 voltios 

const int pin = 9;
 
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
    
  pinMode(pin, OUTPUT);  //definir pin como salida
}
 
void loop(){
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(pin, HIGH);   // poner el Pin en HIGH
  delay(5000);               // esperar 5 segundos
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(pin, LOW);    // poner el Pin en LOW
  delay(20000);               // esperar 20 segundos
}
