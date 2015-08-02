/*

Linear Hall Magnetic Module

Wiring

Transducer    Arduino
DO ------------> Digital Pin 3
G -------------> GND
+ -------------> 5V

*/

int Led = 13;
int buttonpin = 3;
int val;

void setup () {
  pinMode(Led, OUTPUT);
  pinMode(buttonpin, INPUT);
  Serial.begin(9600);
}

void loop () {  
  val = digitalRead(buttonpin);
  Serial.print(val);
  if (val == HIGH) {
    digitalWrite(Led, HIGH);
    Serial.println(", True");
  }
  else {
    digitalWrite(Led, LOW);
    Serial.println(", False");
  }
  delay(1000);
}
