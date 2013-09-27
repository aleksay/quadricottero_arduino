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
    void eventHandler();
    //void iterate();
  
  private:
   
    volatile unsigned int cpmCounter;
    volatile int          stato;
    volatile unsigned int frequency;//holds register value
    volatile unsigned int refreshRate;
    volatile unsigned int duty;//holds register value
  
    void timer1_init(float timeoutFrequency);
};

#endif
