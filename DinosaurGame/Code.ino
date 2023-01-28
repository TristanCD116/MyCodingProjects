// Servo - Version: Latest 
#include <Servo.h>

#define pressed LOW
#define margin 5
#define wait 100
//macros

const byte sensorPinup = A7;
const byte Button = 2;
//detection

const byte servoPin = 5;
Servo myservo;
//servo

unsigned int baseLine; 
boolean calibrated = false; //avoid premature activaions 
int switchState = 1; //open (pullup resistor);

void setup() {
  Serial.begin(9600); // start serial port
  while(!Serial) { //wait 
    ; }
  pinMode(Button, INPUT); //calibration button
  myservo.attach(servoPin);
  myservo.write(100);
  //servo position 
}

void loop() {
  switchState = digitalRead(Button);
  Calibration(switchState);
  //for baseline
  
  if(calibrated == true) {
    
    myservo.write(100); // reset servo pos
    if(abs(analogRead(sensorPinup) - baseLine) > margin) { // measure difference in values
      myservo.write(75); //press spacebar
    }
  delay(wait);// give servo time to move
  }
}
bool Calibration(int switchState) {
  if(switchState == pressed) {
    baseLine = analogRead(sensorPinup);
    Serial.println("Calibrated!");
    Serial.print(baseLine); // print values
    calibrated = true; // begin cactus detection
  }
} 
