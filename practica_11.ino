#include <LiquidCrystal.h>

byte grado[8] =
 {
 0b00001100,
 0b00010010,
 0b00010010,
 0b00001100,
 0b00000000,
 0b00000000,
 0b00000000,
 0b00000000
 };
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int sensortemp=A0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.createChar(1, grado);
//  lcd.setCursor(0, 1);
}

void loop() {
  lcd.print("Estem a: ");
  int valorsensor=analogRead(sensortemp);
  float temperatura=(((valorsensor/1024.0)*5.0)-0.5)*100;
  Serial.print("Temperatura");
  Serial.print(temperatura);
  Serial.print("\n");
  lcd.print(temperatura);
  lcd.write(1);
  lcd.print("C");
  delay(1000);
  lcd.clear();
}

