#include <virtuabotixRTC.h> 
#include <Wire.h>
#include <WString.h>
virtuabotixRTC myRTC(6, 7, 8); //Conectem els pins CLK -> 6, DAT -> 7, RST -> 8

char hora[9];
char data[11];

void setup()
{
  // segons, minuts, hores, dia de la setmana, dia, mes, any
  myRTC.setDS1302Time(00, 39, 16, 5, 29, 4,   2016);
  Wire.begin(1); // Abrimos el canal 1 (0x01) del I2C
  Wire.onRequest(temps);// Creamos el evento que se relaizará cuando el Receptor llame a el emisor (Este Arduino)
  Serial.begin(9600);
}

void loop()
{
  myRTC.updateTime();  
//aqueste part és numés per visualitzar a la pantalla la hora i dia.
/*Serial.print("Data Actual: "); 
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
Serial.println(myRTC.seconds);*/
sprintf(hora, "%02d:%02d:%02d", myRTC.hours, myRTC.minutes, myRTC.seconds);
sprintf(data, "%02d/%02d/%04d", myRTC.dayofmonth, myRTC.month, myRTC.year);
//sprintf(buffer, "%02d:%02d:%02d\n%02d/%02d/%04d", myRTC.hours, myRTC.minutes, myRTC.seconds,myRTC.dayofmonth,myRTC.month,myRTC.year);
Serial.print(hora);
Serial.print("\n");
Serial.print(data);
Serial.print("\n");
delay(500);

// Imprimir resultats cada segon
}

void temps() 
{
 Wire.write(hora);
  //cuando se realize la peticion ese mensaje y lo enviaremos por el canal 1
}



