/*

pin 2,3 -- demultiplexer selector: 

			A 00

			B 01		

			C 10

			

pin 4,5,6 --  mosfet in basso     <-----  dobbiamo valutare se la digitalWrite non è troppo lenta se no anche qui registri



pin 10 -- phase frequency correct pwm 





A0   --sensore di corrente:   se A0 <= 0   ->    nuovo stato 



A1  -- potenziometro per controllare la velocità di rotazione (duty)





*/


/* il codice eseguito sui registri PORTD e DDRD e' piu leggibile in questa forma 
void machineStates(int i){

	// puo essere ottimizzato ancora meglio
	// sulla codifica del demux...

	switch(i){

		case 0:
			digitalWrite(2,LOW);
			digitalWrite(3,HIGH);
		break;

		case 1:
			digitalWrite(4,HIGH);
			digitalWrite(6,LOW);
		break;

		case 2:
			digitalWrite(2,LOW);
			digitalWrite(3,HIGH);
		break;

		case 3:
			digitalWrite(4,LOW);
			digitalWrite(5,HIGH);
		break;

		case 4:
			digitalWrite(2,LOW);
			digitalWrite(3,LOW);
		break;

		case 5:
			digitalWrite(5,LOW);
			digitalWrite(6,HIGH);
	}


}*/

byte states[6] = {B00100100,B00110000,B01010000,B01001000,B00001000,B00000100}; //store PORTD values for the states;

void machineState_init(){

DDRD |= B01111100;  // set pin [2,6] as output

PORTD = states[0];


}


void setup(){

  Serial.begin(9600);
  
machineState_init();
timer1_init();

}

//conta le iterazioni, utile in diversi casi e safe anche se fa overflow

unsigned int cpmCounter=0;
int stato = 0;


void loop(){

	Serial.println(cpmCounter % 7); 

	// imposta il duty da un potenziometro (in futuro da interfaccia bluetooth)

//	OCR1B = map(analogRead(A1),0,1024,0,255);

}


 void timer1_init(){

  
  
   pinMode(10,OUTPUT);
   				    //mcu freq
   unsigned char result=(int)((257.0-(16000000.0/44100))+0.5); //the 0.5 is for rounding;
  	//	 result=(int)((257.0-(TIMER_CLOCK_FREQ/timeoutFrequency))+0.5); //the 0.5 is for rounding;
   ICR1=1023;  // range: 1023 (7.8 KHz) 65 (123 KHz)

   TCCR1A = 0;      // Just clear register. 
   
   TCCR1B = _BV(WGM13); // phase and freq correct mode 
   // OC1A,B HI when COUNT = OCR1A,B upcounting, LO when COUNT = OCR1A,B downcounting. 
   // Use phase correct: mode 8: 
   TCCR1A = _BV(COM1A1) | _BV(COM1A0)| _BV(COM1B1)| _BV(COM1B0);//turns on both 1a and 1b 

   // 8 prescaler 
   // PWM wave frequency is f= 8000000/(2*8*256) = 1953.12 Hz (1.9 kHz) 
   // Should be TCCR1B although the output is on OC1A 
   TCCR1B |= _BV(CS10);//define prescaler 8.  This is equavalent to 1.9 KHz. 
   

   TIMSK1 = _BV(OCIE1B);



   //load the timer for its first cycle

   TCNT1=result; 
 
  
   OCR1B=64; //x2 range 0-255 
   //Now should get PWM on OCR1A and OCR1B with duty cycles proportional to X1 and X2. 
   
 }

 ISR(TIMER1_COMPB_vect) {
 
//Capture the current timer value. This is how much error we have

  //due to interrupt latency and the work in this function

  cpmCounter++;

  if(cpmCounter >= 300){
	//machineStates(cpmCounter % 7);
	PORTD = states[++stato % 6];
      	cpmCounter = 0;
  }

}
 


