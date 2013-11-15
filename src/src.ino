#include "brushless.h"
#include "serialComm.h"


#define F_CPU 16000000UL

brushless *brushlessPtr   = NULL;
serialComm *serialCommPtr = NULL;
Command lastCommand;

void setup() {



  Serial.begin(9600);
  Serial.println("init ");
  if (serialCommPtr == NULL)
  {
    serialCommPtr = new serialComm();  // This is critical  - create a new class here only
  }
  if (brushlessPtr == NULL)
  {
    brushlessPtr  = new brushless();  // This is critical  - create a new class here only
  }
  
  /*
  StartUp Sequence
  
  based on initial values:
    frequency   = 800;
    duty        = 200; //  --> to 254
    refreshRate = 178; //  --> to 19
  in the brushless constructor.
  
  
  linear progression for duty and refresh rate.
  
  */
  delay(180);
  int d = 0;
  
  for (int i=180;i > 18 ;i--){
  
    d = (41490-55 * i)/ 162;
  
    brushlessPtr->setRefreshRate(i);
    brushlessPtr->setDuty(d);
  
    delay(40);
  }
  Serial.println("init stop");
}

void loop() { 

  if(serialCommPtr->getHaveCommand() == 1){

    lastCommand = serialCommPtr->getCommand();    
    commandMap(lastCommand);
  }
}

void commandMap(Command currentCommand){
  
  int r = -10;               //return value holder

  switch(currentCommand->type){

  case 'f':
    r = -10;
    r = brushlessPtr->setFrequency(currentCommand->value);
//    if(r > 0){
//      Serial.print("frequency: ");
//      Serial.println(currentCommand->value);
//    }
//    else{
//      Serial.print(__FUNCTION__);
//      Serial.println(": invalid return value case f");
//    }
//
//    Serial.print("return value case f ICR1: ");
//    Serial.println(r);

    break;

  case 'd':
    r = -10;
    r = brushlessPtr->setDuty(currentCommand->value);
//    if(r > 0){
//      Serial.print("duty: ");
//      Serial.println(currentCommand->value);
//    }
//    else{
//      Serial.print(__FUNCTION__);
//      Serial.println(": invalid return value case d");
//    }
//
//    Serial.print("return value case d OCR1B: ");
//    Serial.println(r);

    break;


  case 'r':
    r = -10;
    r = brushlessPtr->setRefreshRate(currentCommand->value);
//    if(r == 0){
//      Serial.print("refreshRate: ");
//      Serial.println(currentCommand->value);
//    }    
//    else{
//      Serial.print(__FUNCTION__);
//      Serial.println(": invalid return value case r");
//    }
    break;
    

  case 'p':
    Serial.print("f");
    Serial.println(brushlessPtr->getFrequency());
    Serial.print("d");
    Serial.println(brushlessPtr->getDuty());
    Serial.print("r");
    Serial.println(brushlessPtr->getRefreshRate());
    break;

  default:
//    Serial.print(__FUNCTION__);
//    Serial.print(": invalid command: ");
//    Serial.print(currentCommand->type);
//    Serial.print(" value: ");
//    Serial.println(currentCommand->value);
    break;  
  }
}

ISR(TIMER1_COMPB_vect) {
  brushlessPtr->eventHandler();

}

void serialEvent(){
  serialCommPtr->eventHandler();
}





