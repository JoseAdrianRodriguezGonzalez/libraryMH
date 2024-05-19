#include "SensorIR.h"
    SensorIR::SensorIR(int pin){
      this-> pin=pin;
      init();
    }
    void SensorIR::init(){
      pinMode(pin,INPUT);
    }
     bool SensorIR::Ver(){
      ESTADO=digitalRead(pin);
      return ESTADO;
    }
