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
DynamixelMotor motor8(interface,8);
DynamixelMotor motor9(interface,9);
DynamixelMotor motor10(interface,10);
DynamixelMotor motor11(interface,11);
DynamixelMotor motor12(interface,12);
DynamixelMotor motor13(interface,13);
DynamixelMotor motor14(interface,14);

void setup()
{ 
 //Serial.begin(1000000);
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
  motor8.enableTorque();  
  motor8.jointMode(204,820);
  motor8.speed(speed);
  motor9.enableTorque();  
  motor9.jointMode(204,820);// set to joint mode, with a 180° angle range
  motor9.speed(speed);// see robotis doc to compute angle values
  motor10.enableTorque();  
  motor10.jointMode(204,820);
  motor10.speed(speed);
  motor11.enableTorque();  
  motor11.jointMode(204,820);
  motor11.speed(speed);
  motor12.enableTorque();  
  motor12.jointMode(204,820);
  motor12.speed(speed);
  motor13.enableTorque();  
  motor13.jointMode(204,820);
  motor13.speed(speed);
  motor14.enableTorque();  
  motor14.jointMode(204,820);
  motor14.speed(speed);
  delay(50);
  motor1.goalPosition(512);
  motor2.goalPosition(239);
  motor3.goalPosition(358);
  motor4.goalPosition(512);
  motor5.goalPosition(204);
  motor6.goalPosition(239);
  motor7.goalPosition(512);
  motor8.goalPosition(512);
  motor9.goalPosition(204);
  motor10.goalPosition(665);
  motor11.goalPosition(512);
  motor12.goalPosition(820);
  motor13.goalPosition(204);
  motor14.goalPosition(512);
  delay(50);
}
int reset12,reset10,reset3,reset5;
float reset1,reset2,reset4;
int degf=204,deg=512,deg2=512;
float angr1,angr2,angr3,angr10,angr8,angr9,angr12,angr13,angr14;
float t1=0,t2=0,t3=0,t4=0,t5=0,t6=0,t7=0,t8=0,t9=0,t10=0,t11=0,t12=0;
int degf1,degf2=204,degf3=512,degf5=204,degf6=204,degf7,degf8=512,degf9=204,degf10=665,degf13=204,degf14=512,degf12=820;
int f1=1,f2=1,f3=1,f4=1,f5=1,f6=1,f7=1,f8=1;
int T=t1+t2+t3+t4+t5+t6+t7+t8+t9+t10+t11+t12;
void loop() 
{       
  delay(1000);
    while(degf<=375 && f1==1)                        //for hip to come at 15° smoothly
    {
      angr2=-70+(15*t1);
      degf=map(angr2,-90,90,204,820); 
      angr1=-10-(15*t1);
      degf1=map(angr1,-90,90,204,820);
      motor2.goalPosition(degf);
      motor1.goalPosition(degf1);
      t1=(millis()/1000.0)-T;     
    }
    T+=t1;
    f1=0;
    while(degf3>=204)
    {
    t2=(millis()/1000.0)-T;
    angr3=-45-(15*t2);
    degf3=map(angr3,-90,90,204,820);
    motor3.goalPosition(degf3);
    }
    T+=t2;
    while(degf>=204 && f2==1)                  
    {
      t3=(millis()/1000.0)-T;
      angr2=-40-(15*t3);
      degf=map(angr2,-90,90,204,820); 
      angr1=-70+(15*t3);
      degf1=map(angr1,-90,90,204,820);
      motor2.goalPosition(degf);
      //if(degf1>512)
      motor1.goalPosition(degf1);
      //motor1.goalPosition(512);     
    }
    f2=0;
    T+=t3;
    //end of one leg   
    while(degf6<=375 && f3==1)                        //for hip to come at 15° smoothly
    {
      t4=(millis()/1000.0)-T;
      angr2=-80+(15*t4);
      degf6=map(angr2,-90,90,204,820); 
      angr1=-10-(15*t4);
      degf7=map(angr1,-90,90,204,820);
      motor6.goalPosition(degf6);
      motor7.goalPosition(degf7);         
    }
    f3=0;
    T+=t4;
   while(degf5<=358)
    {
   t5=(millis()/1000.0)-T;
   angr3=-90+(15*t5); 
    degf5=map(angr3,-90,90,204,820);
    motor5.goalPosition(degf5);
    }
    T+=t5;
    while(degf6>=205 && f4==1)                  
    {
      t6=(millis()/1000.0)-T;
      angr2=-40-(15*t6);
      degf6=map(angr2,-90,90,204,820); 
      angr1=-70+(15*t6);
      degf7=map(angr1,-90,90,204,820);
      motor6.goalPosition(degf6);
      //if(degf1>512)
      motor7.goalPosition(degf7);
      //motor1.goalPosition(512);     
    }
    f4=0;
    T+=t6;
    //second leg
    // START OF THIRD LEG
  while(degf9<=375 && f5==1)                        //for hip to come at 15° smoothly
    {
      t7=(millis()/1000.0)-T;
      angr9=-70+(15*t7);
      degf9=map(angr9,-90,90,204,820); 
      angr8=-10-(15*t7);
      degf8=map(angr8,-90,90,204,820);
      motor9.goalPosition(degf9);
      motor8.goalPosition(degf8);     
    }
    T+=t7;
    f5=0;
    while(degf10<=820)
    {
    t8=(millis()/1000.0)-T;
    angr10=45+(15*t8);
    degf10=map(angr10,-90,90,204,820);
    motor10.goalPosition(degf10);
    }
    T+=t8;
    while(degf9>=204 && f6==1)                  
    {
      t9=(millis()/1000.0)-T;
      angr9=-40-(15*t9);
      degf9=map(angr9,-90,90,204,820); 
      angr8=-70+(15*t9);
      degf8=map(angr8,-90,90,204,820);
      motor9.goalPosition(degf9);
      motor8.goalPosition(degf8);     
    }
    T+=t9;
    f6=0;
    //end of one leg 
    //LEG FOUR  
    while(degf13<=375 && f7==1)                        //for hip to come at 15° smoothly
    {
      t10=(millis()/1000.0)-T;
      angr13=-80+(15*t10);
      degf13=map(angr13,-90,90,204,820); 
      angr14=-10-(15*t10);
      degf14=map(angr14,-90,90,204,820);
      motor13.goalPosition(degf13);
      motor14.goalPosition(degf14);         
    }
    f7=0;
    T+=t10;
   while(degf12>=665)
    {
   t11=(millis()/1000.0)-T;
   angr12=90-(15*t11); 
    degf12=map(angr12,-90,90,204,820);
    motor12.goalPosition(degf12);
    }
    T+=t11;
    while(degf13>=205 && f8==1)                  
    {
      t12=(millis()/1000.0)-T;
      angr13=-40-(15*t12);
      degf13=map(angr13,-90,90,204,820); 
      angr14=-70+(15*t12);
      degf14=map(angr14,-90,90,204,820);
      motor13.goalPosition(degf13);
      //if(degf1>512)
      motor14.goalPosition(degf14);
      //motor1.goalPosition(512);     
    }
    f8=0;
    T+=t12;
    delay(500);
//    delay(1000);
//    t12=(millis()/1000.0)-t10-t7-t8-t9-t11-t6-t5-t4-t3-t2-t1;
//    reset=45+(4*t12); 
//    reset12=map(reset,-90,90,204,820);
//    reset1=90-(4*t12); 
//    reset10=map(reset1,-90,90,204,820);    
//    reset2=-90-(4*t12); 
//    reset3=map(reset2,-90,90,204,820);   
//    reset4=-90-(4*t12); 
//    reset5=map(reset4,-90,90,204,820);
    //motor1.goalPosition(512);
  //motor2.goalPosition(239);
  motor3.goalPosition(358);
  //motor4.goalPosition(512);
  motor5.goalPosition(204);
  //motor6.goalPosition(239);
  //motor7.goalPosition(512);
  //motor8.goalPosition(512);
  //motor9.goalPosition(204);
  motor10.goalPosition(665);
  //motor11.goalPosition(512);
  motor12.goalPosition(820);
  //motor13.goalPosition(204);
  //motor14.goalPosition(512);
    f1=1;f2=1;f3=1;f4=1;f5=1;f6=1;f7=1;f8=1;
    degf=204;deg=512;deg2=512;degf2=204;degf3=512;degf5=204;degf6=204;degf8=512;degf9=204;degf10=665;degf13=204;degf14=512;degf12=820;

}
