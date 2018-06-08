// El pin de 5V se conecta al pin 12 para alimentarlo justo antes de cargar 
// la configuracion en el modulo BT
// El pin GND a cualquier pin GND del arduino
// El pin RX al TX del arduino. Cruzados.
// El pin TX al RX del arduino

const int LED = 13;
const int BTPWR = 12;   // El pin por donde alimentamos el bluetooth
                        // inicialmente tiene que estar apagado para no ocupar
                        // el puerto serie y poder cargar el sketch en el BT

char nombreBT[10] = "InoSlv01";  // Nombre deseado para el modulo bluetooth
char velocidad ='4';   //9600 baud
char pin [5]= "1212";  // Pin que queremos que nos pida al emparejar el BT

void setup(){
  pinMode(LED, OUTPUT);
  pinMode(BTPWR, OUTPUT);  

  digitalWrite(LED, LOW);
  digitalWrite(BTPWR, HIGH);

  Serial.begin(9600);

  // Inicio de la configuracion del modulo BT mediante comandos AT
  Serial.print("AT");
  delay(1000);       // Pausas necesarias para que el modulo sepa que termina el comando

  Serial.print("AT+NAME");
  Serial.print(nombreBT);
  delay(1000);

  Serial.print("AT+BAUD");
  Serial.print(velocidad);
  delay(1000);

  Serial.print("AT+PIN");
  Serial.print(pin);
  delay(1000);

  digitalWrite(LED, HIGH);   // Indicamos el fin de la configuracion encendiendo el LED
}

void loop(){
  
}
