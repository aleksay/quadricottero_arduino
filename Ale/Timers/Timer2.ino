void setup() {

  DDRB |= (1 << DDB3);
  DDRD |= (1 << DDD3);
    // PD6 is now an output

    OCR2A = 128;
    OCR2B = 128;
    // set PWM for 50% duty cycle


    TCCR2A |= (1 << COM2A1);
    TCCR2A |= (1 << COM2B1);
    // set none-inverting mode

    TCCR2A |= (1 << WGM21) | (1 << WGM20);
    // set fast PWM Mode

    TCCR2B |= (1 << CS21);
    // set prescaler to 8 and starts PWM

}

void loop() {
 

}
