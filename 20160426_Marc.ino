#include <LiquidCrystal.h>
#include <Wire.h>
LiquidCrystal lcd(13,12,11,10,9,8);

char temps; //INICIAMOS UNA CADENA
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

void pastilla1(int intera){
  lcd.clear();
  delay(10);
  lcd.setCursor(0,0);
  lcd.print("Toma la pastilla!");
  lcd.setCursor(0,1);
  lcd.print("Esdeveniment 1");
  interr = digitalRead(inter);
  Serial.print(interr==intera);
  while(intera == interr){
    interr = digitalRead(inter);
    digitalWrite(led1,HIGH);
    delay(500);
    tone(piezo,2000,100);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("23/04/2016");
  lcd.setCursor(0,1);
  lcd.print("18:02:00");
  digitalWrite(led1,LOW);
}
void pastilla2(int intera){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Toma la pastilla!");
  lcd.setCursor(0,1);
  lcd.print("Esdeveniment 2");
  interr = digitalRead(inter);
  Serial.print(interr==intera);
  while(intera == interr){
    interr = digitalRead(inter);
    digitalWrite(led2,HIGH);
    delay(500);
    tone(piezo,2000,100);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("23/04/2016");
  lcd.setCursor(0,1);
  lcd.print("18:02:00");
  digitalWrite(led2,LOW);
}
void pastilla3(int intera){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Toma la pastilla!");
  lcd.setCursor(0,1);
  lcd.print("Esdeveniment 3");
  interr = digitalRead(inter);
  Serial.print(interr==intera);
  while(intera == interr){
    interr = digitalRead(inter);
    digitalWrite(led3,HIGH);
    delay(500);
    tone(piezo,2000,100);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("23/04/2016");
  lcd.setCursor(0,1);
  lcd.print("18:02:00");
  digitalWrite(led3,LOW);
}
void visita60(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Queda 1 hora per");
  lcd.setCursor(0,1);
  lcd.print("anar al metge");
  for(int y=0;y<5;y++){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    tone(piezo,2000,100);
    delay(750);
    digitalWrite(led1,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led1,LOW);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("23/04/2016");
  lcd.setCursor(0,1);
  lcd.print("18:02:00");
}
void visita30(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Queden 30 min per");
  lcd.setCursor(0,1);
  lcd.print("anar al metge");
  for(int x=0;x<5;x++){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    tone(piezo,2000,100);
    delay(750);
    digitalWrite(led1,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led1,LOW);
  }
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("23/04/2016");
   lcd.setCursor(0,1);
   lcd.print("18:02:00");
}

void setup(){
  Wire.begin();
  lcd.begin(16,2);
  lcd.print("23/04/2016");
  lcd.setCursor(0,1);
  lcd.print("17:58:00");
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
  Wire.requestFrom(1,2);
  while(Wire.available())
  {
    temps = Wire.read();
    Serial.print(temps);
  }
//  Wire.requestFrom(2,19);
//  minuts = Wire.read();
  Serial.print("    ");
//  Serial.print(minuts);
//  Serial.print("    ");
  Serial.print(millis());
  Serial.print("    ");
  Serial.print(intera);
  Serial.print("    ");
  Serial.print(tesd[i]);
  Serial.print('\n');
//  Serial.print(segons);
  
  tactual = millis();
  if(i < sizeof(esd)){
    tesdeveniment = tesd[i];
    esdeveniment = esd[i];
    if(tactual >= tesdeveniment){
      if(esdeveniment == 1){
        intera = digitalRead(inter);
        pastilla1(intera);
      }
      else if(esdeveniment == 2){
        intera = digitalRead(inter);
        pastilla2(intera);
      }
      else if(esdeveniment == 3){
        intera = digitalRead(inter);
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
