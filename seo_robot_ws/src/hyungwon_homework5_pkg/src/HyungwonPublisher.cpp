#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "hyungwon_homework5_pkg/msg/hyungwon_message.hpp"

using namespace std::chrono_literals;

class HyungwonPublisher : public rclcpp::Node
{
public:
  HyungwonPublisher()
  : Node("HyungwonPublisher"), count_(0)
  {
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
    publisher_ = this->create_publisher<hyungwon_homework5_pkg::msg::HyungwonMessage>(
      "HyungwonTopic", qos_profile);
    timer_ = this->create_wall_timer(
      1s, std::bind(&HyungwonPublisher::publish_Hyungwon_msg, this));
  }

private:
  void publish_Hyungwon_msg()
  {
    auto msg = hyungwon_homework5_pkg::msg::HyungwonMessage();
    msg.data_str = "HyungwonTopic";
    msg.data_int = count_;
    msg.data_float = static_cast<float>(count_) * 0.1f;
    RCLCPP_INFO(this->get_logger(), "Published message: '%s', '%d', '%f'", 
                msg.data_str.c_str(), msg.data_int, msg.data_float);
    publisher_->publish(msg);
    count_++;
  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<hyungwon_homework5_pkg::msg::HyungwonMessage>::SharedPtr publisher_;
  size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<HyungwonPublisher>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
