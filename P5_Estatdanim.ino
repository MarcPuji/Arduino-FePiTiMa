#include <servo.h> ** per importar la llibreria**
** creació de variables**
servo Miservo;
int const PinPot=A0;
int ValorPot;
int Angulo;
** Establiment del setup**
void setup() {
  
  Miservo.attach(9);

  serial.begin(9600);

}

void loop() {

  ** llegim el valor del potenciometre i l'ensenyem per pantalla**
  ValorPot = analogRead(PinPot);
  Serial.print("Posició del potenciometre: ");
  Serial.print(ValorPot);
  **Transformen el valor del potenciometre en un angle**
  Angulo = map(valorPot, 0, 1023, 0, 179);
  Serial.print(" ,Angulo: ");
  Serial.println(Angulo);
  **Pase l'angle al servo motor**
  Miservo.write(Angulo);
  **Esperem 1 s**
  delay(1000);
}
