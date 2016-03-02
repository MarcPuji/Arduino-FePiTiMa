int interuptor=0;
int pininter=2;
int ledvermell=13;
int ledgroc=12;
int ledverd=11;
int ledvermellvianen=10
int temps=2000;
void setup() 
{
  pinMode(ledvermell,OUTPUT);
  pinMode(ledgroc,OUTPUT);
  pinMode(ledverd,OUTPUT);
  pinMode(ledvermellvianen,OUTPUT);
  pinMode(pininter,INPUT);
}

void loop() 
  {
  interuptor=digitalRead(pininter);
  if (interuptor == LOW)
  {
    digitalWrite(ledvermell, LOW);
    digitalWrite(ledgroc, LOW);
    digitalWrite(ledverd, HIGH);
    digitalWrite(ledvermellvianen, HIGH);
  }
  else
  {
    digitalWrite(ledvermell,LOW);
    digitalWrite(ledverd,LOW);
    digitalWrite(ledgroc,HIGH);
    digitalWrite(ledvermellvianen, HIGH);
    delay(temps);
    digitalWrite(ledvermell,HIGH);
    digitalWrite(ledverd,LOW);
    digitalWrite(ledgroc,LOW);
    digitalWrite(ledvermellvianen, LOW);
    delay(temps);
    digitalWrite(ledvermell, LOW);
    digitalWrite(ledgroc, LOW);
    digitalWrite(ledverd, HIGH);
    digitalWrite(ledvermellvianen, LOW);
    delay(temps);
  }
}

