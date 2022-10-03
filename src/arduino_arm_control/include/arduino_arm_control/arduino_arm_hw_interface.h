#ifndef ARDUINO_ARM_HW_INTERFACE_H
#define ARDUINO_ARM_HW_INTERFACE_H

#include <ros_control_boilerplate/generic_hw_interface.h>
#include <arduino_arm_control/jointState.h>
#include <arduino_arm_control/jointCmd.h>

#define DEG_TO_RAD 0.01745329251
#define RAD_TO_DEG 57.2957795131

namespace arduino_arm_ns
{
  class ArduinoArmHWInterface : public ros_control_boilerplate::GenericHWInterface
  {
  public:
    ArduinoArmHWInterface(ros::NodeHandle &nh, urdf::Model *urdf_model = NULL);

    virtual void init();

    virtual void read(ros::Duration &elapsed_time);

    virtual void write(ros::Duration &elapsed_time);

    virtual void enforceLimits(ros::Duration &period);

  protected:
    ros::Subscriber position_sub;

    void joint_state_callback(const arduino_arm_control::jointState::ConstPtr &msg);

    ros::Publisher position_pub;

    std::vector<double> joint_position_prev_;

    // Name of this class
    std::string name_;

  }; // class

} // namespace arduino_arm_ns

#endif
