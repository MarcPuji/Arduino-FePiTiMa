const int led1 = 1;
const int led2 = 2;
const int led3 = 3;

const int onoff = 8;
const int inter = 7;

const int piezo = 6;

int i = 0;
int esd[] = {}
// exemple: esd[] = {{10000,"pastilla1"},{20000,"pastilla2"}}

void setup()
  for(int x=1;x<4;x++){
    pinMode(x,OUTPUT);
  }
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(6,OUTPUT);
}

void loop() {
  if(i < sizeof(esd[])){
    tactual = millis()
    tesdeveniment = esd[i][0];
    esdeveniment = esd[i][1];
    if(tactual >= tesdeveniment){
      if(esdeveniment = "pastilla1"){
        pastilla1();
        i++;
      }
      else if(esdeveniment = "pastilla2"){
        pastilla2();
        i++;
      } 
}

void pastilla1(){
  
}
void pastilla2(){
  
}

