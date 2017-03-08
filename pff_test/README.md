# pff_test

For the purpose of this test I have used ROS Indigo and turtle_bot package which is already available.

For installing all the dependencies, please follow the below instructions:
http://wiki.ros.org/turtlebot/Tutorials/indigo/Turtlebot%20Installation

For Installing gazebo depencies:

$ sudo apt-get install ros-indigo-turtlebot-gazebo

Use RViz to visualise various sensory information. In a new terminal execute:

$ roslaunch turtlebot_rviz_launchers view_robot.launch

Keyboard teleop mode:

First we need to install the turtlebot_teleop package from the link below:
http://wiki.ros.org/turtlebot_teleop


After installing all the necessary dependencies, clone this repository into the src folder of the catkin workspace and run :

$ catkin_make

Before starting the simulation, source the workspace.

1)Testing the teleop mode using Turtlebot simulator:

Launch the simulator:

$ roslaunch pff_test test_world.launch

This will open a Gazebo simulator windows with a Turtlebot on an empty infinite plane. To test the code just run the below command in a new terminal window . 

Run the following command:

$ roslaunch turtlebot_teleop keyboard_teleop.launch

We can control the turtle bot using the keys from our computer.


2)Testing the Square mode using Turtlebot simulator:

Launch the simulator:

$ roslaunch pff_test test_world.launch

This will open a Gazebo simulator windows with a Turtlebot on an empty infinite plane. To test the code just run the below command in a new terminal window . 

The structure of the algorithm should be the following:
1)Drive distance d
2)Rotate by angle
3)Go to step 1

The polygon will depend on two parameters: the number of sides to the polygon, and the length of each side. To make the robot move in a square of length 1 we can input: 

$ rosrun pff_test open_polygon -n 4 -d 1

![Alt text](/pff_test/images/Screenshot from 2017-03-07 18:26:40.png?raw=true "XYZ")

