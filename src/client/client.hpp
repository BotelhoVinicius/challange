#pragma once

#include "client.pb.h"

#include <string>

namespace challenge {
namespace client {

class Client {
public:
  Client(){};
  ~Client(){};

  bool Connect(std::string configurationPath);
  bool CreateConfig(std::string configFile, std::string address, int32_t port,
                    int32_t packageSize, std::string fileName,
                    int32_t timeout_ms);

  std::string address() { return serverInformation_.address(); }
  int32_t port() { return serverInformation_.port(); }
  int32_t packageSize() { return serverInformation_.package_size(); }
  std::string fileName() { return serverInformation_.file_name(); }
  int32_t timeoutMs() { return serverInformation_.timeout_ms(); }

private:
  ServerInfo serverInformation_;
};

} // namespace client
} // namespace challenge
