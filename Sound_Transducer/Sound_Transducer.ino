/*

Sound Transducer

Wiring

Transducer    Arduino
AO ------------> Analog Pin 5
G -------------> GND
+ -------------> 5V

*/

int Led = 13;
int buttonpin = A5;
int val;

void setup () {
  pinMode(Led, OUTPUT);
  pinMode(buttonpin, INPUT);
  Serial.begin(9600);
}

void loop () {  
  val = analogRead(buttonpin);
  Serial.println(val);
  if (val >32) {
    digitalWrite(Led, HIGH);
    Serial.println(", True");
  }
  else {
    digitalWrite(Led, LOW);
    Serial.println(", False");
  }
  delay(1000);
}
