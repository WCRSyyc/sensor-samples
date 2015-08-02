#include <SoftwareSerial.h>
#include <Wire.h>
#include <RTClib.h>
#include <SD.h>
#include <Adafruit_BMP085.h>
#include <ADXL345.h>
#include <HMC5883L.h>
#include <L3G.h>


RTC_DS1307 RTC;
ADXL345 adxl; 
Adafruit_BMP085 bmp;
HMC5883L compass;
L3G gyro;

const int chipSelect = 4;
float accelxg, accelyg, accelzg, temperature, pressure, Altitude, realAltitude, rawXAxis, rawYAxis,rawZAxis, scaledXAxis, scaledYAxis, scaledZAxis, heading, headingDegrees;
int gyrogx, gyrogy, gyrogz, accelx, accely, accelz, counter1 = 0, counter2 = 0, error = 0;
char alpha;

void setup() {
  setupAccelerometer();
  setupAltimeter();
  setupHMC5883L();
  setupL3G();
  setupI2C();
  setupSD();
}

void loop () {
  loopAccelerometer();
  loopAltimeter();
  loopHMC5883L();
  loopL3G();
  loopI2C();
  loopSD();
}

//--------------------------------------------------------------------------//
//-------------------------SETUP ROUTINES-----------------------------------//
//--------------------------------------------------------------------------//

void setupL3G() {
  if (!gyro.init())
  {
    Serial.println("Failed to autodetect gyro type!");
    while (1);
  }
  gyro.enableDefault();  
}

void setupHMC5883L() {
  compass = HMC5883L(); 
  error = compass.SetScale(1.3);
  error = compass.SetMeasurementMode(Measurement_Continuous);
}

void setupAltimeter() {
  bmp.begin();  
}

void setupAccelerometer () {
  Serial.begin(57600);
  adxl.powerOn();
  adxl.setActivityThreshold(75); 
  adxl.setInactivityThreshold(255);
  adxl.setTimeInactivity(3600); 
  adxl.setActivityX(1);
  adxl.setActivityY(1);
  adxl.setActivityZ(1);
}

void setupI2C () {
  Serial.println(F("   Clock Data      |               Accelerometer Data             |                      Altimeter Data                         |                                     Magnetometer Data                       |     Gyroscope Data"));
  Serial.println(F("  Date     Time    |       x               y              z       | Temperature       Pressure       Altitude    Real altitude  |    |          Raw            |           Scaled           | Radians Degrees |  x    y    z"));
  Wire.begin();
  RTC.begin();

  if (! RTC.isrunning()) {
    Serial.println(F("RTC is NOT running!"));
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
}

void setupSD () {
  //Serial.print("Initializing SD card...");
  pinMode(10, OUTPUT);
  //Serial.println("3");
  if (!SD.begin(chipSelect)) {
    //Serial.println("Card failed, or not present");
    return;
  }
  //Serial.println("4");
  //Serial.println("card initialized.");
  SD.remove("datalog.txt");
  
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  dataFile.println(F("   Clock Data      |               Accelerometer Data             |                      Altimeter Data                         |                                     Magnetometer Data                       |     Gyroscope Data"));
  dataFile.println(F("  Date     Time    |       x               y              z       | Temperature       Pressure       Altitude    Real altitude  |    |          Raw            |           Scaled           | Radians Degrees |  x    y    z"));
  dataFile.close();
}



//--------------------------------------------------------------------------//
//-------------------------LOOP ROUTINES------------------------------------//
//--------------------------------------------------------------------------//


void loopGPS() {
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  while (counter1 < 3 && counter2 < 100001) {
    if (Serial.available() && counter1 < 3) {
      alpha = Serial.read();
      if (counter1 == 0 && alpha == 36) {
        dataFile.print(alpha);
        //Serial.print(alpha);
        counter1 = 1;
      }
      else if (counter1 == 1 && alpha != 36) {
        dataFile.print(alpha);
        //Serial.print(alpha);
      }
      else if (counter1 == 1) {
        dataFile.print(alpha);
        //Serial.print(alpha);
        counter1 = 2;
      }
      else if (counter1 == 2 && alpha != 36) {
        dataFile.print(alpha);
        //Serial.print(alpha);
      } 
      else if (counter1 == 2) {
        counter1 = 3;
      }
    }
    else {
      counter2++;
      if (counter2 > 100000) {
        dataFile.println(" ");
        dataFile.println("Serial not available");
        //Serial.println(" ");
        //Serial.println("Serial not available");
      }
    }
  }
  dataFile.close();
}

void loopSD() {
  
  accelxg = accelx * 0.0078;
  accelyg = accely * 0.0078;
  accelzg = accelz * 0.0078;
  
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  DateTime now = RTC.now();
  dataFile.print(now.year(), DEC);
  dataFile.print('/');
  dataFile.print(now.month(), DEC);
  dataFile.print('/');
  dataFile.print(now.day(), DEC);
  dataFile.print(' ');
  dataFile.print(now.hour(), DEC);
  dataFile.print(':');
  dataFile.print(now.minute(), DEC);
  dataFile.print(':');
  dataFile.print(now.second(), DEC);
  
  dataFile.print("   ");
  dataFile.print(accelxg, DEC);
  dataFile.print("   ");
  dataFile.print(accelyg, DEC);
  dataFile.print("   ");
  dataFile.print(accelzg, DEC);

  dataFile.print("     ");
  dataFile.print(temperature);
  dataFile.print("     "); 
  dataFile.print("     ");
  dataFile.print(pressure);
  dataFile.print("     "); 
  dataFile.print(Altitude);
  dataFile.print("        ");
  dataFile.print(realAltitude);
  dataFile.print("        ");
  
  dataFile.print("      ");
  dataFile.print(rawXAxis);
  dataFile.print("   ");   
  dataFile.print(rawYAxis);
  dataFile.print("   ");   
  dataFile.print(rawZAxis);
  dataFile.print("   ");
  dataFile.print(scaledXAxis);
  dataFile.print("   ");   
  dataFile.print(scaledYAxis);
  dataFile.print("   ");   
  dataFile.print(scaledZAxis);
  dataFile.print("   ");
  dataFile.print(heading);
  dataFile.print("    ");
  dataFile.print(headingDegrees);

  dataFile.print("     ");
  dataFile.print(gyrogx);
  dataFile.print("  ");
  dataFile.print(gyrogy);
  dataFile.print("   ");
  dataFile.println(gyrogz);
  counter1 = 0;
  counter2 = 0;
  //loopGPS();
  //delay(1000);
  dataFile.close();
}

void loopI2C () {
  DateTime now = RTC.now();
  
  
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  
  Serial.print("   ");
  Serial.print(accelxg, DEC);
  Serial.print("   ");
  Serial.print(accelyg, DEC);
  Serial.print("   ");
  Serial.print(accelzg, DEC);

  Serial.print("     ");
  Serial.print(temperature);
  Serial.print(" *C  "); 
  Serial.print("     "); 
  Serial.print(pressure);
  Serial.print(" Pa "); 
  Serial.print(Altitude);
  Serial.print(" meters ");
  Serial.print(realAltitude);
  Serial.print(" meters ");
  
  Serial.print("      ");
  Serial.print(rawXAxis);
  Serial.print("   ");   
  Serial.print(rawYAxis);
  Serial.print("   ");   
  Serial.print(rawZAxis);
  Serial.print("   ");
  Serial.print(scaledXAxis);
  Serial.print("   ");   
  Serial.print(scaledYAxis);
  Serial.print("   ");   
  Serial.print(scaledZAxis);
  Serial.print("   ");
  Serial.print(heading);
  Serial.print("    ");
  Serial.print(headingDegrees);

  Serial.print("     ");
  Serial.print(gyrogx);
  Serial.print("  ");
  Serial.print(gyrogy);
  Serial.print("   ");
  Serial.println(gyrogz);
  //Serial.println("");
  counter1 = 0;
  counter2 = 0;
  //loopGPS();
  //delay(1000);
}

void loopAccelerometer ()  {
  int x,y,z;  
  adxl.readAccel(&accelx, &accely, &accelz);
}

void loopAltimeter() {
  temperature = bmp.readTemperature();
  pressure = bmp.readPressure();
  Altitude = bmp.readAltitude();
  realAltitude = bmp.readAltitude(101500);
  delay(500);
}

void loopHMC5883L() {
  MagnetometerRaw raw = compass.ReadRawAxis();
  MagnetometerScaled scaled = compass.ReadScaledAxis();
  int MilliGauss_OnThe_XAxis = scaled.XAxis;// (or YAxis, or ZAxis)
  heading = atan2(scaled.YAxis, scaled.XAxis);
  float declinationAngle = 0.0457;
  heading += declinationAngle;

  if(heading < 0) {
    heading += 2*PI;
  }
  
  if(heading > 2*PI) {
    heading -= 2*PI;
  }
  
  headingDegrees = heading * 180/M_PI; 
  
  rawXAxis = raw.XAxis;  
  rawYAxis = raw.YAxis;  
  rawZAxis = raw.ZAxis;
  scaledXAxis = scaled.XAxis;  
  scaledYAxis = scaled.YAxis;   
  scaledZAxis = scaled.ZAxis;
}

void loopL3G() {
  gyro.read();
  gyrogx = gyro.g.x;
  gyrogy = gyro.g.y;
  gyrogz = gyro.g.z;  
}
