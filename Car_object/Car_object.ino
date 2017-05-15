#include "MotorDriver.h"
#include "Ultrasonico.h"
MotorDriver driver;
Ultrasonico ultrasonico;
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(100);
  driver = MotorDriver(3,9,8,5,7,6);//MotorA,in1,in2,MotorB,in3,in4
  //ultrasonico = Ultrasonico(A4,A5);//Echo,Trig
}

void loop() {
  if(Serial.available()>0){
    String s =Serial.readString();
    Serial.println(s);
    if(s=="f"){
      driver.forward();
    }
    else if(s=="b"){
      driver.back();
    }
    else if(s=="l"){
      driver.left();
    }
    else if(s=="r"){
      driver.right();
    }
    else if(s=="s"){
       driver.stop();     
    }else if(s.indexOf("speed=")!=-1){
      String aux = s.substring(s.indexOf("="));
      int _inicio = aux.indexOf("=");
      driver.setSpeed(aux.substring(_inicio+1).toInt());
    }else if(s=="u"){
      //Serial.println(ultrasonico.getDistance());
    }
  }

}
