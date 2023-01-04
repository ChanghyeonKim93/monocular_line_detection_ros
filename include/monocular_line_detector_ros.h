#ifndef _MONOCULAR_LINE_DETECTOR_ROS_H_
#define _MONOCULAR_LINE_DETECTOR_ROS_H_

#include <iostream>
#include "ros/ros.h"

#include "sensor_msgs/Image.h" // for 'image'

#include "opencv2/core.hpp"

#include "cv_bridge/cv_bridge.h"


class MonocularLineDetectorROS
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
    // YourLibrary yl_;

public:
    MonocularLineDetectorROS(const ros::NodeHandle& nh);

private:
    void callbackImage(const sensor_msgs::ImageConstPtr& msg);

private:
    void run();
    
};

#endif