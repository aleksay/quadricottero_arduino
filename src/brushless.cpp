
/*

 Il circuito prevede che i pin 2 3 e 4 siano collegati ai 
 pin di comando dei buffer gate il cui input e' il segnale pwm generato dal timer.
 I 3 gate vanno connessi ai mosfet nella parte superiore.
 I pin 5,6 e 7 devono essere invece collegati direttamente ai mosfet della parte inferiore.
 
 
 */
#include <Arduino.h>
#include "brushless.h"

#define TIMER_CLOCK_FREQ 8000000.0
#define NUM_STATES 6

byte states[NUM_STATES] = {
  	B01000100,
  	B10000100,
  	B10001000,
  	B00101000,
  	B00110000,
  	B01010000};

int debugState; //led state...vedi Debug 

brushless::brushless(float timeoutFrequency){

   /*Debug!
    
    uncomment above instruction here and
    move this on the code for blinking included led!
    digitalWrite(13,debugState=!debugState);
    
    */
   
  pinMode(13,OUTPUT);
  debugState=0;
 
  
  DDRD |= B11111100;  // set pin [2,7] as output
  PORTD = states[0];  // set up first state on pins 2,6

  frequency   = 1023;
  duty        = 50;
  refreshRate = 10;

  cpmCounter=0;
  stato = 0;

  timer1_init(timeoutFrequency);

}

int brushless::getFrequency(){ 
  return frequency;
}
int brushless::getDuty(){ 
  return duty;
}
int brushless::getRefreshRate(){ 
  return refreshRate;
}

void brushless::setFrequency(int val){
  /*
  in questo punto sarebbe bello determinare un range di 
   valori utili e mapparlo su una scala di valori semplici tipo 0 - 100
   
   per ora passiamo tutto
   */
digitalWrite(13,debugState=!debugState);
  ICR1 = val;
  frequency = val;  

//Serial.println(cpmCounter);
}

void brushless::setDuty(int val){

  if(val < 0 || val > 255) return;
  
  duty  = val;
  OCR1B = map(duty,0,255,0,frequency);
  
}

void brushless::setRefreshRate(int val){

  /*
  necessaria un analisi sperimentale di questo valore
   */

  refreshRate = val;
}


void brushless::timer1_init(float timeoutFrequency){

  pinMode(10,OUTPUT);

  TCCR1B = (1 << CS10) | (1 << WGM13);
  TCCR1A = (1 << COM1B1);//|(1 << COM1A1) |(1 << COM1A0);
  
  TIMSK1 = _BV(OCIE1B);//signal handler association
      
  ICR1 = 830;
  OCR1B = map(duty,0,255,0,frequency); //range 0-254 with 254 always LOW and 0 alwais HIGH 
}


void brushless::eventHandler(){

  cpmCounter++;

  if(cpmCounter >= refreshRate){

    // iterazione attraverso gli stati dell'automa
    stato      = ++stato % NUM_STATES;
    PORTD      = states[stato];
    
    cpmCounter = 0;  
  }
}

