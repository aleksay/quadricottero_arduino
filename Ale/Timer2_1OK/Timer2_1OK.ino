
/**
 * 
 * OCR2A digital pin 11
 * OCR2B digital pin 3
 * 
 */

void setup(){

  pinMode(3,OUTPUT);
  pinMode(11,OUTPUT);

  /*
TCCR2A = _BV(WGM20) |   
   _BV(WGM21) |
   _BV(WGM22) |
   _BV(COM2A1) |
   _BV(COM2B1) |
   _BV(CS20)
   _BV(CS21)
   _BV(CS22)
   */
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

  TCCR1B = //_BV(CS10)   |       // 1/64 prescale 
   //_BV(CS11)|       
          _BV(CS12)   | 
    _BV(WGM12)  ;       // fast pwm mode

  OCR1A  = 127;  // digital pin 9  arduino
  OCR1B  = 127;  // digital pin 10 arduino




}
void loop(){
}


