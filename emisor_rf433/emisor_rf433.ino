#include <VirtualWire.h>
#include <VirtualWire_Config.h>
 
const int dataPin = 9;
const int ledPin = 13;
const int ledPin2 = 12;
 
void setup()
{  
        
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);     
    vw_setup(2000);
    vw_set_tx_pin(dataPin);

    pinMode(ledPin2, OUTPUT);
}
 
void loop()
{
    digitalWrite(ledPin, LOW);
    while (Serial.available() > 0) 
    {

      char data[1];
      data[0] = Serial.read();
      vw_send((uint8_t*)data,sizeof(data));
      vw_wait_tx();
      digitalWrite(ledPin2, HIGH);
      delay(500);
      digitalWrite(ledPin2, LOW);  
      Serial.println(data);     
    }
    delay(1000);
    digitalWrite(ledPin, HIGH);   
    delay(1000);
}
