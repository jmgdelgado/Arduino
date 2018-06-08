#include "ESP8266.h"
#include <SoftwareSerial.h>
 
const char* SSID = "EUSKALTEL_D0014804";
const char* PASSWORD = "PJKDPHVR";
 
SoftwareSerial softSerial(2, 3); // RX, TX
ESP8266 wifi(softSerial);
 
void setup(void)
{
   Serial.begin(9600);
   Serial.print("setup begin\r\n");
   
   wifi.restart();
   delay(500);
 
   if (wifi.setOprToStationSoftAP()) {
      Serial.print("to station + softap ok\r\n");
   }
   else {
      Serial.print("to station + softap err\r\n");
   }
 
   if (wifi.joinAP(SSID, PASSWORD)) {
      Serial.print("Join AP success\r\n");
      Serial.print("IP: ");
      Serial.println(wifi.getLocalIP().c_str());
   }
   else {
      Serial.print("Join AP failure\r\n");
   }
 
   if (wifi.enableMUX()) {
      Serial.print("multiple ok\r\n");
   }
   else {
      Serial.print("multiple err\r\n");
   }
 
   if (wifi.startTCPServer(80)) {
      Serial.print("start tcp server ok\r\n");
   }
   else {
      Serial.print("start tcp server err\r\n");
   }
 
   if (wifi.setTCPServerTimeout(10)) {
      Serial.print("set tcp server timout 10 seconds\r\n");
   }
   else {
      Serial.print("set tcp server timout err\r\n");
   }
 
   Serial.println("setup end\r\n");
}
 
 
void loop(void)
{
   uint8_t buffer[128] = { 0 };
   uint8_t mux_id;
 
   uint32_t len = wifi.recv(&mux_id, buffer, sizeof(buffer), 100);
   if (len > 0) {
      Serial.print("Received from: ");
      Serial.print(mux_id);
      Serial.print("\r\n");
      for (uint32_t i = 0; i < len; i++) {
         Serial.print((char)buffer[i]);
      }
      Serial.print("\r\n");
      
      if (wifi.releaseTCP(mux_id)) {
         Serial.print("release tcp ");
         Serial.print(mux_id);
         Serial.println(" ok");
      }
      else {
         Serial.print("release tcp");
         Serial.print(mux_id);
         Serial.println(" err");
      }
 
      Serial.print("Status: ");
      Serial.print(wifi.getIPStatus().c_str());
      Serial.println();
   }
}
