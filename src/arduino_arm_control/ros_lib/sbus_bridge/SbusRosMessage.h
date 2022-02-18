#ifndef _ROS_sbus_bridge_SbusRosMessage_h
#define _ROS_sbus_bridge_SbusRosMessage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace sbus_bridge
{

  class SbusRosMessage : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint16_t channels[16];
      typedef bool _digital_channel_1_type;
      _digital_channel_1_type digital_channel_1;
      typedef bool _digital_channel_2_type;
      _digital_channel_2_type digital_channel_2;
      typedef bool _frame_lost_type;
      _frame_lost_type frame_lost;
      typedef bool _failsafe_type;
      _failsafe_type failsafe;

    SbusRosMessage():
      header(),
      channels(),
      digital_channel_1(0),
      digital_channel_2(0),
      frame_lost(0),
      failsafe(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 16; i++){
      *(outbuffer + offset + 0) = (this->channels[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->channels[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->channels[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_digital_channel_1;
      u_digital_channel_1.real = this->digital_channel_1;
      *(outbuffer + offset + 0) = (u_digital_channel_1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->digital_channel_1);
      union {
        bool real;
        uint8_t base;
      } u_digital_channel_2;
      u_digital_channel_2.real = this->digital_channel_2;
      *(outbuffer + offset + 0) = (u_digital_channel_2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->digital_channel_2);
      union {
        bool real;
        uint8_t base;
      } u_frame_lost;
      u_frame_lost.real = this->frame_lost;
      *(outbuffer + offset + 0) = (u_frame_lost.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->frame_lost);
      union {
        bool real;
        uint8_t base;
      } u_failsafe;
      u_failsafe.real = this->failsafe;
      *(outbuffer + offset + 0) = (u_failsafe.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->failsafe);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 16; i++){
      this->channels[i] =  ((uint16_t) (*(inbuffer + offset)));
      this->channels[i] |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->channels[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_digital_channel_1;
      u_digital_channel_1.base = 0;
      u_digital_channel_1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->digital_channel_1 = u_digital_channel_1.real;
      offset += sizeof(this->digital_channel_1);
      union {
        bool real;
        uint8_t base;
      } u_digital_channel_2;
      u_digital_channel_2.base = 0;
      u_digital_channel_2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->digital_channel_2 = u_digital_channel_2.real;
      offset += sizeof(this->digital_channel_2);
      union {
        bool real;
        uint8_t base;
      } u_frame_lost;
      u_frame_lost.base = 0;
      u_frame_lost.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->frame_lost = u_frame_lost.real;
      offset += sizeof(this->frame_lost);
      union {
        bool real;
        uint8_t base;
      } u_failsafe;
      u_failsafe.base = 0;
      u_failsafe.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->failsafe = u_failsafe.real;
      offset += sizeof(this->failsafe);
     return offset;
    }

    virtual const char * getType() override { return "sbus_bridge/SbusRosMessage"; };
    virtual const char * getMD5() override { return "89ed6f5b79cb6f2d42c97b061bec3101"; };

  };

}
#endif
