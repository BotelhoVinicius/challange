#include "message.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <time.h>

static const int TIMEZONE_ADJUST{10800};

namespace challenge {
namespace message {

bool Message::Read(std::string filePath, std::string prefix) {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    std::vector<std::string> payloads;

    std::fstream fileStream(filePath.c_str(), std::ios::in | std::ios::binary);
    if (!fileStream) {
      std::cerr << "Failed to open file: " << filePath << std::endl;
      return false;
    }

    do {
      std::string str;

      fileStream.width(maxSize_);
      fileStream >> str;
      if (fileStream.eof() || str.empty())
        break;
      payloads.push_back(str);
    } while (1);

    for (std::string payload : payloads) {
      MessageInfo message;

      message.set_payload_size(payload.size());
      message.set_time_stamp(static_cast<long int>(time(NULL)));
      message.set_prefix(prefix);
      message.set_payload(payload);

      message_.push_back(message);
    }
  }

  google::protobuf::ShutdownProtobufLibrary();

  return true;
}

bool Message::Write(std::string location) {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  bool success{true};

  int messageIndex{0};
  for (MessageInfo message : message_) {
    if (location.rfind("/", location.size()) != location.size() &&
        !location.empty()) {
      location = location + "/";
    }

    std::string date;
    {
      time_t time = message.time_stamp() - TIMEZONE_ADJUST;
      struct tm *ptm = localtime(&time);
      char buffer[80];
      strftime(buffer, 80, "%Y%m%d%H%M%S", ptm);
      date = std::string(buffer);
    }

    std::fstream output(location + message.prefix() + date + std::string("_") +
                            std::to_string(messageIndex),
                        std::ios::out | std::ios::trunc | std::ios::binary);
    if (!output) {
      success &= false;
    }

    output << message.payload();
    output.close();
    messageIndex++;
  }

  google::protobuf::ShutdownProtobufLibrary();

  return success;
}

} // namespace message
} // namespace challenge
