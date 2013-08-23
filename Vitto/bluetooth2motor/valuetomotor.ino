
const int pinA = 9;
const int pinB = 10;
const int pinC = 11;
const int pinD = 3;


int sendToMotor(char motor, int value){
  
  Serial.print(motor);
  Serial.println(value);
    
     switch(motor){
  case 'a':
    analogWrite(pinA,value);
    break;
  case 'b':
   analogWrite(pinB,value);
    break;
  case 'c':
    analogWrite(pinC,value);
    break;
  case 'd':
    analogWrite(pinD,value);
    break;
  default: 
    break;
  }
  }
  
