
int ledPinAHi = 11;      // select the pin for the LED
int ledPinALo = 10;      // select the pin for the LED
int ledPinBHi = 9;      // select the pin for the LED
int ledPinBLo = 6;      // select the pin for the LED
int ledPinCHi = 5;      // select the pin for the LED
int ledPinCLo = 3;      // select the pin for the LED
int delayValue = 100;

void setup() {
  pinMode(ledPinAHi, OUTPUT);  
  pinMode(ledPinALo, OUTPUT);  
  pinMode(ledPinBHi, OUTPUT);  
  pinMode(ledPinBLo, OUTPUT);  
  pinMode(ledPinCHi, OUTPUT);  
  pinMode(ledPinCLo, OUTPUT); 
  Serial.begin(57600);
  ledPinAHi = HIGH;
  ledPinALo = LOW;
  ledPinBHi = LOW;
  ledPinBLo = LOW;
  ledPinCHi = LOW;
  ledPinCLo = HIGH;

}

int updateStateMachine(int currentState){
 
  switch(currentState) {
   case 0:
   digitalWrite(ledPinBHi, HIGH); 
   digitalWrite(ledPinAHi, LOW); 
   break;
   case 1:
   digitalWrite(ledPinALo, HIGH); 
   digitalWrite(ledPinCLo, LOW); 
   break;
   case 2:
   digitalWrite(ledPinCHi, HIGH); 
   digitalWrite(ledPinBHi, LOW); 
    break;
    case 3:
   digitalWrite(ledPinBLo, HIGH); 
   digitalWrite(ledPinALo, LOW); 
    break;
    case 4:
   digitalWrite(ledPinAHi, HIGH); 
   digitalWrite(ledPinCHi, LOW); 
    break;
    case 5:
   digitalWrite(ledPinCLo, HIGH); 
   digitalWrite(ledPinBLo, LOW); 
    break;
} 

}


void loop() {
   
  
  for (int i=0; i<6; i++){
      updateStateMachine(i);
      delay(delayValue);
 
       // UNCOMMENT FOR VARIABLE DELAY
      delayValue=delayValue-1;
      if (delayValue<0) delayValue =100;
 
 
      Serial.print(i);
      Serial.print("   ");
      Serial.print(delayValue);
      Serial.print("\n");
   }
  
 
 

}
