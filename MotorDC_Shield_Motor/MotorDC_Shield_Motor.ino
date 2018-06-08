#include <AFMotor.h>

AF_DCMotor Motor1(1);  // Motor conectado a M1


void setup()
   {
    
       Motor1.run(RELEASE);     // Se deja el motor en punto muerto
   
   }

void loop()
   {   
       Motor1.run(FORWARD); 
       delay (2000);

       Motor1.setSpeed(180);  // Definimos la velocidad de  Motor1
       Motor1.run(BACKWARD);
       delay (2000);
   }
