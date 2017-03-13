#include <DHT11.h>

int pin=2;
DHT11 dht11(pin);
int flame = 3; // define the flame sensor interface
int err;
float temp, hum;

String retorno,aux;
void setup() {
  pinMode(pin,INPUT);
  pinMode(flame,INPUT);
  Serial.begin(9600);

}

void printSerialData(){
  if((err = dht11.read(hum, temp)) == 0){
    retorno="temp:";
        retorno.concat(String(temp, 2));
        retorno+=",hum:";
        retorno.concat(String(hum, 2));
        retorno+=",flame:";
        retorno.concat(digitalRead(flame));
        Serial.println(retorno);
  }
}

void loop() {
  if(Serial.available()>0){
    aux = Serial.readString();
    if(aux=="data\n"){
      printSerialData();
    }
  }
}
