int calibrationTime = 30;        
long unsigned int lowIn;         
long unsigned int pause = 5000;  

boolean lockLow = true;
boolean takeLowTime;  

int Sensor1Pin = 2;    //the digital pin connected to the PIR sensor's output
int Sensor2Pin = 3;
int ledPin = 13;

boolean S1Active = false, S2Active = false;

void setup(){
  Serial.begin(9600);
  pinMode(Sensor1Pin, INPUT);
  pinMode(Sensor2Pin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(Sensor1Pin, LOW);
  digitalWrite(Sensor2Pin, LOW);
  
  Serial.print("calibrating sensor ");
  for(int i = 0; i < calibrationTime; i++){
    Serial.print(".");
    delay(1000);
  }
  Serial.println(" done");
  Serial.println("SENSOR ACTIVE");
  delay(50);
}

////////////////////////////
//LOOP
void loop(){
  if(digitalRead(Sensor1Pin) == HIGH){
    int sensor = 1;
    Detected(sensor);
  }
  
  if(digitalRead(Sensor1Pin) == LOW && S2Active == false){
    int sensor = 1;
    Undetected(sensor);
  }
  
  if(digitalRead(Sensor2Pin) == HIGH){
    int sensor = 2;
    Detected(sensor);
  }
  
  if(digitalRead(Sensor2Pin) == LOW && S1Active == false){
    int sensor = 2;
    Undetected(sensor);
  }
}

void Detected(int sensor) {
  digitalWrite(ledPin, HIGH);   //the led visualizes the sensors output pin state
  if(lockLow){
    //makes sure we wait for a transition to LOW before any further output is made:
    lockLow = false;            
    
    if(sensor == 1) {
      S1Active = true;
    }
    
    if(sensor == 2) {
      S2Active = true;
    }
    
    Serial.println("---");
    Serial.print("Sensor ");
    Serial.print(sensor);
    Serial.print(" detected motion at ");
    Serial.print(millis()/1000);
    Serial.println(" sec"); 
    delay(50);
  }         
  takeLowTime = true;
}

void Undetected(int sensor) {
  digitalWrite(ledPin, LOW);
  
  if(takeLowTime){
    lowIn = millis();        
    takeLowTime = false;
  }
  if(!lockLow && millis() - lowIn > pause){  
    
    if(sensor == 1) {
      S1Active = false;
    }
    
    if(sensor == 2) {
      S2Active = false;
    }
    
    lockLow = true;
    Serial.print("Sensor ");
    Serial.print(sensor);    
    Serial.print(" motion ended at ");
    Serial.print((millis() - pause)/1000);
    Serial.println(" sec");
    delay(50);
  }
}
