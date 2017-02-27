#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <DHT11.h>

//                     Addr, En, Rw, Rs, d4, d5, d6, d7
LiquidCrystal_I2C lcd( 0x27, 2, 1, 0, 4, 5, 6, 7);


int sensor = 7;
DHT11 dht11(sensor);
int err;
float temp, hum;

void setup(){
       Serial.begin(9600);
       lcd.begin (16,2);    // Inicializar el display con 16 caraceres 2 lineas
       lcd.setBacklightPin(3,POSITIVE);
       lcd.setBacklight(HIGH);
       delay(10);
   }

void loop(){
       // Si devuelve 0 es que ha leido bien
       if((err = dht11.read(hum, temp)) == 0){
             Serial.print("Temperatura: ");
             Serial.print(temp);
             Serial.print(" Humedad: ");
             Serial.print(hum);
             Serial.println();
             lcd.home ();                   // go home
             lcd.print("Temp: ");
             lcd.setCursor (6, 0 );
             lcd.print(temp);
             lcd.setCursor ( 0, 1 );        // go to the 2nd line
             lcd.print("Humedad: ");
             lcd.setCursor (9, 1 );
             lcd.print(hum);
          }else{
             Serial.println();
             Serial.print("Error Num :");
             Serial.print(err);
             Serial.println();
          }
       delay(1000);            //Recordad que solo lee una vez por segundo
   }
