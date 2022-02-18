#ifndef ARDUINO_ARM_HW_INTERFACE_H
#define ARDUINO_ARM_HW_INTERFACE_H

#include <ros_control_boilerplate/generic_hw_interface.h>
#include <arduino_arm_control/jointCmd.h>
#include <arduino_arm_control/jointState.h>
#include <sensor_msgs/JointState.h>

#define DEG_TO_RAD 0.01745329251
#define RAD_TO_DEG 57.2957795131

namespace arduino_arm_ns
{
/** \brief Hardware interface for arduino arm */
class ArduinoArmHWInterface : public ros_control_boilerplate::GenericHWInterface
{
public:
  /**
   * \brief Constructor
   * \param nh - Node handle for topics.
   */
  ArduinoArmHWInterface(ros::NodeHandle& nh, urdf::Model* urdf_model = NULL);

  /** \brief Initialize the robot hardware interface */
  virtual void init();

  /** \brief Read the state from the robot hardware. */
  virtual void read(ros::Duration& elapsed_time);

  /** \brief Write the command to the robot hardware. */
  virtual void write(ros::Duration& elapsed_time);

  /** \breif Enforce limits for all values before writing */
  virtual void enforceLimits(ros::Duration& period);

protected:
  /** \brief Basic model of system for position control */
  virtual void positionControlSimulation(ros::Duration& elapsed_time, const std::size_t joint_id);

  // Name of this class
  std::string name_;

  // Simulated controller
  double p_error_;
  double v_error_;

  // For position controller to estimate velocity
  std::vector<double> joint_position_prev_;

  // Send commands in different modes
  int sim_control_mode_ = 0;


  ros::Subscriber joint_state_sub;
  void stateCallback(const sensor_msgs::JointState::ConstPtr& msg);

  ros::Publisher joint_cmd_pub;

};  // class

}  // namespace ardunio_arm_ns

#endif
