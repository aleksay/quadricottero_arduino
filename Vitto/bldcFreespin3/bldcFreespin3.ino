
int ledPinAHi = 11;      // select the pin for the LED
int ledPinALo = 10;      // select the pin for the LED
int ledPinBHi = 9;      // select the pin for the LED
int ledPinBLo = 6;      // select the pin for the LED
int ledPinCHi = 5;      // select the pin for the LED
int ledPinCLo = 3;      // select the pin for the LED
const int delayValueInit = 40;
int delayValue = delayValueInit;
int dutyCycleValue = 0;

void setup() {
  pinMode(ledPinAHi, OUTPUT);  
  pinMode(ledPinALo, OUTPUT);  
  pinMode(ledPinBHi, OUTPUT);  
  pinMode(ledPinBLo, OUTPUT);  
  pinMode(ledPinCHi, OUTPUT);  
  pinMode(ledPinCLo, OUTPUT); 
  Serial.begin(57600);

}

int updateStateMachine(int currentState){

  switch(currentState) {
  case 0:
    analogWrite(ledPinAHi, dutyCycleValue);  
    analogWrite(ledPinALo, 0);  
    analogWrite(ledPinBHi, 0);  
    analogWrite(ledPinBLo, 0);  
    analogWrite(ledPinCHi, 0);  
    analogWrite(ledPinCLo, dutyCycleValue);  
    break;
  case 1:
    analogWrite(ledPinAHi, 0);  
    analogWrite(ledPinALo, 0);  
    analogWrite(ledPinBHi, dutyCycleValue);  
    analogWrite(ledPinBLo, 0);  
    analogWrite(ledPinCHi, 0);  
    analogWrite(ledPinCLo, dutyCycleValue);  
    break;
  case 2:
    analogWrite(ledPinAHi, 0);  
    analogWrite(ledPinALo, dutyCycleValue);  
    analogWrite(ledPinBHi, dutyCycleValue);  
    analogWrite(ledPinBLo, 0);  
    analogWrite(ledPinCHi, 0);  
    analogWrite(ledPinCLo, 0);  
    break;
  case 3:
    analogWrite(ledPinAHi, 0);  
    analogWrite(ledPinALo, dutyCycleValue);  
    analogWrite(ledPinBHi, 0);  
    analogWrite(ledPinBLo, 0);  
    analogWrite(ledPinCHi, dutyCycleValue);  
    analogWrite(ledPinCLo, 0);  
    break;
  case 4:
    analogWrite(ledPinAHi, 0);  
    analogWrite(ledPinALo, 0);  
    analogWrite(ledPinBHi, 0);  
    analogWrite(ledPinBLo, dutyCycleValue);  
    analogWrite(ledPinCHi, dutyCycleValue);  
    analogWrite(ledPinCLo, 0);  
    break;
  case 5:
    analogWrite(ledPinAHi, dutyCycleValue);  
    analogWrite(ledPinALo, 0);  
    analogWrite(ledPinBHi, 0);  
    analogWrite(ledPinBLo, dutyCycleValue);  
    analogWrite(ledPinCHi, 0);  
    analogWrite(ledPinCLo, 0);  
    break;
  } 

}

int starting=1;

void loop() {

  int pot0Value=analogRead(0);
  delayValue= pot0Value*30;
  int pot1Value=analogRead(1);
  dutyCycleValue= pot1Value/4;

  for (int i=0; i<6; i++){
    updateStateMachine(i); 
        delayMicroseconds(delayValue);

  }

  Serial.print("delayValue: ");
  Serial.print(delayValue);
  Serial.print("   dutyCycleValue: ");
  Serial.print(dutyCycleValue);
  Serial.print("\n");
}



