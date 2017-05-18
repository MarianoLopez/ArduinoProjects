#include "Semaforo.h"
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

//                     Addr, En, Rw, Rs, d4, d5, d6, d7
LiquidCrystal_I2C lcd( 0x27, 2, 1, 0, 4, 5, 6, 7);
Semaforo semaforo,semaforo2,semaforo3,semaforo4;
int contador;
int semaforo_activo = 1;

int RED_GREEN_SEC_WAIT = 23;
int YELLOW_SEC_WAIT = 2;
int GREEN_SEC_BLINK = 5;

void setup() {
  Serial.begin(9600);
  semaforo  = Semaforo(1,2,3,4);
  semaforo2 = Semaforo(2,5,6,7);
  semaforo3 = Semaforo(3,8,9,10);
  semaforo4 = Semaforo(4,11,12,13);
  semaforo.enableMessages();//imprime los estados de los pins por serial
  semaforo2.enableMessages();
  semaforo3.enableMessages();
  semaforo4.enableMessages();
  initLCD();
  semaforo.turnLedOn(RED_LED);
  semaforo2.turnLedOn(RED_LED);
  semaforo3.turnLedOn(RED_LED);
  semaforo4.turnLedOn(RED_LED);
  contador = RED_GREEN_SEC_WAIT+GREEN_SEC_BLINK+YELLOW_SEC_WAIT;
 // todo();
}

void turnSemaforo(Semaforo s,Semaforo prox){
  semaforo_activo = s.getId();
  s.turnLedOn(GREEN_LED);
  wait(RED_GREEN_SEC_WAIT);//5
  
  blinky(s,GREEN_SEC_BLINK);//parpadeo + espera 5
  
  s.turnLedOn(YELLOW_LED);
  prox.turnLedOn(YELLOW_LED);
  wait(YELLOW_SEC_WAIT); //2
  
  s.turnLedOn(RED_LED);
  contador = RED_GREEN_SEC_WAIT+GREEN_SEC_BLINK+YELLOW_SEC_WAIT;//sec
}

void todo(){
  semaforo.turnAll();
  semaforo2.turnAll();
  semaforo3.turnAll();
  semaforo4.turnAll();
}

void loop() {
  turnSemaforo(semaforo,semaforo2);
  turnSemaforo(semaforo2,semaforo3);
  turnSemaforo(semaforo3,semaforo4);
  turnSemaforo(semaforo4,semaforo);
}

void blinky(Semaforo &s,int &sec){
  for(int i=0;i<sec;i++){
    refresh();
    s.turnLedOn(GREEN_LED);  
    delay(500);
    s.turnLedOff(GREEN_LED);  
    delay(500);
  }
}
void wait(int secs){
  for(int i=0;i<secs;i++){
    refresh();
    delay(1000);
  }
}

void refresh(){
  Serial.print("No cruzar por: ");Serial.println("Semáforo"+String(semaforo_activo)+": "+String(contador));//Serial
  lcd.clear();lcd.home();lcd.print("No cruzar por: ");lcd.setCursor(0,1);lcd.print("Semaforo "+String(semaforo_activo)+": "+String(contador));//LCD
  contador-=1;
}


void initLCD(){
 lcd.begin (16,2);    // Inicializar el display con 16 caraceres 2 lineas
 lcd.setBacklightPin(3,POSITIVE);
 lcd.setBacklight(HIGH);
 delay(10);
 lcd.home ();                   // go home
 lcd.print(" ");
 lcd.setCursor ( 0, 1 );        // go to the 2nd line
 lcd.print(" "); 
}




