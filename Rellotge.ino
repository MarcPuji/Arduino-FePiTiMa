#include <virtuabotixRTC.h> 
//Conectem els pins CLK -> 6, DAT -> 7, RST -> 8
virtuabotixRTC myRTC(6, 7, 8);
void setup() 
{ 
Serial.begin(9600);
// segons, minuts, hores, dia de la setmana, dia, mes, any
myRTC.setDS1302Time(00, 39, 15, 4, 21, 4, 2016);
}
void loop() { 
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
// Imprimir resultats cada segon
delay( 1000); 
}
