const int PinControl1 = 2;
const int PinControl2 = 3;
const int PinActivacio = 9;
const int PinDireccio = 4;
const int PinEnces= 5;
const int PinPoten = A0;

int EstatPA  = 0;
int EstatPPA = 0;
int EstatPD  = 0;
int EstatPPD = 0;

int Motor = 0;
int Velocitat = 0;
int Direccio = 1;

void setup()}{
  pinMode(PinControl1,OUTPUT);
  pinMode(PinControl2,OUTPUT);
  pinMode(PinActivacio,OUTPUT);
  pinMode(PinDireccio,INPUT);
  pinMode(PinEnces,INPUT);
  
  digitalWrite(PinActivacio,LOW);
}

void loop(){
  EstatPA = digitalRead(PinEnces);
  delay(1);
  EstatPD = digitalRead(PinDireccio);
  Velocitat = analogRead(PinPoten)/4;
  if(EstatPA != EstatPPA){
    if(EstatPA == HIGH){
      Motor = !Motor
    }
  }
  if(EstatPD != EstatPPD){
    if(EstatPD == HIGH){
      Direccio = !Direccio
    }
  }
  if(Direccio ==1){
    digitalWrite(PinControl1,HIGH)
    digitalWrite(PinControl2,LOW)
  }
  else{
    digitalWrite(PinControl1,LOW)
    digitalWrite(PinControl2,HIGH)
  }
  if(Motor ==1){
    analogWrite(PinActivacio,Velocitat)
  }
  else{
    analogWrite(PinActivacio,0)
  }
  EstatPPD = EstatPD
  EstatPPA = EstatPA
}
