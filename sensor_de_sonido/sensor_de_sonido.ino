// SENSOR DE SONIDO (BIG SOUND) KY -038
// sensor con un microfono que detecta cuando hay sonido
// la sensibilidad se cambia con el potenciometro
// Tiene una salida digital y otra analogica
// se recomienda usar la digital por que el sensor no es muy preciso en analogico
// Con el sensor azul devuelve 1 cuando detecta sonido el sonido tiene 
// que ser alto como una palmada
// 
// distancia por la duracion de la recepcion de la senial
// VCC 5 voltios 


const int pinLED = 13;
const int pinMicrophone = 9;

 
void setup ()
{
  Serial.begin(9600); 
  pinMode (pinLED, OUTPUT);
  pinMode (pinMicrophone, INPUT);
}
 
void loop ()
{
  int soundlevel = analogRead(A0);
  Serial.print(soundlevel);
  Serial.print("  :  ");
  
  bool soundDetected = digitalRead(pinMicrophone);
  Serial.println(soundDetected);
  if (soundDetected)
  {
    digitalWrite (pinLED, HIGH);
    delay(1000);
  }
  else
  {
    digitalWrite (pinLED, LOW);
    delay(10);
  }
}
