void setup() {

  DDRB |= (1 << DDD1)|(1 << DDD2);
    // PB1 and PB2 is now an output

  
    OCR1A = 128;
    // set PWM for 25% duty cycle @ 16bit

    OCR1B = 128;
    // set PWM for 75% duty cycle @ 16bit

    TCCR1A |= (1 << COM1A1)|(1 << COM1B1);
    // set none-inverting mode

    TCCR1A |= (1 << WGM11);
    TCCR1A |= (1 << WGM10);
    // set Fast PWM mode using ICR1 as TOP
    
    TCCR1B |= (1 << CS11);
      // set prescaler to 8 and starts PWM
}

void loop() {
 

}

