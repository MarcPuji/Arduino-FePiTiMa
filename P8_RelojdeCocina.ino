unsigned long tprev = 0;
int esint = 0;
int esintprev = 0;
int led = 2;
long tint = 25000;

void setup() {
  for(int x = 2;x < 7;x++){
    pinMode(x,OUTPUT);
  }
  pinMode(8,INPUT);
}

void loop() {
  unsigned long tactual = millis();

  if(tactual - tprev > tint){
    tprev = tactual;
    digitalWrite(led,HIGH);
    led++;
    if(led == 6){
      tone(6,254,100);
    }
  }
  esint = digitalRead(8);
  if(esint != esintprev){
    for(int x = 2;x < 6;x++){
      digitalWrite(x,LOW);
    }
    led = 2;
    tprev = tactual;
    esintprev = esint;
  }
}
