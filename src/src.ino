//#include "brushless.h"
#include "serialComm.h"

//brushless mymotor(44100);
serialComm serial(57600);


void setup() {
  Serial.begin(57600);
  Serial.println("inizio ");

}



void loop() {
  if(serial.getHaveCommand() == 1){

    char commandType = serial.getCommandType();
    int commandValue = serial.getCommandValue();
    
    Serial.print("received command: ");
    Serial.print(commandType);
    Serial.print(" value ");
    Serial.println(commandValue);
    
    
  //  commandMap(commandType, commandValue);
  }
}



//void commandMap(char commandType, int commandValue){
//
//  switch(commandType){
//
//  case 'f':
//    mymotor.setFrequency(commandValue);
//    Serial.println("set freq");
//    break;
//  case 'd':
//    mymotor.setDuty(commandValue);
//    Serial.println("set duty");
//    break;
//  case 'r':
//    mymotor.setRefreshRate(commandValue);
//    Serial.println("set refr");
//    break;
//  }
//}



void serialEvent(){
serial.eventHandler();

}


