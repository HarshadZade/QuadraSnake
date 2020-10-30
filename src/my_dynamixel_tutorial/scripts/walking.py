#!/usr/bin/env python
# Software License Agreement (BSD License)
#
# Copyright (c) 2008, Willow Garage, Inc.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
#  * Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#  * Redistributions in binary form must reproduce the above
#    copyright notice, this list of conditions and the following
#    disclaimer in the documentation and/or other materials provided
#    with the distribution.
#  * Neither the name of Willow Garage, Inc. nor the names of its
#    contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
# Revision $Id$

## Simple talker demo that published std_msgs/Strings messages
## to the 'chatter' topic

import rospy
import time
import math
from std_msgs.msg import Float64

def talker():
    pub1 = rospy.Publisher('/motor1/command', Float64, queue_size=10)
    pub2 = rospy.Publisher('/motor2/command', Float64, queue_size=10)
    pub3 = rospy.Publisher('/motor3/command', Float64, queue_size=10)
    pub4 = rospy.Publisher('/motor4/command', Float64, queue_size=10)
    pub5 = rospy.Publisher('/motor5/command', Float64, queue_size=10)
    pub6 = rospy.Publisher('/motor6/command', Float64, queue_size=10)
    pub7 = rospy.Publisher('/motor7/command', Float64, queue_size=10)
    pub8 = rospy.Publisher('/motor8/command', Float64, queue_size=10)
    pub9 = rospy.Publisher('/motor9/command', Float64, queue_size=10)
    pub10 = rospy.Publisher('/motor10/command', Float64, queue_size=10)
    pub11 = rospy.Publisher('/motor11/command', Float64, queue_size=10)
    pub12 = rospy.Publisher('/motor12/command', Float64, queue_size=10)
    pub13 = rospy.Publisher('/motor13/command', Float64, queue_size=10)
    pub14= rospy.Publisher('/motor14/command', Float64, queue_size=10)
    rospy.init_node('talker1', anonymous=True)
    rate = rospy.Rate(10) # 10hz
f1=1
f2=1
f3=1
f4=1
f5=1
f6=1
f7=1
f8=1
t1=0
t2=0
t3=0
t4=0
t5=0
t6=0
t7=0
t8=0
t9=0
t10=0
t11=0
t12=0
t13=0
angr1=0
angr2=0
angr3=0
angr4=0
angr5=0
angr6=0
angr7=0
angr8=0
angr9=0
angr10=0
angr11=0
angr12=0
angr13=0
angr14=0
T=t1+t2+t3+t4+t5+t6+t7+t8+t9+t10+t11+t12+t13
       
while not rospy.is_shutdown():
    while angr2<=math.radians(-45) and f1==1:
        angr2=math.radians(-90+(25*t1))
        angr1=math.radians(-(25*t1))
        pub1.publish(angr1)
        pub2.publish(angr2)
        t1=(time.time()/1000000000)-T;
    f1=0
    T+=t1           
    while angr3 >= math.radians(-90):
        t2=(time.time()/1000000000)-T
        angr3=math.radians(-45-(25*t2))
        pub3.publish(angr3)
    T+=t2
    while angr2>=math.radian(-90) and f2==1:
        t3=(time.time()/1000000000)-T
        angr2=math.radian(-45-(25*t3))
        angr1=math.radian(-60+(25*t3))
        pub2.publish(angr2)
        pub1.publish(angr1)
    pub2.publish(math.radian(-90))
    pub1.publish(math.radian(0))
    T+=t3
    f2=0
    while angr6<=math.radians(-45) and f3==1:
        t4=(time.time()/1000000000)-T
        angr6=math.radians(-90+(25*t4))
        angr7=math.radians(-(25*t4))
        pub7.publish(angr6)
        pub6.publish(angr7)
    f3=0
    T+=t4
           
    while angr5 <= math.radians(-45):
        t5=(time.time()/1000000000)-T
        angr5=math.radians(-90+(25*t5))
        pub5.publish(angr5)
    T+=t5   
    while angr6>=math.radian(-90) and f4==1:
        t6=(time.time()/1000000000)-T
        angr6=math.radian(-45-(25*t6))
        angr7=math.radian(-60+(25*t6))
        pub6.publish(angr6)
        pub7.publish(angr7)
    pub6.publish(math.radian(-90))
    pub7.publish(math.radian(0))
    f4=0
    T+=t6
           #leg 3
    while angr9<=math.radians(-45) and f5==1:
        t7=(time.time()/1000000000)-T
        angr9=math.radians(-90+(25*t7))
        angr8=math.radians(-(25*t7))
        pub8.publish(angr8)
        pub9.publish(angr9)
    f5=0
    T+=t7
    while angr10 <= math.radians(90):
        t8=(time.time()/1000000000)-T
        angr10=math.radians(45+(25*t8))
        pub10.publish(angr10)
    T+=t8 
    while angr9>=math.radian(-90) and f6==1:
        t9=(time.time()/1000000000)-T
        angr9=math.radian(-45-(25*t9))
        angr10=math.radian(-60+(25*t9))
        pub9.publish(angr9)
        pub10.publish(angr10)
    f6=0
    T+=t9
          #leg4
    while angr13<=math.radians(-45) and f7==1:
        t10=(time.time()/1000000000)-T
        angr13=math.radians(-90+(25*t10))
        angr14=math.radians(-(25*t10))
        pub13.publish(angr13)
        pub14.publish(angr14)
    f7=0
    T+=t10
    while angr12 <= math.radians(45):
        t11=(time.time()/1000000000)-T
        angr12=math.radians(90-(25*t11))
        pub12.publish(angr12)
    T+=t11
    while angr13>=math.radian(-90) and f7==1:
        t12=(time.time()/1000000000)-T
        angr13=math.radian(-45-(25*t12))
        angr14=math.radian(-60+(25*t12))
        pub13.publish(angr13)
        pub14.publish(angr14)
    f7=0
    T+=t12
    pub13.publish(math.radians(-90))
    pub14.publish(math.radians(0))
           
    while(angr3<=math.raidans(-45)):
        t13=(time.time()/1000000000)-T
        angr3=math.radians(-90+(25*t13))
        pub3.publish(angr3)
        angr5=math.radians(-45-(25*t13))
        pub5.publish(angr3)
        angr10=math.radians(-90+(25*t13))
        pub10.publish(angr3)
        angr12=math.radians(-45-(25*t13))
        pub12.publish(angr3)
    T+=t13
if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
