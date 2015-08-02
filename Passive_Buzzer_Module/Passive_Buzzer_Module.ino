/*

Passive Buzzer Module Code

Wiring

Module       Arduino
- -----------> GND
Middle ------> 5V
S -----------> Digital Pin 11

*/

int buzzer = 11;                   // setting controls the digital IO foot buzzer

void setup () {
  pinMode (buzzer, OUTPUT);        // set the digital IO pin mode, OUTPUT to output
}

void loop () {
  unsigned char i, j;              // define variables
  while (1) {
    for (i = 0; i <80; i++) {       // outputs a frequency sound
      digitalWrite (buzzer, HIGH);  // send voice
      delay (1) ;                   // Delay 1ms
      digitalWrite (buzzer, LOW);  // do not send voice
      delay (1) ;                   // delay ms
    }
    
    for (i = 0; i <500; i++) {     // output to another frequency sound
      digitalWrite (buzzer, HIGH); // send voice
      delay (2) ;                  // delay 2ms
      digitalWrite (buzzer, LOW);  // do not send voice
      delay (2) ;                  // delay 2ms
    }
  }
}


