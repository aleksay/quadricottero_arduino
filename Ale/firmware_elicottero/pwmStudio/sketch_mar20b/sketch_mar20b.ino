void setup(){
Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(11, OUTPUT);
  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS22);
  OCR2A = 255;
  OCR2B = 255;
}

int i=0;

void loop(){
Serial.println(i);
  i = i % 256;
  
TCCR2B = TCCR2B & 0b11111000 | byte(i);
TCCR2A = TCCR2A & 0b11111000 | byte(255 - i);

i++;
delay(100);

}
