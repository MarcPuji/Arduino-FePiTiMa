#include <SPI.h>
#include <virtuabotixRTC.h> 
#include <LiquidCrystal.h>
LiquidCrystal lcd(10);
virtuabotixRTC myRTC(8, 9, 12); //Conectem els pins CLK -> 8, DAT -> 9, RST -> 12

//es defineixen els pins corresponents a cada component
const int led1 = A0;
const int led2 = A1;
const int led3 = A2;
const int led4 = A3;
const int inter = 6;
const int piezo = A4;
const int emerg=0; //Emisor de radiofreqüència

char hora[9];
char data[11];

//es defineixen uns contadors per tal de controlar el temps d'emergència
int dif = 0;
int crono = 0;

//s'inicialitza el contador d'esdeveniments
int i = 0;

//llista d'esdeveniments
//Any, mes, dia, hora, minuts,segons,hores de repetició, quantitat, pastilla/visita (1,2,3,4) per pastilles i 0 si visita, dosi
int horaesd[5][10] = {{2016, 5, 21, 17, 15, 0, 8, 20, 3,1},
  {2016, 5, 21, 17, 15, 7, 8, 10, 2,2},
  {2016, 5, 21, 17, 15, 15, 1, 0, 1,1},
  {2016, 5, 21, 17, 15, 24, 2, 4, 4,1},
  {2016, 5, 21, 18, 15, 36, 0, 0, 0,0}
  }; 

//es defineixen unes variables per controlar el canvi del interruptor
int intera = 0;
int interr = 0;

void pastilla1(int intera){
  interr = digitalRead(inter); //es llegeixen els valors del interruptor abans i després de començar l'avís per saber si ja s'ha pres la pastilla
  Serial.print(interr==intera);
  dif = 0;
  crono = millis(); //es comença a contar quant es tarda a prendre la pastilla per saber si s'ha d'avisar als familiars
  while(intera == interr){
    interr = digitalRead(inter);
    digitalWrite(led1,HIGH);
    delay(500);
    tone(piezo,2000,100); //avisos lluminosos i acustics per al usuari
    dif = millis() - crono;
    if (dif>=10000) //si es passa cert temps sense pendre's la pastilla, s'entra en emergència
    {
      digitalWrite(emerg,HIGH);
      delay(100);
      digitalWrite(emerg,LOW);
      delay(100); //s'envia el senyal
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Enviant senyal");
      lcd.setCursor(0,1);
      lcd.print("d'emergencia");
    }
  }
  lcd.clear();
  digitalWrite(led1,LOW);
}
void pastilla2(int intera){
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
      lcd.print("Enviant senyal");
      lcd.setCursor(0,1);
      lcd.print("d'emergencia");
    }
  }
  lcd.clear();
  digitalWrite(led2,LOW);
}
void pastilla3(int intera){
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
      lcd.print("Enviant senyal");
      lcd.setCursor(0,1);
      lcd.print("d'emergencia");
    }
  }
  lcd.clear();
  digitalWrite(led3,LOW);
}
void pastilla4(int intera){
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
      lcd.print("Enviant senyal");
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
  // es defineix data i hora quan s'engega el dispositiu
  // segons, minuts, hores, dia de la setmana, dia, mes, any
  myRTC.setDS1302Time(50, 14, 17, 4, 21, 5, 2016);
  lcd.begin(16, 2);
  pinMode(emerg,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  

  Serial.begin(9600);
}
     
void loop() {
  
   myRTC.updateTime();  
   sprintf(hora, "%02d:%02d:%02d", myRTC.hours, myRTC.minutes, myRTC.seconds);
   sprintf(data, "%02d/%02d/%04d", myRTC.dayofmonth, myRTC.month, myRTC.year);
   lcd.setCursor(0, 0);
   lcd.print(hora);
   lcd.setCursor(0, 1);
   lcd.print(data); //es va actualitzant l'hora en pantalla a cada loop
   delay(200);
   lcd.clear();
   while(i < 5){ //es recorren tots els esdeveniments
    if(horaesd[i][0]==myRTC.year && horaesd[i][1]==myRTC.month && horaesd[i][2]==myRTC.dayofmonth && (horaesd[i][3]==myRTC.hours || ((horaesd[i][3]-1)==myRTC.hours && horaesd[i][8]==0))  && horaesd[i][4]==myRTC.minutes && horaesd[i][5]==myRTC.seconds)
    { //si algun dels esdeveniments té la data i l'hora actual s'avalua
      if(horaesd[i][8] == 1 && horaesd[i][7]>0){ //es busca de quin esdeveniment es tracta
        horaesd[i][7]=horaesd[i][7]-1; //si es una pastilla i encara s'ha de pendre, s'elimina una de les pastilles pendents a pendre
        if (horaesd[i][3]+horaesd[i][6]<24)
        {
          horaesd[i][3]=+horaesd[i][6]; //si la freqüència de presa de pastilla + l'hora en la que ens trobem no passa de 24 hores, es sumen les hores directament
        }
        else
        {
          horaesd[i][2]=horaesd[i][2]+int((horaesd[i][3]+horaesd[i][6])/24); //altrament cal partir el temps que cal sumar en dies i hores
          horaesd[i][3]=horaesd[i][3]+horaesd[i][6]-24*int((horaesd[i][3]+horaesd[i][6])/24); //amb aquest procediment s'actualitza la llista d'esdeveiments
        }
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Pren la pastilla!");
        if (horaesd[i][9] == 1){ //s'avalua quina es la dosi a pendre
          lcd.setCursor(0,1);
          lcd.print("Dosi: Sencera");
        }
        else{
          lcd.setCursor(0,1);
          lcd.print("Dosi: Mitja");
        }
        intera = digitalRead(inter);
        pastilla1(intera); //es crida la funció pastilla que pertoca
        delay(250);
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
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Pren la pastilla!");
        if (horaesd[i][9] == 1){
          lcd.setCursor(0,1);
          lcd.print("Dosi: Sencera");
        }
        else{
          lcd.setCursor(0,1);
          lcd.print("Dosi: Mitja");
        }
        intera = digitalRead(inter);
        pastilla2(intera);
        delay(250);

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
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Pren la pastilla!");
        if (horaesd[i][9] == 1){
          lcd.setCursor(0,1);
          lcd.print("Dosi: Sencera");
        }
        else{
          lcd.setCursor(0,1);
          lcd.print("Dosi: Mitja");
        }
        intera = digitalRead(inter);
        pastilla3(intera);
        delay(250);
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
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Pren la pastilla!");
        if (horaesd[i][9] == 1){
          lcd.setCursor(0,1);
          lcd.print("Dosi: Sencera");
        }
        else{
          lcd.setCursor(0,1);
          lcd.print("Dosi: Mitja");
        }
        intera = digitalRead(inter);
        pastilla4(intera);
      }
     else if(horaesd[i][8] == 0){
      visita60();
      delay(250);
      }
    }
    i++; //es va augmentant l'index de la llista per tal de mirar tots els esdeveniments ja que no tenen perque estar en ordre
   }
  i=0; //es torna a entrar al loop que mira els esdeveniments
}

