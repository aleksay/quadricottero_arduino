/*
  Software serial multple serial test
 
 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.
 
 The circuit: 
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)
 
 Note:
 Not all pins on the Mega and Mega 2560 support change interrupts, 
 so only the following can be used for RX: 
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69
 
 Not all pins on the Leonardo support change interrupts, 
 so only the following can be used for RX: 
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).
 
 created back in the mists of time
 modified 25 May 2012
 by Tom Igoe
 based on Mikal Hart's example
 
 This example code is in the public domain.
 
 */
#include <SoftwareSerial.h>

//SoftwareSerial mySerial(10, 11); // RX, TX

void setup()  
{
  // Open serial communications and wait for port to open:
 
  Serial.begin(115200);        // The Serial Mate defaults to 115200bps
//  delay(320);                     // IMPORTANT DELAY! (Minimum ~276ms)
//  Serial.print("$$$");         // Enter command mode
//  delay(15);                      // IMPORTANT DELAY! (Minimum ~10ms)
//  Serial.println("U,9600,N");  // Temporarily Change the baudrate to 9600, no parity
//  Serial.begin(57600);          // Start Serial serial at 9600


  // set the data rate for the SoftwareSerial port
  //mySerial.begin(4800);
  //mySerial.println("Hello, world?");
}

void loop() // run over and over
{
  if (Serial.available() > 1)
    Serial.write(Serial.read());
//  else
//    Serial.println("Hi dude!! we are alive");

   // Serial.read();
//    Serial.write(Serial.read());
//    Serial.read();
//    Serial.write(Serial.read());
//Serial.read();
//    Serial.write(Serial.read());
//Serial.read();
}

