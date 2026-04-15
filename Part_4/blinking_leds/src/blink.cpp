#include <ros/ros.h>
#include <duckietown_msgs/LEDPattern.h>
#include <std_msgs/ColorRGBA.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "duckiebot_led_blink");
    ros::NodeHandle nh;

    std::string veh_name;
    veh_name = "teal";

    std::string topic = "/teal/led_emitter_node/led_pattern";
    ros::Publisher led_pub = nh.advertise<duckietown_msgs::LEDPattern>(topic, 1, true);

    ros::Rate rate(1.0);  
    bool flipped = false;

    while (ros::ok()) {
        duckietown_msgs::LEDPattern msg;
        msg.rgb_vals.resize(5);

        std_msgs::ColorRGBA red;
        red.r = 1.0;
        red.g = 0.0;
        red.b = 0.0;
        red.a = 1.0;

        std_msgs::ColorRGBA blue;
        blue.r = 0.0;
        blue.g = 0.0;
        blue.b = 1.0;
        blue.a = 1.0;

        if (!flipped) {
            msg.rgb_vals[0] = red; 
            msg.rgb_vals[2] = red;  
            msg.rgb_vals[1] = blue;  
            msg.rgb_vals[4] = blue;
        } else {
            msg.rgb_vals[0] = blue; 
            msg.rgb_vals[2] = blue;
            msg.rgb_vals[1] = red; 
            msg.rgb_vals[4] = red;
        }

        led_pub.publish(msg);
        flipped = !flipped;

        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}
