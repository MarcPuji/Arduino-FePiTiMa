int notes[] = {262,294,330,349};

void setup() {
  Serial.begin(9600);
  for(int x = 2; x<6; x++){
    pinMode(x, OUTPUT);
    digitalWrite(x, LOW);
  }
}

void loop() {
  int keyVal = analogRead(A0);
  Serial.println(keyVal);

  if(keyVal == 1023){
    tone(8, notes[0]);
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }

  else if(keyVal >= 990 && keyVal <= 1010){
    tone(8, notes[1]);
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }

  else if(keyVal >= 505 && keyVal <= 515){
    tone(8, notes[2]);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  }

  else if(keyVal >= 5 && keyVal <= 10){
    tone(8, notes[3]);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
  }

  else{
    noTone(8);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
}
