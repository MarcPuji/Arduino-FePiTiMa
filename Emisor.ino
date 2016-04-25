#include <virtuabotixRTC.h> 
#include <Wire.h>
#include <WString.h>
virtuabotixRTC myRTC(6, 7, 8); //Conectem els pins CLK -> 6, DAT -> 7, RST -> 8
char hora[3];
char minut[3];
char segon[3];
String text="";
void setup()
{
  // segons, minuts, hores, dia de la setmana, dia, mes, any
  myRTC.setDS1302Time(00, 39, 15, 4, 21, 4, 2016);
  Wire.begin(1); // Abrimos el canal 1 (0x01) del I2C
  Wire.onRequest(temps);// Creamos el evento que se relaizará cuando el Receptor llame a el emisor (Este Arduino)
  Serial.begin(9600);
}

void loop()
{
  myRTC.updateTime();  
//aqueste part és numés per visualitzar a la pantalla la hora i dia.
Serial.print("Data Actual: "); 
Serial.print(myRTC.dayofmonth); 
Serial.print("/"); 
Serial.print(myRTC.month); 
Serial.print("/");
Serial.print(myRTC.year);
Serial.print(" ");
Serial.print(myRTC.hours);
Serial.print(":");
Serial.print(myRTC.minutes);
Serial.print(":");
Serial.println(myRTC.seconds);

  sprintf(hora,"%d",myRTC.hours);
  sprintf(minut,":%d",myRTC.minutes);
  sprintf(segon,":%d",myRTC.seconds);
  String h=hora;
  String m=minut;
  text=h+m;
  Serial.print(text);
  delay(500);

// Imprimir resultats cada segon
}

void temps() 
{

//  Wire.write(text);
  //cuando se realize la peticion ese mensaje y lo enviaremos por el canal 1
}



