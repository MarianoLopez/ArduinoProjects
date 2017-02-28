// motor A
int enA = 3;
int in1 = 9;
int in2 = 8;

// motor B
int enB = 5;
int in3 = 7;
int in4 = 6;

int _speed = 130;

void setMotorsSpeed(int _sp){
  analogWrite(enA,_sp);
  analogWrite(enB,_sp);
}

void motorForward(char motor){
  if(motor=='A'){
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW); 
  }else{
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);  
  }
}


void motorBackward(char motor){
  if(motor=='A'){
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);  
  }else{
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
  } 
}

void _mForward(){ 
  setMotorsSpeed(_speed);
  motorForward('A');
  motorForward('B');
  Serial.println("go forward!");
}
void _mBack(){
  setMotorsSpeed(_speed);
  motorBackward('A');
  motorBackward('B');
  Serial.println("go back!");
}
void _mleft(){
  setMotorsSpeed(_speed-10);
  motorBackward('B');
  motorForward('A');
  Serial.println("go left!");
}
void _mright(){
  setMotorsSpeed(_speed-10);
  motorForward('B');
  motorBackward('A');
  Serial.println("go right!");
}
void _mStop(){
  setMotorsSpeed(0);
  Serial.println("Stop!");
}

