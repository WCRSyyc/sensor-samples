/*

Hall Magnetic Sensor Code

Wiring

Sensor     Arduino
- ----------> GND
Middle -----> 5V
S ----------> Digital Pin 12

*/

const int sensorPin = 12;
const int ledPin = 13;

int sensorState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);      
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);  
}

void loop(){
  sensorState = digitalRead(sensorPin);

  if (sensorState == LOW) {        
    digitalWrite(ledPin, HIGH); // Turn on LED
    Serial.println("True");
  } 
  else {
    digitalWrite(ledPin, LOW);  // Turn off LED
    Serial.println("False");
  }
  delay(1000);
}


