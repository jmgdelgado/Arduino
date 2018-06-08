// RECEPTOR INFRARROJO
// Receptor infrarrojo
// 
// La pata de la senial S hay que conectarla a un pin digital que 
// soporte interrupciones, en este caso se usara el pin 2
// 
// El receptor con placa, se pone el pin S al pin 2 del Arduino:
// en el NodeMCU se pone en el GPIO 14 --> D5
// El receptor sin placa, el de la izquierca es DATA, el centro el GND y el de la
// derecha es VCC
//
// Con esta libreria solo reconoce los codigos del mando del kit raspberry
//
// VCC 5 voltios:  en el NodeMCU a 3.3V

#ifndef UNIT_TEST
#include <Arduino.h>
#endif
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

#define LED_BUILTIN 2

// An IR detector/demodulator is connected to GPIO pin 14(D5 on a NodeMCU
// board).
uint16_t RECV_PIN = 14;  // GPIO14 o D05

IRrecv irrecv(RECV_PIN);

decode_results results;

// int INTERRUPCION = 0; //PIN 2  Numero de interrupcion no del pin
int PIN_RELE = 4;  // Pin GPIO_04, el D2 en NodeMCU,  el que activa el rele
uint32_t numDispo = 0;  // Numero del dispositivo receptor

const int TERMOSTATO = 16724175; //Numero de tecla correspondiente
                              // dispositivo del termostato
const uint32_t TECLA_ON  = 16724175; //Num. tecla del mando para encendido
const uint32_t TECLA_OFF = 16738455; //Num. tecla del mando para apagado 
const uint32_t TECLA_BASURA = 2147483647; //Num. tecla de ruido que llega                           

unsigned long Tiempo_T1 = 0; // Tiempo de llegada de la primera tecla
unsigned long Tiempo_T2 = 0; // Tiempo de llegada de la segunda tecla

// uint8_t protocolo = 0;
// uint16_t direccion = 0;      // Identificador del mando
uint32_t tecla = 0;         // Identificador de la tecla pulsada
char teclaChar[40] ="";


void setup(){

  Serial.begin(115200);
  irrecv.enableIRIn();  // Start the receiver
  while (!Serial)  // Wait for the serial connection to be establised.
    delay(50);
  Serial.println();
  Serial.print("IRrecvDemo is now running and waiting for IR message on Pin ");
  Serial.println(RECV_PIN);

  
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);  
  pinMode(PIN_RELE, OUTPUT);
  
  // Serial.println("Iniciando comunicacion: ");
}


// Esta es la funcion que llama la libreria cuando se produce la interrupcion
// aqui es donde se puede meter el codigo que queremos hacer cuando se produzca
// la interrupcion, en este caso se cogen los datos de la pulsacion y se mete
// en las variables globales
void IREvent (uint8_t protocol, uint16_t address, uint32_t command){
  // protocolo = protocol;
  // direccion = address;
  tecla = command;
}

void loop(){

  if (irrecv.decode(&results)) {
    // print() & println() can't handle printing long longs. (uint64_t)
    serialPrintUint64(results.value, HEX);
    // Serial.println("");
    
    sprintf(teclaChar,"%u",results.value);
 
    irrecv.resume();  // Receive the next value 
       
    // digitalWrite(LED_BUILTIN,HIGH);    

    Serial.print("-->"); 
    Serial.println(teclaChar);
    tecla = atoi(teclaChar);
    // Serial.print("---->"); 
    // Serial.println(tecla);   
      

if (tecla == TERMOSTATO || tecla == TECLA_ON || tecla == TECLA_OFF) {

      // Serial.print("-->"); 
      // Serial.println(teclaChar);

      Serial.print(" ------>  OK, ESTADO: ");
      Serial.println(numDispo);

    // Serial.println((char)millis());

    if(numDispo == 0 && tecla != TECLA_BASURA){
      if(tecla == TERMOSTATO){ 
        numDispo = 1;  
        Tiempo_T1 = millis();  
        Serial.print(" ========> DISPO: ");
        Serial.println(tecla);     
      }
    } 
    else {
          if (numDispo == 1) {
            Tiempo_T2 = millis();
            // La tecla de ON-OFF tiene que llegar a menos de 2 segundos 
            // de el numero de dispositivo
            if(Tiempo_T2 < Tiempo_T1 + 2000){  
      
              Serial.print(" ==========> ORDEN: ");
              Serial.println(tecla); 
              
              if(tecla == TECLA_ON ){
                digitalWrite(PIN_RELE,HIGH);
                digitalWrite(LED_BUILTIN,LOW);
                numDispo = 0; 
                Serial.print(" ============> ON: ");
                Serial.println(tecla);
              }
              if(tecla == TECLA_OFF ){
                digitalWrite(PIN_RELE,LOW);
                digitalWrite(LED_BUILTIN,HIGH);
                numDispo = 0; 
                Serial.print(" ============> OFF: ");
                Serial.println(tecla);
              } 
              // numDispo = 0;  
            }
            else { 
              numDispo = 0;
              Tiempo_T1 = 0;
              Tiempo_T2 = 0;
            }
          }
    }   
} 
else {
       Serial.println(""); 
}

    // digitalWrite(LED_BUILTIN,LOW); 
  }

}
