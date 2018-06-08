// JOYSTICK
// Joystick que envia las posiciones X e Y de sus potencimetros a la entradas Analogicas
// El boton del joystick se envia a una entrada digital
/*
GND - GND
Vcc - 5v
VRx - A0
VRy - A1
SW -  D9
*/
 
const int pinLED = 13;
const int pinJoyX = A0;
const int pinJoyY = A1;
const int pinJoyButton = 9;
 
void setup() {
   pinMode(pinJoyButton , INPUT_PULLUP);   //activar resistencia pull up 
   Serial.begin(9600);
}
 
void loop() {
   int Xvalue = 0;
   int Yvalue = 0;
   bool buttonValue = false;
 
   //leer valores
   Xvalue = analogRead(pinJoyX);
   delay(100);                 //es necesaria una pequeña pausa entre lecturas analógicas
   Yvalue = analogRead(pinJoyY);
   buttonValue = digitalRead(pinJoyButton);
 
   //mostrar valores por serial
   Serial.print("X:" );
   Serial.print(Xvalue);
   Serial.print(" | Y: ");
   Serial.print(Yvalue);
   Serial.print(" | Pulsador: ");
   Serial.println(buttonValue);
   delay(1000);
}
