#include <TimerOne.h>

void setup(){
  Serial.begin(9600);
  pinMode(11,OUTPUT);
  Timer1.initialize(100);
  Timer1.pwm(9,768);
  Timer1.attachInterrupt(doubleBuffer);
}



int periods[8] = {
  2,7,12,18,25,15,3,30};
  
int duties[] = {
  2,64,256,32,768,64,1024,0};

int period = 0;
int duty = 0;
int flip= 1;


void doubleBuffer(){

  if(flip = 1){
    Timer1.setPeriod(period);
    flip=0;  
  }
  else
    Timer1.setPwmDuty(9,duty);  
    flip=1;
}

int i=0;

void loop(){
  //Serial.println("");

  if(i<8){
    period = periods[i];
    duty = duties[i];
    delay(5);
    i++;
  }  
  else i = 0 ;

}

