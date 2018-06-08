// MODULO 7 COLOR  FLADH - KY-034
// Modulo actuador que consiste en un flash led que cambia de color
// automaticamente cuando se alimenta. No hace falta el pin de senia
// para que funcione, pero si se utiliza, el led se encendera 
// cuando la senial este en HIGH
//
//
// VCC 5 voltios 

int Led = 13;
 
void setup ()
{
  pinMode (Led, OUTPUT); // Initialization of the LED output pin
}
 
void loop () // main program loop
{
  digitalWrite (Led, HIGH); // LED will be switched on
  delay (4000); // waitmode for 4 seconds
  digitalWrite (Led, LOW); // LED will be switched off
  delay (2000); // waitmode for another 2 seconds
}
