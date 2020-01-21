#include "Arduino.h"
#include "DynamixelMotor.h"
#define PI 3.14
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
  motor14.jointMode(205,819);
  motor14.speed(speed);
 delay(100);
}
int f=0;
float t=0;
int degf1=0;
int degf3=0;
int i=0;
int j=0;
void loop() 
{  while(f==0)
  { 
    for(int i=0;i<1300;i++)
    {  
    float angr1=-10*t;
    int degf1=map(angr1,-90,90,205,819);
    float angr2=10*t;
    int degf2=map(angr2,-90,90,205,819);
    motor8.goalPosition(degf2);
    motor9.goalPosition(degf1); 
    motor10.goalPosition(819);
    motor11.goalPosition(512);
    motor12.goalPosition(819);
    motor13.goalPosition(degf1);
    motor14.goalPosition(degf2);
    t= (millis()/1000.0);
    }
    
    for(int j=737;j>=512;)
    {
    motor8.goalPosition(j);
    motor9.goalPosition(205); 
    motor10.goalPosition(819);
    motor11.goalPosition(512);
    motor12.goalPosition(819);
    motor13.goalPosition(205);
    motor14.goalPosition(j);
    t= (millis()/1000.0);
    j=j-0.5;
    }
    f=1;        
  }
}
