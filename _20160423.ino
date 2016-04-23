const int led1 = 2;
const int led2 = 3;
const int led3 = 4;

const int inter = 7;
const int piezo = 6;

int i = 0;
int esd[] = {1,2};
int tesd[] = {5000,10000}; 

int tactual = 0;
int tesdeveniment = 0;
int esdeveniment = 0;
int intera = 0;
int interr = 0;

void pastilla1(bool intera){
  interr = digitalRead(inter);
  Serial.print(interr==intera);
  while(intera == interr){
    interr = digitalRead(inter);
    digitalWrite(led1,HIGH);
    delay(500);
    tone(piezo,2000,100);
  }
  digitalWrite(led1,LOW);
  intera = interr;
}
void pastilla2(int intera){
  interr = digitalRead(inter);
  Serial.print(interr==intera);
  while(intera == interr){
    interr = digitalRead(inter);
    digitalWrite(led2,HIGH);
    delay(500);
    tone(piezo,2000,100);
  }
  digitalWrite(led2,LOW);
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
  Serial.begin(9600);
  for(int x=1;x<4;x++){
    pinMode(x,OUTPUT);
    digitalWrite(x,LOW);
  }
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(6,OUTPUT);
  digitalWrite(6,LOW);
}

void loop() {
  Serial.print(millis());
  Serial.print("    ");
  Serial.print(intera);
  Serial.print("    ");
  Serial.print(tesd[i]);
  Serial.print('\n');
  
  intera = digitalRead(inter);
  tactual = millis();
  if(i < sizeof(esd)){
    tesdeveniment = tesd[i];
    esdeveniment = esd[i];
    if(tactual >= tesdeveniment){
      if(esdeveniment == 1){
        intera = digitalRead(inter);
        //tone(piezo,2000,1000);
        pastilla1(intera);
      }
      else if(esdeveniment == 2){
        intera = digitalRead(inter);
//        digitalWrite(piezo,HIGH); esta malament
        pastilla2(intera);
      }
      else if(esdeveniment == 3){
        intera = digitalRead(inter);
//        digitalWrite(piezo,HIGH);  esta malament
        pastilla3(intera);
      }
      else if(esdeveniment == 60){
        visita60();
      }
      else if(esdeveniment == 30){
        visita30();
      }
     i++;
    }
  }
}
