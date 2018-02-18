const int switchPin = 8;
unsigned long previousTime = 0;
int switchState = 0;
int prevSwitchState = 0;

int led = 2;

long interval = 6000;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);  // Abriendo el puerto serie
  
  for (int x = 2; x < 8; x++){
    pinMode(x,OUTPUT);
  }
  pinMode(switchPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  unsigned long currentTime = millis();
  if (currentTime - previousTime > interval){
    previousTime = currentTime;
    digitalWrite(led,HIGH);
    led++;
    if (led == 7){
      
    }
  }

  switchState = digitalRead(switchPin);

  Serial.print("Estado: ");
  Serial.println(switchState);
  
  if (switchState != prevSwitchState){
    for (int x = 2; x < 8; x++){
      digitalWrite(x,LOW);
    }
    led = 2;
    previousTime = currentTime;
  }
  prevSwitchState = switchState;
}
