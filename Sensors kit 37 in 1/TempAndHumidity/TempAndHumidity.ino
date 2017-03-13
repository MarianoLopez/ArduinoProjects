#include <DHT11.h>

int pin=2;
DHT11 dht11(pin);

int err;
float temp, hum;

// Incoming serial data
int data=0;
String retorno;
void setup() {
  Serial.begin(9600);

}

void printSerialData(){
  if((err = dht11.read(hum, temp)) == 0){
    retorno="temp:";
        retorno.concat(String(temp, 2));
        retorno+=",hum:";
        retorno.concat(String(hum, 2));
        Serial.println(retorno);
  }
}

void loop() {
  if(Serial.available()>0){
    String aux = Serial.readString();
    if(aux=="data\n"){
      printSerialData();
    }
  }
}
