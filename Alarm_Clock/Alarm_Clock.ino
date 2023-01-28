#include <LCD_I2C.h>
//download necessary libraries

#define pressed HIGH
#define wait 170
//macros

LCD_I2C lcd(0x27, 16, 2);

unsigned long preMillis = 0;
const long INTERVAL = 60000; //1 minute
char str[8];
int m, h = 0;
//clock functionality


boolean alarmOn = false;
const char alarm[6] = "06:10"; //can be changed 
//alarm functionality
//local variables

//custom characters for seven segment display lcd
byte lineR[8] =
{
  B00111,
  B00111,
  B00111,
  B00111,
  B00111,
  B00111,
  B00111,
  B00111
};

byte lineL[8] =
{
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100
};

byte lineU[8] =
{
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte lineD[8] =
{
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111
};

byte lineM[8] =
{
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111
};

byte dot[8] =
{
  B00000,
  B00000,
  B00100,
  B01110,
  B01110,
  B00100,
  B00000,
  B00000
};

byte Alarm[8] =
{
  B00000,
  B01110,
  B10101,
  B10111,
  B10001,
  B01110,
  B00000,
  B00000
};

void setup()
{
  Serial.begin(9600);
  while (!Serial) {
    ;
  } //wait for the port to connect
  lcd.begin();
  lcd.backlight();
  lcd.leftToRight();
  lcd.setCursor(0, 0);
  lcdWrite(m, h);
  //setup the lcd and I2C

  lcd.createChar(0, lineR);
  lcd.createChar(1, lineL);
  lcd.createChar(2, lineU);
  lcd.createChar(3, lineD);
  lcd.createChar(4, lineM);
  lcd.createChar(5, dot);
  lcd.createChar(6, Alarm);
  //Create custom characters
  pinMode(10, INPUT);
  pinMode(9, INPUT);
  pinMode(8, INPUT);
  //user interface pins
}

void loop() {
  unsigned long currentMillis = millis();
  //Builtin Timer
  
  if (m >= 59) {
    m = -1;
    h++;
  }
  // every 60 minutes, increment h
  else if (h > 23) {
    h = 0;
    //every 24 hours, reset
  }
  
  else if (currentMillis - preMillis >= INTERVAL) { //avoid delay function
    m++;
    lcdWrite(m, h);
    preMillis = currentMillis;
  }
  //every minute, increment

  Input(m, h); // user inputs
  WakeUP(); //alarm
}

void lcdWrite(int min, int hour) {
  sprintf(str, "%02d:%02d", hour, min); //transfer to array with zero padding
  Serial.println(str);
  lcd.clear(); //refresh screen before each print

  for (int i = 0; i <= 6; i++) {
    //Print each individual custom character
    switch (str[i]) {
      case '0':
        lcd.setCursor(i * 3, 1);
        lcd.write(0);
        lcd.write(3);
        lcd.write(1);
        lcd.setCursor(i * 3, 0);
        lcd.write(0);
        lcd.write(2);
        lcd.write(1);
        break;

      case '1':
        lcd.setCursor(i * 3 + 1, 1);
        lcd.write(0);
        lcd.write(1);
        lcd.setCursor(i * 3 + 1, 0);
        lcd.write(0);
        lcd.write(1);
        break;

      case '2':
        lcd.setCursor(i * 3, 1);
        lcd.write(0);
        lcd.write(3);
        lcd.write(3);
        lcd.setCursor(i * 3, 0);
        lcd.write(2);
        lcd.write(4);
        lcd.write(1);
        break;

      case '3':
        lcd.setCursor(i * 3, 1);
        lcd.write(3);
        lcd.write(3);
        lcd.write(1);
        lcd.setCursor(i * 3, 0);
        lcd.write(2);
        lcd.write(4);
        lcd.write(1);
        break;

      case '4':
        lcd.setCursor(i * 3 + 2, 1);
        lcd.write(1);
        lcd.setCursor(i * 3, 0);
        lcd.write(0);
        lcd.write(3);
        lcd.write(1);
        break;

      case '5':
        lcd.setCursor(i * 3, 1);
        lcd.write(3);
        lcd.write(3);
        lcd.write(1);
        lcd.setCursor(i * 3, 0);
        lcd.write(0);
        lcd.write(4);
        lcd.write(2);
        break;

      case '6':
        lcd.setCursor(i * 3, 1);
        lcd.write(0);
        lcd.write(4);
        lcd.write(1);
        lcd.setCursor(i * 3, 0);
        lcd.write(0);
        lcd.write(2);
        break;

      case '7':
        lcd.setCursor(i * 3 + 2, 1);
        lcd.write(1);
        lcd.setCursor(i * 3, 0);
        lcd.write(2);
        lcd.write(2);
        lcd.write(1);
        break;

      case '8':
        lcd.setCursor(i * 3, 1);
        lcd.write(0);
        lcd.write(3);
        lcd.write(1);
        lcd.setCursor(i * 3, 0);
        lcd.write(0);
        lcd.write(4);
        lcd.write(1);
        break;

      case '9':
        lcd.setCursor(i * 3 + 2, 1);
        lcd.write(1);
        lcd.setCursor(i * 3, 0);
        lcd.write(0);
        lcd.write(4);
        lcd.write(1);
        break;

      case ':':
        lcd.setCursor(i * 3 + 1, 1);
        lcd.write(5);
        lcd.setCursor(i * 3 + 1, 0);
        lcd.write(5);
        break;
    }
  }
}

void Input(int Min, int Hour) {

  if (digitalRead(12) == pressed) {
    h++;
    lcdWrite(m, h);
    //adjust hours
  }
  else if (digitalRead(11) == pressed) {
    m++;
    lcdWrite(m, h);
    //adjust minutes
  }
  else if (digitalRead(10) == pressed) {
    alarmOn = !alarmOn;
    Serial.println(alarmOn);
  }
  //toggle state

  if (alarmOn == true) {
    lcd.setCursor(16, 2); 
    lcd.write(6);
    //print alarm icon
  }
  else {
    lcd.setCursor(16, 2);
    lcd.print(" ");
    //blank
  }
  delay(wait);
}

void WakeUP() {
  if(strcmp(str, alarm) == 0 && alarmOn == true) {
    tone(13, 2000, 20);
    delay(10);
    //compare strings
  }
}