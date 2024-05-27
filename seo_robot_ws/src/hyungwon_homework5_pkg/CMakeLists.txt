cmake_minimum_required(VERSION 3.5)
project(hyungwon_homework5_pkg)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Generate messages
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/HyungwonMessage.msg"
)

# Include directories
include_directories(include)

# Add executables
add_executable(HyungwonPublisher src/HyungwonPublisher.cpp)
add_executable(HyungwonSubscriber src/HyungwonSubscriber.cpp)

# Link libraries
ament_target_dependencies(HyungwonPublisher rclcpp std_msgs)
ament_target_dependencies(HyungwonSubscriber rclcpp std_msgs)

# Add message dependencies
rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} rosidl_typesupport_cpp)

target_link_libraries(HyungwonPublisher ${cpp_typesupport_target})
target_link_libraries(HyungwonSubscriber ${cpp_typesupport_target})

# Install executables
install(TARGETS
  HyungwonPublisher
  HyungwonSubscriber
  DESTINATION lib/${PROJECT_NAME})

# Add message dependencies
ament_export_dependencies(rosidl_default_runtime)

# ament_package()  ament_export_dependencies 
ament_package()
