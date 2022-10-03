# /usr/bin/env python3
from os import stat
from numpy import angle
from serial import Serial
import rospy
from arduino_arm_control.msg import jointCmd, jointState
import numpy as np

rospy.init_node("serial_comm_node")
r = rospy.Rate(2)
state_pub = rospy.Publisher(
    "/arduino_board/jointState", jointState, queue_size=1)

state = jointState()


def cmd_cb(cmd):
    angles = cmd.angle
    angles = np.array([int(angle+90) for angle in angles])
    (angle1, angle2, angle3) = angles
    angle1 = str(angle1).zfill(3)
    angle2 = str(angle2).zfill(3)
    angle3 = str(angle3).zfill(3)
    string = f"<{angle3},{angle2},{angle1}>".encode()
    print("Sent command: " + string.decode())
    arduino_comm.write(bytes(string))

    feedback()


def feedback():
    arduino_feedback = arduino_comm.readline().decode()
    arduino_feedback = arduino_feedback.replace("\n", "")
    angles = arduino_feedback.split(',')
    angles = [int(angle) - 90 for angle in angles]
    state.angle = angles
    state_pub.publish(state)

    print("Recieved angles: " + arduino_feedback)


def serial_comm():
    cmd_sub = rospy.Subscriber("/arduino_board/jointCmd", jointCmd, cmd_cb)
    #feedback()
    #r.sleep()
    rospy.spin()


if __name__ == '__main__':
    try:
        arduino_comm = Serial("/dev/ttyACM0", 115200)
        serial_comm()
    except rospy.ROSInterruptException:
        pass
