#include "Arduino.h"
#include "DynamixelMotor.h"
//#define PI 3.14
// id of the motor
const uint8_t id=7;
// speed, between 0 and 1023
int16_t speed=1000;
// communication baudrate
const long unsigned int baudrate = 1000000;

// hardware serial without tristate buffer
// see blink_led example, and adapt to your configuration
HardwareDynamixelInterface interface(Serial);

DynamixelMotor motor8(interface,8);
DynamixelMotor motor9(interface,9);
DynamixelMotor motor10(interface,10);
DynamixelMotor motor11(interface,11);
DynamixelMotor motor12(interface,12);
DynamixelMotor motor13(interface,13);
DynamixelMotor motor14(interface,14);


void setup()
{ 
  //Serial.begin(9600);
  interface.begin(baudrate);
  //delay(100);
  motor8.enableTorque();  
  motor8.jointMode(205,819);
  motor8.speed(speed);
  motor9.enableTorque();  
  motor9.jointMode(205,819);// set to joint mode, with a 180° angle range
  motor9.speed(speed);// see robotis doc to compute angle values
  motor10.enableTorque();  
  motor10.jointMode(205,819);
  motor10.speed(speed);
  motor11.enableTorque();  
  motor11.jointMode(205,819);
  motor11.speed(speed);
  motor12.enableTorque();  
  motor12.jointMode(205,819);
  motor12.speed(speed);
  motor13.enableTorque();  
  motor13.jointMode(205,819);
  motor13.speed(speed);
  motor14.enableTorque();  
  motor14.jointMode(1024,3072);
  motor14.speed(speed);
 delay(100);
 pinMode(13, OUTPUT);
}
float t=0,angr1=0,angr2=0,angr14=0;
int degf1=0,degf2=0,degf14,i=0,j=0,f=0,s;
void loop() 
{  while(f==0)
  { 
    while(degf2<=819)
    {  
      angr1=-10*t;
      degf1=map(angr1,-90,90,205,819);
      degf1 = constrain(degf1, 205, 819);
      angr2=10*t;
      degf14=map(angr2,-90,90,1024,3072);
      degf2=map(angr2,-90,90,205,819);
      //degf2 = constrain(degf2, 205, 819);
      motor8.goalPosition(degf2);   //+90
      motor9.goalPosition(degf1);   //-90
      motor10.goalPosition(819);
      motor11.goalPosition(512);
      motor12.goalPosition(819);
      motor13.goalPosition(degf1);
      motor14.goalPosition(degf14);
      t= (millis()/1000.0);   
      digitalWrite(LED_BUILTIN, HIGH);
//      delay(1000);
//      digitalWrite(LED_BUILTIN, LOW);
    }
    motor9.goalPosition(205); 
    motor10.goalPosition(819);
    motor11.goalPosition(512);
    motor12.goalPosition(819);
    motor13.goalPosition(205);
    while(degf2>512)    
    {  
      s= (millis()/1000.0)-t;
      angr14=90-10*s;
      angr2=90-5*s;
      degf14=map(angr14,-90,90,1024,3072);
      degf2=map(angr2,-90,90,205,819);
      degf2 = constrain(degf2, 205, 819);
      motor8.goalPosition(degf2);
      if(degf14>=1800)   
      {motor14.goalPosition(degf14);}
    }
    f=1;        
  }
//  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(1000);                       // wait for a second
//  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
//  delay(1000); 
}
