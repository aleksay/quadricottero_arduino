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

void machineStates(int i){

	// puo essere ottimizzato ancora meglio.
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
}


void setup(){

	// pins setup

	pinMode(2,OUTPUT);  //demux selector
	pinMode(3,OUTPUT);

	pinMode(4,OUTPUT);  // to lower mosfet
	pinMode(5,OUTPUT);
	pinMode(6,OUTPUT);
		 

	 // setup phase frequency correct on pin 10
	pinMode(10,OUTPUT);
	 
	ICR1   = 1023;  // range: 1023 (7.8 KHz) 65 (123 KHz)
	 
	TCCR1A = _BV(COM1B1)| _BV(COM1B0);  //connect pin OC1B to timer
	 
	TCCR1B = _BV(WGM13)     //phase correct setup
			| _BV(CS10);		// no prescaler		
	 
	OCR1B  = 128; // start pwm signal at default 50% duty

}


//conta le iterazioni, utile in diversi casi e safe anche se fa overflow
unsigned int i=0;

void loop(){

	//quando il sensore sta andando a zero
	if(analogRead(A0) == 0){
		machineState(i % 6); // si itera tra gli stati

		// incrementa il conteggio delle iterazioni
		i++;	
	}

	// imposta il duty da un potenziometro (in futuro da interfaccia bluetooth)
	OCR1B = map(analogRead(A1),0,1024,0,255);
}





