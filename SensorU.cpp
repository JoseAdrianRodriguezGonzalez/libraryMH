#include "SensorU.h"
    SensorU::SensorU(int ECHO,int TRIG){
      this-> TRIG=TRIG;
      this-> ECHO=ECHO;
      init();
    }
    void SensorU::init(){
      pinMode(TRIG,OUTPUT);
      pinMode(ECHO,INPUT);
    }
    int SensorU::Lectura(){
      digitalWrite(TRIG,HIGH);
      delay(1);
      digitalWrite(TRIG,LOW);
      DURACION=pulseIn(ECHO,HIGH);
      DISTANCIA=DURACION /58.2;
      return DISTANCIA;
    }
  
