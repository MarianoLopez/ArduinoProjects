#include <Servo.h>
#define send true;//para imprimir mensajes

Servo rotacion; // create servo object to control servo
Servo principal;
Servo secundario;
Servo terminal;
//And Arrays For All....
int pin_servos[] = {9,10,11,8};
String s_servos[] = {"rotacion","principal", "secundario", "terminal"};
Servo servos[] = {rotacion,principal,secundario,terminal};
int min_servos[] = {0,40,60,30};
int max_servos[] = {180,140,135,180};

void setup() {
  for(int i=0;i<4;i++){servos[i].attach(pin_servos[i]);}
  Serial.begin(9600);     
  Serial.setTimeout(500);
  initServos();
}

void initServos(){
  writeServo(0,90);//rotación
  writeServo(1,50);//principal
  writeServo(2,120);//secundario
  writeServo(3,30);//terminal
}

int getValueFromString(String s,String needle){
  String aux = "";
  int intValue = 0;
  if(s.indexOf(needle+"=")!=-1){
    aux = s.substring(s.indexOf("="));
    intValue = aux.substring(aux.indexOf("=")+1).toInt();
  }
  return intValue;
}

void writeServo(int i, int value){
  if(value < min_servos[i]){
   value = min_servos[i]; 
  }else if(value > max_servos[i]){
   value = max_servos[i]; 
  }
  #ifdef send
    Serial.print(s_servos[i]);Serial.print(": ");Serial.println(value);
  #endif
  servos[i].write(value); 
}

void loop() {
  if(Serial.available()>0){
    String s = Serial.readString();
    int value = 0;
    for(int i=0;i<4;i++){
      if(s.indexOf(s_servos[i])!=-1){
        value = getValueFromString(s,s_servos[i]);  
        writeServo(i,value);
      }
    }
  }
}
