/*

Metal Touch Sensor Code

Wiring

Sensor      Arduino
DO ---------> Digital Pin 3
+ ----------> 5V
G ----------> GND

*/


int Led = 13;
int touchpin = 3;
int val;

void setup () {
  pinMode(Led, OUTPUT);
  pinMode(touchpin, INPUT);
  Serial.begin(9600);
}

void loop () {
  val = digitalRead(touchpin);
  
  if(val == HIGH) {
    digitalWrite(Led, HIGH);
    Serial.println("Metal Detected");
  }
  
  else {
    digitalWrite(Led, LOW);
    Serial.println("Metal Not Detected");
  }
  
  delay(1000);
}
