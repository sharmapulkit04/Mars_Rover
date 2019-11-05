/*
 * rosserial PubSub Example
 * Prints "hello world!" and toggles led
 */

#include <ros.h>
#include <std_msgs/Char.h>

ros::NodeHandle  nh;


void messageCb( const std_msgs::Char& wifi_sig){


  
}

ros::Subscriber<std_msgs::Char> sub("wifi_sig", messageCb );

void setup()
{
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{
  nh.spinOnce();
  delay(500);
  
}
