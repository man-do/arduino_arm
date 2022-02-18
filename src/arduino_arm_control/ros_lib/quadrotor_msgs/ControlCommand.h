#ifndef _ROS_quadrotor_msgs_ControlCommand_h
#define _ROS_quadrotor_msgs_ControlCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros/time.h"
#include "geometry_msgs/Quaternion.h"
#include "geometry_msgs/Vector3.h"

namespace quadrotor_msgs
{

  class ControlCommand : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _control_mode_type;
      _control_mode_type control_mode;
      typedef bool _armed_type;
      _armed_type armed;
      typedef ros::Time _expected_execution_time_type;
      _expected_execution_time_type expected_execution_time;
      typedef geometry_msgs::Quaternion _orientation_type;
      _orientation_type orientation;
      typedef geometry_msgs::Vector3 _bodyrates_type;
      _bodyrates_type bodyrates;
      typedef geometry_msgs::Vector3 _angular_accelerations_type;
      _angular_accelerations_type angular_accelerations;
      typedef float _collective_thrust_type;
      _collective_thrust_type collective_thrust;
      uint32_t rotor_thrusts_length;
      typedef float _rotor_thrusts_type;
      _rotor_thrusts_type st_rotor_thrusts;
      _rotor_thrusts_type * rotor_thrusts;
      enum { NONE = 0 };
      enum { ATTITUDE = 1 };
      enum { BODY_RATES = 2 };
      enum { ANGULAR_ACCELERATIONS = 3 };
      enum { ROTOR_THRUSTS = 4 };

    ControlCommand():
      header(),
      control_mode(0),
      armed(0),
      expected_execution_time(),
      orientation(),
      bodyrates(),
      angular_accelerations(),
      collective_thrust(0),
      rotor_thrusts_length(0), st_rotor_thrusts(), rotor_thrusts(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->control_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->control_mode);
      union {
        bool real;
        uint8_t base;
      } u_armed;
      u_armed.real = this->armed;
      *(outbuffer + offset + 0) = (u_armed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->armed);
      *(outbuffer + offset + 0) = (this->expected_execution_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->expected_execution_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->expected_execution_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->expected_execution_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->expected_execution_time.sec);
      *(outbuffer + offset + 0) = (this->expected_execution_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->expected_execution_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->expected_execution_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->expected_execution_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->expected_execution_time.nsec);
      offset += this->orientation.serialize(outbuffer + offset);
      offset += this->bodyrates.serialize(outbuffer + offset);
      offset += this->angular_accelerations.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->collective_thrust);
      *(outbuffer + offset + 0) = (this->rotor_thrusts_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rotor_thrusts_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->rotor_thrusts_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->rotor_thrusts_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rotor_thrusts_length);
      for( uint32_t i = 0; i < rotor_thrusts_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->rotor_thrusts[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->control_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->control_mode);
      union {
        bool real;
        uint8_t base;
      } u_armed;
      u_armed.base = 0;
      u_armed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->armed = u_armed.real;
      offset += sizeof(this->armed);
      this->expected_execution_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->expected_execution_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->expected_execution_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->expected_execution_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->expected_execution_time.sec);
      this->expected_execution_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->expected_execution_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->expected_execution_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->expected_execution_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->expected_execution_time.nsec);
      offset += this->orientation.deserialize(inbuffer + offset);
      offset += this->bodyrates.deserialize(inbuffer + offset);
      offset += this->angular_accelerations.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->collective_thrust));
      uint32_t rotor_thrusts_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      rotor_thrusts_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      rotor_thrusts_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      rotor_thrusts_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->rotor_thrusts_length);
      if(rotor_thrusts_lengthT > rotor_thrusts_length)
        this->rotor_thrusts = (float*)realloc(this->rotor_thrusts, rotor_thrusts_lengthT * sizeof(float));
      rotor_thrusts_length = rotor_thrusts_lengthT;
      for( uint32_t i = 0; i < rotor_thrusts_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_rotor_thrusts));
        memcpy( &(this->rotor_thrusts[i]), &(this->st_rotor_thrusts), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return "quadrotor_msgs/ControlCommand"; };
    virtual const char * getMD5() override { return "a1918a34164f6647c898e4d55efbfcef"; };

  };

}
#endif
