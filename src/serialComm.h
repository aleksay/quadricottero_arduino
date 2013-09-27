#ifndef SERIALCOMM_h
#define SERIALCOMM_h

#include <WString.h>

class serialComm {

public:

  serialComm(int i);
  int getHaveCommand();
  char getCommandType();
  int getCommandValue();
  void eventHandler();
  //void iterate();

private:
  String inputBuffer;
  int haveCommand;
  char commandType;
  unsigned int commandValue;
  int bufferLength;

};

#endif

