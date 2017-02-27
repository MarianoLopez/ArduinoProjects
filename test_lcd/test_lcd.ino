#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

//                     Addr, En, Rw, Rs, d4, d5, d6, d7
LiquidCrystal_I2C lcd( 0x27, 2, 1, 0, 4, 5, 6, 7);


void setup(){
       lcd.begin (16,2);    // Inicializar el display con 16 caraceres 2 lineas
       lcd.setBacklightPin(3,POSITIVE);
       lcd.setBacklight(HIGH);
       delay(10);
       lcd.home ();                   // go home
       lcd.print("Hello World");
       lcd.setCursor ( 0, 1 );        // go to the 2nd line
       lcd.print("Hola Mundo"); 
}


void loop(){

}
