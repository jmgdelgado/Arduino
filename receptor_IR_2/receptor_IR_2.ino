// RECEPTOR INFRARROJO
// Receptor infrarrojo
// 
// La pata de la senial S hay que conectarla a un pin digital que 
// soporte interrupciones, en este caso se usara el pin 2
// 
// El receptor con placa, se pone el pin S al pin 2 del Arduino
// El receptor sin placa, el de la izquierca es DATA, el centro el GND y el de la
// derecha es VCC
//
// Con esta libreria reconoce los codigos de todos los mandos
//
// VCC 5 voltios 


#include <IRremote.h>

int ReceptorIR = 11;
IRrecv irrecv(ReceptorIR);
decode_results Codigo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();

}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&Codigo))
  {
    Serial.print("0x");
    Serial.println(Codigo.value, HEX);
    if (Codigo.value == 0xE0E0F00F)
    {
      Serial.println("Pulsada la tecla MUTE");
    }
    delay(50);
    irrecv.resume();
  }

}
