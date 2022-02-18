#ifndef _ROS_quadrotor_msgs_TrajectoryPoint_h
#define _ROS_quadrotor_msgs_TrajectoryPoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/duration.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Twist.h"

namespace quadrotor_msgs
{

  class TrajectoryPoint : public ros::Msg
  {
    public:
      typedef ros::Duration _time_from_start_type;
      _time_from_start_type time_from_start;
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;
      typedef geometry_msgs::Twist _velocity_type;
      _velocity_type velocity;
      typedef geometry_msgs::Twist _acceleration_type;
      _acceleration_type acceleration;
      typedef geometry_msgs::Twist _jerk_type;
      _jerk_type jerk;
      typedef geometry_msgs::Twist _snap_type;
      _snap_type snap;
      typedef float _heading_type;
      _heading_type heading;
      typedef float _heading_rate_type;
      _heading_rate_type heading_rate;
      typedef float _heading_acceleration_type;
      _heading_acceleration_type heading_acceleration;

    TrajectoryPoint():
      time_from_start(),
      pose(),
      velocity(),
      acceleration(),
      jerk(),
      snap(),
      heading(0),
      heading_rate(0),
      heading_acceleration(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->time_from_start.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_from_start.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_from_start.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_from_start.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_from_start.sec);
      *(outbuffer + offset + 0) = (this->time_from_start.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_from_start.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_from_start.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_from_start.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_from_start.nsec);
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->velocity.serialize(outbuffer + offset);
      offset += this->acceleration.serialize(outbuffer + offset);
      offset += this->jerk.serialize(outbuffer + offset);
      offset += this->snap.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->heading);
      offset += serializeAvrFloat64(outbuffer + offset, this->heading_rate);
      offset += serializeAvrFloat64(outbuffer + offset, this->heading_acceleration);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->time_from_start.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_from_start.sec);
      this->time_from_start.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_from_start.nsec);
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->velocity.deserialize(inbuffer + offset);
      offset += this->acceleration.deserialize(inbuffer + offset);
      offset += this->jerk.deserialize(inbuffer + offset);
      offset += this->snap.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->heading));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->heading_rate));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->heading_acceleration));
     return offset;
    }

    virtual const char * getType() override { return "quadrotor_msgs/TrajectoryPoint"; };
    virtual const char * getMD5() override { return "a3e9ef9667402c342c2c39b23c07961d"; };

  };

}
#endif
