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

void loop() {
  if((err = dht11.read(hum, temp)) == 0){
    retorno="temp:";
        retorno.concat(String(temp, 2));
        retorno+=",hum:";
        retorno.concat(String(hum, 2));
        Serial.println(retorno);
  }
  delay(2000);
}
