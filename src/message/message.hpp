#pragma once

#include "message.pb.h"

#include <string>

namespace challenge {
namespace message {

class Message {
public:
  Message(){};
  Message(uint32_t maxSize) : maxSize_(maxSize){};
  ~Message(){};

  bool Read(std::string filePath, std::string prefix);
  bool Write(std::string location);

  void PushMessage(MessageInfo msg) { message_.push_back(msg); }
  std::vector<MessageInfo> message() { return message_; };

private:
  // from protocol buffer
  std::vector<MessageInfo> message_;

  // from constructor
  uint32_t maxSize_{0};
};

} // namespace message
} // namespace challenge
