#include "brushless.h"
#include "serialComm.h"


brushless *brushlessPtr =NULL;
serialComm *serialCommPtr =NULL;




void setup() {



  Serial.begin(9600);
  Serial.println("inizio ");
  if (serialCommPtr==NULL)
  {
    serialCommPtr=new serialComm();  // This is critical  - create a new class here only
  }
  if (brushlessPtr==NULL)
  {
    brushlessPtr=new brushless();  // This is critical  - create a new class here only
  }
}



void loop() {


  if(serialCommPtr->getHaveCommand() == 1){

    char commandType = serialCommPtr->getCommandType();
    int commandValue = serialCommPtr->getCommandValue();

    commandMap(commandType, commandValue);
  }

  //OCR1B = ++ICR1/2;
  // delay(5);
}



void commandMap(char commandType, int commandValue){
  int r=-10;//return value holder

  switch(commandType){

  case 'f':
    r=-10;
    r=brushlessPtr->setFrequency(commandValue);
    if(r>0){

      Serial.print("frequency: ");
      Serial.println(commandValue);
    }
    else{
      Serial.print(__FUNCTION__);
      Serial.println(": invalid return value case f");
    }

    Serial.print("return value case f ICR1: ");
    Serial.println(r);

    break;


  case 'd':
    r=-10;
    r=brushlessPtr->setDuty(commandValue);
    if(r>0){
      Serial.print("duty: ");
      Serial.println(commandValue);
    }
    else{
      Serial.print(__FUNCTION__);
      Serial.println(": invalid return value case d");
    }

    Serial.print("return value case d OCR1B: ");
    Serial.println(r);

    break;


  case 'r':
    r=-10;
    r=brushlessPtr->setRefreshRate(commandValue);
    if(r==0){
      Serial.print("refreshRate: ");
      Serial.println(commandValue);
    }    
    else{
      Serial.print(__FUNCTION__);
      Serial.println(": invalid return value case r");
    }
    break;



  case 'p':
    Serial.print("Frequency: ");
    Serial.println(brushlessPtr->getFrequency());
    Serial.print("Duty Cycle: ");
    Serial.println(brushlessPtr->getDuty());
    Serial.print("Refresh Rate: ");
    Serial.println(brushlessPtr->getRefreshRate());
    break;

  default:
    Serial.print(__FUNCTION__);
    Serial.println(": invalid command letter type");
    break;  
  }
}

ISR(TIMER1_COMPB_vect) {
  brushlessPtr->eventHandler();

}

void serialEvent(){
  serialCommPtr->eventHandler();
}




