 void setup(){
  Serial.begin(9600);
   pinMode(9,OUTPUT);
   pinMode(10,OUTPUT);
   
   unsigned char result=(int)((257.0-(8000000.0/44100))+0.5); //the 0.5 is for rounding;
   ICR1=1023;  // range: 1023 (7.8 KHz) 65 (123 KHz)

   TCCR1A = 0;      // Just clear register. 
   TCCR1B = _BV(WGM13); 
   // OC1A,B HI when COUNT = OCR1A,B upcounting, LO when COUNT = OCR1A,B downcounting. 
   // Use phase correct: mode 8: 
   TCCR1A = _BV(COM1A1) | _BV(COM1A0)| _BV(COM1B1)| _BV(COM1B0);//turns on both 1a and 1b 

   // 8 prescaler 
   // PWM wave frequency is f= 8000000/(2*8*256) = 1953.12 Hz (1.9 kHz) 
   // Should be TCCR1B although the output is on OC1A 
   TCCR1B |= _BV(CS10);//define prescaler 8.  This is equavalent to 1.9 KHz. 
   

   TIMSK1 = 1<<TOIE2;

   //load the timer for its first cycle
   TCNT1=result; 
 
   OCR1A=128; //X1 range 0-255 
   OCR1B=64; //x2 range 0-255 
   //Now should get PWM on OCR1A and OCR1B with duty cycles proportional to X1 and X2. 
   
 }
 void loop(){
 
// 
   int k = analogRead(A0);
   int j = analogRead(A1);
   
//   int tmpI = k * (255 - map(k,0,1024,0,255));
//   int tmpO = map(k,0,1024,0,255);
//   
//   Serial.print("duty: ");
//   Serial.print(tmpO);
//   Serial.print(" freq: ");
//   Serial.println(tmpI);
//   
//   OCR1B = map(k,0,1024,0,255);
//   int tmp = k * (255 - map(k,0,1024,0,255));
//   ICR1 = tmp;
//   
//   int i = map(j,0,1024,65,1023);
//   int o = map(k,0,1024,0,255);
//   Serial.print("duty: ");
//  Serial.print(o);
//  Serial.print(" freq: ");
//  Serial.println(i);
//   
//   
//   OCR1B = 0;
//   ICR1 = i;
 //ICR1 += 30;
 //OCR1B += 10;
//delay(1000); 
 
 
 
 }
