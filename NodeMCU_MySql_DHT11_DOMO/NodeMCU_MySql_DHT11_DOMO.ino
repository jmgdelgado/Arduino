// Esta es la librería para utilizar las funciones de red del ESP8266
#include <ESP8266WiFi.h> 

// SENSOR DE TEMPERATURA Y HUMEDAD DHT11
// Sensor DHT11 de Temperatura y Humedad
//
// Se necesita la libreria de Adafruit DHT sensor library.
// ATENCION: Instalar la version 1.2.3 con la 1.3.0 no compila 
// 
// La pata DATA se conecta a una salida digital
// En Arduino Nano: Pin D2
// En NodeMCU: Pin D4
//
// VCC 5 voltios 

#include <DHT.h>

 
const char* ssid     = "EUSKALTEL_D0014804"; // Rellena con el nombre de tu red WiFi
const char* password = "PJKDPHVR";           // Rellena con la contraseña de tu red WiFi 
const char* host     = "192.168.0.31";       // La IP del equipo donde esta MySql y Apache
const int   httpPort = 80;                   // Puerto HTTP //S

// Wake from deep sleep, in seconds.
#define wakeuptime 900


int powerDHT = D5;   // Este pin vamos a utilizarlo para alimentar el sensor solo cuando se vaya a utilizar
int SENSOR = 2;      // GPIO2 : D4
int temp, humedad;   // La precision es de un grado, no va a dar decimales

DHT dht (SENSOR, DHT11);  // Se crea el tipo sensor de tipo dht11

void setup() {
  Serial.begin(9600);
  delay(10);

  pinMode(D5,OUTPUT);
  digitalWrite(D5,HIGH);

  // Comenzamos el sensor DHT
  dht.begin();  
 
  // Conectamos a la red WiFi
  conectarWifi();
  delay(5000);
}
 
void loop() {
  float Temperatura = 0;
  float Humedad = 0;
  int   Sensor = 1;

  Humedad     = dht.readHumidity();
  Temperatura = dht.readTemperature();
  sacarEnMonitorSerie(Temperatura,Humedad);
 
    
  if (Temperatura > -100 && Temperatura < 200)
  {
    delay(1);
  }
  else return;
  

  // Creamos el cliente
  WiFiClient  client;
  // Conectamos al Servidor
  client = conectarServidor(client);

  delay(1);
 
  // Creamos la URL para la petición 
  String url = crearURL(Sensor,Temperatura,Humedad);
 
  // Enviamos la petición
  client = enviarPeticionHTTP(client,url);


  // Leemos la respuesta y la enviamos al monitor serie
  client = leerRespuestaHTTP(client);
  

  Serial.println("Cerrando la conexión");
  client.stop();
   
  // Consutar la memoria libre
  // Quedan un poco más de 40 kB
  Serial.printf("\nMemoria libre en el ESP8266: %d Bytes\n\n",ESP.getFreeHeap());
 

  // Poner en modo DEEP SLEEP el ESP, tiempo en microsegundos
  // Hay que conectar el pin D0 con el pin RST: Reset
  // ATENCION: hay que puentearlo despues de cargar el programa sino da error
  // Se reinicia todo el programa cuando despierta

  digitalWrite(D5,LOW);
  
  dormirDeepSleep(wakeuptime);
  // delay(10000);
  Serial.println("Despertando");
 

}

void dormirDeepSleep(int segundos)
{
  // Poner en modo DEEP SLEEP el ESP, tiempo en microsegundos
  // Hay que conectar el pin D0 con el pin RST: Reset
  // ATENCION: hay que puentearlo despues de cargar el programa sino da error
  // Se reinicia todo el programa cuando despierta
  // Sleep
  Serial.println("Going to sleep");
  delay(5000);
  ESP.deepSleep(segundos * 1000000, WAKE_RF_DEFAULT);  
}


void conectarWifi()
{
  // Conectamos a la red WiFi
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  /* Configuramos el ESP8266 como cliente WiFi. Si no lo hacemos 
     se configurará como cliente y punto de acceso al mismo tiempo */
  WiFi.mode(WIFI_STA); // Modo cliente WiFi
  WiFi.begin(ssid, password);
 
  // Esperamos a que estemos conectados a la red WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected"); 
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); // Mostramos la IP
  return;
}  


WiFiClient conectarServidor(WiFiClient  client)
{
  Serial.print("connecting to ");
  Serial.println(host);
 
  if (!client.connect(host, httpPort)) {
    // ¿hay algún error al conectar?
    Serial.println("Ha fallado la conexión");
    delay(1000);
    return client;
  }

  Serial.println("Conectado");
  Serial.println("");
  delay(1);
  return client;
}

WiFiClient enviarPeticionHTTP(WiFiClient  client, String url)
{
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
         "Host: " + host + "\r\n" + 
         "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Superado el tiempo de espera !");
      client.stop();
      return client;
    }
  }
  return client;
}

WiFiClient leerRespuestaHTTP(WiFiClient  client)
{
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  } 
  Serial.println();
  Serial.println();

  return client;
}

String crearURL(int Sensor, float Temperatura, float Humedad)
{
  String url = "/domo/dht_insert.php?temp=";
  url += String(Temperatura);
  url += "&hume=";
  url += String(Humedad);
  url += "&sensor=";
  url += String(Sensor);    
 
  Serial.print("URL de la petición: http://");
  Serial.print(host);
  Serial.print(":");
  Serial.print(httpPort);
  Serial.println(url);  
  Serial.println("");

  return url;
}


void sacarEnMonitorSerie(float Temperatura, float Humedad)
{
  Serial.print("Temperatura: ");
  Serial.print(Temperatura);
  Serial.print("ºC Humedad: ");
  Serial.print(Humedad);
  Serial.print("%");
}



