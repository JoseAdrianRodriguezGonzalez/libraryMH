#ifndef _Sensor_IR
#define _Sensor_IR
#include<Arduino.h>
class SensorIR{
  private:
    byte pin;
    bool ESTADO;
  public:
    SensorIR(int pin);
    void init();
     bool Ver(); 
};
#endif
