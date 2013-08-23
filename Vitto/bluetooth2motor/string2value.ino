
void processString(){
  
      char  inputStringValue[3];
      inputStringValue[0] = inputString[1];
      inputStringValue[1] = inputString[2];
      inputStringValue[2] = inputString[3];
      
      
      sendToMotor( inputString[0],  atoi(inputStringValue) );
      stringComplete = true;

}
