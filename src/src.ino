#include "brushless.h"
#include "serialComm.h"


brushless mymotor(44100.0);
serialComm myserial(0);

void setup() {

  Serial.begin(9600);
  Serial.println("inizio ");

}


void loop() {
  
  if(myserial.getHaveCommand() == 1){

    char commandType = myserial.getCommandType();
    int commandValue = myserial.getCommandValue();
    
 //   Serial.print("received command: ");
//    Serial.print(commandType);
 //   Serial.print(" value ");
 //   Serial.println(commandValue);
    
    
    commandMap(commandType, commandValue);
  }
}



void commandMap(char commandType, int commandValue){

  switch(commandType){

  case 'f':
    mymotor.setFrequency(commandValue);
    Serial.print("set freq ");
    Serial.println(mymotor.getFrequency());
    break;
  case 'd':
    mymotor.setDuty(commandValue);
    Serial.print("set duty ");
    Serial.println(mymotor.getDuty());
    break;
  case 'r':
    mymotor.setRefreshRate(commandValue);
    Serial.print("set refr ");
    Serial.println(mymotor.getRefreshRate());
    break;
  }
}

ISR(TIMER1_COMPB_vect) {
 mymotor.eventHandler();

}

void serialEvent(){
  myserial.eventHandler();
}


