/*

RGB SMD Module Code

Wiring

Module       Arduino
- ------------> GND
R ------------> Digital Pin 9
G ------------> Digital Pin 10
B ------------> Digital Pin 11

*/


#define BLUE_LED_DIO 11     /* Select the DIO for driving the BLUE LED */
#define RED_LED_DIO 9       /* Select the DIO for driving the RED LED */
#define GREEN_LED_DIO 10    /* Select the DIO for driving the GREEN LED */

/* Initialise serial and DIO */
void setup()
{
  /* Configure the DIO pins used by the analogWrite PWM function */
  pinMode(BLUE_LED_DIO, OUTPUT); 
  pinMode(RED_LED_DIO, OUTPUT); 
  pinMode(GREEN_LED_DIO, OUTPUT); 
}

/* Main program loop */
void loop()
{
  int k;
  
  /* Slowly reduce the red LED's intensity and at the same time 
     increase the green LED's intensity */
  for (k = 0; k <=255; k++)
  {
    analogWrite(RED_LED_DIO,255 - k);
    analogWrite(GREEN_LED_DIO, k);  
    delay(10);
  }
  
  /* Slowly reduce the green LED's intensity and at the same time 
     increase the blue LED's intensity */
  for (k = 0; k <=255; k++)
  {
    analogWrite(GREEN_LED_DIO,255 - k);  
    analogWrite(BLUE_LED_DIO, k);  
    delay(10);
  }
  
  /* Slowly reduce the blue LED's intensity and at the same time 
     increase the red LED's intensity */
  for (k = 0; k <=255; k++)
  {
    analogWrite(BLUE_LED_DIO,255 - k); 
    analogWrite(RED_LED_DIO, k);  
    delay(10);
  }
}


