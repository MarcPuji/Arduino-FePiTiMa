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

int i = 0;
//Any, mes, dia, hora, minuts,segons,hores de repeticio, quantita, capsula/visita si es 1 abre la capsula 1 si es 2 capsula 2.... 
int horaesd[5][9] = {{2016, 5, 21, 17, 15, 0, 8, 20, 3},
  {2016, 5, 21, 17, 15, 5, 8, 10, 2},
  {2016, 5, 21, 17, 15, 10, 1, 0, 1},
  {2016, 5, 21, 17, 15, 20, 0, 4, 4},
  {2016, 5, 21, 18, 15, 30, 0, 0, 0}
  }; 

int tactual = 0;
int tesdeveniment = 0;
int esdeveniment = 0;
int intera = 0;
int interr = 0;

void pastilla1(int intera){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Toma la pastilla!");
  lcd.setCursor(0,1);
  lcd.print("Esdeveniment 1");
  interr = digitalRead(inter);
  Serial.print(interr==intera);
  dif = 0;
  crono = millis();
  while(intera == interr){
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
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("enviant senyal");
      lcd.setCursor(0,1);
      lcd.print("d'emergencia");
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
  Serial.print(interr==intera);
  dif = 0;
  crono = millis();
  while(intera == interr){
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
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("enviant senyal");
      lcd.setCursor(0,1);
      lcd.print("d'emergencia");
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
  dif = 0;
  crono = millis();
  while(intera == interr){
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
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("enviant senyal");
      lcd.setCursor(0,1);
      lcd.print("d'emergencia");
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
  crono = millis();
  while(intera == interr){
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
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("enviant senyal");
      lcd.setCursor(0,1);
      lcd.print("d'emergencia");
    }
  }
  lcd.clear();
  digitalWrite(led4,LOW);
}
void visita60(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Visita al metge");
  lcd.setCursor(0,1);
  lcd.print("en una hora");
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
//   tactual = millis();
   while(i < 5){
    if(horaesd[i][0]==myRTC.year && horaesd[i][1]==myRTC.month && horaesd[i][2]==myRTC.dayofmonth && (horaesd[i][3]==myRTC.hours || ((horaesd[i][3]-1)==myRTC.hours && horaesd[i][8]==0))  && horaesd[i][4]==myRTC.minutes && horaesd[i][5]==myRTC.seconds)
    {
      if(horaesd[i][8] == 1 && horaesd[i][7]>0){
        horaesd[i][7]=horaesd[i][7]-1;
        if (horaesd[i][3]+horaesd[i][6]<24)
        {
          horaesd[i][3]=+horaesd[i][6];
        }
        else
        {
          horaesd[i][2]=horaesd[i][2]+int((horaesd[i][3]+horaesd[i][6])/24);
          horaesd[i][3]=horaesd[i][3]+horaesd[i][6]-24*int((horaesd[i][3]+horaesd[i][6])/24);
        }
        intera = digitalRead(inter);
        pastilla1(intera);
//        break;
      }
      else if(horaesd[i][8] == 2 && horaesd[i][7]>0){
        horaesd[i][7]=horaesd[i][7]-1;
        if (horaesd[i][3]+horaesd[i][6]<24)
        {
          horaesd[i][3]=+horaesd[i][6];
        }
        else
        {
          horaesd[i][2]=horaesd[i][2]+int((horaesd[i][3]+horaesd[i][6])/24);
          horaesd[i][3]=horaesd[i][3]+horaesd[i][6]-24*int((horaesd[i][3]+horaesd[i][6])/24);

        }
        intera = digitalRead(inter);
        pastilla2(intera);

      }
      else if(horaesd[i][8] == 3 && horaesd[i][7]>0){
        horaesd[i][7]=horaesd[i][7]-1;
        if (horaesd[i][3]+horaesd[i][6]<24)
        {
          horaesd[i][3]=+horaesd[i][6];
        }
        else
        {
          horaesd[i][2]=horaesd[i][2]+int((horaesd[i][3]+horaesd[i][6])/24);
          horaesd[i][3]=horaesd[i][3]+horaesd[i][6]-24*int((horaesd[i][3]+horaesd[i][6])/24);
        }
        intera = digitalRead(inter);
        pastilla3(intera);
      }
      else if(horaesd[i][8] == 4 && horaesd[i][7]>0){
        horaesd[i][7]=horaesd[i][7]-1;
        if (horaesd[i][3]+horaesd[i][6]<24)
        {
          horaesd[i][3]=+horaesd[i][6];
        }
        else
        {
          horaesd[i][2]=horaesd[i][2]+int((horaesd[i][3]+horaesd[i][6])/24);
          horaesd[i][3]=horaesd[i][3]+horaesd[i][6]-24*int((horaesd[i][3]+horaesd[i][6])/24);
        }
        intera = digitalRead(inter);
        pastilla4(intera);
      }
      else if(horaesd[i][8] == 0){
      visita60();
      }
    }
         i++;
   }
    i=0;
}

