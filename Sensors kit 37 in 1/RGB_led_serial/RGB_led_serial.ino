// pins for the LEDs:
const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;

int red, green, blue; //valores

//descomenar en caso de usar common Anode LED
//#define COMMON_ANODE

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // make the pins outputs:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

}

void loop() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {

    // look for the next valid integer in the incoming serial stream:
    red = Serial.parseInt();
    green = Serial.parseInt();
    blue = Serial.parseInt();

    // look for the newline. That's the end of your sentence:
    if (Serial.read() == '\n') {
      setColor(red,green,blue);
      // print the three numbers in one string as hexadecimal:
      Serial.print("#");
      Serial.print(red,HEX);
      Serial.print(green,HEX);
      Serial.println(blue,HEX);
    }
  }
}

void setColor(int r, int g, int b){
  #ifdef COMMON_ANODE
    r = 255 - r;
    g = 255 - g;
    b = 255 - b;
  #endif
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}








