int CLK=2;
int DT=3;
int LED=5;
int SW=9;

int anteriorCLK;
int valorCLK;
int valorDT;
int cont;
int valorSW;

void setup(){
  Serial.begin(9600);
  pinMode(LED, OUTPUT);

  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT);
  
  anteriorCLK=digitalRead(CLK);
  cont=0;
}

void loop(){
  valorCLK=digitalRead(CLK);
  if(valorCLK!=anteriorCLK){
    valorDT=digitalRead(DT);
    valorSW=digitalRead(SW);
    if(valorDT==valorCLK){ //derecha
      cont++;
      Serial.print(cont);
      Serial.print("   :   ");
      Serial.println(valorSW);
      if(cont>=255){
        cont=0;        
      }
    }else{ //izquierda
      cont--;
      Serial.print(cont);
      Serial.print("   :   ");
      Serial.println(valorSW);      
      if(cont<=0){
        cont=255;
      }
    }

    anteriorCLK=valorCLK;
  }
}
