#include <ros/ros.h>
#include <duckietown_msgs/WheelsCmdStamped.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "drive_forward_node");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<duckietown_msgs::WheelsCmdStamped>(
        "/teal/wheels_driver_node/wheels_cmd", 1);

    ros::Rate rate(10);

    duckietown_msgs::WheelsCmdStamped cmd;
    cmd.vel_left = 0.3;
    cmd.vel_right = 0.3;

    ros::Time start_time = ros::Time::now();

    ROS_INFO("Driving forward for 3 seconds...");

    while (ros::ok() && (ros::Time::now() - start_time).toSec() < 3.0)
    {
        cmd.header.stamp = ros::Time::now();
        pub.publish(cmd);
        rate.sleep();
    }

    cmd.vel_left = 0.0;
    cmd.vel_right = 0.0;
    cmd.header.stamp = ros::Time::now();
    pub.publish(cmd);

    ROS_INFO("Robot stopped. Node exiting.");

    ros::Duration(0.5).sleep();
    return 0;
}
