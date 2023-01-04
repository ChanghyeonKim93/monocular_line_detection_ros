#ifndef _IMAGE_NODE_ROS_
#define _IMAGE_NODE_ROS_

#include <iostream>
#include "ros/ros.h"

#include "sensor_msgs/Image.h" // for 'image'

#include "opencv2/core.hpp"

#include "cv_bridge/cv_bridge.h"


class ImageNodeROS
{
private:
    ros::NodeHandle nh_;

// Subscribers
private:
    ros::Subscriber sub_image_;

    std::string topicname_image_;

// Publishers
private:
    ros::Publisher pub_empty_; // NOT IMPLEMENTED

// CLASS of the YOUR OWN MODULE
private:
    // YSLIBRARY ys_;

public:
    ImageNodeROS(const ros::NodeHandle& nh);

private:
    void callbackImage(const sensor_msgs::ImageConstPtr& msg);

private:
    void run();
    
};

#endif