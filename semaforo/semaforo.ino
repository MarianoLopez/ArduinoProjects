#include "Semaforo.h"
Semaforo semaforo(3,4,5);
Semaforo semaforo2(8,9,10);

void setup() {}

// the loop function runs over and over again forever
void loop() {
  semaforos();
}

void semaforos() {
  /*luz(semaforo.getRedLed(), 25);
  luz(semaforo.getYellowLed(), 5);
  luz(semaforo.getGreenLed(), 25);
  blinky(semaforo.getGreenLed(), 5);  
  luz(semaforo.getYellowLed(), 5);*/

  luzSync(semaforo.getRedLed(),semaforo2.getGreenLed(), 25);
  blinkySync(semaforo2.getGreenLed(),semaforo.getRedLed(), 5);  
  
  luzSync(semaforo.getYellowLed(),semaforo2.getYellowLed(), 5);
  
  luzSync(semaforo.getGreenLed(),semaforo2.getRedLed(), 25);
  blinkySync(semaforo.getGreenLed(),semaforo2.getRedLed(), 5);  
  
  luzSync(semaforo.getYellowLed(),semaforo2.getYellowLed(), 5);
}

void luz(int led, int tiempo) {
  digitalWrite(led, HIGH);
  delay(tiempo*1000);
  digitalWrite(led, LOW);
  }

  void luzSync(int led,int led2, int tiempo) {
  digitalWrite(led, HIGH);digitalWrite(led2, HIGH);
  delay(tiempo*1000);
  digitalWrite(led, LOW);digitalWrite(led2, LOW);
  }


void blinky(int led, int t)  {
  for (int i=0; i<t; i++) {
    luz(led, 1);
    delay(1000);
  }
}

void blinkySync(int led, int t,int led2)  {
  digitalWrite(led2, HIGH);
  for (int i=0; i<t; i++) {
    luz(led, 1);
    delay(1000);
  }
  digitalWrite(led2, LOW);
}
