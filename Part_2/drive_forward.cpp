#include <ros/ros.h>
#include <duckietown_msgs/Twist2DStamped.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "drive_forward_node");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<duckietown_msgs::Twist2DStamped>(
        "/teal/joy_mapper_node/car_cmd", 1);

    ros::Rate rate(10);

    duckietown_msgs::Twist2DStamped cmd;
    cmd.v = 0.3;
    cmd.omega = 0.0;
    
    ros::Time start_time = ros::Time::now();

    ROS_INFO("Driving forward 4 tiles (hopefully)");

    while (ros::ok() && (ros::Time::now() - start_time).toSec() < 8.0)
    {
        cmd.header.stamp = ros::Time::now();
        pub.publish(cmd);
        rate.sleep();
    }

    cmd.v = 0.0;

    cmd.header.stamp = ros::Time::now();
    pub.publish(cmd);

    ROS_INFO("Robot stopped. Node exiting.");

    ros::Duration(0.5).sleep();
    return 0;
}
