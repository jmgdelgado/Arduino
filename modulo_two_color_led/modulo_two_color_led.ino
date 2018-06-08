// MODULO TWO COLOR LED RGB - KY-011 y KY-029
// los dos modulos funcionan igual, uno es mas pequeio que otro
// Modulo actuador que consiste en un led con 2 entradas para color R,G
// 
// La pata R: S rojo, hay que conectar una resistencia de 220 ohmios
// La pata V: la del medio verde, hay que conectar una resistencia de 220 ohmios
//
// VCC 5 voltios (en este caso los pines de color)

int Led_Red = 10;
int Led_Green = 11;
 
void setup ()
{
  // Output pin initialization for the LEDs
  pinMode (Led_Red, OUTPUT); 
  pinMode (Led_Green, OUTPUT); 
}
 
void loop () //Main program loop
{
  digitalWrite (Led_Red, HIGH); // LED will be switched on
  digitalWrite (Led_Green, LOW); // LED will be switched off
  delay (3000); // Waitmode for 3 seconds
 
  digitalWrite (Led_Red, LOW); // LED will be switched off
  digitalWrite (Led_Green, HIGH); // LED will be switched on
  delay (3000); // Waitmode for another 3 seconds in which the status of the LEDs are shifted.
}
