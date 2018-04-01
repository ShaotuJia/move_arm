/**
 * @brief This class publish part position that is incorrect on AGV_1
 * 1. publish topic /ariac/incorrect_pos_agv_1
 * 2. create server /ariac/incorrect_pos_agv_1
 */

#ifndef PART_PERCEPTION_INCLUDE_INCORRECT_POS_H_
#define PART_PERCEPTION_INCLUDE_INCORRECT_POS_H_


#include <vector>
#include <ros/ros.h>
#include <math.h>
#include "tf2_msgs/TFMessage.h"
#include "geometry_msgs/TransformStamped.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Transform.h"
#include "std_msgs/Header.h"
#include "osrf_gear/Order.h"

class Incorrect_Pos_AGV {
private:
	std::vector<osrf_gear::Order> received_orders;	// recieved orders
	ros::NodeHandle node;	// ros nodehandle
	tf2_msgs::TFMessage part_pos_agv_1;		// the position of all parts on agv_1
	const double translation_tolerance = 0.03;		// the tolerance in translation is 0.03m
	const double orientation_tolerance = 0.1;		// the tolerance in orientation is 0.1 rad



public:
	explicit Incorrect_Pos_AGV(ros::NodeHandle node);
	void order_callback(const osrf_gear::Order::ConstPtr & order_msg);	// recieve orders
	void part_detect(const tf2_msgs::TFMessage::ConstPtr& msg);
	bool is_within_tolerance(const geometry_msgs::Transform& actual_pose, const geometry_msgs::Pose& desired_pose);;
	bool is_within_translation_tolerance(const geometry_msgs::Vector3& actual_trans, const geometry_msgs::Point& desired_trans);
	bool is_within_orientation_tolerance(const geometry_msgs::Quaternion& actual_orient, const geometry_msgs::Quaternion& desired_orient);
};



#endif /* PART_PERCEPTION_INCLUDE_INCORRECT_POS_H_ */
