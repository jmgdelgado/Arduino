#include <Servo.h>              // Incluir la librería Servo
Servo servo1;                   // Crear un objeto tipo Servo llamado servo1 
int angulo = 0 ;

void setup()
   {   servo1.attach(9) ;  }    // Conectar servo1 al pin 9  

void loop()
   {  for(angulo  = 0; angulo  <= 180;  angulo  += 1)  
         {    servo1.write(angulo);
              delay(25);
         }
   }
