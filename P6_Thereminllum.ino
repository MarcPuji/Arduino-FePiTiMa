int Valordelsensor;
int Valorminsensor=1023;
int Valormaxsensor=0;

const int Pinled=13;

void setup() {
  pinMode(Pinled,13);
  digitalWrite(Pinled,HIGH);

  while(millis()<5000){
    Valodelsensor=analogRead(A0);
    if(valorsensor>Valormaxsensor){
      Valormaxsensor=valorsensor;
      }
      if(Valorsensor < valorminsensor){
        Valormimsensor=valorsensor;
        }
  }
  digitalWrite(Pinled,LOW);
  
}

void loop() {
  Valorsensensor=analogRead(A0);

  int tonalitat=map(valorsensor,valorminsensor,valormaxsensor,50,4000);

  tone(8,tonalitat,20);

  delay(10);
  
}
