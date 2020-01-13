// Test motor joint mode
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
  motor1.jointMode(204,820);
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
  motor7.jointMode(204,820);
  motor7.speed(speed);

  motor1.goalPosition(512);
  motor2.goalPosition(512);
  motor3.goalPosition(512);
  motor4.goalPosition(512);
  motor5.goalPosition(512);
  motor6.goalPosition(512);
  motor7.goalPosition(512);
  delay(100);
}

float t=0;
void loop() 
{
//  motor1.goalPosition(512);
//  motor2.goalPosition(512);
//  motor3.goalPosition(512);
//  motor4.goalPosition(512);
//  motor5.goalPosition(512);
//  motor6.goalPosition(512);
//  motor7.goalPosition(512);
//  delay(50);
  while(1)
  { 
    
    t=(millis()/1000.0);
    
    float angr1,angr2,degf6,degf7;
    angr2=180-(3*t)-90;
    float degf2=map(angr2,-90,90,204,820); 
    if (t<6)
     {angr1=180-130+(8*t);}
    else
    { angr1=180-(11*t)-35;} 
    float degf1=map(angr1,-90,90,204,820); 
   
    motor1.goalPosition(degf1);
    motor2.goalPosition(degf2); 
    /*motor3.goalPosition(degf2);
    motor4.goalPosition(degf3);
    motor5.goalPosition(degf4);*/
    motor6.goalPosition(degf1);
    motor7.goalPosition(degf2);
   
      }

//    delay(50);
  }
