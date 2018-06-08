// SENSOR DE VIBRACION - SW-420
// Sensor de vibracion del Kit 16 en 1
// En reposo devuelve el valor 0, al vibrar devuelve un valor
// dependiendo de la magnitud de la vibracion
//
// La pata D0 se conecta a una entrada digital
//
// VCC 3.3 a 5 voltios 

int LED_Pin = 13;
int vibr_Pin =3;

void setup(){
  pinMode(LED_Pin, OUTPUT);
  pinMode(vibr_Pin, INPUT); //set vibr_Pin input for measurment
  Serial.begin(9600); //init serial 9600
 // Serial.println("----------------------Vibration demo------------------------");
}
void loop(){
  long measurement =TP_init();
  delay(50);
 // Serial.print("measurment = ");
  Serial.println(measurement);
  if (measurement > 1000){
    digitalWrite(LED_Pin, HIGH);
  }
  else{
    digitalWrite(LED_Pin, LOW); 
  }
}
long TP_init(){
  delay(10);
  long measurement=pulseIn (vibr_Pin, HIGH);  //wait for the pin to get HIGH and returns measurement
  return measurement;
}
