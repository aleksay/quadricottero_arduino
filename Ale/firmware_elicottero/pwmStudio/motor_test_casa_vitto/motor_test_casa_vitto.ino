#define DEBUG

//int incomingByte = 0;   // for incoming serial data
//int delayPeriod = 100; // ms
//float dutyCycle = 0;
//int ton = 0;
//int toff = 0;

const int pinA = 9;
const int pinB = 10;
const int pinC = 11;
//const int pinD = 3;

int valueA=0;
int valueB=0;
int valueC=0;
int valueD=0;

char motore;//=0;
int valore=0; 

void setup() {
  Serial.begin(115200);     // opens serial port, sets data rate to 9600 bps
//  pinMode(pinA, OUTPUT);
//  pinMode(pinB, OUTPUT);
//  pinMode(pinC, OUTPUT);
  //pinMode(pinD, OUTPUT);
  //Serial.println("I'm a cobra");
 // Serial.flush();
}

void loop() {

  if (Serial.available() > 0) {
    motore = Serial.read(); 
    valore = Serial.parseInt();
    
    //drop '\n' if client sends with LR o CR, 
    //comment it for "no line end" 
    Serial.read(); 
    
#ifdef DEBUG   
    Serial.print("I received: ");
    Serial.print(valore);
    Serial.print(" for ");
    Serial.println(motore);
#endif
   
  }
  
  switch(motore){

  case 'a':
    valueA=valore;
     analogWrite(valueA,pinA);
    motore=0;
#ifdef DEBUG
    Serial.print("value on A ");
    Serial.print(valueA);
#endif
    break;
  case 'b':
    valueB=valore;
    motore=0;
     analogWrite(valueB,pinB);
#ifdef DEBUG
Serial.print("value on B ");
    Serial.print(valueB);
#endif
    break;
  case 'c':
    valueC=valore;
    motore=0;
#ifdef DEBUG
    Serial.print("value on C ");
    Serial.print(valueC);
#endif
    break;
  case 'd':
    valueD=valore;
    motore=0;
#ifdef DEBUG
    Serial.print("value on D ");
    Serial.print(valueD);
#endif
    break;
  default: 
    break;
  }
#ifdef DEBUG
    Serial.flush();
#endif


  //pwmWrite(valueA,pinA);
  //pwmWrite(valueB,pinB);
  //pwmWrite(valueC,pinC);
  //pwmWrite(valueD,pinD);
//#ifdef DEBUG
// analogWrite(valueA,pinA);
//  analogWrite(valueB,pinB);
//  analogWrite(valueC,pinC);
//#endif
//
//Serial.print(valueA);
//Serial.print(" ");
//Serial.println(pinA);
//Serial.print(valueB);
//Serial.print(" ");
//Serial.println(pinB);

}


//void pwmWrite(int incomingByte, int pin){
//  float dutyCycle = incomingByte/255.0;    
//  int ton = dutyCycle*delayPeriod;
//  int toff = delayPeriod*(1-dutyCycle);
//  Serial.print("ton: ");
//  Serial.print(ton);
//  Serial.print("toff: ");
//  Serial.println(toff);
//
//
//
//  digitalWrite(pin, HIGH);   // set the LED on
//  delay(ton);              // wait for a second
//  digitalWrite(pin, LOW);    // set the LED off
//  delay(toff);              // wait for a second
//}



