// OLED LCD LED DISPLAY I2C
// Aunque pone que es de 128x64 parece que es 128x32
// Es de comunicacion I2C
// Pins en Arduino Nano
// SDA: A4 (SDA)  En un shield, si tiene comunicacion I2C se puede conectar a esos pins
// SCL: A5 (SCL)  

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

char buffer[10];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

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

  // text display tests
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Hello, world!");
  display.setTextColor(BLACK, WHITE); // 'inverted' text
  display.println(3.141592);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  //   display.print("0x"); display.println(0xDEADBEEF, HEX);
  //   display.display();
  //   delay(6000);


  // Apagado
  //display.clearDisplay(); 
  //display.display();
}

void loop() {
  // put your main code here, to run repeatedly:

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Hello, world!");
  display.setTextColor(BLACK, WHITE); // 'inverted' text
  display.println(3.141592);
  display.setTextSize(1);
  display.setTextColor(WHITE);



  long t= millis()/1000 ;
  int horas = t/3600 ;
  int minutos = (t % 3600) / 60;
  int segs = (t - horas*3600 - minutos * 60) % 60 ;

  int n = sprintf(buffer, "%02d:%02d:%02d", horas, minutos, segs);


  display.setCursor(0,25);
  
  display.println(buffer);
  display.display();
  delay(1000);
  display.clearDisplay(); 
  display.display();  
  
      
}
