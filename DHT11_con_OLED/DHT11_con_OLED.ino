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

#define OLED_RESET  LED_BUILTIN  //4  En Arduino se puede poner 4 pero en NodeMCU no, asi funciona en los dos
Adafruit_SSD1306 display(OLED_RESET);

char buffer[10];

int SENSOR = 2;
int temp, humedad;   // La precision es de un grado, no va a dar decimales

DHT dht (SENSOR, DHT11);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  
  // Comenzamos el sensor DHT
  dht.begin();


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

void loop() {
  // put your main code here, to run repeatedly:

  humedad = dht.readHumidity();
  temp = dht.readTemperature();
  float hic = dht.computeHeatIndex(temp, humedad, false);

  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.print("ºC Humedad: ");
  Serial.print(humedad);
  Serial.print("%  Indice de calor: ");
  Serial.println(hic);

  if (temp > -100 && temp < 200)
  {    
      display.clearDisplay();

      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.println("Sensor DHT11");
      display.print("Temperatura: ");
      display.print(temp);
      display.print(" ");
      display.print((char)167);  
      display.println("C");
      display.print("Humedad: ");
      display.print(humedad);
      display.println(" %");
  
      display.display(); 
  }
  
  delay(1000);
  

}
