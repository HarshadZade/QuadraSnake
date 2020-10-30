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
    pub8 = rospy.Publisher('/motor1/command', Float64, queue_size=10)
    pub9 = rospy.Publisher('/motor2/command', Float64, queue_size=10)
    pub10 = rospy.Publisher('/motor3/command', Float64, queue_size=10)
    pub11 = rospy.Publisher('/motor4/command', Float64, queue_size=10)
    pub12 = rospy.Publisher('/motor5/command', Float64, queue_size=10)
    pub13 = rospy.Publisher('/motor6/command', Float64, queue_size=10)
    pub14= rospy.Publisher('/motor19/command', Float64, queue_size=10)
    rospy.init_node('talker1', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    t=0,f=0
    angr2=0
    angr1=0
    a=1
    b=0
    s=0
    time=0
    while not rospy.is_shutdown():
	       while f==0:
               while angr2<=math.radians(90):
                   angr1=math.radians(-10*b)
                   angr2=math.radians(10*b)
                   pub8.publish(angr2)
                   pub9.publish(angr1)
                   pub10.publish(math.radians(-90))
                   pub11.publish(0)
                   pub12.publish(math.radians(-90))
                   pub13.publish(angr1)
                   pub14.publish(angr2)
                   rate.sleep()
                   t=((time.time()/1000000000)+(b/10))
                   b + 1
               time=t
               pub9.publish(math.radians(-90))
               pub10.publish(math.radians(-90))
               pub11.publish(math.radians(0))
               pub12.publish(math.radians(-90))
               pub13.publish(math.radians(-90))
               while angr2>math.radians(0):
                   
                   t=((time.time()/1000000000)+(s/10))-time
                   s+1
                   angr2=math.radians(90-5*s)
                   pub8.publish(angr2)
                   pub14.publish(angr2)
                   rate.sleep()
                f=1
                

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
