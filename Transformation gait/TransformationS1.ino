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

DynamixelMotor motor1(interface,1);
DynamixelMotor motor2(interface,2);
DynamixelMotor motor3(interface,3);
DynamixelMotor motor4(interface,4);
DynamixelMotor motor5(interface,5);
DynamixelMotor motor6(interface,6);
DynamixelMotor motor7(interface,7);


void setup()
{ 
    pinMode(LED_BUILTIN, OUTPUT);
  //Serial.begin(9600);
  interface.begin(baudrate);
  //delay(100);
  motor1.enableTorque();  
  motor1.jointMode(205,819);
  motor1.speed(speed);
  motor2.enableTorque();  
  motor2.jointMode(205,819);// set to joint mode, with a 180° angle range
  motor2.speed(speed);// see robotis doc to compute angle values
  motor3.enableTorque();  
  motor3.jointMode(205,819);
  motor3.speed(speed);
  motor4.enableTorque();  
  motor4.jointMode(205,819);
  motor4.speed(speed);
  motor5.enableTorque();  
  motor5.jointMode(205,819);
  motor5.speed(speed);
  motor6.enableTorque();  
  motor6.jointMode(205,819);
  motor6.speed(speed);
  motor7.enableTorque();  
  motor7.jointMode(205,819);
  motor7.speed(speed);
 delay(100);
}
int f=0;
float t=0,angr1=0,angr2=0;
int degf1=0,degf=819;
int degf2=0;
int i=0;
int j=0,s;
void loop() 
{  while(f==0)
  { 
    while(degf2<=819)
    {  
      angr1=-10*t;
      degf1=map(angr1,-90,90,205,819);
      degf1 = constrain(degf1, 205, 819);
      angr2=10*t;
      degf2=map(angr2,-90,90,205,819);
      //degf2 = constrain(degf2, 205, 819);
      motor1.goalPosition(degf2);    //+90
      motor2.goalPosition(degf1);    //-90
      motor3.goalPosition(205);
      motor4.goalPosition(512);
      motor5.goalPosition(205);
      motor6.goalPosition(degf1);   //-90
      motor7.goalPosition(degf2);   //+90
      t= (millis()/1000.0);
    }
    motor2.goalPosition(205); 
    motor3.goalPosition(205);
    motor4.goalPosition(512);
    motor5.goalPosition(205);
    motor6.goalPosition(205);
    while(degf2>512)
    {
      s= (millis()/1000.0)-t;
      angr2=90-5*s;
      degf2=map(angr2,-90,90,205,819);
      degf2 = constrain(degf2, 205, 819);
      motor1.goalPosition(degf2);  
      motor7.goalPosition(degf2);
    }
    f=1;        
  }
//  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(1000);                       // wait for a second
//  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
//  delay(1000); 
}
