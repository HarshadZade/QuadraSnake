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
    rospy.init_node('linera_prog2', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    t=0
    angr2=0
    angr4=0
    angr6=0
    a=0
    b=0
    pub1.publish(math.radians(0))
    pub2.publish(math.radians(90))
    pub3.publish(math.radians(-45))
    pub4.publish(0)
    pub5.publish(math.radians(-92))
    pub6.publish(math.radians(90))
    pub7.publish(math.radians(0))
    pub8.publish(math.radians(0))
    pub9.publish(math.radians(90))
    pub10.publish(math.radians(-45))
    pub11.publish(0)
    pub12.publish(math.radians(-92))
    pub13.publish(math.radians(90))
    pub14.publish(math.radians(0))
    time.sleep(2)
    while not rospy.is_shutdown():
	while a==0:
		##Lift 1st leg
##		pub1.publish(math.radians(-3.5))
##		pub2.publish(math.radians(90))
##		pub3.publish(math.radians(-58.69))
##		pub4.publish(0)   
##	    	pub5.publish(math.radians(-90))
		pub7.publish(math.radians(60))
##		time.sleep(1)
		pub6.publish(math.radians(30))   
		a=1;
	time.sleep(1)
	while a==1:
		##Move forward and keep the foot down
		pub5.publish(math.radians(-50))
		time.sleep(1)
		pub7.publish(math.radians(0))
		pub6.publish(math.radians(90))
##		pub6.publish(math.radians(50))	
##		pub7.publish(math.radians(80))   
		a=2;
	time.sleep(2)
	while a==2: 
		##Lift 2nd leg
		pub1.publish(math.radians(45))
		pub2.publish(math.radians(30))
		a=3;
	time.sleep(1)
	while a==3:
		##Move forward and keep the foot down
		pub3.publish(math.radians(-90))
		time.sleep(1)
		pub1.publish(math.radians(0))
		pub2.publish(math.radians(90))  
		a=4;
	time.sleep(2)
	while a==4:
		##Lift 3rd leg
		pub13.publish(math.radians(20))
		pub14.publish(math.radians(80))
		a=5;
	time.sleep(1)
	while a==5:
		##Move forward and keep the foot down
		pub12.publish(math.radians(-50))
		time.sleep(1)
		pub14.publish(math.radians(0))
		pub13.publish(math.radians(90))
		a=6;
	time.sleep(2)
	while a==6: 
		##Lift 4th leg
		pub8.publish(math.radians(80))
		pub9.publish(math.radians(30))
		a=7;
	time.sleep(1)
	while a==7:
		##Move forward and keep the foot down
		pub10.publish(math.radians(-90))
		time.sleep(1)
		pub8.publish(math.radians(0))
		pub9.publish(math.radians(90))  
		a=8;
	time.sleep(2)
	while a==8:
		##All the hip joints to orginal position
		pub3.publish(math.radians(-45))
		pub5.publish(math.radians(-92))
		pub10.publish(math.radians(-45))
		pub12.publish(math.radians(-92))  
		a=0;
	time.sleep(3)
	rate.sleep();

	

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
