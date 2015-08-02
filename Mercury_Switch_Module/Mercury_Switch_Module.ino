/*

Mercury Switch Module Code

wiring

Sensor        Arduino
S ----------> Digital Pin 3
Middle -----> 5V
- ----------> GND

*/

int ledPin = 13;                // Connect LED to pin 13 
int switcher = 3;                 // Connect Tilt sensor to Pin3 
void setup() 
{ 
 pinMode(ledPin, OUTPUT);      // Set digital pin 13 to output mode 
 pinMode(switcher, INPUT);       // Set digital pin 3 to input mode
 Serial.begin(9600); 
} 
void loop() 
{ 
     
  if(digitalRead(switcher)==HIGH) //Read sensor value 
    {  
       digitalWrite(ledPin, HIGH);   // Turn on LED when the sensor is tilted
       Serial.println("True"); 
    } 
  else
    { 
       digitalWrite(ledPin, LOW);    // Turn off LED when the sensor is not triggered 
       Serial.println("False");
    } 
  delay(1000);
}

