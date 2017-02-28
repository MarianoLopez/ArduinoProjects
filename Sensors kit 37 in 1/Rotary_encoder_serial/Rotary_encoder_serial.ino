 #define outputA 6
 #define outputB 7

 int counter = 0; 
 int aState;
 int aLastState;  
 int maximo = 100;
 int minimo = 0;

 void setup() { 
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   Serial.begin (9600);
   aLastState = digitalRead(outputA);    // Reads the initial state of the outputA
 } 

 void loop() { 
   aState = digitalRead(outputA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aState != aLastState){
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputB) != aState) { 
        if(counter<maximo){counter ++;}
     } else {
       if(counter>minimo){counter --;}
     }
     Serial.print("Position: ");
     Serial.println(counter);
   } 
   aLastState = aState; // Updates the previous state of the outputA with the current state
 }
