#include <Arduino.h>
#include "serialComm.h"

String inputBuffer;
int haveCommand;
char commandType;
int commandValue;

serialComm::serialComm(int baudrate){
  //Serial.begin(baudrate);
  
  inputBuffer = "";
  inputBuffer.reserve(20);
  
  haveCommand  = 0;
  commandType  = '\n';
  commandValue = 0;
}

void serialComm::processString(){
  
      char  inputStringValue[3];
      inputStringValue[0] = inputBuffer[1];
      inputStringValue[1] = inputBuffer[2];
      inputStringValue[2] = inputBuffer[3];      
 	
      commandType = inputBuffer[0];
      commandValue = atoi(inputStringValue);
    
      haveCommand = 1;
} 

void serialComm::eventHandler() {
  while (Serial.available()) {
    
    // get the new byte:
    char inChar = (char)Serial.read(); 
    
    // add it to the inputString:
    inputBuffer += inChar;
    
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
     char  inputStringValue[3];
      inputStringValue[0] = inputBuffer[1];
      inputStringValue[1] = inputBuffer[2];
      inputStringValue[2] = inputBuffer[3];      
 	
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
