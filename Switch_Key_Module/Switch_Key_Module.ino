/*

Switch Key Module Code

Wiring

Sensor       Arduino
- ---------> GND
Middle ----> 5V
S ---------> Digital Pin 3


*/
int Led = 13;
int button = 3;
int val;

void setup () {
  pinMode (Led, OUTPUT);
  pinMode (button, INPUT);
  Serial.begin(9600);
}

void loop () {
  val = digitalRead(button);
  
  if(val == HIGH) {
    digitalWrite(Led, LOW);
    Serial.println("False");
  }
  
  else {
    digitalWrite(Led, HIGH);
    Serial.println("True");
  }
  delay(1000);
}
