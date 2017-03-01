int Led = 9 ;
int flame = 2; // define the flame sensor interface
 
 
void setup (){
  pinMode (Led, OUTPUT);
  pinMode (flame, INPUT);
  Serial.begin(9600);
}
 
void loop (){
  Serial.println(digitalRead(flame));
  digitalWrite(Led,digitalRead(flame));
  delay(1000);
}
