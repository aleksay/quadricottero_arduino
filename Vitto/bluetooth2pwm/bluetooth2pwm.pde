


#include <NewSoftSerial.h>


// roba dutycycle
int delayPeriod = 100; // ms
float dutyCycle = 0;
int ton = 0;
int toff = 0;

char btch
int bluetoothIn; // per variable incoming
//int incomingByte;   // for incoming serial data


void setup()
{
  Serial.begin(115200); 
  pinMode(13,OUTPUT);
}

//
void loop()
{

  if(Serial.available() > 0)
  {
    btch_r
    bluetoothIn=Serial.read();
    //bluetoothIn[1]=Serial.read();
    //bluetoothIn[2]=Serial.read();
    //bluetoothIn[3]=Serial.read();

//    switch (bluetoothIn[0])
//    {
//    case "a": cout << "a";
//        break;
//    case "b": cout << "b";
//        break;
//    case "c": cout << "c";
//        break;
//    case "d": cout << "d";
//        break;
//    default: cout << "err";
//        break;
//    }  


      
    //  incomingByte = atoi(bluetoothIn); 
       
      Serial.println(bluetoothIn);
    //  Serial.println(bluetoothIn[1], DEC);
     // Serial.println(bluetoothIn[2], DEC);
//      Serial.println(bluetoothIn[3], DEC);
 
 //   Serial.print("I received: ");
   //   Serial.println(incomingByte);
         //           dutyCycle = incomingByte/255.0;    
          //          ton = dutyCycle*delayPeriod;
          //          toff = delayPeriod*(1-dutyCycle);

              //        digitalWrite(13, HIGH);   // set the LED on
              //        delay(ton);              // wait for a second
               //       digitalWrite(13, LOW);    // set the LED off
                //      delay(toff);              // wait for a second



  }

}


