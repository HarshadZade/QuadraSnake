#include "Arduino.h"
#include "DynamixelMotor.h"
#define PI 3.14
// id of the motor
const uint8_t id=7;
// speed, between 0 and 1023
int16_t speed=512;
// communication baudrate
const long unsigned int baudrate = 1000000;

// hardware serial without tristate buffer
// see blink_led example, and adapt to your configuration
HardwareDynamixelInterface interface(Serial);

DynamixelMotor motor1(interface,1);
DynamixelMotor motor2(interface,2);
DynamixelMotor motor3(interface,3);
DynamixelMotor motor4(interface,4);
DynamixelMotor motor5(interface,5);
DynamixelMotor motor6(interface,6);
DynamixelMotor motor7(interface,7);

void setup()
{ 
 Serial.begin(1000000);
  interface.begin(baudrate);
  //delay(100);
  motor1.enableTorque();  
  motor1.jointMode(304,717);
  motor1.speed(speed);
  motor2.enableTorque();  
  motor2.jointMode(204,820);// set to joint mode, with a 180° angle range
  motor2.speed(speed);// see robotis doc to compute angle values
  motor3.enableTorque();  
  motor3.jointMode(204,820);
  motor3.speed(speed);
  motor4.enableTorque();  
  motor4.jointMode(204,820);
  motor4.speed(speed);
  motor5.enableTorque();  
  motor5.jointMode(204,820);
  motor5.speed(speed);
  motor6.enableTorque();  
  motor6.jointMode(204,820);
  motor6.speed(speed);
  motor7.enableTorque();  
  motor7.jointMode(304,717);
  motor7.speed(speed);

  motor1.goalPosition(512);
  motor2.goalPosition(204);
  motor3.goalPosition(204);
  motor4.goalPosition(512);
  motor5.goalPosition(204);
  motor6.goalPosition(204);
  motor7.goalPosition(512);
  delay(50);
}
int degf=204,deg1=512,deg2=512;
float angr1,angr2;
float t=0,s=0;
int degf1,degf2;
void loop() 
{  
    while(degf<291)                        //for hip to come at 15° smoothly
    {
      angr2=-90+(4*s);
      degf=map(angr2,-90,90,204,820); 
      angr1=15+(1*s);
      degf1=map(angr1,-60,60,307,717);
      motor2.goalPosition(degf);
      motor1.goalPosition(degf1);
      s=(millis()/1000.0);     
    }
    t=(millis()/1000.0)-s;   
    if(deg1>350)
    {
      if(deg2>256)
      {
      angr2=-65-(4*t);
      degf2=map(angr2,-60,60,307,717); 
      deg2=map(angr2,-60,60,307,717);
      motor2.goalPosition(degf2);
      }
      angr1=21-(5*t);
      degf1=map(angr1,-60,60,307,717);
      deg1=map(angr1,-60,60,307,717);
      motor1.goalPosition(degf1);
    }
  //motor3.goalPosition(degf2);
  //motor4.goalPosition(degf3);
  //motor5.goalPosition(degf4);
  //motor6.goalPosition(degf1);
  //motor7.goalPosition(degf2);   
  //delay(50);
}
