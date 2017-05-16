#include "MotorDriver.h"
#include "UltrasonicoDriver.h"
#include "ServoDriver.h"
#include "InfraredDriver.h"

MotorDriver driver;
UltrasonicoDriver ultrasonico;
ServoDriver servo;
InfraredDriver IR;

const int distancia_minima = 25;
int izquierda,centro,derecha;
bool piloto = false;
bool linea = false;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(100);
  
  driver = MotorDriver(3,9,8,5,7,6);//MotorA,in1,in2,MotorB,in3,in4
  ultrasonico = UltrasonicoDriver(A4,A5);//Echo,Trig
  IR = InfraredDriver(12,11,2);//izq, centro, der PINS
  servo = ServoDriver(13);//pin
  servo.setGrados(160,75,0);//grados_izq,grados_centro,grados_derecha
  servo.setGiroDelay(500);//ms
  servo.ir(CENTRO);
}

void loop() {
 if(Serial.available()>0){
    String s =Serial.readString();
    Serial.println(s);
    if(s=="f"){
      driver.adelante();
    }else if(s=="b"){
      driver.atras();
    }else if(s=="l"){
      driver.izquierda();
    }else if(s=="r"){
      driver.derecha();
    }else if(s=="s"){
       driver.frenar();
        piloto=false;     
    }else if(s.indexOf("speed=")!=-1){
      String aux = s.substring(s.indexOf("="));
      int _inicio = aux.indexOf("=");
      driver.setSpeed(aux.substring(_inicio+1).toInt());
    }else if(s=="u"){
      Serial.println(ultrasonico.getDistancia());
    }else if(s=="izq"){
      servo.ir(IZQUIERDA);
    }else if(s=="der"){
      servo.ir(DERECHA);
    }else if(s=="cen"){
      servo.ir(CENTRO);
    }else if(s=="piloto"){
      piloto=!piloto;
      if(!piloto){driver.frenar();}
    }else if(s=="linea"){
      linea=!linea;
      if(!linea){driver.frenar();}
      }
  }else{//data no available
    pilotoAutomatico(piloto);
    Line(linea);
  }
}

void pilotoAutomatico(bool _piloto){
  if(_piloto){
    servo.ir(CENTRO);
    centro = ultrasonico.getDistancia();
    
    if(centro<=distancia_minima){     
      driver.frenar();
      
      servo.ir(DERECHA);
      derecha = ultrasonico.getDistancia();
      
      servo.ir(IZQUIERDA);
      izquierda = ultrasonico.getDistancia();
      servo.ir(CENTRO);
      /*Serial.print(izquierda);
      Serial.print(" - ");
      Serial.print(centro);
      Serial.print(" - ");
      Serial.println(derecha);*/
      if(derecha>izquierda)  {
        driver.derecha();
       }else if(derecha<izquierda){
        driver.izquierda();
       }else if((derecha<=distancia_minima)||(izquierda<=distancia_minima)){
        driver.atras();
       }
       
    }else{
      driver.adelante();                    
    }
  }//if piloto
}

//seguir
void Line(bool _linea) {
  //0=negro, 1=blanco
  if(_linea){
    if(IR.isIzquierda()&&IR.isCentro()&&!IR.isDerecha()){ //110
      driver.izquierda();
    }else if(!IR.isIzquierda()&&IR.isCentro()&&IR.isDerecha()){//011
      driver.derecha();
    }else if(!IR.isIzquierda()&&IR.isCentro()&&!IR.isDerecha()){//010
      driver.adelante();
    }else if(!IR.isIzquierda()&&!IR.isCentro()&&!IR.isDerecha()){//000
      driver.izquierda();
    }else if(IR.isIzquierda()&&IR.isCentro()&&IR.isDerecha()){//111  
      driver.frenar();
    }else if(!IR.isIzquierda()&&!IR.isCentro()&&IR.isDerecha()){
      driver.derecha();
    }
  }
}
