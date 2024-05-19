#ifndef _Sensor_U
#define _Sensor_U
#include<Arduino.h>
class SensorU{
  private:
    byte TRIG,ECHO;
    int DURACION,DISTANCIA;
  public:
    SensorU(int ECHO,int TRIG);
    void init();
    int Lectura();
  
};
#endif
