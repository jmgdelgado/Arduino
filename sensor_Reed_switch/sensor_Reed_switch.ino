// SENSOR REED SWITCH- MAGNETIC REED - INTERRUPTOR MAGNETICO KY-025
// Sensor Magnetico DIGITAL y ANALOGICO que se activa con un campo magnetico, 
// por ejemplo acercando un iman, actua como un interructor magnetico
//
// Funciona como los sensores KY-021,KY-003 y KY-035
// pero tiene salida digital y analogica y un potenciometro para variar la sensibilidad
// El pin analogico no parece muy util
//
// Cuando detecta un campo magnetico se ilumina el led del sensor
// y devuelve el estado 0, en estado de reposo devuelve 1
// 
// La pata S se conecta a una salida digital
//
// VCC 5 voltios 


// Declaration and initialization of the input pin
int Analog_Eingang = A0; // X-axis-signal
int Digital_Eingang = 10; // Button
  
void setup ()
{
  pinMode (Analog_Eingang, INPUT);
  pinMode (Digital_Eingang, INPUT);
       
  Serial.begin (9600); // Serial output with 9600 bps
}
  
// The program reads the current value of the input pins
// and outputs it via serial out
void loop ()
{
  float Analog;
  int Digital;
    
  // Current value will be read and converted to the voltage
  Analog = analogRead (Analog_Eingang) * (5.0 / 1023.0); 
  Digital = digitalRead (Digital_Eingang);
    
  // and outputted here
  Serial.print ("Analog voltage value:"); Serial.print (Analog, 4);  Serial.print ("V, ");
  Serial.print ("Extreme value:");
  
  if(Digital==1)
  {
      Serial.println (" reached");
  }
  else
  {
      Serial.println (" not reached yet");
  }
  Serial.println ("----------------------------------------------------------------");
  delay (200);
}
