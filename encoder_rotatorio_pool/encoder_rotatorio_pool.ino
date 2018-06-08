const int channelPinA = 9;
const int channelPinB = 10;
const int buttonPin   = 5;
 
unsigned char stateChannelA;
unsigned char stateChannelB;
unsigned char prevStateChannelA = 0;
unsigned char stateButton;
 
const int maxSteps = 255;
int prevValue;
int value;
 
const int timeThreshold = 5; 
unsigned long currentTime;
unsigned long loopTime;
 
bool IsCW = true;
 
void setup() {
   Serial.begin(9600);
   pinMode(channelPinA, INPUT);
   pinMode(channelPinB, INPUT);
   pinMode(buttonPin, INPUT);   
   currentTime = millis();
   loopTime = currentTime;
   value = 0;
   prevValue = 0;
}
 
void loop() {
   currentTime = millis();
   if (currentTime >= (loopTime + timeThreshold))
   {
      stateChannelA = digitalRead(channelPinA);
      stateChannelB = digitalRead(channelPinB);
      stateButton   = digitalRead(stateButton);     
       
      // Serial.print(stateChannelA);
      // Serial.print(" : ");
      // Serial.println(stateChannelB);
            
      if (stateChannelA != prevStateChannelA)  // Para precision simple if((!stateChannelA) && (prevStateChannelA))
      {
         if (stateButton == 0) value = 0;
         if (stateChannelB != stateChannelA) // B es HIGH, es CW
         {
            bool IsCW = true;
            if (value + 1 <= maxSteps) {
              value++; // Asegurar que no sobrepasamos maxSteps
            }
            else value = 0;
             
         }
         else  // B es LOW, es CWW
         {
            bool IsCW = false;
            if (value - 1 >= 0) value = value--; // Asegurar que no tenemos negativos
         }
 
      }
      prevStateChannelA = stateChannelA;   // Guardar valores para siguiente
 
      // Si ha cambiado el valor, mostrarlo
      if (prevValue != value)
      {
         prevValue = value;
         Serial.println(value);
           Serial.print(stateChannelA);
           Serial.print(" : ");
           Serial.print(stateChannelB);           
           Serial.print(" : ");
           Serial.println(stateButton); 
      }
 
      loopTime = currentTime;  // Actualizar tiempo
   }
   
   // Otras tareas
}
