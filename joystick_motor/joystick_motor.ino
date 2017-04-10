//definicion de pins
const int motorPin1 = 12;    // 28BYJ48 In1
const int motorPin2 = 11;    // 28BYJ48 In2
const int motorPin3 = 10;   // 28BYJ48 In3
const int motorPin4 = 9;   // 28BYJ48 In4

const int motor2Pin1 = 7;    // 28BYJ48 In1
const int motor2Pin2 = 6;    // 28BYJ48 In2
const int motor2Pin3 = 5;   // 28BYJ48 In3
const int motor2Pin4 = 4;   // 28BYJ48 In4

//definicion variables
int motorSpeed = 800;   //variable para fijar la velocidad
int stepCounter = 0;     // contador para los pasos
int stepCounter2 = 0;     // contador para los pasos
int stepsPerRev = 4076;  // pasos para una vuelta completa


//secuencia media fase
const int numSteps = 8;
const int stepsLookup[8] = { B1000, B1100, B0100, B0110, B0010, B0011, B0001, B1001 };
bool motorDone = true;

int laser = 2;

int JoyStick_X = A0; // x
int JoyStick_Y = A1; // y
int JoyStick_Z = 3; // key
int x, y, z;
int y_aux =510;
bool izq,der,arr,abj,btn = false;

void setup (){
  pinMode (JoyStick_X, INPUT);
  pinMode (JoyStick_Y, INPUT);
  pinMode (JoyStick_Z, INPUT_PULLUP);
  pinMode(laser,OUTPUT);

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(motor2Pin3, OUTPUT);
  pinMode(motor2Pin4, OUTPUT);
        
  Serial.begin (9600); // 9600 bps
}

void down(){
  for (int i = 0; i < stepsPerRev/6 ; i++){
    clockwise();
    delayMicroseconds(motorSpeed);
  }
}

void up(){
  for (int i = 0; i < stepsPerRev/6; i++){
    anticlockwise();
    delayMicroseconds(motorSpeed);
  }
}

void right(){
  for (int i = 0; i < stepsPerRev/6; i++){
    anticlockwise2();
    delayMicroseconds(motorSpeed);
  }
}

void left(){
  for (int i = 0; i < stepsPerRev/6 ; i++){
    clockwise2();
    delayMicroseconds(motorSpeed);
  }
}
void loop (){
  
        x = analogRead (JoyStick_X);
        y = analogRead (JoyStick_Y);
        z = digitalRead (JoyStick_Z);
                
        
        if(y>=501  && y<= 515){
          //centro
        }else if(y<=500 && y>=0){
          up();
        }else{
          down();
        }
        
        
        //if(z==0){btn=!btn;digitalWrite(laser,btn);}
       digitalWrite(laser,z);
      
        if(x>=501 && x<=515){
            izq = false;
            der = false;
        }else if(x<=500 && x>=0){
          izq = true;
          der = false;
          left();
        }else{
          izq = false;
          der = true;
          right();
        }
      

 
}

void clockwise(){
  stepCounter++;
  if (stepCounter >= numSteps) stepCounter = 0;
  setOutput(stepCounter);
}
 
void anticlockwise(){
  stepCounter--;
  if (stepCounter < 0) stepCounter = numSteps - 1;
  setOutput(stepCounter);
}
 
void setOutput(int step){
  digitalWrite(motorPin1, bitRead(stepsLookup[step], 0));
  digitalWrite(motorPin2, bitRead(stepsLookup[step], 1));
  digitalWrite(motorPin3, bitRead(stepsLookup[step], 2));
  digitalWrite(motorPin4, bitRead(stepsLookup[step], 3));
}
void clockwise2(){
  stepCounter2++;
  if (stepCounter2 >= numSteps) stepCounter2 = 0;
  setOutput2(stepCounter2);
}
 
void anticlockwise2(){
  stepCounter2--;
  if (stepCounter2 < 0) stepCounter2 = numSteps - 1;
  setOutput2(stepCounter2);
}
void setOutput2(int step){
  digitalWrite(motor2Pin1, bitRead(stepsLookup[step], 0));
  digitalWrite(motor2Pin2, bitRead(stepsLookup[step], 1));
  digitalWrite(motor2Pin3, bitRead(stepsLookup[step], 2));
  digitalWrite(motor2Pin4, bitRead(stepsLookup[step], 3));
}

