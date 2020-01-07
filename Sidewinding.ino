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
//  Serial.begin(9600);
  interface.begin(baudrate);
  //delay(100);
  motor1.enableTorque();  
  motor1.jointMode(410,614);
  motor1.speed(speed);
  motor2.enableTorque();  
  motor2.jointMode(410,614);// set to joint mode, with a 180° angle range
  motor2.speed(speed);// see robotis doc to compute angle values
  motor3.enableTorque();  
  motor3.jointMode(410,614);
  motor3.speed(speed);
  motor4.enableTorque();  
  motor4.jointMode(410,614);
  motor4.speed(speed);
  motor5.enableTorque();  
  motor5.jointMode(410,614);
  motor5.speed(speed);
  motor6.enableTorque();  
  motor6.jointMode(410,614);
  motor6.speed(speed);
  motor7.enableTorque();  
  motor7.jointMode(410,614);
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
    float angr1=30*sin((1*(3.14*t)/6)+((2*3.14))/3);
    int degf1=map(angr1,-30,30,410,614); 
    float angr2=30*sin((1*(3.14*t)/6)+((4*3.14))/3);
    int degf2=map(angr2,-30,30,410,614); 
    float angr3=30*sin((1*(3.14*t)/6)+((4*3.14))/3);
    float angr7=asin((1/2)*sin(angr3));
    int degf3=map(angr7,-30,30,410,614);  
    float angr4=30*sin((1*(3.14*t)/6)+((8*3.14))/3);
    int degf4=map(angr4,-30,30,410,614); 
    float angr5=30*sin((1*(3.14*t)/6)+((8*3.14))/3);
    int degf5=map(angr5,-30,30,410,614);       
    motor1.goalPosition(512);
    motor2.goalPosition(degf1); 
    motor3.goalPosition(degf2);
    motor4.goalPosition(degf3);
    motor5.goalPosition(degf4);
    motor6.goalPosition(degf5);
    motor7.goalPosition(512);
    t= (millis()/1000.0);
//    delay(50);
  }
}
