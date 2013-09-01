/*

 Il circuito prevede che i pin 2 3 e 4 siano collegati ai 
 pin di comando dei buffer gate il cui input e' il segnale pwm generato dal timer.
 I 3 gate vanno connessi ai mosfet nella parte superiore.
 I pin 4,5 e 6 devono essere invece collegati direttamente ai mosfet della parte inferiore.
 
 
 */

#define NUM_STATES 6

byte states[NUM_STATES] = {
  B01000100,
  B10000100,
  B10001000,
  B00101000,
  B00110000,
  B01010000}; //store PORTD values for the states;


void machineState_init(){

  DDRD |= B01111100;  // set pin [2,6] as output
  PORTD = states[0];
}

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
volatile int refreshRate = 26;


void setup(){

  Serial.begin(9600);

 inputString.reserve(20);

  machineState_init();
  timer1_init();
}


unsigned int cpmCounter=0;
int stato = 0;
int tmp = 64;
int extDuty = 60;


void loop(){
  // print the string when a newline arrives:
  if (stringComplete) {
    int val = inputString.toInt();
    
    Serial.println(val); 
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

void timer1_init(){

  pinMode(10,OUTPUT);

  unsigned char result=(int)((257.0-(16000000.0/44100))+0.5); //the 0.5 is for rounding;
  //	 result=(int)((257.0-(TIMER_CLOCK_FREQ/timeoutFrequency))+0.5); //the 0.5 is for rounding;
  ICR1=875;  // range: 1023 (7.8 KHz) 65 (123 KHz)

  TCCR1A = 0;      // Just clear register. 

  TCCR1B = _BV(WGM13); // phase and freq correct mode 
  // OC1A,B HI when COUNT = OCR1A,B upcounting, LO when COUNT = OCR1A,B downcounting. 
  // Use phase correct: mode 8: 
  TCCR1A = _BV(COM1A1) | _BV(COM1A0)| _BV(COM1B1)| _BV(COM1B0);//turns on both 1a and 1b 

  // 8 prescaler 
  // PWM wave frequency is f= 8000000/(2*8*256) = 1953.12 Hz (1.9 kHz) 
  // Should be TCCR1B although the output is on OC1A 
  TCCR1B |= _BV(CS10);//define no prescaler. 

  TIMSK1 = _BV(OCIE1B);

  //load the timer for its first cycle
  TCNT1=result; 

  OCR1B=64; //range 0-255 
}

ISR(TIMER1_COMPB_vect) {

  cpmCounter++;

  if(cpmCounter >= refreshRate){

    // iterazione attraverso gli stati dell'automa
    PORTD = states[++stato % NUM_STATES];
    cpmCounter = 0;
  }
}


void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    } 
  }
  refreshRate = inputString.toInt();
}


