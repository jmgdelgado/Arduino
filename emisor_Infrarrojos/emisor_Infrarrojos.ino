// EMISOR INFRARROJO
// Emisor infrarrojo
// 
// La pata de la senial S hay que conectarla al pin digital D3 
// en el cado del Arduino UNO, ver en los comentarios mas adelante
// 
// Hay una funcion para cada marca de mando
//
// Probado a enviar un codigo recibido por el receptor y lo envia y reconoce el receptor

#include <IRremote.h>

IRsend irsend;

void setup ()
{
  // Serial.begin (9600);
}

// The configuration of the output pin will be made by the library
// The output pin is a different one for different arduinos
// Arduino UNO:  Output = D3
// Arduino MEGA: Output = D9
// You will find a full list of output pins on the website:
// http://z3t0.github.io/Arduino-IRremote/

void loop () {
  for (int i = 0; i <50; i ++) {
    irsend.sendSony (0xa90, 12); // Sony TV power code
    delay (40);
   }
}
