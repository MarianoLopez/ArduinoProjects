#include "Motor.h"
void setup() {
  Serial.begin(9600);     
  //Motor.h
  pinMode(in1,OUTPUT);pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);pinMode(in4,OUTPUT);
  pinMode(enA, OUTPUT);pinMode(enB, OUTPUT);
  _mStop();
}

void loop() {
  Line();

}

//seguir
void Line() {
    int izq,frente,der;
    izq=digitalRead(12);    
    frente=digitalRead(11);
    der=digitalRead(2); 
    //delay(3000);
    if(izq&&frente&&!der){
      _mleft(); //110
    }else if(!izq&&frente&&der){
      _mright();//011
    }else if(!izq&&frente&&!der){
      _mForward();//010
    }else if(!izq&&!frente&&!der){
      _mleft();//000
    }else if(izq&&frente&&der){
      _mStop();//111  
    }else if(!izq&&!frente&&der){
      _mright();
    }else if(!izq&&!frente&&der){
      _mright();//001
    }else if(izq&&!frente&&!der){
      _mleft();//100
    }
}
