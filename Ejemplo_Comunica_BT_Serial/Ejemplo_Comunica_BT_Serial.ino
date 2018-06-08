#include <SoftwareSerial.h> //Librería que permite establecer comunicación serie en otros pins
 
//Aquí conectamos los pins RXD,TDX del módulo Bluetooth.
// Son el RX y TX en el arduino, hay que cruzarlos en el modulo BT
SoftwareSerial BT(10,11); //10 RX, 11 TX.

// GND al GND y 5V a 5V

// Este programa puede conectar el Monitor Serie del Arduino con un
// Terminal Bluetooth como BlueTerm en el movil. Cuando se introduce un 1 en el 
// BlueTerm se enciende el LED13, cuando se introduce un 0 se apaga

// Cuando el BT HC-06 no esta conectado a ningun dispositivo se 
// puede configurar con los comandos AT
// La comunicacion con el HC-06 es a BT.begin(9600)
// La comunicacion con el HC-05 es a BT.begin(9600) en modo Esclavo

// Comandos AT para el HC-06 (esclavo)
// AT+NAMEnombre
// AT+PIN1212
// AT+BAUD4   //9600


char leido;
 
void setup()
{
  
  BT.begin(9600); //Velocidad del puerto del módulo Bluetooth
  Serial.begin(9600); //Abrimos la comunicación serie con el PC y establecemos velocidad
  pinMode(13,OUTPUT);
  pinMode(8,OUTPUT);
}
 
void loop()
{
  if(BT.available())
  {
     // Serial.write(BT.read());

     leido = BT.read();
     Serial.write(leido);
     if (leido == '1') {
        digitalWrite(13,HIGH);
     }
     if (leido == '0') {
        digitalWrite(13,LOW);
     }  
  }
 
  if(Serial.available())
  {    
     BT.write(Serial.read());  
/*
     leido = Serial.read();
     if (leido == 1){
        digitalWrite(8,HIGH);
     }
     if (leido == 0){
        digitalWrite(8,LOW);
     }  
*/       
  }
}
