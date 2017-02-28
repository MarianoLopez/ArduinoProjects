int Echo = A4;  
int Trig = A5; 

int rightDistance = 0,leftDistance = 0,middleDistance = 0 ;

 /*Ultrasonic distance measurement Sub function*/
int Distance_test(){
  digitalWrite(Trig, LOW);   
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  
  delayMicroseconds(20);
  digitalWrite(Trig, LOW);   
  float Fdistance = pulseIn(Echo, HIGH);  
  Fdistance= Fdistance/58;       
  return (int)Fdistance;
}
