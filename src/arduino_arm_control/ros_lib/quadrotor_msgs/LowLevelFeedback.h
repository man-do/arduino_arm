#ifndef _ROS_quadrotor_msgs_LowLevelFeedback_h
#define _ROS_quadrotor_msgs_LowLevelFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace quadrotor_msgs
{

  class LowLevelFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _battery_voltage_type;
      _battery_voltage_type battery_voltage;
      typedef uint8_t _battery_state_type;
      _battery_state_type battery_state;
      typedef uint8_t _control_mode_type;
      _control_mode_type control_mode;
      uint32_t motor_speeds_length;
      typedef int16_t _motor_speeds_type;
      _motor_speeds_type st_motor_speeds;
      _motor_speeds_type * motor_speeds;
      uint32_t thrust_mapping_coeffs_length;
      typedef float _thrust_mapping_coeffs_type;
      _thrust_mapping_coeffs_type st_thrust_mapping_coeffs;
      _thrust_mapping_coeffs_type * thrust_mapping_coeffs;
      enum { BAT_INVALID = 0 };
      enum { BAT_GOOD = 1 };
      enum { BAT_LOW = 2 };
      enum { BAT_CRITICAL = 3 };
      enum { NONE = 0 };
      enum { ATTITUDE = 1 };
      enum { BODY_RATES = 2 };
      enum { ANGULAR_ACCELERATION = 3 };
      enum { ROTOR_THRUSTS = 4 };
      enum { RC_MANUAL = 10 };

    LowLevelFeedback():
      header(),
      battery_voltage(0),
      battery_state(0),
      control_mode(0),
      motor_speeds_length(0), st_motor_speeds(), motor_speeds(nullptr),
      thrust_mapping_coeffs_length(0), st_thrust_mapping_coeffs(), thrust_mapping_coeffs(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_battery_voltage;
      u_battery_voltage.real = this->battery_voltage;
      *(outbuffer + offset + 0) = (u_battery_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_battery_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_battery_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_battery_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->battery_voltage);
      *(outbuffer + offset + 0) = (this->battery_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->battery_state);
      *(outbuffer + offset + 0) = (this->control_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->control_mode);
      *(outbuffer + offset + 0) = (this->motor_speeds_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->motor_speeds_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->motor_speeds_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->motor_speeds_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor_speeds_length);
      for( uint32_t i = 0; i < motor_speeds_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_motor_speedsi;
      u_motor_speedsi.real = this->motor_speeds[i];
      *(outbuffer + offset + 0) = (u_motor_speedsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor_speedsi.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->motor_speeds[i]);
      }
      *(outbuffer + offset + 0) = (this->thrust_mapping_coeffs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->thrust_mapping_coeffs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->thrust_mapping_coeffs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->thrust_mapping_coeffs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->thrust_mapping_coeffs_length);
      for( uint32_t i = 0; i < thrust_mapping_coeffs_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->thrust_mapping_coeffs[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_battery_voltage;
      u_battery_voltage.base = 0;
      u_battery_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_battery_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_battery_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_battery_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->battery_voltage = u_battery_voltage.real;
      offset += sizeof(this->battery_voltage);
      this->battery_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->battery_state);
      this->control_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->control_mode);
      uint32_t motor_speeds_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      motor_speeds_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      motor_speeds_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      motor_speeds_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->motor_speeds_length);
      if(motor_speeds_lengthT > motor_speeds_length)
        this->motor_speeds = (int16_t*)realloc(this->motor_speeds, motor_speeds_lengthT * sizeof(int16_t));
      motor_speeds_length = motor_speeds_lengthT;
      for( uint32_t i = 0; i < motor_speeds_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_motor_speeds;
      u_st_motor_speeds.base = 0;
      u_st_motor_speeds.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_motor_speeds.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_motor_speeds = u_st_motor_speeds.real;
      offset += sizeof(this->st_motor_speeds);
        memcpy( &(this->motor_speeds[i]), &(this->st_motor_speeds), sizeof(int16_t));
      }
      uint32_t thrust_mapping_coeffs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      thrust_mapping_coeffs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      thrust_mapping_coeffs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      thrust_mapping_coeffs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->thrust_mapping_coeffs_length);
      if(thrust_mapping_coeffs_lengthT > thrust_mapping_coeffs_length)
        this->thrust_mapping_coeffs = (float*)realloc(this->thrust_mapping_coeffs, thrust_mapping_coeffs_lengthT * sizeof(float));
      thrust_mapping_coeffs_length = thrust_mapping_coeffs_lengthT;
      for( uint32_t i = 0; i < thrust_mapping_coeffs_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_thrust_mapping_coeffs));
        memcpy( &(this->thrust_mapping_coeffs[i]), &(this->st_thrust_mapping_coeffs), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return "quadrotor_msgs/LowLevelFeedback"; };
    virtual const char * getMD5() override { return "e3cfad3ba98dfdc505bcf1fe91833d87"; };

  };

}
#endif
