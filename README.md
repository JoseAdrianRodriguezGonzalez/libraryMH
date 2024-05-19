# 1.-Librerías incluidas:
    Las librerías incluidas son MH.h, SensorIR y SensorU
##    1.1-Librería MH.h
###        1.1.1-La librería MH.h es la encarga del motor H incluido en el circuito, el modelo del circuito integrado es el L293D, aunque también esta librería es compatible con L298D
###        1.1.2-La librería incluye las funciones:
            MH(byte IN1,byte IN2, byte IN3, byte IN4, byte EN1, byte EN2);
            init();
            Detener();
            Velocidad(int R, int L);
            void giroDerecha();
            void giroIzquierda();
            void Atras();
 ####           1.1.2.1-La función MH(); es la librería que inicia y declara los pines en donde va a estar conectadpo el puente H, se requieren 6 párametros, los primeros 4 son para las salidas de los motores, en los que controla el sentido del giro, ya sea a la izquierda o a la derecha, los dos últimos son los pines en los que se permite controlar el PWM, de los dos motores. Es importante ordenarlos correctamente, los primeros 4 parametros tienen que estar en el orden de los ines de salida:
                IN1
                IN2
                IN3
                IN4
            y en los dos últimos parametros deben de estar los activadores de PWM,(ENABLE):
                EN1
                EN2
            Por lo que el manejo de la función debe ser de la siguiente manera
            MH(byte IN1,byte IN2, byte IN3, byte IN4, byte EN1, byte EN2);
            Dentro de esta funcion se encuentra la función init()
  ####          1.1.2.2-Función init();
                La función init() inicializa los pines recibidos por MH, declarandolos todos como salidas, esta función no es necesaria colocarlo en nuestro archivo main.ino, porque esta función la incluye MH(). Dentro de la función init se encuentra la función Detener();
  ####          1.1.2.3-Función Detener();
                Esta función solamente apaga los motores, dejandolos inhabilitados por los pines EN1 y EN2, como a su vez, apagados directamente sus sentidos de giro
  ####          1.1.2.4-Adelante();
                En esta función solamente se declaran los pines IN1 e IN3 que vayan hacia adelante 
  ####          1.1.2.5-Velocidad(int R, int L);
                Esta función solo requiere dos parametros, un valor entero para el lado derecho y un valor izquierdo para el lado izquierdo, esta función en ambos valores entero tienen 6 posibles valores, o 6 velocidades distintas.
                velocidades:            Valores(pwm)
                0                       0
                1                       51  
                2                       102
                3                       153
                4                       204
                5                       255
  ####          1.1.2.6-giroDerecha();
                Está función permite hacer el giro hacia la derecha del motor, activando IN2 e IN3
  ####          1.1.2.7-giroIzquierda();
                Esta función permite que el coche gire a la izquierda, el pin IN1 y el pin IN4 se activando
  ####          1.1.2.8-Atras();
                Esta función lo que permite hacer es que el coche retroceda o vaya para atrás, activando IN2 e IN4
  ###      1.1.3 Nota: Los nombres de las varaibles son solo un ejemplo que están escritos en la librería, pero, al hacer tu código main.ino puede nombrarlos a su gusto.
 ##   1.2-SensorU.h-> Esta librería es la encargada de controlar los sensores ultrasonicos del dispositivo.
 ###       1.2.1-la librería tiene las siguientes funciones
        SensorU(int ECHO, int TRIG);
        init();
        Lectura();
        Estas tres funciones permiten que los sensores se inicialicen y lean.
 ####           1.2.1.1-SensorU(int ECHO, int TRIG)
            Esta función permite inicializar el sensor apuntando a los pines de Trig y ECHO del sensor HC-SR04, dentro de esta función esta la función init();
 ####           1.2.1.2-init()
            Esta función inicializa el trig como salida y el ECHO como entrada
 ####           1.2.1.3-Lectura()
            Esta función lo que hace es leer el dato, primero enviando un pulso, despues de haberlo enviado, se mide cuanto duro el pulso, y al saberlo, se hace una operación aritmetica en la que permite determianr la distancia en la que s eencuentran los objetos proximos, para al final, devolver la función el valor de la distancia.
 ###       1.2.2-Nota: Los nombres de las varaibles son solo un ejemplo que están escritos en la librería, pero, al hacer tu código main.ino puede nombrarlos a su gusto.
##    1.3-Librería SensorIR.H
 ###       1.3.1 Esta librería es la que permite detectar si hay una posible caída, para así, poder evitarla.
 ###       1.3.2- La librería cuenta con las funciones:
            SensorIR(int pin);
            void init();
            bool Ver();
####            1.3.2.1-SensorIR(int pin);
                Esta funcion inicializa el sensor con el pin indicado como parametro, dentro de ella viene la función init();
####            1.3.2.2-void init()
                Esta función solamente declara el pin como salida
####            1.3.2.3-bool Ver()
                Esta función solamente visualiza el estado en el que está el sensor,(ALTO o BAJO), y ese valor ESTADO, lo devuelve en la función Ver, dandole así un valor a la función
####        1.3.3-Nota: Los nombres de las varaibles son solo un ejemplo que están escritos en la librería, pero, al hacer tu código main.ino puede nombrarlos a su gusto.
