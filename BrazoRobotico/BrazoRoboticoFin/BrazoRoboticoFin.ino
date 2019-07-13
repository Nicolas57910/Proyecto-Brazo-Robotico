/*Hecho por: Nicolás Moreno Rincón
 *           Miguel Ángel Melchor Gallego
 */
#include <Servo.h>
  Servo base;
  Servo derecha;
  Servo izquierda;
  Servo garra;
  char valor;
  String estado;
  int angulo;
  int d,i,b,g;
void setup() {
   base.attach(12);
  derecha.attach(11);
  izquierda.attach(10);
  garra.attach(9);
  base.write(0);
  derecha.write(0),
  izquierda.write(90);
  garra.write (0);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){
    if(Serial.available()<180){
    valor=Serial.read();

    if (valor=='B'){
      angulo=Serial.parseInt();
       base.write(angulo);    
    }
    if (valor=='D'){
      angulo=Serial.parseInt();
       derecha.write(angulo);    
    }
    if (valor=='I'){
      angulo=Serial.parseInt();
       izquierda.write(angulo);    
    }
    if (valor=='G'){
      angulo=Serial.parseInt();
      if(angulo<55 ||angulo>0){
       garra.write(angulo);    
      }
    }
    if (valor== 'A')
    {
      servob(); 
    }
    if (valor== 'Q')
    {
      servod(); 
    }
    if (valor== 'C')
    {
      servoi(); 
    }
    if(valor== 'M')
    {
      servoga();
    }
    if(valor== 'E')
    {
      servogc();
    }   
    if(valor=='P')
    {
      automatico();
    }
    }
  }
}
void servob()
{
  delay(30);
  while (Serial.available())
  {
    char c=Serial.read();
    estado += c;
  }
  if (estado.length()>0)
  {
    base.write(estado.toInt());
    estado="";
  }
}

void servod()
{
  delay(30);
  while (Serial.available())
  {
    char c=Serial.read();
    estado += c;
  }
  if (estado.length()>0)
  {
    derecha.write(estado.toInt());
    estado="";
  }
}

void servoi()
{
  delay(30);
  while (Serial.available())
  {
    char c=Serial.read();
    estado += c;
  }
  if (estado.length()>0)
  {
    izquierda.write(estado.toInt());
    estado="";
  }
}

void servoga()
{
  delay(30);
  garra.write(0);
}
void servogc()
{
  delay(30);
  garra.write(55);
}

void automatico(){
   g=b=d=i=0;
   garra.write(0);
  base.write(0);
  derecha.write(0);
  izquierda.write(0);
  while(d<120){                 //IR POR PTIMER CUBO
      d=d+10;
      derecha.write(d);
      delay(150);
  }
  while(i<40){
      i=i+10;
      izquierda.write(i);
      delay(150);
  }
  while(b<103){
      if(b==100){
         b=b+3;
      }else{
         b=b+10;
      }
      base.write(b);
      delay(120);
  }
  
      garra.write(55);
      delay(500);
  while(d>90){
      d=d-10;
      derecha.write(d);        //LLEVA PRIMER CUBO
      delay(150);
  }
  while(b<180){
    b=b+10;
    base.write(b); 
    delay(100);
  }
  while(d>30){
    d=d-10;
    derecha.write(d);
    delay(100);
  }
  garra.write(0);
}
