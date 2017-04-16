#include "Semaforo.h"
Semaforo semaforo("semaforo 1",3,4,5);
Semaforo semaforo2("semaforo 2",8,9,10);
int contador;

void setup() {
  Serial.begin(9600);
  semaforo.enableMessages();//imprime los estados de los pins por serial
  semaforo2.enableMessages();
  delay(1000);
}

void loop() {
  contador = 60;//1min
  semaforo.turnLedOn(RED_LED);
  semaforo2.turnLedOn(GREEN_LED);
  wait(28);
  
  semaforo.turnLedOn(YELLOW_LED);
  semaforo2.turnLedOn(YELLOW_LED);
  wait(2);

  semaforo.turnLedOn(GREEN_LED);
  semaforo2.turnLedOn(RED_LED);
  wait(23);
  //parpadeo
  for(int i=0;i<5;i++){
    semaforo.turnLedOn(GREEN_LED);  
    wait(1);
    semaforo.turnLedOff(GREEN_LED);  
  }
  
  semaforo.turnLedOn(YELLOW_LED);
  semaforo2.turnLedOn(YELLOW_LED);
  wait(2);
}

void wait(int secs){
  for(int i=0;i<secs;i++){
    Serial.println(contador);
    delay(1000);
    contador-=1;
  }
}


