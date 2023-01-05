#ifndef _MONOCULAR_LINE_DETECTOR_ROS_H_
#define _MONOCULAR_LINE_DETECTOR_ROS_H_

#include <iostream>

// ROS related
#include "ros/ros.h"
#include "sensor_msgs/Image.h" // for 'image'

// OpenCV related
#include "cv_bridge/cv_bridge.h"
#include "opencv2/core.hpp"

#include "opencv2/ximgproc/fast_line_detector.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/ximgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

// Custom library
#include "timer.h"

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
    cv::Ptr<cv::ximgproc::FastLineDetector> fast_line_detector_;

public:
    MonocularLineDetectorROS(const ros::NodeHandle& nh);

private:
    void callbackImage(const sensor_msgs::ImageConstPtr& msg);

private:
    void run();
    
};

#endif