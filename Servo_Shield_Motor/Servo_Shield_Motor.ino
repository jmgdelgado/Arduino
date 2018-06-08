#include <AFMotor.h>
#include <Servo.h>
Servo servo1 ;

void setup()
   {    Serial.begin(115200);  
        servo1.attach(9);       // El servo 1 se controla con el pin 9
                                // En el Shield es el Servo_2
   }

   
void loop()
   {    for (int ang =0 ; ang <180 ; ang++)
          {  servo1.write( ang) ;
             delay(25);
          }
        delay(1000);
   }
