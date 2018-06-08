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
 
int val;
 
void setup () {
  // Output pin initialization for the LEDs
  pinMode (Led_Red, OUTPUT); 
  pinMode (Led_Green, OUTPUT); 
}
void loop () {
   // In this for loop, the two LEDs will get different PWM-Values. 
   // Via mixing the brightness of the different LEDs, you will get different colors. 
   for (val = 255; val> 0; val--)
      {
      analogWrite (Led_Green, val);
      analogWrite (Led_Red, 255-val);
      delay (15);
   }
   // You will go backwards through the color range in this second loop.
   for (val = 0; val <255; val++)
      {
      analogWrite (Led_Green, val);
      analogWrite (Led_Red, 255-val);
      delay (15);
   }
}
