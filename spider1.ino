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
  motor2.goalPosition(239);
  motor3.goalPosition(358);
  motor4.goalPosition(512);
  motor5.goalPosition(205);
  motor6.goalPosition(239);
  motor7.goalPosition(512);
  delay(50);
}
int degf=204,deg=512,deg2=512;
float angr1,angr2,angr3;
float t1=0,t2=0,t3=0,t4=0,t5=0,t6=0;
int degf1,degf2=204,degf3=512,degf5=204,degf6=204,degf7;
int f1=1,f2=1,f3=1,f4=1;
void loop() 
{     
    while(degf<410 && f1==1)                        //for hip to come at 15° smoothly
    {
      angr2=-80+(4*t1);
      degf=map(angr2,-90,90,204,820); 
      angr1=-10-(5*t1);
      degf1=map(angr1,-90,90,204,820);
      motor2.goalPosition(degf);
      motor1.goalPosition(degf1);
      t1=(millis()/1000.0);     
    }
    f1=0;
    while(degf3>=204)
    {
    t2=(millis()/1000.0)-t1;
    angr3=-45-(4*t2);
    degf3=map(angr3,-90,90,204,820);
    motor3.goalPosition(degf3);
    }
    while(degf>205 && f2==1)                  
    {
      t3=(millis()/1000.0)-t2-t1;
      angr2=-25-(4*t3);
      degf=map(angr2,-90,90,204,820); 
      angr1=-70+(4*t3);
      degf1=map(angr1,-90,90,204,820);
      motor2.goalPosition(degf);
      //if(degf1>512)
      motor1.goalPosition(degf1);
      //motor1.goalPosition(512);     
    }
    f2=0;
    //end of one leg
    while(degf6<410 && f3==1)                        //for hip to come at 15° smoothly
    {
      t4=(millis()/1000.0)-t3-t2-t1;
      angr2=-80+(4*t4);
      degf6=map(angr2,-90,90,204,820); 
      angr1=-10-(5*t4);
      degf7=map(angr1,-90,90,204,820);
      motor6.goalPosition(degf6);
      motor7.goalPosition(degf7);         
    }
    f3=0;
    while(degf5<=358)
    {
    t5=(millis()/1000.0)-t4-t3-t2-t1;
    angr3=-90+(4*t5);
    degf5=map(angr3,-90,90,204,820);
    motor5.goalPosition(degf5);
    }
    while(degf6>205 && f4==1)                  
    {
      t6=(millis()/1000.0)-t5-t4-t3-t2-t1;
      angr2=-25-(4*t6);
      degf6=map(angr2,-90,90,204,820); 
      angr1=-70+(4*t6);
      degf7=map(angr1,-90,90,204,820);
      motor6.goalPosition(degf6);
      //if(degf1>512)
      motor7.goalPosition(degf7);
      //motor1.goalPosition(512);     
    }
    f4=0;
  //motor3.goalPosition(degf2);
  //motor4.goalPosition(degf3);
  //motor5.goalPosition(degf4);
  //motor6.goalPosition(degf1);
  //motor7.goalPosition(degf2);   
  //delay(50);
}
