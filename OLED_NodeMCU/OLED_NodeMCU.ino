// OLED LCD LED DISPLAY I2C
// Aunque pone que es de 128x64 parece que es 128x32
// Es de comunicacion I2C
// Pins en NodeMCU
// SDA: D2 (SDA)  En un shield, si tiene comunicacion I2C se puede conectar a esos pins
// SCL: D1 (SCL)  

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET LED_BUILTIN  //4
Adafruit_SSD1306 display(OLED_RESET);

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  // Clear the buffer.
  display.clearDisplay();
  display.display();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Hello from:");
  display.println("http://arduino-er.blogspot.com/");
  display.display();

}

void loop() {
  // put your main code here, to run repeatedly:

}

