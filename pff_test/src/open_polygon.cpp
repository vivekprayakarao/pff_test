#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <cmath>
#include <iostream>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "open_polygon");
	ros::NodeHandle n;
	ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/navi", 10);
	ros::Rate loop_rate(10);

	double v = 0.5;
	double w = 0.5;
	int n_sides=atoi(argv[2]);
	int side_length=atoi(argv[4]);
	double poly_angle = (2*M_PI)/n_sides ;
	double t_linear = side_length / v ;
	double t_angular = poly_angle / w ;
	double t_start =ros::Time::now().toSec();

	while(ros::Time::now().toSec() <= t_start + t_linear)
	{
		geometry_msgs::Twist msg;
		//std::cout<< v << std::endl;
		msg.linear.x = 0.0;
		msg.linear.y = 0.0;
		msg.linear.z = 0.0;
		msg.angular.x = 0.0;
		msg.angular.y = 0.0;
		msg.angular.z = 0.0;
		pub.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
	}


	for (int i=0; i < n_sides ; i++){
		double t_start =ros::Time::now().toSec();
		while(ros::Time::now().toSec() <= t_start + t_linear)
		{
			geometry_msgs::Twist msg;
			if(i==0) std::cout<< v << std::endl;
			msg.linear.x = v;
			msg.linear.y = 0.0;
			msg.linear.z = 0.0;
			msg.angular.x = 0.0;
			msg.angular.y = 0.0;
			msg.angular.z = 0.0;
			pub.publish(msg);
			ros::spinOnce();
			loop_rate.sleep();
		}

		double t_start1 =ros::Time::now().toSec();
		while(ros::Time::now().toSec()<= t_start1 + t_angular)
		{
			geometry_msgs::Twist msg;
			msg.linear.x = 0.0;
			msg.linear.y = 0.0;
			msg.linear.z = 0.0;
			msg.angular.x = 0.0;
			msg.angular.y = 0.0;
			msg.angular.z = w;
			pub.publish(msg);
			ros::spinOnce();
			loop_rate.sleep();
		}

	}
	return 0;
}
