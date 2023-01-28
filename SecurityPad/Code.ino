// Servo - Version: Latest 
#include <Servo.h>

// Keypad - Version: Latest
#include <Keypad.h>

#define servoPin 10
#define length 5
//macros

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

char Input[length + 1]; // to avoid artifacts in while loop
char Key; //Key input by user
String ans = "237AA"; // answer code
String master; // conversion input to string 
int pos = 0; // count in loop 

//initialize an instance of class Keypad
Keypad INKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
//initialize a servo
Servo myservo;

void setup(){
  Serial.begin(9600);
  //Monitor
  
  myservo.attach(servoPin);
  myservo.write(0);
  //Servo motor setup
}
  
void loop(){

while(pos < length && Key != '*') {
    Key = INKeypad.getKey();
    //get Key address
    if(Key) {
      tone(11, 2000, 20);
      delay(10);
      Input[pos] = Key;
      Serial.println(Key);
      Input[pos] = Key;
      pos++;
      delay(10);
      //add user input into character array
  }
}
for(int a = 0; a < length; a++) {
  master.concat(Input[a]);
  Serial.println(master);
  //convert into string
}
  if(master == ans && Key != '*') {
    myservo.write(85);
    delay(3000);
    //correct password and unlocked
}
else {
  for(int i = 0; i < 6; i++) {
    myservo.write(0); 
    // wrong answer and locked
  }
}
pos = 0;
master = "";
Key = ' ';
//reset all cnting variables in loops 

}
