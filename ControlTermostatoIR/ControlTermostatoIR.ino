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
int PIN_RELE = 6;  // Pin 6 el que activa el rele
int POWER_RELE = 7;  // Pin 7 para alimentar el rele
uint32_t numDispo = 0;  // Numero del dispositivo receptor

const int TERMOSTATO = 12495; //Numero de tecla correspondiente
                              // dispositivo del termostato
const uint32_t TECLA_ON  = 12495; //Num. tecla del mando para encendido
const uint32_t TECLA_OFF = 26775; //Num. tecla del mando para apagado                            

unsigned long Tiempo_T1 = 0; // Tiempo de llegada de la primera tecla
unsigned long Tiempo_T2 = 0; // Tiempo de llegada de la segunda tecla

uint8_t protocolo = 0;
uint16_t direccion = 0;      // Identificador del mando
uint32_t tecla = 0;         // Identificador de la tecla pulsada

uint8_t oldSREG;

void setup(){
  IRLbegin<IR_ALL>(INTERRUPCION);      // Inicio de las interrupciones
  // Serial.begin(115200);                 // Tambien funcionaria con 9600

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);  
  pinMode(PIN_RELE, OUTPUT);
  pinMode(POWER_RELE, OUTPUT);
  digitalWrite(POWER_RELE,HIGH);  
  // Serial.println("Iniciando comunicacion: ");
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
    // digitalWrite(LED_BUILTIN,HIGH); 
      
    // Serial.print("Protocolo: ");
    // Serial.print(protocolo);
    // Serial.print(" Direccion: ");
    // Serial.print(direccion, HEX);
    // Serial.print(" Tecla: ");
    // Serial.print(tecla);
    // Serial.print(" - ");
    // Serial.println(tecla, HEX);
    protocolo=0;

    // Serial.println((char)millis());

    if(numDispo == 0){
      if(tecla == TERMOSTATO){ 
        numDispo = tecla;  
        Tiempo_T1 = millis();       
      }
    }
    else {
      Tiempo_T2 = millis();
      // La tecla de ON-OFF tiene que llegar a menos de 2 segundos 
      // de el numero de dispositivo
      if(Tiempo_T2 < Tiempo_T1 + 2000){  
        
        if(tecla == TECLA_ON ){
          digitalWrite(POWER_RELE,HIGH);
          digitalWrite(PIN_RELE,HIGH);
          // digitalWrite(LED_BUILTIN,HIGH);
        }
        if(tecla == TECLA_OFF ){
          digitalWrite(PIN_RELE,LOW);
          digitalWrite(POWER_RELE,LOW);          
          // digitalWrite(LED_BUILTIN,LOW);
        } 
        numDispo = 0;  
      }
      else { 
        numDispo = 0;
        Tiempo_T1 = 0;
        Tiempo_T2 = 0;
      }
    }
    

    // digitalWrite(LED_BUILTIN,LOW); 
  }

  SREG = oldSREG;   // Se vuelve a poner el estado anterior de las interrupciones para que se traten

}
