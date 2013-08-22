void setup() {

  /*
  Equals to:
    pinMode(6,OUTPUT);
    pinMode(5,OUTPUT);
  */
  DDRD |= (1 << DDD6);
  DDRD |= (1 << DDD5);

  // set PWM for 50% duty cycle
  OCR0A = 128;
  OCR0B = 128;

  // set none-inverting mode for both pins
  TCCR0A |= (1 << COM0A1);
  TCCR0A |= (1 << COM0B1);


  TCCR0A |= (1 << WGM01) | (1 << WGM00);
  // set fast PWM Mode

  TCCR0B |= (1 << CS01);
  // set prescaler to 8 and starts PWM

}

void loop() {
 

}

