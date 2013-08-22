
/**
 * 
 * OCR2A digital pin 11
 * OCR2B digital pin 3
 * 
 */

void setup(){

  Serial.begin(9600);
  
  pinMode(3,OUTPUT);
  pinMode(11,OUTPUT);

 
  TCCR2A = _BV(WGM20)  |     // 8 bit fast pwm mode, WGM12 twin in TCCR1B
 	   _BV(WGM21)  |     // 8 bit fast pwm mode, WGM12 twin in TCCR1B
  	   _BV(COM2A1) |     // set OC1A e OC1B (pin 9,10 datasheet) compare match mode, clear when timer on TOP 
  	   _BV(COM2B1) ;

  TCCR2B = //_BV(CS20)   |       // 1/64 prescale 
     	     _BV(CS11)|       
 	     _BV(CS22);//   | 
  	//_BV(WGM22)  ;       // fast pwm mode

  OCR2A  = 127;  // digital pin 11  arduino
  OCR2B  = 127;  // digital pin 3 arduino


  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);

  TCCR1A = _BV(WGM10)  |     // 8 bit fast pwm mode, WGM12 twin in TCCR1B
 	 _BV(COM1A1) |     // set OC1A e OC1B (pin 9,10 datasheet) compare match mode, clear when timer on TOP 
 	 _BV(COM1B1) ;

  TCCR1B = _BV(CS10)   |       // 1/64 prescale 
   //_BV(CS11)|       
          _BV(CS12)   | 
    _BV(WGM12)  ;       // fast pwm mode

  OCR1A  = 127;  // digital pin 9  arduino
  OCR1B  = 127;  // digital pin 10 arduino

  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);

TCCR0B = 00000000;


  TCCR0A = _BV(COM0A1) | _BV(COM0B1);
  TCCR0A |= (1 << WGM01) | (1 << WGM00);
  // set fast PWM Mode


  TCCR0B |=  _BV(CS02);

 // set PWM for 50% duty cycle
  OCR0A = 128;
  OCR0B = 128;

}
void loop(){
}
