// DS1302 REAL TIME CLOCK MODULE
// Es un modulo que gracias a su bateria conserva la hora y fecha asignada
// esto es util para mantener una fecha-hora aun cuando se desconecte
// la alimentacion del arduino
// Este ejemplo utiliza la libreria RTClib
//
// VCC: 5V
// GND: GND
// CLK: SCK_PIN: D5
// DAT: IO_PIN: D6
// RST: CE_PIN: D4
// Valores por defecto?
//
// Se puede inicializar el reloj con una fecha y este la mantendra
// mientras tenga bateria la pila de litio, aunque este desconectado

// Date and time functions using just software, based on millis() & timer

#include <Wire.h>
#include "RTClib.h"


//DS1307 rtc;
//RTC_Millis rtc;
//DS3231 rtc;
//PCF8563 rtc;
//PCF8583 rtc;
//DS1302 rtc(CE_PIN,SCK_PIN,IO_PIN);
//DS1302 rtc;// CE_PIN 4, SCK_PIN 5, IO_PIN 6 as default
//DS1302 rtc(4, 6, 5);

RTC_Millis rtc;

void setup () {
    Serial.begin(57600);
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.begin(DateTime(__DATE__, __TIME__));
}

void loop () {
    DateTime now = rtc.now();

    Serial.print("Hoy: ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.print(' ');
    Serial.print(now.day(), DEC);                
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.year(), DEC);   
    Serial.println();

    
    Serial.print(" seconds since 1970: ");
    Serial.println(now.unixtime());
    
    // calculate a date which is 7 days and 30 seconds into the future
    DateTime future (now.unixtime() + 7 * 86400L + 30);
    
    Serial.print(" now + 7d + 30s: ");
    Serial.print(future.year(), DEC);
    Serial.print('/');
    Serial.print(future.month(), DEC);
    Serial.print('/');
    Serial.print(future.day(), DEC);
    Serial.print(' ');
    Serial.print(future.hour(), DEC);
    Serial.print(':');
    Serial.print(future.minute(), DEC);
    Serial.print(':');
    Serial.print(future.second(), DEC);
    Serial.println();
    
    Serial.println();
    delay(3000);
}
