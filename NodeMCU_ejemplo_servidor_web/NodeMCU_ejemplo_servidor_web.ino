#include <ESP8266WiFi.h>

#define LED_BUILTIN 2

const char* ssid = "EUSKALTEL_D0014804";
const char* password = "PJKDPHVR";

int estado;
String webTexto="";

WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  delay(10);

  //Configuración  del GPIO2
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);
  
  
  Serial.println();
  Serial.println();
  Serial.print("Conectandose a red : ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password); //Conexión a la red
  
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi conectado");
  
  
  server.begin(); //Iniciamos el servidor
  Serial.println("Servidor Iniciado");


  Serial.println("Ingrese desde un navegador web usando la siguiente IP:");
  Serial.println(WiFi.localIP()); //Obtenemos la IP
}

void loop() {
  
  WiFiClient client = server.available();
  if (client) //Si hay un cliente presente
  { 
    Serial.println("Nuevo Cliente");
    
    //esperamos hasta que hayan datos disponibles
    while(!client.available()&&client.connected())
    {
    delay(1);
    }
    
    // Leemos la primera línea de la petición del cliente.
    String linea1 = client.readStringUntil('r');
    Serial.println(linea1);

    if (linea1.indexOf("LED=ON")>0) //Buscamos un LED=ON en la 1°Linea
    {
      digitalWrite(LED_BUILTIN,HIGH);
    }
    if (linea1.indexOf("LED=OFF")>0)//Buscamos un LED=OFF en la 1°Linea
    {
      digitalWrite(LED_BUILTIN,LOW);
    }
    
    client.flush(); 
                
    Serial.println("Enviando respuesta...");   
    //Encabesado http    
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");// La conexión se cierra después de finalizar de la respuesta
    client.println();
    //Pagina html  para en el navegador
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<head><title>Naylam Mechatronics</title>");
    client.println("<body>");
    client.println("<h1 align='center'>Test ESP8266</h1>");
    client.println("<div style='text-align:center;'>");
    client.println("<br />");            
    client.println("<button onClick=location.href='./?LED=ON'>LED ON</button>");           
    client.println("<button onClick=location.href='./?LED=OFF'>LED OFF</button>");

      //Se crean botones con estilos para modificar el estado del LED
    client.println("<br />");  
    client.println("<button type='button' onClick=location.href='/LED=ON' style='margin:auto; background-color:green; color:#A9F5A9; padding:5px; border:2px solid black; width:200;'><h2> ENCENDER</h2> </button>");
    client.println("<button type='button' onClick=location.href='/LED=OFF' style='margin:auto; background-color:red; color:#F6D8CE; padding:5px; border:2px solid black; width:200;'><h2> APAGAR</h2> </button><br><br>");

    estado = digitalRead(LED_BUILTIN);
    webTexto = "Estado: " + String(estado);
    webTexto = "<h1 align='center'>" + webTexto + "</h1>";
    client.println(webTexto);
    // client.println("<h1 align='center'>webTexto</h1>");
    
    client.println("<br />");
    client.println("</div>");
    client.println("</body>");
    client.println("</html>");
    
    delay(1);
    Serial.println("respuesta enviada");
    Serial.println();

  }
}

