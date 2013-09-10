/*


*/

#ifndef BRUSHLESS_h
#define BRUSHLESS_h


class brushless {
  
  public:
  
    brushless(int timeoutFrequency);
    void setFrequency(int val);
    void setRefreshRate(int val);
    void setDuty(int val);
    int getFrequency();
    int getRefreshRate();
    int getDuty();
    //void iterate();
  
  private:
    
    void timer1_init(int timeoutFrequency);
    int frequency;
    int refreshRate;
    int duty;
    
};

#endif
