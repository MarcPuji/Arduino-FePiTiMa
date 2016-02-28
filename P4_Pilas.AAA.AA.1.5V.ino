
const int greenLEDPin = 11;
const int redLEDPin = 13;
const int blueLEDPin = 12;

const int battery = A0;

float voltage=0;
float divition=5.0/1023;
int analogValue=0;

void setup() {
  Serial.begin(9600);

  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(battery, INPUT);
}

void loop() {
 analogValue = analogRead(battery);
 voltage=divition*analogValue;
  if (voltage<1.6 && voltage>1.0)
 {
  digitalWrite(greenLEDPin,HIGH);
  digitalWrite(blueLEDPin,LOW);
  digitalWrite(redLEDPin,LOW);
 }
  else if(voltage<=1.0 && voltage>0.5)
 {
  digitalWrite(greenLEDPin,LOW);
  digitalWrite(blueLEDPin,HIGH);
  digitalWrite(redLEDPin,LOW);
 }
  else if(voltage<=0.5 && voltage>=0.1)
 {
  digitalWrite(greenLEDPin,LOW);
  digitalWrite(blueLEDPin,LOW);
  digitalWrite(redLEDPin,HIGH);
 }
    else
  {
  digitalWrite(greenLEDPin,LOW);
  digitalWrite(blueLEDPin,LOW);
  digitalWrite(redLEDPin,LOW);
  }
 Serial.print("Voltage=");
 Serial.print(voltage);
 Serial.print("\n");
 delay(1000);
 voltage=0;
}

