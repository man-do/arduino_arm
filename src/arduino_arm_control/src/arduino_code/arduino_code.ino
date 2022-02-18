#include <Servo.h>
#include <ServoEasing.hpp>
#include <ros.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/Float32MultiArray.h>
#include <sensor_msgs/JointState.h>


ServoEasing servo9;
ServoEasing servo10;
ServoEasing servo11;

#define HOME_ANGLE 90
#define JOINT_VEL_FAST 60
#define JOINT_VEL__SLOW 30

void servos_cb(const sensor_msgs::JointState& cmd_msg){

  Serial.println(cmd_msg.position[0]);
  
}

ros::NodeHandle nh;

ros::Subscriber<sensor_msgs::JointState> jointCmdSub("/arduino/jointCmd", servos_cb);

sensor_msgs::JointState state_msg;

ros::Publisher jointStatePub("arduino/jointState", &state_msg); 

void setup() {
  Serial.begin(115200);
  
  /*  Joint pins
   *  base_link1_joint 9
   * link1_link2_joint 10
   * link2_link3_joint 11
  */

  servo9.attach(9, HOME_ANGLE);
  servo10.attach(10, HOME_ANGLE);
  servo11.attach(11, HOME_ANGLE);


  nh.advertise(jointStatePub);
  nh.subscribe(jointCmdSub);
}

void loop() {
  //servo9.startEaseTo(180, JOINT_VEL_FAST);
  //servo10.startEaseTo(0, JOINT_VEL_FAST);
  //Serial.print( servo9.getCurrentAngle());
  //Serial.print(",");
  //Serial.println( servo10.getCurrentAngle());

  nh.spinOnce();
  delay(1);
}

double radiansToDegrees(float position_radians)
{

  position_radians = position_radians + 1.6;

  return position_radians * 57.2958;

}
