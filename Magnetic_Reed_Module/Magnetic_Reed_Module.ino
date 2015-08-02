/*

Code for Magnetic Reed Module

Wiring

Module         Arduino
- ------------> GND
Middle -------> 5V
S ------------> Digital Pin 2

*/


int ledPin = 13; // choose pin for the LED 
int inputPin = 2; // choose input pin (for magnetic switch) 
int val = 0; // variable for reading the pin status 

void setup() { 
  pinMode(ledPin, OUTPUT); // declare LED as output 
  pinMode(inputPin, INPUT); // declare magnetic switch as input
  Serial.begin(9600); 
} 

void loop(){ 
  val = digitalRead(inputPin); // read input value 
  if (val == HIGH) { // check if the input is HIGH 
    digitalWrite(ledPin, LOW); // turn LED OFF
    Serial.println("True");
  } 
  
  else { 
    digitalWrite(ledPin, HIGH); // turn LED ON 
    Serial.println("False");
  } 
} 

