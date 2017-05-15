class MotorDriver{
  private:
    int motorA, motorB;
    int in1,in2,in3,in4,_speed;
    boolean mensajes;
    void init(){
      pinMode(in1,OUTPUT);pinMode(in2,OUTPUT);
      pinMode(in3,OUTPUT);pinMode(in4,OUTPUT);
      pinMode(motorA, OUTPUT);pinMode(motorB, OUTPUT);
    }
    void setMotorsSpeed(){
       int aux = getSpeed();
       if(_speed!=0){aux+=40;}//fix dx
       printIf("Motor speed: "+getSpeed());
       analogWrite(motorA,getSpeed());
       analogWrite(motorB,aux);
    }
    void printIf(String message){if(mensajes){Serial.println(message);}}
    
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

  public:
    MotorDriver(){}
    MotorDriver(int enA,int i1,int i2,int enB,int i3,int i4){
      motorA = enA;
      motorB = enB;
      in1 = i1;
      in2 = i2;
      in3 = i3;
      in4 = i4;
      _speed = 100;
      mensajes = false;
      init();
    }
    void enableMensajes(){mensajes = true;}
    void disableMensajes(){mensajes = false;}
    void setSpeed(int s){_speed = s;}
    int getSpeed(){return _speed;}

    void forward(){ 
      setMotorsSpeed();
      motorForward('A');
      motorForward('B');
      printIf("go forward!");
    }
    void back(){
      setMotorsSpeed();
      motorBackward('A');
      motorBackward('B');
      printIf("go back!");
    }
    void left(){
      setMotorsSpeed();
      motorBackward('B');
      motorForward('A');
      printIf("go left!");
    }
    void right(){
      setMotorsSpeed();
      motorForward('B');
      motorBackward('A');
      printIf("go right!");
    }
    void stop(){
      int aux = getSpeed();
      setSpeed(0);
      setMotorsSpeed();
      setSpeed(aux);
      printIf("Stop!");
    }
};

