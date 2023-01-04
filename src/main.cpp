#include <ros/ros.h>

#include <iostream>
#include <string>

#include "monocular_line_detector_ros.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "line_detector_node");
    ros::NodeHandle nh("~");
    ROS_INFO_STREAM("START: \"line_detection_node\".\n");
    
    // Init. monocular line detector
    MonocularLineDetectorROS mono_line_detector(nh);
 
    ROS_INFO_STREAM("TERMINATE: \"line_detection_node\".");
    return -1;
}