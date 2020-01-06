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

DynamixelMotor motor8(interface,8);
DynamixelMotor motor9(interface,9);
DynamixelMotor motor10(interface,10);
DynamixelMotor motor11(interface,11);
DynamixelMotor motor12(interface,12);
DynamixelMotor motor13(interface,13);
DynamixelMotor motor14(interface,14);

void setup()
{ 
//  Serial.begin(9600);
  interface.begin(baudrate);
  //delay(100);
  motor8.enableTorque();  
  motor8.jointMode(307,717);
  motor8.speed(speed);
  motor9.enableTorque();  
  motor9.jointMode(307,717);// set to joint mode, with a 180° angle range
  motor9.speed(speed);// see robotis doc to compute angle values
  motor10.enableTorque();  
  motor10.jointMode(307,717);
  motor10.speed(speed);
  motor11.enableTorque();  
  motor11.jointMode(307,717);
  motor11.speed(speed);
  motor12.enableTorque();  
  motor12.jointMode(307,717);
  motor12.speed(speed);
  motor13.enableTorque();  
  motor13.jointMode(307,717);
  motor13.speed(speed);
  motor14.enableTorque();  
  motor14.jointMode(307,717);
  motor14.speed(speed);

  motor8.goalPosition(512);
  motor9.goalPosition(512);
  motor10.goalPosition(512);
  motor11.goalPosition(512);
  motor12.goalPosition(512);
  motor13.goalPosition(512);
  motor14.goalPosition(512);
  delay(100);
}

float t=0;
void loop() 
{
//  motor8.goalPosition(512);
//  motor9.goalPosition(512);
//  motor10.goalPosition(512);
//  motor11.goalPosition(512);
//  motor12.goalPosition(512);
//  motor13.goalPosition(512);
//  motor14.goalPosition(512);
//  delay(50);
  while(1)
  {    
    float angr1=60*sin((1*(3.14*t)/6)+((2*3.14))/3);
//    Serial.println(angr1);
    //float deg = angr * 57296 / 1000;
    //Serial.println(deg);
    int degf1=map(angr1,-60,60,307,717);
//    Serial.println(degf1);    
    float angr3=60*sin((1*(3.14*t)/6)+((6*3.14))/3);
//    Serial.println(angr3);
    //float deg1 = angr * 57296 / 1000;
    int degf3=map(angr3,-60,60,307,717);       
    float angr5=60*sin((1*(3.14*t)/6)+((10*3.14))/3);
//    Serial.println(angr5);
    //float deg2 = angr * 57296 / 1000;
    int degf5=map(angr5,-60,60,307,717);       
    motor8.goalPosition(512);
    motor9.goalPosition(degf1); 
    motor10.goalPosition(512);
    motor11.goalPosition(degf3);
    motor12.goalPosition(512);
    motor13.goalPosition(degf5);
    motor14.goalPosition(512);
    t= (millis()/1000.0);
//    delay(50);
  }
}
