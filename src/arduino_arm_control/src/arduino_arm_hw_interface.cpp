#include <arduino_arm_control/arduino_arm_hw_interface.h>

// ROS parameter loading
#include <rosparam_shortcuts/rosparam_shortcuts.h>


namespace arduino_arm_ns
{
ArduinoArmHWInterface::ArduinoArmHWInterface(ros::NodeHandle& nh, urdf::Model* urdf_model)
  : ros_control_boilerplate::GenericHWInterface(nh, urdf_model), name_("arduino_arm_hw_interface")
{
  joint_state_sub = nh.subscribe("/arduino/jointState", 1, &ArduinoArmHWInterface::stateCallback , this);

  joint_cmd_pub = nh.advertise<sensor_msgs::JointState>("/arduino/jointCmd", 3);

  ROS_INFO("ArduinoArmHWInterface declared.");
}

void ArduinoArmHWInterface::stateCallback(const sensor_msgs::JointState::ConstPtr& msg)
{
  /*
  std_msgs/Header header
    uint32 seq
    time stamp
    string frame_id
  string[] name
  float64[] position
  float64[] velocity
  float64[] effort

  */

  for(int joint_id=0; joint_id<num_joints_; joint_id++){
      joint_velocity_[joint_id] = msg->velocity[joint_id]*DEG_TO_RAD;
      joint_position_[joint_id] = msg->position[joint_id]*DEG_TO_RAD;
    }

}

void ArduinoArmHWInterface::init()
{
  // Call parent class version of this function
  ros_control_boilerplate::GenericHWInterface::init();

  // Resize vectors
  joint_position_prev_.resize(num_joints_, 0.0);

}

void ArduinoArmHWInterface::read(ros::Duration& elapsed_time)
{
}

void ArduinoArmHWInterface::write(ros::Duration& elapsed_time)
{
  // Safety
  enforceLimits(elapsed_time);


/*  Commands
  std::vector<double> joint_position_command_;
  std::vector<double> joint_velocity_command_;
  std::vector<double> joint_effort_command_;
  
  JointState.msg
  std_msgs/Header header
    uint32 seq
    time stamp
    string frame_id
  string[] name
  float64[] position
  float64[] velocity
  float64[] effort


*/

  // only publish a msg if it has a change
  bool change_detected=false;
  for(int i=0; i<num_joints_; i++){
    if(joint_position_prev_[i] != joint_position_command_[i]){
      change_detected=true;
      i=num_joints_; // exit loop
    }
  }

  static sensor_msgs::JointState cmd_;

  for (std::size_t joint_id = 0; joint_id < num_joints_; ++joint_id)
  {
      cmd_.position[joint_id] = joint_position_command_[joint_id]*RAD_TO_DEG;
      cmd_.velocity[joint_id] = joint_velocity_command_[joint_id];

      joint_position_prev_[joint_id]=joint_position_command_[joint_id];
  
  }
}

void ArduinoArmHWInterface::enforceLimits(ros::Duration& period)
{
  // Enforces position and velocity
  pos_jnt_sat_interface_.enforceLimits(period);
}

void ArduinoArmHWInterface::positionControlSimulation(ros::Duration& elapsed_time, const std::size_t joint_id)
{
  const double max_delta_pos = joint_velocity_limits_[joint_id] * elapsed_time.toSec();

  // Move all the states to the commanded set points at max velocity
  p_error_ = joint_position_command_[joint_id] - joint_position_[joint_id];

  const double delta_pos = std::max(std::min(p_error_, max_delta_pos), -max_delta_pos);
  joint_position_[joint_id] += delta_pos;

  // Bypass max velocity p controller:
  // joint_position_[joint_id] = joint_position_command_[joint_id];

  // Calculate velocity based on change in positions
  if (elapsed_time.toSec() > 0)
  {
    joint_velocity_[joint_id] = (joint_position_[joint_id] - joint_position_prev_[joint_id]) / elapsed_time.toSec();
  }
  else
    joint_velocity_[joint_id] = 0;

  // Save last position
  joint_position_prev_[joint_id] = joint_position_[joint_id];
}

}  // namespace arduino_arm
