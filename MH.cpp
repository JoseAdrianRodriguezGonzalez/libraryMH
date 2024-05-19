#include "MH.h"
    MH::MH(byte IN1,byte IN2, byte IN3, byte IN4, byte EN1, byte EN2){
      /*Instancias de los punteros de cada salida*/
      this ->IN1=IN1;
      this ->IN2=IN2;
      this ->IN3=IN3;
      this ->IN4=IN4;
      this ->EN1=EN1;
      this ->EN2=EN2;
      init();
    }
 void MH::init(){
    pinMode(IN1,OUTPUT);
    pinMode(IN2,OUTPUT);
    pinMode(EN1,OUTPUT);
     pinMode(IN3,OUTPUT);
    pinMode(IN4,OUTPUT);
    pinMode(EN2,OUTPUT);
    Detener();    
  }
  
void MH::Detener(){
  digitalWrite(IN1,0);
  digitalWrite(IN2,0);
  digitalWrite(IN3,0);
  digitalWrite(IN4,0);
  analogWrite(EN1,0);
  analogWrite(EN2,0);
  
}

void  MH::Adelante(){
  digitalWrite(IN1,1);
  digitalWrite(IN3,1);
  
}
void MH::Velocidad(int R,int L){
  switch (R){
    case 0:
      analogWrite(EN1,0);
      break;
    case 1:
      analogWrite(EN1,51);
      break;
    case 2:
      analogWrite(EN1,102);
      break;
    case 3:
      analogWrite(EN1,153);
      break;
    case 4:
      analogWrite(EN1,204);
      break;
    case 5:
       analogWrite(EN1,255);
       break;
    }
    switch (L){
      case 0:
        analogWrite(EN2,0);
        break;
      case 1:
        analogWrite(EN2,51);
        break;
      case 2:
        analogWrite(EN2,102);
        break;
      case 3:
        analogWrite(EN2,153);
        break;
      case 4:
        analogWrite(EN2,204);
        break;
      case 5:
        analogWrite(EN2,255);
        break;
    }
  
  }
  void MH::giroIzquierda(){
    digitalWrite(IN2,1);
    digitalWrite(IN3,1);
  }
  
  void MH::giroDerecha(){
    digitalWrite(IN1,1);
    digitalWrite(IN4,1);
  }
  void MH::Atras(){
    digitalWrite(IN2,1);
    digitalWrite(IN4,1);
  }
