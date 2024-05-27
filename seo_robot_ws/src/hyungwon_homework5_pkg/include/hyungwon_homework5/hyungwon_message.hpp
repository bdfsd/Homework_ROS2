#ifndef HYUNGWON_HOMEWORK5__HYUNGWON_MESSAGE_HPP_
#define HYUNGWON_HOMEWORK5__HYUNGWON_MESSAGE_HPP_

#include <string>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace hyungwon_homework5_pkg
{
  struct HyungwonMessage
  {
    std::string data_str;
    int32_t data_int;
    double data_float;
  };
}

#endif  // HYUNGWON_HOMEWORK5__HYUNGWON_MESSAGE_HPP_
