#include <VirtualWire.h>
#include <VirtualWire_Config.h>
 
const int dataPin = 9;
const int ledPin = 13;
const int ledPin2 = 12;
 
void setup()
{
    vw_setup(2000);
    vw_set_rx_pin(dataPin);
    vw_rx_start();
    
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, false);

    pinMode(ledPin2, OUTPUT);    
}
 
void loop()
{
    digitalWrite(ledPin2, HIGH); 
    uint8_t data;
    uint8_t dataLength=1;
 
    if (vw_get_message(&data,&dataLength))
    {
      digitalWrite(ledPin, HIGH);   
      delay(1000);
      digitalWrite(ledPin, LOW);
      
        if((char)data=='a')
        {
            digitalWrite(ledPin, true);
        }
        else if((char)data=='b')
        {
            digitalWrite(ledPin, false);
        }            
    }
    delay(500);
    digitalWrite(ledPin2, LOW); 
    delay(500);
}
