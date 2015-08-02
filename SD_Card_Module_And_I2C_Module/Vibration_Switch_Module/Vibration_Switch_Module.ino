/*

Vibration Switch Module

Wiring

Module     Arduino
- ----------> GND
Middle -----> 5V
S ----------> Digital Pin 7

*/
int ledPin = 13;                // Connect LED to pin 13 
int switcher = 7;                 // Connect Tilt sensor to Pin7 
int x;

void setup() { 
  pinMode(ledPin, OUTPUT);      // Set digital pin 13 to output mode 
  pinMode(switcher, INPUT);       // Set digital pin 3 to input mode 
  Serial.begin(9600);
} 

void loop() { 
  x = digitalRead(switcher);
  Serial.print(x);
  if(digitalRead(switcher)==HIGH) { //Read sensor value   
    digitalWrite(ledPin, HIGH);   // Turn on LED when the sensor is tilted
    Serial.println("True");
    //delay(1000);
  } 
  else { 
    digitalWrite(ledPin, LOW);    // Turn off LED when the sensor is not triggered 
    Serial.println("False");
  } 
}
