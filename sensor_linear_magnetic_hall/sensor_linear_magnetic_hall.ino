// LINEAR HALL - LINEAR MAGNETIC HALL - KY-024
// Sensor magnetico, detecta los campos magneticos como al acercar un iman
// 
// Tiene una salida analogica y otra digital
//
// La pata A0 se conecta a una entrada analogica
// La pata D0 se conecta a una entrada digital
//
// VCC 5 voltios 

// Example code for KY-024
// Linear magnetic Hall

 
// Declaration and initialization of the input pin
int Analog_Eingang = A0; // X-axis-signal
int Digital_Eingang = 3; // Button
  
void setup ()
{
  pinMode (Analog_Eingang, INPUT);
  pinMode (Digital_Eingang, INPUT);
       
  Serial.begin (9600); // Serielle output with 9600 bps
}
  
// The program reads the current value of the input pins
// and output it via serial out
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
