/*

Finger Heartbeat Measurement Module

Wiring

Module     Arduino
- --------> GND
Middle ---> 5V
S --------> Analog Pin 0

*/
int ledPin = 13;
int sensorPin = 0;
double alpha = 0.75;
int period = 1000;
double change = 0.0;

void setup () {
  pinMode (ledPin, OUTPUT);
  Serial.begin (115200);
}
void loop () {
  static double oldValue = 0;
  static double oldChange = 0;
  int rawValue = analogRead (sensorPin);
  double value = alpha * oldValue + (1 - alpha) * rawValue * 0.1;
  Serial.print(value);
  Serial.println(" beats/min");
  oldValue = value;
  delay (period);
}
