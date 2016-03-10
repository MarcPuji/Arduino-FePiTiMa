const int PindelPulsador=2;
const int PindelMotor=9;
int EstadodelPulsador=0;

void setup() {
  pinMode(PindelPulsador, INPUT);
  pinMode(PindelMotor, OUTPUT);
}

void loop() {
  EstadodelPulsador=digitalRead(PindelPulsador);

  if(EstadodelPulsador==HIGH){
    digitalWrite(PindelMotor, HIGH);
  }
  else{
    digitalWrite(PindelMotor, LOW);
  }
}
