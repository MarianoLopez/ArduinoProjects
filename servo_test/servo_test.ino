#include <Servo.h>
Servo myservo; // create servo object to control servo

void setup() {
  myservo.attach(13);// attach servo on pin 3 to servo object
  Serial.begin(9600);     
  Serial.setTimeout(500);
}

void loop() {
  int aux;
  if(Serial.available()>0){    
    aux = Serial.readString().toInt();
    Serial.print("Servo:");
    Serial.println(aux);
    myservo.write(aux);
  }
  delay(1000);
}





