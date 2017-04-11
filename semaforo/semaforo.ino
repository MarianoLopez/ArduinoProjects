

const int rojo = 3;
const int amarillo = 4;
const int verde = 5;


void setup() {
  pinMode(rojo, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(verde, OUTPUT);
  }

// the loop function runs over and over again forever
void loop() {
  semaforo();
}

void semaforo() {
  luz(rojo, 25);
  luz(amarillo, 5);
  luz(verde, 25);
  blinky(verde, 5);  
}

void luz(int led, int tiempo) {
  digitalWrite(led, HIGH);
  delay(tiempo*1000);
  digitalWrite(led, LOW);
  }


void blinky(int led, int t)  {
  for (int i=0; i<t; i++) {
  luz(led, 1);
  delay(1000);
  }
}
