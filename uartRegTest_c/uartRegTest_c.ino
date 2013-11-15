int baudrate = 9600;
int baud_prescaler;
 
void setup() {
  // put your setup code here, to run once:
//baudrate = baud;
 baud_prescaler = ((F_CPU / (baudrate * 16UL))) - 1;

 UBRR0H = (uint8_t)(baud_prescaler >> 8);
 UBRR0L = (uint8_t)(baud_prescaler);
 UCSR0B = (1 << RXEN0)|(1 << TXEN0);
 UCSR0C = (3<<UCSZ00);
 
 pinMode(13,OUTPUT);
}

unsigned char tmp=0;

void loop() {
  // un carattere per loop...la stringa invece va
   usart_print(" ho letto: ");
   usart_write(usart_read());
   //usart_write();
}


unsigned char usart_read(){
  //il blink genera un pwm di 60Mhz costante
  while(!(UCSR0A & (1<<RXC0)))myblink();
  return UDR0;
}
void usart_write(unsigned char c){
  while(!(UCSR0A & (1<<UDRE0)));
  UDR0 = c;
}

void usart_print(String str){
  int i=0;
  for(i=0;i<str.length();i++){
    usart_write(str.charAt(i));
  }
}

void myblink(){
  // molto interessante!!
  
  digitalWrite(13, HIGH);
 // delay(50);
  digitalWrite(13, LOW);
 // delay(50);
}
