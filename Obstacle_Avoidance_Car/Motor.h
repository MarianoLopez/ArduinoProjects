// motor A
int enA = 3;
int in1 = 9;
int in2 = 8;

// motor B
int enB = 5;
int in3 = 7;
int in4 = 6;

int _speed = 100;

void printIf(String message){
  #ifdef send
      Serial.println(message);
  #endif
}

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
  printIf("go forward!");
}
void _mBack(){
  setMotorsSpeed(_speed);
  motorBackward('A');
  motorBackward('B');
  printIf("go back!");
}
void _mleft(){
  setMotorsSpeed(_speed);
  motorBackward('B');
  motorForward('A');
  printIf("go left!");
}
void _mright(){
  setMotorsSpeed(_speed);
  motorForward('B');
  motorBackward('A');
  printIf("go right!");
}
void _mStop(){
  setMotorsSpeed(0);
  printIf("Stop!");
}



