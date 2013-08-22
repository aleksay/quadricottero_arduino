#define DEBUG 1

const int pinA = 9;
const int pinB = 10;
const int pinC = 11;
const int pinD = 3;

char motore = 0;
int valore = 0; 


boolean haveCommand=false;
char inChar[5] = "";


void setup() {
  Serial.begin(57600); 


}

void loop() {
  //Serial.println("loop");
  if (haveCommand) {
    //  motore = inputString.charAt(0); 
    //  char t[4]= inputString.substring(1);


parseCommand();
haveCommand = false;
    //valore = atoi(inChar);






    //drop '\n' if client sends with LR o CR, 
    //comment it for "no line end" 
    //      Serial.read(); 


    //delay(10); // not necessary
#ifdef DEBUG   
    Serial.print("Ardu: Received ");
    Serial.print(motore);
    Serial.print(valore);
    Serial.println();

#endif

    //analogWrite(pinA,valore);
    switch(motore){

    case 'a':
      motore=0;
      analogWrite(pinA,valore);
#ifdef DEBUG
      Serial.print("Ardu: Wrote A");
      Serial.println(valore);
#endif
      break;
    case 'b':
      motore=0;
      analogWrite(pinB,valore);
#ifdef DEBUG
      Serial.print("Ardu: Wrote B");
      Serial.println(valore);
#endif
      break;
    case 'c':
      motore=0;
      analogWrite(pinC,valore);
#ifdef DEBUG
      Serial.print("Ardu: Wrote C");
      Serial.println(valore);
#endif
      break;
    case 'd':
      motore=0;
      analogWrite(pinD,valore);
#ifdef DEBUG
      Serial.print("Ardu: Wrote D");
      Serial.println(valore);
#endif
      break;
    default: 
      break;
    }

  }


}

void serialEvent() {
  int i=0;
  while (Serial.available()) {
    // get the new byte:
    // char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inChar[i]=Serial.read();
  //  Serial.print("|");
 //   Serial.print(inChar[i]);
 //   Serial.print("|");
 //   Serial.println(i);
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar[i] == '\n') {
      haveCommand = true;
//      Serial.println("quit");
      //return;
    } 
    
    i++;
  //  Serial.println(i);
  delay(1);
  }

}


void parseCommand(){
Serial.println("parse motore");
  motore = inChar[0];
 
Serial.println(motore);
  char tmp[3]="";
    for(int i=0;i<3;i++){
    tmp[i]=inChar[i+1];
  }
  valore = atoi(tmp);
   Serial.println("parse valore");
  Serial.println(valore);
}




//void serialEvent() {
//
//  Serial.println("event");
//
//  int i = 0;
//  int stopper = 0;
//
//
//  while (Serial.available() && i < 5) {
//
//    if(i==0){
//      motore = Serial.read();
//    }
//    else{
//
//
//      // get the new byte:
//      inChar[i] = Serial.read(); 
//      Serial.println(inChar[i]);
//      // add it to the inputString:
//      if(i > 3){
//        if((stopper = Serial.read()) == '\n') haveCommand = true;
//      }
//      Serial.print("stopper: ");
//      Serial.println(stopper);
//    }
//    if(i > 3){
//        if((stopper = Serial.read()) == '\n') haveCommand = true;
//      }
//      Serial.print("stopper: ");
//      Serial.println(stopper);
//  }
//    i++;
//
//
//  
//}



