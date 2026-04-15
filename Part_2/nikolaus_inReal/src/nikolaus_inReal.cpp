#include <ros/ros.h>
#include <duckietown_msgs/WheelsCmdStamped.h>
#include <duckietown_msgs/Twist2DStamped.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "nikolaus_node");
    ros::NodeHandle nh;
   
    ros::Publisher pub_Twist = nh.advertise<duckietown_msgs::Twist2DStamped>("/teal/car_cmd_switch_node/cmd", 10);

    ros::Rate rate(10);
    
    duckietown_msgs::Twist2DStamped Twist;
    Twist.v = 0.0;
    Twist.omega = 0.0;

    ros::Time start_time = ros::Time::now();

    ROS_INFO("Begin to draw the nikolaus haus");
    
    while (ros::ok() && (ros::Time::now() - start_time).toSec() < 2.0){
    	Twist.v=0.2;
    	Twist.omega=0.0;
        Twist.header.stamp = ros::Time::now();
        pub_Twist.publish(Twist);
        rate.sleep();
    }
    Twist.v=0.0;Twist.omega=0.0;
    pub_Twist.publish(Twist);
    ros::Duration(0.5).sleep();
    ROS_INFO("First turn");   
    start_time = ros::Time::now();
    while (ros::ok() && (ros::Time::now() - start_time).toSec() < 1.0){
    	Twist.v = 0.0;
    	Twist.omega=3.0;
    	Twist.header.stamp = ros::Time::now();
    	pub_Twist.publish(Twist);
    	rate.sleep();
    }
    start_time = ros::Time::now();
    while (ros::ok() && (ros::Time::now() - start_time).toSec() < 2.0){
    	Twist.v=0.2;
    	Twist.omega=0.0;
        Twist.header.stamp = ros::Time::now();
        pub_Twist.publish(Twist);
        rate.sleep();
    }
    Twist.v=0.0;Twist.omega=0.0;
    pub_Twist.publish(Twist);
    ros::Duration(0.5).sleep();
    ROS_INFO("Second turn");   
    start_time = ros::Time::now();
    
    while (ros::ok() && (ros::Time::now() - start_time).toSec() < 1.0){
    	Twist.v = 0.0;
    	Twist.omega=3.0;
    	Twist.header.stamp = ros::Time::now();
    	pub_Twist.publish(Twist);
    	rate.sleep();
    }
    
    while (ros::ok() && (ros::Time::now() - start_time).toSec() < 2.0){
    	Twist.v=0.2;
    	Twist.omega=0.0;
        Twist.header.stamp = ros::Time::now();
        pub_Twist.publish(Twist);
        rate.sleep();
    }
    Twist.v=0.0;Twist.omega=0.0;
    pub_Twist.publish(Twist);
    ros::Duration(0.5).sleep();
    ROS_INFO("Third turn");   
    start_time = ros::Time::now();
    
    while (ros::ok() && (ros::Time::now() - start_time).toSec() < 1.0){
    	Twist.v = 0.0;
    	Twist.omega=2.0;
    	Twist.header.stamp = ros::Time::now();
    	pub_Twist.publish(Twist);
    	rate.sleep();
    }
    
    while (ros::ok() && (ros::Time::now() - start_time).toSec() < 2.0){
    	Twist.v=0.2;
    	Twist.omega=0.0;
        Twist.header.stamp = ros::Time::now();
        pub_Twist.publish(Twist);
        rate.sleep();
    }
    Twist.v=0.0;Twist.omega=0.0;
    pub_Twist.publish(Twist);
    ros::Duration(0.5).sleep();
    ROS_INFO("Fourth turn");   
    start_time = ros::Time::now();
    
    while (ros::ok() && (ros::Time::now() - start_time).toSec() < 1.0){
    	Twist.v = 0.0;
    	Twist.omega=3.0;
    	Twist.header.stamp = ros::Time::now();
    	pub_Twist.publish(Twist);
    	rate.sleep();
    }
    
    while (ros::ok() && (ros::Time::now() - start_time).toSec() < 2.0){
    	Twist.v=0.2;
    	Twist.omega=0.0;
        Twist.header.stamp = ros::Time::now();
        pub_Twist.publish(Twist);
        rate.sleep();
    }
    Twist.v=0.0;Twist.omega=0.0;
    pub_Twist.publish(Twist);
    ros::Duration(0.5).sleep();
    
    //Back to Origin
    
    ROS_INFO("First Diagonal");
    start_time = ros::Time::now();
    while (ros::ok() && (ros::Time::now() - start_time).toSec() < 1.0){
    	Twist.v = 0.0;
    	Twist.omega= 5.0;
    	Twist.header.stamp = ros::Time::now();
    	pub_Twist.publish(Twist);
    	rate.sleep();
    }
    start_time = ros::Time::now();
    while (ros::ok() && (ros::Time::now() - start_time).toSec() < 2.0){
    	Twist.v=0.28;
    	Twist.omega=0.0;
        Twist.header.stamp = ros::Time::now();
        pub_Twist.publish(Twist);
        rate.sleep();
    }
    Twist.v=0.0;Twist.omega=0.0;
    pub_Twist.publish(Twist);
    ros::Duration(0.5).sleep();
    
    ROS_INFO("Straight line");
    start_time = ros::Time::now();
    while (ros::ok() && (ros::Time::now() - start_time).toSec() < 1.0){
    	Twist.v = 0.0;
    	Twist.omega=-5.0;
    	Twist.header.stamp = ros::Time::now();
    	pub_Twist.publish(Twist);
    	rate.sleep();
    }
    start_time = ros::Time::now();
    while (ros::ok() && (ros::Time::now() - start_time).toSec() < 2.0){
    	Twist.v=0.2;
    	Twist.omega=0.0;
        Twist.header.stamp = ros::Time::now();
        pub_Twist.publish(Twist);
        rate.sleep();
    }
    Twist.v=0.0;Twist.omega=0.0;
    pub_Twist.publish(Twist);
    ros::Duration(0.5).sleep();
    
    ROS_INFO("Second Diagonal");
    start_time = ros::Time::now();
    while (ros::ok() && (ros::Time::now() - start_time).toSec() < 1.0){
    	Twist.v = 0.0;
    	Twist.omega=-1.5;
    	Twist.header.stamp = ros::Time::now();
    	pub_Twist.publish(Twist);
    	rate.sleep();
    }
    start_time = ros::Time::now();
    while (ros::ok() && (ros::Time::now() - start_time).toSec() < 2.0){
    	Twist.v=0.28;
    	Twist.omega=0.0;
        Twist.header.stamp = ros::Time::now();
        pub_Twist.publish(Twist);
        rate.sleep();
    }
    Twist.v=0.0;Twist.omega=0.0;
    pub_Twist.publish(Twist);
    ros::Duration(0.5).sleep();
    
    
    Twist.v=0.0;Twist.omega=0.0;
    pub_Twist.publish(Twist);
    ros::Duration(0.5).sleep();
    
    Twist.header.stamp = ros::Time::now();
    pub_Twist.publish(Twist);

    ROS_INFO("Robot stopped. Node exiting.");

    return 0;
}
