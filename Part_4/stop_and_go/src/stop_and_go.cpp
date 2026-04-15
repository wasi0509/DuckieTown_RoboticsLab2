
#include <ros/ros.h>
#include <duckietown_msgs/SegmentList.h>
#include <duckietown_msgs/Segment.h>
#include <duckietown_msgs/BoolStamped.h>
#include <duckietown_msgs/LEDPattern.h>
#include <std_msgs/ColorRGBA.h>


bool stop_triggered = false;
bool is_paused = false;
duckietown_msgs::LEDPattern msg;

void segmentsCallback(const duckietown_msgs::SegmentList::ConstPtr& msg) {
    if (is_paused || stop_triggered) return;
    for (const auto& segment : msg->segments) {
        if (segment.color == duckietown_msgs::Segment::RED) {
            if (segment.points[0].x > 0.15 && segment.points[0].x < 0.20) {
                ROS_INFO("!!! Red line detected at x = %.2f !!!", segment.points[0].x);
                stop_triggered = true;
                break;
            }
        }
    }
}

void publishFrontRed(ros::Publisher led_pub, duckietown_msgs::LEDPattern& msg){

	msg.rgb_vals.resize(5);
	
	std_msgs::ColorRGBA red, off;
	red.r = 1.0; red.g = 0.0; red.b = 0.0; red.a = 1.0;
	off.r = 0.0; off.g = 0.0; off.b = 0.0; off.a = 1.0;
	
	msg.rgb_vals[0] = red;
	msg.rgb_vals[4] = red;
	msg.rgb_vals[1] = off;
	msg.rgb_vals[3] = off;
	
	led_pub.publish(msg);
}


int main(int argc, char** argv) {
    ros::init(argc, argv, "stop_and_go_node");
    ros::NodeHandle nh;

    ros::Subscriber sub_segments = nh.subscribe("/miroko/ground_projection_node/lineseglist_out", 1, segmentsCallback);
    ros::Publisher pub_override = nh.advertise<duckietown_msgs::BoolStamped>("/miroko/joy_mapper_node/joystick_override", 1);
    ros::Publisher pub_led = nh.advertise<duckietown_msgs::LEDPattern>("/miroko/led_emitter_node/led_pattern", 1);
    
    ROS_INFO("Stop and Go Node Started. Waiting for red lines...");

    ros::Rate rate(10);

    while (ros::ok()) {
        ros::spinOnce();

        if (stop_triggered) {
            is_paused = true;
            stop_triggered = false;

            duckietown_msgs::BoolStamped override_msg;
            override_msg.header.stamp = ros::Time::now();
            override_msg.data = true;
            pub_override.publish(override_msg);
            ROS_INFO("[Action] Robot stopped (override = True).");


            duckietown_msgs::LEDPattern led_msg;
            std_msgs::ColorRGBA red_color;
            red_color.r = 1.0; red_color.g = 0.0; red_color.b = 0.0; red_color.a = 1.0;
            std_msgs::ColorRGBA off_color;
            off_color.r = 0.0; off_color.g = 0.0; off_color.b = 0.0; off_color.a = 1.0;
                        
            publishFrontRed(pub_led, msg);
            
            for (int i = 0; i < 10; i++){
            	publishFrontRed(pub_led, msg);
            	
            }
            ros::Duration(5.0).sleep();

            ROS_INFO("[Action] Front LEDs changed to RED.");


            ROS_INFO("[Wait] Pausing for 5 seconds...");
            
            //ros::Duration(5.0).sleep();


            override_msg.header.stamp = ros::Time::now();
            override_msg.data = false;
            pub_override.publish(override_msg);
            ROS_INFO("[Action] Resuming lane following (override = False).");


            ROS_INFO("[Wait] Crossing the line...");
            ros::Duration(2.0).sleep();

            is_paused = false;
            ROS_INFO("Ready for the next red line.");
        }
        rate.sleep();
    }
    return 0;
}
