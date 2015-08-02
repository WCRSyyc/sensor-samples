/*

Flame Sensor Code

Wiring

Sensor      Arduino
AO ---------> Analog Pin 0
+ ----------> 5V
G ----------> GND

*/


int Led = 13;
int flamepin = 0;
int val;

void setup () {
  pinMode(Led, OUTPUT);
  pinMode(flamepin, INPUT);
  Serial.begin(9600);
}

void loop () {
  val = analogRead(flamepin);
  Serial.println(val);
  if(val < 300) {
    digitalWrite(Led, HIGH);
    Serial.println("Flame Detected");
  }
  
  else {
    digitalWrite(Led, LOW);
    Serial.println("Flame Not Detected");
  }
  delay(1000);
}
