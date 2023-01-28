// IRremote - Version: Latest 
#include <IRremote.hpp>

// LiquidCrystal - Version: Latest 
#include <LiquidCrystal.h>

#define wait 10
#define margin 0.2
//macros

boolean chck = false;
unsigned int sensL;
float BaseL;
//finding the base voltage 

const int RECPIN = 13;
const int sensorPin = A0; 
//Sensor and analog pins

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
float cnt = 0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//LCD variables and pins 

IRrecv irrecv(RECPIN);
decode_results results;
//define which pin shall be receiving & decoding the results

void setup() {
  
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Time:  ");
  //Setting up the timer (LCD).
  
  irrecv.enableIRIn();
  //Allow IR input into the transceiver
  
  }

void loop() {
    
  if(chck == true) {
    int sensorVal = analogRead(sensorPin);
    float voltage = (sensorVal/1024.0) * 5.0;
    //Calculate voltage
  
    Serial.print("Voltage:  ");
    Serial.print(voltage);
    Serial.println(); 
    //monitor analog variables.
  
  if(irrecv.decode(&results) && results.value == 0xFF38C7) { // change depending on your IR remote address.
    Serial.println(results.value, HEX);
    //check what button is pressed
     
  while (voltage + margin >= BaseL) {
    lcd.setCursor(0,1);
    lcd.print(cnt++/100);
    delay(wait);
    // the laser hasent been crossed
    
    sensorVal = analogRead(sensorPin);
    voltage = (sensorVal/1024.0) * 5.0;
    // check before continuing loop
    
  }
  cnt = 0.00;
  //reinitilize the script  
  } 
  irrecv.resume();
  delay(wait); 
} 
  else {
  BaseL = analogRead(sensorPin)/1024.0*5;
  Serial.print("Init:  ");
  Serial.println(BaseL);
  chck = true;
  //scan for a baseline light level.
  }
}

