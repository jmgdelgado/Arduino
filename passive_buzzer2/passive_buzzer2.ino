// PASSIVE BUZZER
// Pequeño altavoz para generar sonidos y tonos
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

const int pinBuzzer = 9;
 
const int tonos[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494};
const int countTonos = 10;
   
void setup()
{ 
}
 
void loop()
{
  for (int iTono = 0; iTono < countTonos; iTono++)
  {
   tone(pinBuzzer, tonos[iTono]);
   delay(1000);
  }
  noTone(pinBuzzer);
}
