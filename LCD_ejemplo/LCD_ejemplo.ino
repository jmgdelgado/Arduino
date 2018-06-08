#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

// CUIDADO aunque se llame igual, no es la libreria que se instala desde el IDE de Arduino
// es una libreria externa
// AL INSTALAR LA LIBRERIA LIQUIDCRYSTAL_I2C DA UN ERROR. Para solucionarlo:
// Accede a este archivo libraries/LiquidCrystal_I2C/I2CIO.cpp y busca una
// línea que pone #include . Ahí sustituye el …/Wire/Wire.h por Wire.h

// Conectado el display LCD a los pines I2C del shield de sensores 5.0
// Tambien se puede conectar el SDA al pin analogico A4 
// y el SCL al pin analogico A5

// Esta es la direccion I2C del display LCD 
// obtenida con el sketch IC2_Scanner
// byte direccionI2C = 0x27;
#define I2C_ADDR    0x27

LiquidCrystal_I2C lcd( I2C_ADDR, 2, 1, 0, 4, 5, 6, 7);

void setup() {
       lcd.begin (16,2);    // Inicializar el display con 16 caraceres 2 lineas
       lcd.setBacklightPin(3,POSITIVE);
       lcd.setBacklight(HIGH);

       lcd.home ();                   // go home
       lcd.print("Hola Mundo");
       lcd.setCursor ( 0, 1 );        // go to the 2nd line
       lcd.print("Arduino");
}

void loop() {
  // put your main code here, to run repeatedly:

       delay(5000);      
       lcd.home ();                   // go home
       // lcd.clear();
       lcd.print("Hola Arduino");
       lcd.setCursor ( 0, 1 );        // go to the 2nd line
       lcd.print("LiquidCrystal I2C");
}
