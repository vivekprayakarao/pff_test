cmake_minimum_required(VERSION 2.8.3)
project(pff_test)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  nav_msgs
  rospy
  roscpp
  tf
)

###################################
## catkin specific configuration ##
###################################

catkin_package()

###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
)


add_executable(open_polygon src/open_polygon.cpp)
target_link_libraries(open_polygon ${catkin_LIBRARIES})
add_dependencies(open_polygon project_3_generate_messages_cpp)

add_executable(prop_polygon src/prop_polygon.cpp)
target_link_libraries(prop_polygon ${catkin_LIBRARIES})
add_dependencies(prop_polygon project_3_generate_messages_cpp)

add_executable(prop_polygon2 src/prop_polygon_v2.cpp)
target_link_libraries(prop_polygon2 ${catkin_LIBRARIES})
add_dependencies(prop_polygon2 project_3_generate_messages_cpp)
