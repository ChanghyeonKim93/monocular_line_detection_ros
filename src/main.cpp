#include <ros/ros.h>

#include <iostream>
#include <string>

#include "image_node_ros.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "line_detection_node");
    ros::NodeHandle nh("~");
    ROS_INFO_STREAM("START: \"line_detection_node node\".\n");
    
    ImageNodeROS img_node_ros(nh);
 
    ROS_INFO_STREAM("line_detection_node - TERMINATE.");
    return -1;
}