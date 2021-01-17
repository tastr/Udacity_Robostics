#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <stdlib.h>
#include "std_msgs/Int32.h"


int main( int argc, char** argv )
{ 


    ros::init(argc, argv, "add_markers_simple");

    ros::NodeHandle n;
    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
    
    visualization_msgs::Marker marker;

    // Set our initial shape type to be a cube
    uint32_t shape = visualization_msgs::Marker::CUBE;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "add_markers_simple";
    marker.id = 1;


    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;
    

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = .5;
    marker.scale.y = .5;
    marker.scale.z = .5;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;


    ROS_INFO("Start add_marker_simple node");
    ros::Duration(2.0).sleep();

    while(ros::ok()){
  

    marker.pose.position.x = 0;
    marker.pose.position.y = -1;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;



    ROS_INFO("Publish the first marker");
    marker.action = visualization_msgs::Marker::ADD;
    marker_pub.publish(marker);
    
    ROS_INFO("Wait for 5 seconds");
    ros::Duration(5.0).sleep();

    ROS_INFO("Hide the first marker");
    marker.action = visualization_msgs::Marker::DELETE;
    marker_pub.publish(marker);

    ROS_INFO("Wait for 5 seconds");
    ros::Duration(5.0).sleep();


    marker.pose.position.x = -1;
    marker.pose.position.y = 0;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    ROS_INFO("Publish the second marker");
    marker.action = visualization_msgs::Marker::ADD;
    marker_pub.publish(marker);

    ROS_INFO("Wait for 5 seconds");
    ros::Duration(5.0).sleep();
}
    return 0; 
}
