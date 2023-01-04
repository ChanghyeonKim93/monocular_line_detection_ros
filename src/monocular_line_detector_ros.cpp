#include "monocular_line_detector_ros.h"


MonocularLineDetectorROS::MonocularLineDetectorROS(const ros::NodeHandle& nh)
: nh_(nh), topicname_image_("")
{
    // Check whether needed parameters exist or not.
    if(ros::param::has("~topicname_image"))
        ros::param::get("~topicname_image",topicname_image_);
    else
        throw std::runtime_error("There is no 'topicname_image'.");


    // std::cout << topicname_image_ << std::endl;

    // Subcribe
    sub_image_ = 
        nh_.subscribe<sensor_msgs::Image>(topicname_image_, 1, 
                                          &MonocularLineDetectorROS::callbackImage, this);
    
    // Publish
    

    // Construct YOUR library
    // 

    // run
    this->run();

    ROS_INFO_STREAM("MonocularLineDetectorROS is constructed.");
};


void MonocularLineDetectorROS::run()
{
    ros::Rate rate(500);
    while(ros::ok()) {
        // ROS_INFO_STREAM("RUN!");
        ros::spinOnce();
        rate.sleep();
    };
};

void MonocularLineDetectorROS::callbackImage(const sensor_msgs::ImageConstPtr& msg)
{
    // msg -> cv::Mat img
    ROS_INFO_STREAM("CALLBACK Image!");
    cv_bridge::CvImagePtr cv_ptr;
    cv_ptr = cv_bridge::toCvCopy(msg, msg->encoding); 

    cv::Mat img = cv_ptr->image;
    ROS_INFO_STREAM("Size : " << img.cols << ", " << img.rows);

    // YOUR algorithm !
    // Do Yourself


    // Done.
};