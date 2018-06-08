// SENSOR DE GAS MQ-2 Metano,butano,GLP,humo
// sensor electro-químico que varía su resistencia 
// al estar en contacto con las sustancias
// la sensibilidad se cambia con el potenciometro
// Tiene una salida digital y otra analogica
// Tienen un calentador que puede consumir bastante y necesitar alimentacion externa
// 
// funciona con el gas de un mechero
// VCC 5 voltios 


const int pinLED = 13;

const int MQ_PIN = 2;
const int MQ_DELAY = 2000;
 
void setup()
{
  Serial.begin(9600);
  pinMode(pinLED,OUTPUT);
  pinMode(MQ_PIN,INPUT);
}
 
 
void loop()
{
  bool state= digitalRead(MQ_PIN);
 
  if (!state)
  {
    Serial.println("Deteccion");
    digitalWrite(pinLED,HIGH);
  }
  else
  {
    Serial.println("No detectado");
    digitalWrite(pinLED,LOW);
  }
  delay(MQ_DELAY);
}
