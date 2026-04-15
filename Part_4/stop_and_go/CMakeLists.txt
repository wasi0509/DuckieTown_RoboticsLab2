cmake_minimum_required(VERSION 3.0.2)
project(stop_and_go)

find_package(catkin REQUIRED COMPONENTS
  duckietown_msgs
  roscpp
)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()


###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES stop_and_go
#  CATKIN_DEPENDS duckietwon_msgs roscpp
#  DEPENDS system_lib
)


include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)
add_executable(stop_and_go src/stop_and_go.cpp)
target_link_libraries(stop_and_go ${catkin_LIBRARIES})



