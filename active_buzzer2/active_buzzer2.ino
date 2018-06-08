// ACTIVE BUZZER
// Pequeño altavoz para generar sonidos y tonos, a diferencia del pasivo,
// no se puede cambiar la frecuencia, se puede modular con las entradas PWM
// Se controla con una senial digital, en este caso D9
// Si se utiliza la funcion tone(), no se pueden utilizar los pines 3 y 11
// y no se puede utilizar la funcion tone() en dos pines a la vez
// hay que utilizar noTone en un pin antes de pasar al otro
//
// VCC 5 voltios,en realidad no hace falta alimentarlo,
// si se conecta el piezo buzzer que solo tiene pin + y - tambien funciona
// poniendo la senial en el +
// este programa funciona tanto para el passive buzzer como para el active buzzer
// el active buzzer no va a cambiar la frecuencia ya que tiene la suya propia 

int BUZZER = 9;
int i;

void setup(){
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  for(i=0; i<=255; i++){
    Serial.print(i);
    Serial.print(": ");
    Serial.print ((i*100)/255);
    Serial.println("%");
    analogWrite(BUZZER, i);
    delay(50);
    analogWrite(BUZZER, 0);
    delay(50);
  }
}
