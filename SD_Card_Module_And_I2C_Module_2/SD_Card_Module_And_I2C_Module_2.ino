#include <Wire.h>
#include <RTClib.h>
#include <SD.h>
Sd2Card card;
File testFile;

RTC_DS1307 RTC;

const int chipSelect = 10;

void setup() {
  setupI2C();
  setupSD();
}

void loop () {
  loopI2C();
  loopSD();
}

void setupI2C () {
  Serial.begin(57600);
  Wire.begin();
  RTC.begin();

  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
}

void loopI2C () {
  DateTime now = RTC.now();
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
  delay(1000);
}

void setupSD() {
  SD.begin(10);
  pinMode(10, OUTPUT);
  if (!card.init(SPI_HALF_SPEED, chipSelect)) {
    Serial.println("initialization failed. Things to check:");
    Serial.println("* is a card is inserted?");
    Serial.println("* Is your wiring correct?");
    Serial.println("* did you change the chipSelect pin to match your shield or module?");
    return;
  }
}

void loopSD() {
  testFile = SD.open("test1.txt", FILE_WRITE);
  if (testFile) {
    DateTime now = RTC.now();
    testFile.print(now.year(), DEC);
    testFile.print('/');
    testFile.print(now.month(), DEC);
    testFile.print('/');
    testFile.print(now.day(), DEC);
    testFile.print(' ');
    testFile.print(now.hour(), DEC);
    testFile.print(':');
    testFile.print(now.minute(), DEC);
    testFile.print(':');
    testFile.print(now.second(), DEC);
    testFile.println();
    testFile.close();
    delay(5000);
  }  
  else {
    Serial.println("error opening datalog.txt");
  } 
}
