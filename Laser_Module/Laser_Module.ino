/*

  Code for laser module
  
  Wiring
  
  Laser       Arduino
  - --------> GND
  Middle ---> 5V
  S --------> Digital 13
  
  Laser_Module
  Turns on an Laser on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int laser = 13;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(laser, OUTPUT);
  //begin the serial monitor, baud rate 9600
  Serial.begin(9600);  
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(laser, HIGH);   // turn the laser on (HIGH is the voltage level)
  Serial.println("laser on");  // print that the laser is on to the serial monitor
  delay(1000);                 // wait for a second
  digitalWrite(laser, LOW);    // turn the laser off by making the voltage LOW
  Serial.println("laser off"); // print that the laser is off to the serial monitor
  delay(1000);                 // wait for a second
}
