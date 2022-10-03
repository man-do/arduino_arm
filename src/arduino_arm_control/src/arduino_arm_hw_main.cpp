#include <ros_control_boilerplate/generic_hw_control_loop.h>
#include <arduino_arm_control/arduino_arm_hw_interface.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "arduino_arm_hw_interface");
  ros::NodeHandle nh;

  ros::AsyncSpinner spinner(3);
  spinner.start();

  std::shared_ptr<arduino_arm_ns::ArduinoArmHWInterface> arduino_arm_hw_interface(new arduino_arm_ns::ArduinoArmHWInterface(nh));
  arduino_arm_hw_interface->init();

  ros_control_boilerplate::GenericHWControlLoop control_loop(nh, arduino_arm_hw_interface);
  control_loop.run();

  return 0;
}
