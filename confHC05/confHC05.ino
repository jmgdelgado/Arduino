// El pin de 5V se conecta al pin 12 para alimentarlo justo antes de cargar 
// la configuracion en el modulo BT
// El pin GND a cualquier pin GND del arduino
// El pin RX al TX del arduino. Cruzados.
// El pin TX al RX del arduino

const int LED =13;
const int BTPWR=12;     // El pin por donde alimentamos el bluetooth
                        // inicialmente tiene que estar apagado para no ocupar
                        // el puerto serie y poder cargar el sketch en el BT

char nombreBT[11]="InoMstr01";   // Nombre deseado para el modulo bluetooth
char pin[5]="1212";    // Pin que queremos que nos pida al emparejar el BT
char velocidad='4';  //9600 baud
char modo='1';    // Modo 1: Maestro;  0: Esclavo.

void setup(){
  pinMode(LED, OUTPUT);
  pinMode(BTPWR, OUTPUT);

  Serial.begin(38400); //velocidad de BT en modo configuracion

  /* solo pulsador */    // Codigo para modulos BT con pulsador
//  digitalWrite(LED, HIGH);
//  delay(9000);              // Cuando se encienda el LED hay que apretar el pulsador
//  digitalWrite(LED, LOW);
  /*******************/   

  // Inicio de la configuracion del modulo BT mediante comandos AT
  digitalWrite(BTPWR, HIGH);
  delay(3000);
  Serial.print("AT\r\n");

  Serial.print("AT+NAME:");
  Serial.print(nombreBT);
  Serial.print("\r\n");

  //Serial.print("AT+PIN:"); //AT+PSWD:
  Serial.print("AT+PSWD:"); //AT+PSWD:
  Serial.print(pin);
  Serial.print("\r\n");

  Serial.print("AT+BAUD:");
  Serial.print(velocidad);
  Serial.print("\r\n");

  Serial.print("AT+MODE:");
  Serial.print(modo);
  Serial.print("\r\n");

  digitalWrite(LED, HIGH);  // Indicamos el fin de la configuracion encendiendo el LED
  
}

void loop(){
  
}
