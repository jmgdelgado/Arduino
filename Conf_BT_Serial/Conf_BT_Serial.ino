#include <SoftwareSerial.h> //Librería que permite establecer comunicación serie en otros pins
 
//Aquí conectamos los pins RXD,TDX del módulo Bluetooth.
// Son el RX y TX en el arduino, hay que cruzarlos en el modulo BT
SoftwareSerial BT(10,11); //10 RX, 11 TX.

// GND al GND y 5V a 5V

// Este programa puede conectar el Monitor Serie del Arduino con 
// el modulo BT. Con este programa se configura el HC-05 mediante
// comandos AT.
// Para poner en modo comunicacion el HC-05 hay que desconectar el 
// pin de 5V del modulo BT y volverlo a conectar mientras se pulsa
// el boton hasta que parpadee lento un par de veces

// Comandos AT
// AT+NAME:HC-05
// AT+UART:9600,0,0
// AT+PSWD:1212
// AT+ROLE:1  0:esclavo, 1:maestro
// AT+BIND:direccion MAC del esclavo

 
void setup()
{
  BT.begin(38400); //Velocidad del puerto del módulo Bluetooth
  //BT.begin(9600); //Velocidad del puerto del módulo Bluetooth
  Serial.begin(9600); //Abrimos la comunicación serie con el PC y establecemos velocidad
}
 
void loop()
{
  if(BT.available())
  {    
     Serial.write(BT.read());  
  }
 
  if(Serial.available())
  {    
     BT.write(Serial.read());   
  }
}
