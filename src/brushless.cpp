
/*

 Il circuito prevede che i pin 2 3 e 4 siano collegati ai 
 pin di comando dei buffer gate il cui input e' il segnale pwm generato dal timer.
 I 3 gate vanno connessi ai mosfet nella parte superiore.
 I pin 4,5 e 6 devono essere invece collegati direttamente ai mosfet della parte inferiore.
 
 
 */
#include <Arduino.h>
#include "brushless.h"

#define TIMER_CLOCK_FREQ 16000000.0
#define NUM_STATES 6


byte states[NUM_STATES] = {
  B01000100,
  B10000100,
  B10001000,
  B00101000,
  B00110000,
  B01010000};


volatile unsigned int cpmCounter=0;
volatile int stato = 0;

volatile int frequency;
volatile int refreshRate;
volatile int duty;


brushless::brushless(int timeoutFrequency){

  DDRD |= B01111100;  // set pin [2,6] as output
  PORTD = states[0];  // set up first state on pins 2,6

  timer1_init(timeoutFrequency);

  frequency   = 875;
  duty        = 64;
  refreshRate = 100;

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

  ICR1 = val;
  frequency = val;  
}

void brushless::setDuty(int val){

  if(val < 0 || val > 255) return;

  OCR1B = val;
  duty  = val;
}

void brushless::setRefreshRate(int val){

  /*
  necessaria un analisi sperimentale di questo valore
   */

  refreshRate = val;
}


void brushless::timer1_init(int timeoutFrequency){

  pinMode(10,OUTPUT);

  unsigned char result=(int)((257.0-(TIMER_CLOCK_FREQ/timeoutFrequency))+0.5); //the 0.5 is for rounding;

  ICR1   = 875;  // range: 1023 (7.8 KHz) 65 (123 KHz)    il max dovrebbe essere 65536

  TCCR1A = 0;    // Just clear register. 

  TCCR1B = _BV(WGM13) | _BV(CS10); // phase and freq correct mode and define no prescaler. 

  // OC1A,B HI when COUNT = OCR1A,B upcounting, LO when COUNT = OCR1A,B downcounting. 
  TCCR1A = _BV(COM1A1) | _BV(COM1A0)| _BV(COM1B1)| _BV(COM1B0); 

  TIMSK1 = _BV(OCIE1B);//signal handler association

  //load the timer for its first cycle
  TCNT1  = result; 

  OCR1B  = 64; //range 0-255 
}


ISR(TIMER1_COMPB_vect) {

  cpmCounter++;

  if(cpmCounter >= refreshRate){

    // iterazione attraverso gli stati dell'automa
    stato      = ++stato % NUM_STATES;
    PORTD      = states[stato];
    
    cpmCounter = 0;
  
  }
}

