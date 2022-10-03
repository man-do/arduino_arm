#include <arduino_arm_control/arduino_arm_hw_interface.h>

namespace arduino_arm_ns
{
  ArduinoArmHWInterface::ArduinoArmHWInterface(ros::NodeHandle &nh, urdf::Model *urdf_model)
      : ros_control_boilerplate::GenericHWInterface(nh, urdf_model)
  {
    ROS_INFO_NAMED("arduino_arm_hw_interface", "ArduinoArmHWInterface Ready.");

    position_sub = nh.subscribe("/arduino_board/jointState", 1, &ArduinoArmHWInterface::joint_state_callback, this);

    position_pub = nh.advertise<arduino_arm_control::jointCmd>("/arduino_board/jointCmd", 3);

    ROS_INFO("ArduinoArmHWInterface declared");
  }

  void ArduinoArmHWInterface::init()
  {
    ros_control_boilerplate::GenericHWInterface::init();

    // array for storing previous state (for velocity calculation)
    joint_position_prev_.resize(joint_position_.size());

    ROS_INFO("ArduinoArmHWInterface initiated.");
  }

  void ArduinoArmHWInterface::joint_state_callback(const arduino_arm_control::jointState::ConstPtr &msg)
  {
    /*
    #Header header
    float32[3] angle # degrees
    float32[3] vel # deg/s
    */

    for (int i = 0; i < num_joints_; i++)
    {
      joint_velocity_[i] = msg->vel[i] * DEG_TO_RAD; // declared in GenericHWInterface
      joint_position_[i] = msg->angle[i] * DEG_TO_RAD;
    }
  }

  void ArduinoArmHWInterface::read(ros::Duration &elapsed_time)
  {
  }

  void ArduinoArmHWInterface::write(ros::Duration &elapsed_time)
  {
    // Safety
    enforceLimits(elapsed_time);

    static arduino_arm_control::jointCmd cmd_;

    /*
    float32[3] vel #deg/s
    float32[3] angle #deg
    uint32 msg_ctr # count sent msgs to detected missed messages
    */

    /*
    caculate at a much higher rate then needed. then only send ones needed to fill buffer.
    */

    // only publish a msg if it has a change
    bool change_detected = false;
    for (int i = 0; i < num_joints_; i++)
    {
      if (joint_position_prev_[i] != joint_position_command_[i])
      {
        change_detected = true;
        i = num_joints_; // exit loop
      }
    }

    // if a new msg is available then send it
    if (change_detected)
    {
      for (int i = 0; i < num_joints_; i++)
      {
        //ROS_INFO("%f", joint_position_command_[i]);
        cmd_.angle[i] = joint_position_command_[i] * RAD_TO_DEG;
        cmd_.vel[i] = (fabs(joint_position_command_[i] - joint_position_prev_[i]) * RAD_TO_DEG) / elapsed_time.toSec(); // (must be positive for aubo) joint_velocity_command_[i]*RAD_TO_DEG; joint_velocity_command_[i] calculate my own velocities
        // cmd_.eff[i]=joint_effort_command_[i];

        joint_position_prev_[i] = joint_position_command_[i];
      }

      position_pub.publish(cmd_);

    } // changed detected
  }

  void ArduinoArmHWInterface::enforceLimits(ros::Duration &period)
  {
    pos_jnt_sat_interface_.enforceLimits(period);
  }

} // namespace rrbot_control
