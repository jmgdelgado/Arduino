// ENCODER ROTATORIO
// VCC 5V
// Para saber si se esta girando y su direccion se
// Miran los pines CLK (canal1) y DT (canal2)
// si se van a usar con interrupciones poner a los pines 2 y 3
// sino vale cualquier entrada digital
// El pin SW tiene que ver con pulsar eje-boton o
// con el paso por 0, no he conseguido averiguarlo

const int channelPinA = 2;
const int channelPinB = 3;
 
const int timeThreshold = 5;
long timeCounter = 0;
 
const int maxSteps = 255;
volatile int ISRCounter = 0;
int counter = 0;
 
bool IsCW = true;
 
void setup()
{
   pinMode(channelPinA, INPUT_PULLUP);
   Serial.begin(9600);
   attachInterrupt(digitalPinToInterrupt(channelPinA), doEncodeA, CHANGE);
   attachInterrupt(digitalPinToInterrupt(channelPinB), doEncodeB, CHANGE);
}
 
void loop()
{
   if (counter != ISRCounter)
   {
      counter = ISRCounter;
      Serial.println(counter);
   }
   delay(100);
}
 
void doEncodeA()
{
   if (millis() > timeCounter + timeThreshold)
   {
      if (digitalRead(channelPinA) == digitalRead(channelPinB))
      {
         IsCW = true;
         if (ISRCounter + 1 <= maxSteps) ISRCounter++;
      }
      else
      {
         IsCW = false;
         if (ISRCounter - 1 > 0) ISRCounter--;
      }
      timeCounter = millis();
   }
}
 
void doEncodeB()
{
   if (millis() > timeCounter + timeThreshold)
   {
      if (digitalRead(channelPinA) != digitalRead(channelPinB))
      {
         IsCW = true;
         if (ISRCounter + 1 <= maxSteps) ISRCounter++;
      }
      else
      {
         IsCW = false;
         if (ISRCounter - 1 > 0) ISRCounter--;
      }
      timeCounter = millis();
   }
}
