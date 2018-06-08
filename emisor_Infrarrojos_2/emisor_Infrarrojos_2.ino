// EMISOR INFRARROJO
// Emisor infrarrojo
// 
// La pata de la senial S hay que conectarla al pin digital D3 
// en el cado del Arduino UNO, ver en los comentarios mas adelante
// 
// Hay una funcion para cada marca de mando
//
// Probado a enviar un codigo recibido por el receptor y lo envia y reconoce el receptor



//Arduino-IRremote library will be added
#include <IRremote.h>
#include <IRremoteInt.h> 
  
//...and here initialized
IRsend irsend;
  
// The configuration of the output pin will be made by the library
// The output pin is a different one for different arduinos
// Arduino UNO:  Output = D3
// Arduino MEGA: Output = D9
// You will find a full list of output pins on the website:
// http://z3t0.github.io/Arduino-IRremote/

void setup()
{
}
  
// main program loop
void loop() {
        // The transmitter sends in this example the signal A90 (hex. dezimal form) in the encoding "RC5"
        // It will be transmitted 3 times after that it will make a 5 second break
    for (int i = 0; i < 3; i++) {
        // irsend.sendRC5(0xA90, 12); // [0xA90] signal | [12] Bit-length signal (hex A90=1010 1001 0000)
        irsend.sendSAMSUNG(0xE0E0F00F,32); // Parametros: Tecla MUTE sacada del receptor, numero de bits del codigo de Samsung
        delay(40);
    }
    delay(5000); // 5 second break between the sending impulses
}
