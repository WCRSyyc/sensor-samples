/*Arduino Sample Code 

Line tracking sensor code

Wiring

Sensor        Arduino
GND ----------> GND
OUT ----------> Digital Pin 2
VCC ----------> 5V

Also note that this is set up for a black line on white.  
If you are using a white line on black then you need to make the changes indicated below.

*/
void setup() {   
  Serial.begin(9600); 
} 

void loop() {   
  int x;
  x = digitalRead(2);
  Serial.print(x); // print the data from the sensor    
  
  if (x == 0) { //if you are using white line on black change the x == 0 to x == 1
    Serial.println(" Not On Line");
  }
  if (x == 1) { //if you are using white line on black change the x == 1 to x == 0
    Serial.println(" On Line");
  }
  delay(1000);
} 

