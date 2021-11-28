#include "ros/ros.h"
#include "std_msgs/Float64.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "rotate");

  ros::NodeHandle nh;

  ros::Publisher pub3 = nh.advertise<std_msgs::Float64>("/robot/joint1_position_controller/command", 100);

  ros::Rate loop_rate(10);

  ros::Time startTime = ros::Time::now();
  
  float ang;
  while (ros::ok())
  {
    std :: cout << "Enter desired angle:\n";
    std :: cin >> ang;
    std_msgs::Float64 msg_to_send;

    msg_to_send.data = ang;

    pub3.publish(msg_to_send);

    ros::spinOnce();

    loop_rate.sleep();
  }
}

