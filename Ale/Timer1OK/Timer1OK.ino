#define DEBUG 1

/**
clock =  16384 KHz

dividers:
	8		-> 2048
	64		->  256
	256		->   64
	1024	->   16



*/



void setup(){
#ifdef DEBUG
	Serial.begin(9600);
#endif	

	pinMode(9,OUTPUT);
	pinMode(10,OUTPUT);

	TCCR1A = _BV(WGM10)  |     // 8 bit fast pwm mode, WGM12 twin in TCCR1B
			 _BV(COM1A1) |     // set OC1A e OC1B (pin 9,10 datasheet) compare match mode, clear when timer on TOP 
			 _BV(COM1B1) ;

	TCCR1B = _BV(CS10)   |       // 1/64 prescale 
			 // _BV(CS11)|       
			 _BV(CS12)   | 
			 _BV(WGM12)  ;       // fast pwm mode

	OCR1A  = 127;
	OCR1B  = 127;
	OCR2A  = 127;
}

volatile int i    = 127;    // volatile if accessed by interrupt handler
volatile int grow = 1;
volatile int tmp  = 2;



void loop(){

  
  if(grow == 1 && i >= 255){
    grow = 0;    
  }
  if(grow == 0 && i <= 0){
    grow = 1;    
    
    if(tmp > 5) tmp = 2;
    
    //TCCR1B &=  byte(map(i,0,255,2,5)) <<CS10 ; 
    volatile byte tcc = TCCR1B;
 
#ifdef DEBUG
 
    Serial.print("vecchio ");
    Serial.print(tcc,BIN);
#endif	
	tmp = tmp << CS10;

	
#ifdef DEBUG
 	
    Serial.print(" add ");
    Serial.print(tmp,BIN);
#endif	
       
	bitClear(tcc, CS10);
    bitClear(tcc, CS11);
    bitClear(tcc, CS12);
	
	bitWrite(tcc,CS10,bitRead(tmp,CS10));
	bitWrite(tcc,CS11,bitRead(tmp,CS11));
	bitWrite(tcc,CS12,bitRead(tmp,CS12));

#ifdef DEBUG
	Serial.print(" nuovo ");
    Serial.println(tcc,BIN);
#endif  
    tmp++;
    
    TCCR1B = tcc;
  }
    
  
  if(grow == 1){
    i++;
    
  }else{
    i--;
  }

  OCR1A = i;
    
  delay(10);
}
