/*


*/

#ifndef BRUSHLESS_h
#define BRUSHLESS_h


class brushless {
  
  public:
  
    brushless(float timeoutFrequency);
    void setFrequency(int val);
    void setRefreshRate(int val);
    void setDuty(int val);
    int getFrequency();
    int getRefreshRate();
    int getDuty();
    //void iterate();
  
  private:
   
    byte states[NUM_STATES] = {
  	B01000100,
  	B10000100,
  	B10001000,
  	B00101000,
  	B00110000,
  	B01010000};

    volatile unsigned int cpmCounter;
    volatile int          stato;
    volatile unsigned int frequency;//holds register value
    volatile unsigned int refreshRate;
    volatile unsigned int duty;//holds register value
  
};

#endif
