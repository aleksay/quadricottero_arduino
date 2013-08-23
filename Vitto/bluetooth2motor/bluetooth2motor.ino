String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete



void setup() {

  // initialize serial:
  Serial.begin(57600);

  // reserve 200 bytes for the inputString:
  inputString.reserve(20);

}

void loop() {
  
  // print the string when a newline arrives:
  writeStringToSerial();

}


