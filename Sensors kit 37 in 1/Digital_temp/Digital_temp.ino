#include <math.h>
int sensorPin = A5;
 
void setup() {
 Serial.begin(9600);
}
 
void loop() {
 double temp =  toCelcius(analogRead(sensorPin));
 Serial.println(temp);
 delay(1000);
}

double toKelvin(int value){
  double temp;
  temp = log(10000.0 * ((1024.0 / value - 1)));
  temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * temp * temp )) * temp);
  return temp;
}

double toCelcius(int value){
  double temp;
  temp = toKelvin(value);
  temp = temp - 273.15;

  return temp;
}

