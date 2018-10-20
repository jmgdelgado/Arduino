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

// OLED LCD LED DISPLAY I2C
// Aunque pone que es de 128x64 parece que es 128x32
// Es de comunicacion I2C
// Pins en Arduino Nano
// SDA: A4 (SDA)  En un shield, si tiene comunicacion I2C se puede conectar a esos pins
// SCL: A5 (SCL) 
// Pins en NodeMCU
// SDA: D2 (SDA)  En un shield, si tiene comunicacion I2C se puede conectar a esos pins
// SCL: D1 (SCL)  

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
const char* ssid     = "EUSKALTEL_D0014804"; // Rellena con el nombre de tu red WiFi
const char* password = "PJKDPHVR";           // Rellena con la contraseña de tu red WiFi 
const char* host     = "192.168.0.31";       // La IP del equipo donde esta MySql y Apache
const int   httpPort = 80;                   // Puerto HTTP //S

// Wake from deep sleep, in seconds.
#define wakeuptime 20

#define OLED_RESET  LED_BUILTIN  //4  En Arduino se puede poner 4 pero en NodeMCU no, asi funciona en los dos

Adafruit_SSD1306 display(OLED_RESET);   // Se crea el objeto display OLED

int SENSOR = 2;      // GPIO2 : D4
int temp, humedad;   // La precision es de un grado, no va a dar decimales

DHT dht (SENSOR, DHT11);  // Se crea el tipo sensor de tipo dht11

void setup() {
  Serial.begin(9600);
  delay(10);

  // Comenzamos el sensor DHT
  dht.begin();  

  inicializarDisplayOLED();
 
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
    mostrarEnOLED(Temperatura,Humedad);  
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
  
  // dormirDeepSleep(wakeuptime);
  delay(10000);
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
  String url = "/dht_insert.php?temp=";
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


void inicializarDisplayOLED()
{
  // Hay que conocer la direccion I2C del dispositivo, para ello ejecutar antes el 
  // script IC2_Scanner. En este caso nos ha dado la direccion 0x3C, hay que poner
  // esta direccion en la funcion display.begin()

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  // init done
  
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(2000);  
  // Clear the buffer.
  display.clearDisplay();  
}


void sacarEnMonitorSerie(float Temperatura, float Humedad)
{
  Serial.print("Temperatura: ");
  Serial.print(Temperatura);
  Serial.print("ºC Humedad: ");
  Serial.print(Humedad);
  Serial.print("%");
}

void mostrarEnOLED(float Temperatura, float Humedad)
{
      display.clearDisplay();

      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.println("Sensor DHT11");
      display.print("Temperatura: ");
      display.print(Temperatura);
      display.print(" ");
      display.print((char)167);  
      display.println("C");
      display.print("Humedad: ");
      display.print(Humedad);
      display.println(" %");
  
      display.display();  

      delay(10);
}

