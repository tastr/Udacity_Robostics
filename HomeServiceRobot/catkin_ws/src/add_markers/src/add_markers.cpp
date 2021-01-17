#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "nav_msgs/Odometry.h"
#include <stdlib.h>

#include "std_msgs/Int32.h"




     visualization_msgs::Marker marker;
    // Set our initial shape type to be a cube
    uint32_t shape = visualization_msgs::Marker::CUBE;

void chatterCallback(const std_msgs::Int32::ConstPtr& msg){
    ros::NodeHandle n;
    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
    marker.action = visualization_msgs::Marker::ADD;

    ROS_INFO("STATUS: [%d]", msg->data);

   if(msg->data == 0){
    marker.pose.position.x = 0;
    marker.pose.position.y = -1;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;
    ROS_INFO("Setup the first marker");
    marker_pub.publish(marker);
   }

   if(msg->data == 1){
    ROS_INFO("The first position reached");
    marker.action = visualization_msgs::Marker::DELETE;
    marker_pub.publish(marker);
    ROS_INFO("Delete the first marker");
   }

   if(msg->data == 2){
    ROS_INFO("The second position reached");
    marker.pose.position.x = -1;
    marker.pose.position.y = 0;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;
    marker_pub.publish(marker);
   }




}



int main( int argc, char** argv )
{ 
    ros::init(argc, argv, "listener");
    ros::init(argc, argv, "add_markers");
    //ros::init(argc, argv, "odom_listener");
    ros::NodeHandle n;
    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "add_markers";
    marker.id = 0;


    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::ADD;

    



    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = .5;
    marker.scale.y = .5;
    marker.scale.z = .5;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;



    marker.lifetime = ros::Duration();


  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

  ros::spin();
}
