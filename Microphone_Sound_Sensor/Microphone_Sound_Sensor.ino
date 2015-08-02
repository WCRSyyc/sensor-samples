//SOUND MONITOR for the classroom 
/*
Microphone Sound Sensor Code

Wiring

Sensor      Arduino
- ---------> GND
+ ---------> 5V
AO --------> Analog Pin 4

*/


int sensorPin = 4;    //Microphone Sensor Pin
int sensorValue = 0; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);    
  Serial.println(sensorValue);
  
  //delay(1000);
 
  //If you feel that the sensor values on the serial monitor
  //are going by too quickly for you to read, you can make it 
  //so that the values only show up on the serial monitor 
  //if you make a noise.  You can replace 
  //Serial.println(sensorValue); 
  //with: 
  //if (sensorValue < 509){
    //Serial.println(sensorValue);
  //}
}
