// Encender un led o un rele mediante comunicacion serie
// Al rele hay que conectar al Arduino con 5 voltios (si el rele es de 5V)
// otro cable a tierra y el cable de la senial que lo abrira o cerrara
// En este caso se va a enviar la orden de encender o apagar mediante el envio
// de un testo por el puerto Serie con auyuda de la herramienta Monitor Serie

const int PinSenial = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PinSenial,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    if(Serial.read()=='1')
    {
      digitalWrite(PinSenial,HIGH);
    }
    else
    {
      digitalWrite(PinSenial,LOW);
    }
  }

}
