
#include <NewSoftSerial.h>
//#include <Serial.h>
int bluetoothIn = 0;
void setup()
{
  Serial.begin(115200); 
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
}

//
void loop()
{
  
  if(Serial.available() > 0)
  {
    bluetoothIn = Serial.read(); // legge valore seriale, e ficca in bluetoothIn
//    if ( (int)(char)bluetoothIn==0 )  digitalWrite(13, LOW); 
//    if ( (int)(char)bluetoothIn==1 )  digitalWrite(13, HIGH);
//    Serial.print((char)bluetoothIn); 
//     Serial.print((char)1); 
//    if ( bluetoothIn==(char)1 )   Serial.print("derp");

    Serial.print((char)bluetoothIn); //ristampa a terminale typecasted
    Serial.print("-"); //spazzi
    Serial.print(bluetoothIn); //ristampa a terminale valore letto dal seriale
    Serial.print("    "); //spazzi
if ( bluetoothIn==48 ) digitalWrite(13, LOW);
if ( bluetoothIn==49 ) digitalWrite(13, HIGH);
  }
 
}

