#include <Servo.h>                                      //HECHO POR NICOLAS MORENO Y MIGUEL ANGEL MELCHOR GALLEGO
#define motorbase 12
#define motorderecha 11
#define motorizquierda 10
#define motorbrazo 9
Servo base;
Servo derecha;
Servo izquierda;
Servo brazo;


void setup() {
  base.attach(motorbase);
  derecha.attach(motorderecha);
  izquierda.attach(motorizquierda);
  brazo.attach(motorbrazo);
  
  brazo.write(0); 
  izquierda.write(50);
  base.write(120);
  delay(1000);
  izquierda.write(30);
  delay(1000);
  derecha.write(140);
  delay(1000);
  brazo.write(90);
  delay(1000);
  derecha.write(85);
  delay(1000);
  izquierda.write(100);
  delay(1000);
  base.write(20);
  delay(1000);
  brazo.write(0);
    
}

void loop() {
  
  
}
