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

const int MQ_PIN = A0;
const int MQ_DELAY = 2000;
 
void setup()
{
  Serial.begin(9600);
  pinMode(pinLED,OUTPUT);
}
 
void loop() 
{
  int raw_adc = analogRead(MQ_PIN);
  float value_adc = raw_adc * (5.0 / 1023.0);
 
  Serial.print("Raw:");
  Serial.print(raw_adc);
  Serial.print("    Tension:");
  Serial.println(value_adc);
 
  delay(MQ_DELAY);
}
