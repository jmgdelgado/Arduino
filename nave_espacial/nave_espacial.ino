int switchState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);  
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2);

  if (switchState == LOW) {
    // el boton no esta pulsado
    digitalWrite(3, HIGH);  // LED verde
    digitalWrite(4, LOW);   // LED rojo
    digitalWrite(5, LOW);   // LED rojo        
  }
  else {  // el boton esta pulsado
    digitalWrite(3, LOW);   // LED verde
    digitalWrite(4, LOW);   // LED rojo
    digitalWrite(5, HIGH);  // LED rojo  

    delay(250);
    
    digitalWrite(4, HIGH);   // LED rojo
    digitalWrite(5, LOW);    // LED rojo  
    
    delay(250);    
  }

}
