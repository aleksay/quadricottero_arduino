
void protocollSetup(){
  // reserve 200 bytes for the inputString:
  inputString.reserve(20);
}

void processString(){

    // char  inputStringValue[3];
    inputStringValue[0] = inputString[1];
    inputStringValue[1] = inputString[2];
    inputStringValue[2] = inputString[3];

    motore = inputString[0];
    value = atoi(inputStringValue);

    stringComplete = true;

  }



