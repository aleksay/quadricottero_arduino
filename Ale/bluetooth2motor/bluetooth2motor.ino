
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
char  inputStringValue[3];
char motore;
int value;


void setup() {

  // initialize serial:
  Serial.begin(57600);

  protocollSetup();
  
  motorSetup();

}

void loop() {
  
  if (stringComplete) {
    Serial.println(inputString); 
    // clear the string:
    inputString = "";
    stringComplete = false;
  }

}

void serialEvent() {
  while (Serial.available()) {
   
    char inChar = (char)Serial.read(); 
    inputString += inChar;
    if (inChar == '\n') {
      processString();
      sendToMotor(motore,value);
    } 
    
  }
}


