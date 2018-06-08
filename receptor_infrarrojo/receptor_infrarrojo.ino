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
// Con esta libreria solo reconoce los codigos del mando del kit raspberry
//
// VCC 5 voltios 

#include <IRLremote.h>

int INTERRUPCION = 0; //PIN 2  Numero de interrupcion no del pin

uint8_t protocolo = 0;
uint16_t direccion = 0;      // Identificador del mando
uint32_t tecla = 0;         // Identificador de la tecla pulsada

uint8_t oldSREG;

void setup(){
  IRLbegin<IR_ALL>(INTERRUPCION);      // Inicio de las interrupciones
  Serial.begin(115200);                 // Tambien funcionaria con 9600
}


// Esta es la funcion que llama la libreria cuando se produce la interrupcion
// aqui es donde se puede meter el codigo que queremos hacer cuando se produzca
// la interrupcion, en este caso se cogen los datos de la pulsacion y se mete
// en las variables globales
void IREvent (uint8_t protocol, uint16_t address, uint32_t command){
  protocolo = protocol;
  direccion = address;
  tecla = command;
}

void loop(){
  oldSREG = SREG;  // Se guarda el estado de las interrupciones
  cli();            // Se desabilitan las interrupciones mientras se trata la actual

  if(protocolo!=0){
    Serial.print("Protocolo: ");
    Serial.print(protocolo);
    Serial.print(" Direccion: ");
    Serial.print(direccion, HEX);
    Serial.print(" Tecla: ");
    Serial.print(tecla);
    Serial.print(" - ");
    Serial.println(tecla, HEX);
    protocolo=0;
    if(tecla==26775) {
      Serial.println("Pulsada la tecla 0");
    }
  }

  SREG = oldSREG;   // Se vuelve a poner el estado anterior de las interrupciones para que se traten
  
}
