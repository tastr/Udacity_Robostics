#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include "std_msgs/Int32.h"

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;




int main(int argc, char** argv){
  // Initialize the nodes
  ros::init(argc, argv, "pick_objects");
  ros::init(argc, argv, "talker");
  
  //initilize node handle 
  ros::NodeHandle n;
  //initilize publisher for sending massages 
  ros::Publisher chatter_pub = n.advertise<std_msgs::Int32>("chatter", 1000);




  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);
  // Wait 5 sec for move_base action server to come up
	  while(!ac.waitForServer(ros::Duration(5.0))){
	    ROS_INFO("Waiting for the move_base action server to come up");
	  }
  std_msgs::Int32 msg;

  msg.data = 0;
  chatter_pub.publish(msg);

	  move_base_msgs::MoveBaseGoal goal;
          
	  // set up the frame parameters
	  goal.target_pose.header.frame_id = "map";
	  goal.target_pose.header.stamp = ros::Time::now();

	  // Define the first position and orientation for the robot to reach
	  goal.target_pose.pose.position.y = -1;
	  goal.target_pose.pose.orientation.w = 1.0;

	   // Send the goal position and orientation for the robot to reach
	  ROS_INFO("Sending first goal");
	  ac.sendGoal(goal);

	  // Wait an infinite time for the results
	  ac.waitForResult();
         
	  // Check if the robot reached its goal
	  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){              
	    ROS_INFO("I've reached pickup zone'");
            msg.data = 1;
          }
	  else{
	    ROS_INFO("The base failed to reach pickup zone for some reason");
            msg.data = -1;
	   }
          chatter_pub.publish(msg);


	  //Wait 5 seconds
	  ROS_INFO("Waiting 5 seconds");
	  ros::Duration(5.0).sleep();


	  // Define the second position and orientation for the robot to reach
	  goal.target_pose.pose.position.x = -1;
	  goal.target_pose.pose.position.y = 0;
	  goal.target_pose.pose.orientation.w = 1.0;

	   // Send the goal position and orientation for the robot to reach
	  ROS_INFO("Sending the second goal");
	  ac.sendGoal(goal);

	  // Wait an infinite time for the results
	  ac.waitForResult();

	  // Check if the robot reached its goal
	  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
	    ROS_INFO("I've reached drop off zone'");
            msg.data = 2;
          }
	  else{
	    ROS_INFO("The base failed to reach drop off zone for some reason");
            msg.data = -2;
          }
          chatter_pub.publish(msg);
          
  return 0;



}
