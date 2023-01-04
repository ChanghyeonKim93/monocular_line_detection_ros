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
    // Create FLD detector
    // Param               Default value   Description
    // length_threshold    10            - Segments shorter than this will be discarded
    // distance_threshold  1.41421356    - A point placed from a hypothesis line
    //                                     segment farther than this will be
    //                                     regarded as an outlier
    // canny_th1           50            - First threshold for
    //                                     hysteresis procedure in Canny()
    // canny_th2           50            - Second threshold for
    //                                     hysteresis procedure in Canny()
    // canny_aperture_size 3            - Aperturesize for the sobel operator in Canny().
    //                                     If zero, Canny() is not applied and the input
    //                                     image is taken as an edge image.
    // do_merge            false         - If true, incremental merging of segments
    //                                     will be performed
    int   length_threshold = 20;
    float distance_threshold = 1.41421356f;
    double canny_th1 = 40.0;
    double canny_th2 = 80.0;
    int canny_aperture_size = 3; // sobel filter size
    bool do_merge = false;
    this->fast_line_detector_ = cv::ximgproc::createFastLineDetector(length_threshold,
            distance_threshold, canny_th1, canny_th2, canny_aperture_size,
            do_merge);

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

    cv::Mat img_gray,img_color;
    cv_ptr->image.copyTo(img_color);
    cv::cvtColor(img_color, img_gray, CV_BGR2GRAY);
    img_gray.convertTo(img_gray, CV_8UC1);
    
    // ROS_INFO_STREAM("Size : " << img_gray.cols << ", " << img_gray.rows);

    // Detect lines on image.
    std::vector<cv::Vec4f> lines;
    fast_line_detector_->detect(img_gray, lines);

    ROS_INFO_STREAM("# of detected lines: " << lines.size() ); // 1.5 ms

    // Image showing
    for(const cv::Vec4f& line : lines)
    {
        cv::Point2f p0(line(0),line(1));
        cv::Point2f p1(line(2),line(3));
        cv::line(img_color, p0,p1, cv::Scalar(255,0,255),2);
    }

    cv::namedWindow("img with lines");
    cv::imshow("img with lines", img_color);
    cv::waitKey(5);

    // Done.
};