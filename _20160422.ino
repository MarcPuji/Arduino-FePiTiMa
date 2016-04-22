const int led1 = 1;
const int led2 = 2;
const int led3 = 3;

const int inter = 7;
const int piezo = 6;

int i = 0;
int esd[] = {1,2};
int tesd[] = {10000,20000}; 

int tactual = 0;
int tesdeveniment = 0;
int esdeveniment = 0;
int intera = 0;
int interr = 0;

void pastilla1(int intera){
  interr = digitalRead(inter);
  while(intera == interr){
    interr = digitalRead(inter);
    delay(500);
  }
  digitalWrite(led1,LOW);
  tone(piezo,2000,20);
  intera = interr;
}
void pastilla2(int intera){
  interr = digitalRead(inter);
  while(intera == interr){
    interr = digitalRead(inter);
    delay(500);
  }
  digitalWrite(led2,LOW);
  tone(piezo,2000,20);
  intera = interr;
}
void pastilla3(int intera){
  interr = digitalRead(inter);
  while(intera == interr){
    delay(500);
    interr = digitalRead(inter);
  }
  digitalWrite(led3,LOW);
  tone(piezo,2000,20);
  intera = interr;
}
void visita60(){
  
}
void visita30(){
  
}

void setup(){
  for(int x=1;x<4;x++){
    pinMode(x,OUTPUT);
  }
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(6,OUTPUT);
}

void loop() {
  if(i < sizeof(esd)){
    tactual = millis();
    tesdeveniment = tesd[i];
    esdeveniment = esd[i];
    if(tactual >= tesdeveniment && inter==1){
      if(esdeveniment == 1){
        intera = digitalRead(inter);
        digitalWrite(piezo,HIGH);
        pastilla1(intera);
      }
      else if(esdeveniment == 2){
        intera = digitalRead(inter);
        digitalWrite(piezo,HIGH);
        pastilla2(intera);
      }
      else if(esdeveniment = 3){
        intera = digitalRead(inter);
        digitalWrite(piezo,HIGH);
        pastilla3(intera);
      }
      else if(esdeveniment = 60){
        visita60();
      }
      else if(esdeveniment = 60){
        visita30();
      }
    }
    i++;
  }
}
