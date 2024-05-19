#ifndef _MH_H
#define _MH_H
#include <Arduino.h>
    class MH{
  private:
    byte IN1,IN2,IN3,IN4;
    byte EN1,EN2;
  public:
    MH(byte IN1,byte IN2, byte IN3, byte IN4, byte EN1, byte EN2);
    void init();
  
    void Detener();

    void  Adelante();
    void Velocidad(int R,int L);
    void giroDerecha();
    void giroIzquierda();
    void Atras();
};
#endif
