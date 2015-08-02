/*

Mini Magnetic Ring Sensor Code

Wiring

Sensor      Arduino
- ----------> GND
Middle -----> 5V
S ----------> Digital Pin 3

*/

int Led = 13 ;// define LED Interface
int sensorpin = 3; // define the Reed sensor interfaces
int val;// define numeric variables val
void setup() {
  pinMode(Led, OUTPUT);// define LED as output interface
  pinMode(sensorpin, INPUT);// output interface as defined Reed sensor
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(sensorpin) ;// digital interface will be assigned a value of 3 to read val
  if(val == HIGH) { // When the Reed sensor detects a signal, LED flashes
    digitalWrite(Led, LOW);
    Serial.println("False");
  }
  else {
    digitalWrite(Led, HIGH);
    Serial.println("True");
  }
  delay(1000);
} 


