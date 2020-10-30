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
    pub1 = rospy.Publisher('/motor8/command', Float64, queue_size=10)
    pub2 = rospy.Publisher('/motor9/command', Float64, queue_size=10)
    pub3 = rospy.Publisher('/motor10/command', Float64, queue_size=10)
    pub4 = rospy.Publisher('/motor11/command', Float64, queue_size=10)
    pub5 = rospy.Publisher('/motor12/command', Float64, queue_size=10)
    pub6 = rospy.Publisher('/motor13/command', Float64, queue_size=10)
    pub7 = rospy.Publisher('/motor14/command', Float64, queue_size=10)
    rospy.init_node('linera_prog2', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    t=0
    angr2=0
    angr4=0
    angr6=0
    a=0
    b=0
    pub1.publish(0)
    pub2.publish(math.radians(57)) 
    pub3.publish(0)
    pub4.publish(math.radians(83))
    pub5.publish(0)
    pub6.publish(math.radians(45))
    pub7.publish(0)
    time.sleep(1)
    while not rospy.is_shutdown():

	while a==0:
		pub1.publish(math.radians(14.6))	
		pub2.publish(math.radians(60))	
		pub4.publish(math.radians(116))
		pub6.publish(math.radians(75))
		pub7.publish(math.radians(90))
		a=1;
	time.sleep(7)
	while a==1:
		pub1.publish(math.radians(45.5))
		pub2.publish(math.radians(85))
		pub4.publish(math.radians(90))
		pub6.publish(math.radians(77))
		a=2;
	time.sleep(2)
	while a==2:
		pub3.publish(math.radians(-22))
		pub1.publish(math.radians(14.5))
		pub2.publish(math.radians(60))
		pub4.publish(math.radians(116))
		pub6.publish(math.radians(75))
		a=3;
	time.sleep(2)
	rate.sleep();
	rate.sleep();
## Walk in line of the robot direction
##	while a==0:
##		pub1.publish(math.radians(22.5))
##		pub2.publish(math.radians(42))
##		pub4.publish(math.radians(53))
##		pub6.publish(math.radians(40))
##		pub7.publish(math.radians(50))
##		a=1;
##	time.sleep(2)
##	while a==1:
##		pub1.publish(0)
##  		pub2.publish(math.radians(57)) 
##    		pub4.publish(math.radians(83))
##		pub6.publish(math.radians(45))
##		pub7.publish(0)
##		a=0;
##	time.sleep(2)
##	rate.sleep();

	

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
