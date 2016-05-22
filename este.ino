#include <LiquidCrystal.h>

#include <SPI.h>
#include <virtuabotixRTC.h> 
#include <LiquidCrystal.h>
LiquidCrystal lcd(10);
virtuabotixRTC myRTC(8, 9, 12); //Conectem els pins CLK -> 8, DAT -> 9, RST -> 12
int emerg=0;
const int led1 = A0;
const int led2 = A1;
const int led3 = A2;
const int led4 = A3;
const int inter = 6;
const int piezo = A4;
char hora[9];
char data[11];

int dif = 0;
int crono = 0;
int surt = 0;

int i = 0;
//Any, mes, dia, hora, minuts,segons,hores de repeticio, quantita, capsula/visita si es 1 abre la capsula 1 si es 2 capsula 2.... 
int horaesd[5][9] = {{2016, 5, 21, 17, 15, 0, 8, 20, 3},
  {2016, 5, 21, 17, 15, 15, 8, 10, 1},
  {2016, 1, 2, 10, 13, 1, 1, 3, 3},
  {2016, 1, 2, 10, 14, 1, 0, 4, 7},
  {2016, 1, 2, 10, 13, 1, 1, 7, 30}
  }; 

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
  dif = 0;
  surt = 1;
  i=0;
  crono = millis();
  while(intera == interr && surt == 0){
    interr = digitalRead(inter);
    digitalWrite(led1,HIGH);
    delay(500);
    tone(piezo,2000,100);
    dif = millis() - crono;
    if (dif>=10000)
    {
      digitalWrite(emerg,HIGH);
      delay(100);
      digitalWrite(emerg,LOW);
      delay(100);
      digitalWrite(led1,LOW);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Enviant senyal");
      lcd.setCursor(0,1);
      lcd.print("d'emergencia");
      dif = 0;
      surt = 1;
    }
  }
  lcd.clear();
  digitalWrite(led1,LOW);
}
void pastilla2(int intera){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Toma la pastilla!");
  lcd.setCursor(0,1);
  lcd.print("Esdeveniment 2");
  interr = digitalRead(inter);
  dif = 0;
  surt = 1;
  i=0;
  crono = millis();
  while(intera == interr && surt == 0){
    interr = digitalRead(inter);
    digitalWrite(led2,HIGH);
    delay(500);
    tone(piezo,2000,100);
    dif = millis() - crono;
    if (dif>=10000)
    {
      digitalWrite(emerg,HIGH);
      delay(100);
      digitalWrite(emerg,LOW);
      delay(100);
      digitalWrite(led1,LOW);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("enviant senyal");
      lcd.setCursor(0,1);
      lcd.print("d'emergencia");
      dif = 0;
      surt = 1;
    }
  }
  lcd.clear();
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
  i=0;
  surt = 0;
  dif = 0;
  crono = millis();
  while(intera == interr && surt == 0){
    interr = digitalRead(inter);
    digitalWrite(led3,HIGH);
    delay(500);
    tone(piezo,2000,100);
    dif = millis() - crono;
    if (dif>=10000)
    {
      digitalWrite(emerg,HIGH);
      delay(100);
      digitalWrite(emerg,LOW);
      delay(100);
      digitalWrite(led1,LOW);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("enviant senyal");
      lcd.setCursor(0,1);
      lcd.print("d'emergencia");
      surt = 1;
      dif = 0;
    }
  }
  lcd.clear();
  digitalWrite(led3,LOW);
}
void pastilla4(int intera){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Toma la pastilla!");
  lcd.setCursor(0,1);
  lcd.print("Esdeveniment 4");
  interr = digitalRead(inter);
  Serial.print(interr==intera);
  dif = 0;
  surt = 0;
  crono = millis();
  while(intera == interr && surt == 0){
    interr = digitalRead(inter);
    digitalWrite(led4,HIGH);
    delay(500);
    tone(piezo,2000,100);
    dif = millis() - crono;
    if (dif>=10000)
    {
      digitalWrite(emerg,HIGH);
      delay(100);
      digitalWrite(emerg,LOW);
      delay(100);
      digitalWrite(led1,LOW);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("enviant senyal");
      lcd.setCursor(0,1);
      lcd.print("d'emergencia");
      dif = 0;
      surt = 1;
    }
  }
  lcd.clear();
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
    digitalWrite(led4,HIGH);
    tone(piezo,2000,100);
    delay(750);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    delay(750);
  }
  lcd.clear();

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
    digitalWrite(led4,HIGH);
    tone(piezo,2000,100);
    delay(750);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    delay(750);
  }
   lcd.clear();
}

void setup() 
{
  // segons, minuts, hores, dia de la setmana, dia, mes, any
  myRTC.setDS1302Time(50, 14, 17, 4, 21, 5, 2016);
  lcd.begin(16, 2);
  pinMode(emerg,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  
//  digitalWrite(,LOW);
  Serial.begin(9600);
}
     
void loop() {
  
   myRTC.updateTime();  
   sprintf(hora, "%02d:%02d:%02d", myRTC.hours, myRTC.minutes, myRTC.seconds);
   sprintf(data, "%02d/%02d/%04d", myRTC.dayofmonth, myRTC.month, myRTC.year);
   lcd.setCursor(0, 0);
   lcd.print(hora);
   lcd.setCursor(0, 1);
   lcd.print(data);
   delay(200);
   lcd.clear();
   tactual = millis();
   while(i < 5){
    if(horaesd[i][0]==myRTC.year && horaesd[i][1]==myRTC.month && horaesd[i][2]==myRTC.dayofmonth && horaesd[i][3]==myRTC.hours && horaesd[i][4]==myRTC.minutes && horaesd[i][5]==myRTC.seconds){
      if(horaesd[i][8] == 1){
        intera = digitalRead(inter);
        pastilla1(intera);
//        i=0;
      }
      else if(horaesd[i][8] == 2){
        intera = digitalRead(inter);
        pastilla2(intera);
//        i=0;
      }
      else if(horaesd[i][8] == 3){
        intera = digitalRead(inter);
        pastilla3(intera);
//        i=0;
      }
      else if(horaesd[i][8] == 4){
        intera = digitalRead(inter);
        pastilla4(intera);
      }
      else if(esdeveniment == 60){
        visita60();
      }
      else if(esdeveniment == 30){
        visita30();
      }
    }
         i++;
   }
    i=0;
}
