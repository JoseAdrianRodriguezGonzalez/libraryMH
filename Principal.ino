/*Librerías necesarias, motoro h, sensor ultrasonico, ir y servomotor*/
#include "MH.h"
#include "SensorU.h"
#include "SensorIR.h"
#include<Servo.h>
/*Sensores ultrasonicos*/
#define ECHO1 8
#define TRIG1 9
#define ECHO2 10
#define TRIG2 11
/*Motor*/
#define IN1 2 //Adelante
#define IN2 6 //Atras
#define EN1 3//Motor izquierdo
#define IN3 7//Adelante 
#define IN4 4//Atras
#define EN2 5//Motor derecho
/*Sensor infrarrojo*/
#define OUT 13
/*Servomotor*/
#define servo 12
/*Declaraciones de objetos de motor h, infrarrojo y ultrasonico*/
MH mh(IN1,IN2,IN3,IN4,EN1,EN2); //Declaraciones de objeto motor h
SensorU S1(ECHO1,TRIG1);//Declaracion del objeto del sensor ultrasonico 1
SensorU S2(ECHO2,TRIG2);//Declaraion del objeto del sensor ultrasonico 2
SensorIR S3(OUT);//Declaracion del sensor infrarrrojo
//Servomotor
Servo servo1; //Declaracion del objeto de servo motor 1
int Pm=500;
int PM=2400;
//Variables del sensor
int derecha;
int izquierda;
int DURACION;
int DISTANCIA;
void setup() {
  // put your setup code here, to run once:
  servo1.attach(servo,Pm,PM);//Inicialización del servo
}//Ir adelante
/*Función de moverse hacia adelante*/
void inicio(){//
    mh.Adelante();//Direccion
    mh.Velocidad(5,5);//Velocidad
  servo1.write(90);//Servomotor se coloca en un angulo recto
  Abajo();//Se checasi no hay caida

}//Medición
void Chequeo(){//Censo de mediciones
  S2.Lectura(); //Lee el sensor ultrasonico de arriba
  if(S2.Lectura() <= 20||S1.Lectura()<=20) {//Sí abmos detectan un bojeto a menos o igual de 20
    mh.Detener();//Detiene el motor h
    servo1.write(0);//se mueve a la derecha el servomotor
    S2.Lectura();//Lee el sensor de arriba lo que hay en la derecha
    derecha=S2.Lectura();//Se guarda en la variable derecha
    delay(1000+derecha);//La demora que toma se suma más lo de la derecha
    servo1.write(180);//El sergomotor gira a la izquierda
    izquierda=S2.Lectura();//El sensor mide y gurada ese valor en la variable de izquierda
    delay(1000+izquierda);//Toma le demora de la izquierda
    servo1.write(90);//EL servomotor vuelve a su lugar de origen
    if(derecha>izquierda){//Si hay mas espacio en la derecha
      mh.giroDerecha();//Gira a la derecha
      mh.Velocidad(5,5);//Con velocidad máxima
      delay(800);//COn una demora de 800 miliosegundos
      Abajo();//Busca si no hay caida
  }
     else{//Si hay más espacio a la izquierda
    
      mh.giroIzquierda();//Gira a la izquierda
      mh.Velocidad(5,5);//COn velocidad máxima
      delay(800);//Demora de 800 milisegundos
      Abajo();//Busca si no hay nada abajo
   }
  
  }else{//Si las mediciones están normales, es decir, nesta libre el espacio
    //inicio(); 
    mh.Detener();    //Se detienen los motores
    derecha=S2.Lectura();//Lee la derecha
    mh.Adelante();//Va hacia adelante
    servo1.write(90);//POscionado el servo a 90 grados
    mh.Velocidad(5,5);//Con velocidad maxima
    delay(1000);//Demora de 1 segundo
    /*
   digitalWrite(IN1, HIGH);
   digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
   digitalWrite(IN4, LOW);
   */
    
  }
  
}//Ver la parte de abajo 
void Abajo(){
  if(S3.Ver()==1){//Si hay un valor digital booelano de 1
    mh.Detener();//Se detiene 
    delay(500);//Con una demora de 500 milisegundos
    mh.Atras();//Se va hacia atras
    mh.Velocidad(5,5);//COj una veloicdad maxima
    delay(500);//Con una demora de 500 milisegundos
    mh.Detener();//Se detiene
    mh.giroIzquierda();//Gira a la izquierda
    mh.Velocidad(5,5);//Se toma la velocidad maixma
    delay(1200);//COn una demora de 1200 milisegundos
  }
}//Codigo principal
void loop() {
  inicio();
  Chequeo();
  Abajo();
}
