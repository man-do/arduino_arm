#ifndef _ROS_quadrotor_msgs_Trajectory_h
#define _ROS_quadrotor_msgs_Trajectory_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "quadrotor_msgs/TrajectoryPoint.h"

namespace quadrotor_msgs
{

  class Trajectory : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _type_type;
      _type_type type;
      uint32_t points_length;
      typedef quadrotor_msgs::TrajectoryPoint _points_type;
      _points_type st_points;
      _points_type * points;
      enum { UNDEFINED = 0 };
      enum { GENERAL = 1 };
      enum { ACCELERATION = 2 };
      enum { JERK = 3 };
      enum { SNAP = 4 };

    Trajectory():
      header(),
      type(0),
      points_length(0), st_points(), points(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      *(outbuffer + offset + 0) = (this->points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->points_length);
      for( uint32_t i = 0; i < points_length; i++){
      offset += this->points[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      uint32_t points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->points_length);
      if(points_lengthT > points_length)
        this->points = (quadrotor_msgs::TrajectoryPoint*)realloc(this->points, points_lengthT * sizeof(quadrotor_msgs::TrajectoryPoint));
      points_length = points_lengthT;
      for( uint32_t i = 0; i < points_length; i++){
      offset += this->st_points.deserialize(inbuffer + offset);
        memcpy( &(this->points[i]), &(this->st_points), sizeof(quadrotor_msgs::TrajectoryPoint));
      }
     return offset;
    }

    virtual const char * getType() override { return "quadrotor_msgs/Trajectory"; };
    virtual const char * getMD5() override { return "336a821d34c863b8682f8bb8399b4618"; };

  };

}
#endif
