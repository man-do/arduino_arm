#include <ros_control_boilerplate/generic_hw_control_loop.h>
#include <arduino_arm_control/arduino_arm_hw_interface.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "arduino_arm_hw_interface");
  ros::NodeHandle nh;

  // NOTE: We run the ROS loop in a separate thread as external calls such
  // as service callbacks to load controllers can block the (main) control loop
  ros::AsyncSpinner spinner(3);
  spinner.start();

  // Create the hardware interface specific to your robot
  std::shared_ptr<arduino_arm_ns::ArduinoArmHWInterface> sim_hw_interface(
      new arduino_arm_ns::ArduinoArmHWInterface(nh));
  sim_hw_interface->init();

  // Start the control loop
  ros_control_boilerplate::GenericHWControlLoop control_loop(nh, sim_hw_interface);
  control_loop.run();  // Blocks until shutdown signal recieved

  return 0;
}
