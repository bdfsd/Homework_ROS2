#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "hyungwon_homework5_pkg/msg/hyungwon_message.hpp"  

using std::placeholders::_1;

class HyungwonSubscriber : public rclcpp::Node
{
public:
  HyungwonSubscriber()
  : Node("HyungwonSubscriber")
  {
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
    subscription_ = this->create_subscription<hyungwon_homework5_pkg::msg::HyungwonMessage>(
      "HyungwonTopic",
      qos_profile,
      std::bind(&HyungwonSubscriber::subscribe_topic_message, this, _1));
  }

private:
  void subscribe_topic_message(const hyungwon_homework5_pkg::msg::HyungwonMessage::SharedPtr msg) const
  {
    RCLCPP_INFO(this->get_logger(), "Received message: '%s', '%d', '%f'", 
                msg->data_str.c_str(), msg->data_int, msg->data_float);
  }
  rclcpp::Subscription<hyungwon_homework5_pkg::msg::HyungwonMessage>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<HyungwonSubscriber>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
