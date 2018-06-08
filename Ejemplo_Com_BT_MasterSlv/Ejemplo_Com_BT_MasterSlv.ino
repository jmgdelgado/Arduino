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

// Este sketch es para cargar en el Master y envia un 1 y luego un 0 cada 2 segundos
// En el esclavo hay que cargar el sketch Ejemplo_Comunica_BT_Serial
// y el esclavo enciende o apaga un led dependiendo si recibe 0 o 1

// Comandos AT para el HC-06 (esclavo)
// AT+NAMEnombre
// AT+PIN1212
// AT+BAUD4   //9600


char leido;
 
void setup()
{
  
  BT.begin(9600); //Velocidad del puerto del módulo Bluetooth
  Serial.begin(9600); //Abrimos la comunicación serie con el PC y establecemos velocidad

}
 
void loop()
{
     // Serial.println("On");
     BT.write('1');   
     delay(2000);
     // Serial.println("off");
     BT.write('0');
     delay(2000);
  
}
