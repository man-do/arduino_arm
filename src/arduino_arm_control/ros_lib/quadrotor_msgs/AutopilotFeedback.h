#ifndef _ROS_quadrotor_msgs_AutopilotFeedback_h
#define _ROS_quadrotor_msgs_AutopilotFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros/duration.h"
#include "quadrotor_msgs/LowLevelFeedback.h"
#include "quadrotor_msgs/TrajectoryPoint.h"
#include "nav_msgs/Odometry.h"

namespace quadrotor_msgs
{

  class AutopilotFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _autopilot_state_type;
      _autopilot_state_type autopilot_state;
      typedef ros::Duration _control_command_delay_type;
      _control_command_delay_type control_command_delay;
      typedef ros::Duration _control_computation_time_type;
      _control_computation_time_type control_computation_time;
      typedef ros::Duration _trajectory_execution_left_duration_type;
      _trajectory_execution_left_duration_type trajectory_execution_left_duration;
      typedef uint8_t _trajectories_left_in_queue_type;
      _trajectories_left_in_queue_type trajectories_left_in_queue;
      typedef quadrotor_msgs::LowLevelFeedback _low_level_feedback_type;
      _low_level_feedback_type low_level_feedback;
      typedef quadrotor_msgs::TrajectoryPoint _reference_state_type;
      _reference_state_type reference_state;
      typedef nav_msgs::Odometry _state_estimate_type;
      _state_estimate_type state_estimate;
      enum { OFF = 0 };
      enum { START = 1 };
      enum { HOVER = 2 };
      enum { LAND = 3 };
      enum { EMERGENCY_LAND = 4 };
      enum { BREAKING = 5 };
      enum { GO_TO_POSE = 6 };
      enum { VELOCITY_CONTROL = 7 };
      enum { REFERENCE_CONTROL = 8 };
      enum { TRAJECTORY_CONTROL = 9 };
      enum { COMMAND_FEEDTHROUGH = 10 };
      enum { RC_MANUAL = 11 };

    AutopilotFeedback():
      header(),
      autopilot_state(0),
      control_command_delay(),
      control_computation_time(),
      trajectory_execution_left_duration(),
      trajectories_left_in_queue(0),
      low_level_feedback(),
      reference_state(),
      state_estimate()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->autopilot_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->autopilot_state);
      *(outbuffer + offset + 0) = (this->control_command_delay.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->control_command_delay.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->control_command_delay.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->control_command_delay.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->control_command_delay.sec);
      *(outbuffer + offset + 0) = (this->control_command_delay.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->control_command_delay.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->control_command_delay.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->control_command_delay.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->control_command_delay.nsec);
      *(outbuffer + offset + 0) = (this->control_computation_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->control_computation_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->control_computation_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->control_computation_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->control_computation_time.sec);
      *(outbuffer + offset + 0) = (this->control_computation_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->control_computation_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->control_computation_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->control_computation_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->control_computation_time.nsec);
      *(outbuffer + offset + 0) = (this->trajectory_execution_left_duration.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->trajectory_execution_left_duration.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->trajectory_execution_left_duration.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->trajectory_execution_left_duration.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->trajectory_execution_left_duration.sec);
      *(outbuffer + offset + 0) = (this->trajectory_execution_left_duration.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->trajectory_execution_left_duration.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->trajectory_execution_left_duration.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->trajectory_execution_left_duration.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->trajectory_execution_left_duration.nsec);
      *(outbuffer + offset + 0) = (this->trajectories_left_in_queue >> (8 * 0)) & 0xFF;
      offset += sizeof(this->trajectories_left_in_queue);
      offset += this->low_level_feedback.serialize(outbuffer + offset);
      offset += this->reference_state.serialize(outbuffer + offset);
      offset += this->state_estimate.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->autopilot_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->autopilot_state);
      this->control_command_delay.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->control_command_delay.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->control_command_delay.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->control_command_delay.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->control_command_delay.sec);
      this->control_command_delay.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->control_command_delay.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->control_command_delay.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->control_command_delay.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->control_command_delay.nsec);
      this->control_computation_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->control_computation_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->control_computation_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->control_computation_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->control_computation_time.sec);
      this->control_computation_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->control_computation_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->control_computation_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->control_computation_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->control_computation_time.nsec);
      this->trajectory_execution_left_duration.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->trajectory_execution_left_duration.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->trajectory_execution_left_duration.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->trajectory_execution_left_duration.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->trajectory_execution_left_duration.sec);
      this->trajectory_execution_left_duration.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->trajectory_execution_left_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->trajectory_execution_left_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->trajectory_execution_left_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->trajectory_execution_left_duration.nsec);
      this->trajectories_left_in_queue =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->trajectories_left_in_queue);
      offset += this->low_level_feedback.deserialize(inbuffer + offset);
      offset += this->reference_state.deserialize(inbuffer + offset);
      offset += this->state_estimate.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "quadrotor_msgs/AutopilotFeedback"; };
    virtual const char * getMD5() override { return "e230aa37fee8c7210a7d3139a5dbecdb"; };

  };

}
#endif
