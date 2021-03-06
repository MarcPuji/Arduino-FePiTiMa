const int PinSensorA = A0;
const int PinSensorB = A5;
const float Temp = 20.0;

void setup(){
  Serial.begin(9600);
  for(int Pinn = 2;Pinn < 5;Pinn++){
    pinMode(Pinn,OUTPUT);
    digitalWrite(Pinn,LOW);
  }for(int Pinn = 8;Pinn < 11;Pinn++){
    pinMode(Pinn,OUTPUT);
    digitalWrite(Pinn,LOW);
  }
}
void loop(){
  int SensorA = analogRead(PinSensorA);
  int SensorB = analogRead(PinSensorB);
  
  float TensioA = (SensorA/1024.0)*5.0;
  float TensioB = (SensorB/1024.0)*5.0;
  
  float TA = (TensioA - 0.5)*100;
  float TB = (TensioB - 0.5)*100;
  
  if(TA < Temp){
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
  }if(TB < Temp){
    digitalWrite(4,LOW);
    digitalWrite(3,LOW);
    digitalWrite(2,LOW);
  }
  
  if(TA > Temp+1 && TA < Temp+2){
    digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
  }if(TB > Temp+1 && TB < Temp+2){
    digitalWrite(4,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(2,LOW);
  }
  
  if(TA > Temp+3 && TA < Temp+5){
    digitalWrite(10,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(8,LOW);
  }if(TB > Temp+3 && TB < Temp+5){
    digitalWrite(4,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(2,LOW);
  }
  
  if(TA > Temp+5){
    digitalWrite(10,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(8,HIGH);
    delay(250);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
  }if(TB > Temp+5){
    digitalWrite(4,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(2,HIGH);
    delay(250);
    digitalWrite(4,LOW);
    digitalWrite(3,LOW);
    digitalWrite(2,LOW);
  }
  delay(100);
}
