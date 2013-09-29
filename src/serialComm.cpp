#include <Arduino.h>
#include "serialComm.h"

//int debugState; //led state...vedi Debug 

serialComm::serialComm(){
          Serial.print("Entering constructor for: ");
        Serial.println(__FUNCTION__);

  
  bufferLength     = 0;
  inputBuffer  = "";
  inputBuffer.reserve(20);
  
  haveCommand  = 0;
  commandType  = '\n';
  commandValue = 0;
  
 
  
}

void serialComm::eventHandler() {
  while (Serial.available()) {
    
    // get the new byte:
    char inChar = (char)Serial.read(); 
    
    // add it to the inputString:
    inputBuffer += inChar;

    // if the incoming character is a newline, set a flag
    // extract integer value from string:
    if (inChar == '\n') {
      
        
      bufferLength = inputBuffer.length();
      char inputStringValue[inputBuffer.length()-1];
      
      int i=1;
      while(i<bufferLength-1){
        inputStringValue[i-1] = inputBuffer[i];
        i++;
      }
      
//     //char  inputStringValue[3];
//      inputStringValue[0] = inputBuffer[1];
//      inputStringValue[1] = inputBuffer[2];
//      inputStringValue[2] = inputBuffer[3];      
// 	
      commandType = inputBuffer[0];
      commandValue = atoi(inputStringValue);
    
      haveCommand = 1;
    } 
  }
}
 


int serialComm::getCommandValue(){
  
  int tmp      = commandValue;

  inputBuffer  = "";
  haveCommand  = 0;
  commandType  = '\n';
  commandValue = 0;
  
  return tmp;
}

char serialComm::getCommandType(){
  return commandType;  
}

int serialComm::getHaveCommand(){
  return haveCommand;
}
