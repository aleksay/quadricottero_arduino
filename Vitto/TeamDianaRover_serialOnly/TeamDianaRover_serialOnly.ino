
//serial variable 
char serInString[20];  // array that will hold the different bytes  100=100characters;
                        // -> you must state how long the array will be else it won't work.
int  serInIndx  = 0;    // index of serInString[] in which to insert the next incoming byte


void setup()
  {
  Serial.begin(115200);  // start serial for output
  digitalWrite(50,HIGH); //link seriale on  
  delay(200); //aspetta che si accendano tutti i nodi prima di iniziare a inviare comandi
  }

void loop()
{
  
  
  
  
  
  
}

void serialEvent() 
  {
    int sb; 
    digitalWrite(50,LOW); //comando ricevuto

    while(Serial.available()) { 
       strcpy(serInString,"                   ");
       byte cont=0; // string length counter
       
       while (Serial.available()){ 
          if (serInIndx > 18) break; // overflow control
          sb = Serial.read();
          serInString[serInIndx] = sb;
          serInIndx++;
          serInString[serInIndx] = -1;
          if (sb=='\0') 
            cont++;
          if (cont==3)
            break;
       }
       
       int comando=atol(serInString[1]);
       
       
         serInIndx  = 0;
    delay(250); //se si riduce questo ridurre anche il tempo di ricezione sulla scheda motori (attualmente 100+100)
    }
       
       
