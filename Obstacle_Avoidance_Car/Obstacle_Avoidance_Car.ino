#include "Motor.h"
#include "Ultrasonico.h"
#include "Servo.h"

#define send false;//para imprimir mensajes

int _speed;//motor
const int distancia_minima = 50;
int Servodelay = 500;
bool piloto = false;
bool linea = false;
//int tiempo_giro = 0;

void setup() { 
  myservo.attach(13);// Servo.h
  Serial.begin(9600);     
  Serial.setTimeout(100);
  pinMode(Echo, INPUT);pinMode(Trig, OUTPUT);  //ver Ultrasonico.h
  //Motor.h
  pinMode(in1,OUTPUT);pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);pinMode(in4,OUTPUT);
  pinMode(enA, OUTPUT);pinMode(enB, OUTPUT);
  _mStop();
  _speed=100;
} 

void printIf(String message, int value){
  #ifdef send
      Serial.print(message);
      Serial.println(value);
  #endif
}

void pilotoAutomatico(bool _piloto){
  if(_piloto){
    myservo.write(frente);//setservo position according to scaled value
    delay(Servodelay); 
    middleDistance = Distance_test();
    printIf("middleDistance=",middleDistance);
    if(middleDistance<=distancia_minima){     
      _mStop();
      myservo.write(derecha);          
      delay(Servodelay);      
      rightDistance = Distance_test();
      printIf("rightDistance=",rightDistance);
  
      myservo.write(izquierda);              
      delay(Servodelay); 
      leftDistance = Distance_test();
      printIf("leftDistance=",leftDistance);
  
      myservo.write(frente);              
      if(rightDistance>leftDistance)  {
        _mright(_speed);
       // delay(tiempo_giro);
       }else if(rightDistance<leftDistance){
        _mleft(_speed);
       // delay(tiempo_giro);
       }else if((rightDistance<=distancia_minima)||(leftDistance<=distancia_minima)){
        _mBack(_speed);
       }
    }else{
      _mForward(_speed);                     
    }
  }
}

void loop() {
  pilotoAutomatico(piloto);
  Line(linea); 
  if(Serial.available()>0){
    //Serial.println("reading");
    String s =Serial.readString();
    Serial.println(s);
    if(s=="f"){
      _mForward(_speed);
    }
    else if(s=="b"){
      _mBack(_speed);
    }
    else if(s=="l"){
      _mleft(_speed);
    }
    else if(s=="r"){
      _mright(_speed);
    }
    else if(s=="s"){
       _mStop();     
       piloto=false;
       linea=false;
    }else if(s.indexOf("speed=")!=-1){
      String aux = s.substring(s.indexOf("="));
      int _inicio = aux.indexOf("=");
      _speed = aux.substring(_inicio+1).toInt();
      printIf("Motor speed: ",_speed);
      //setMotorsSpeed(_speed);
    }
    else if(s=="piloto"){
      piloto=!piloto;
      if(!piloto){_mStop();}
    }else if(s=="linea"){
      linea=!linea;
      if(!linea){_mStop();}
    }
  }
}



//seguir
void Line(bool _linea) {
  if(_linea){
    int izq,frente,der;
    izq=digitalRead(12);    
    frente=digitalRead(11);
    der=digitalRead(2); 
    /*Serial.print(izq);
    Serial.print(frente);
    Serial.println(der);*/
    //delay(3000);
    if(izq&&frente&&!der){
      _mleft(_speed); //110
    }else if(!izq&&frente&&der){
      _mright(_speed);//011
    }else if(!izq&&frente&&!der){
      _mForward(_speed);//010
    }else if(!izq&&!frente&&!der){
      _mleft(_speed);//000
    }else if(izq&&frente&&der){
      _mStop();//111  
    }else if(!izq&&!frente&&der){
      _mright(_speed);
    }
  }
}

