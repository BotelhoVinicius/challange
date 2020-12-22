#pragma once

#include "client.pb.h"

#include <string>

namespace challenge {
namespace client {

class Client {
public:
  Client(){};
  ~Client(){};

  bool InitializeConfig(std::string configurationPath);
  bool CreateConfig(std::string configFile, std::string address, int32_t port,
                    int32_t packageSize, std::string fileName);
  bool SendFile(std::string filePath);

  std::string address() { return clientInformation_.address(); }
  int32_t port() { return clientInformation_.port(); }
  int32_t packageSize() { return clientInformation_.package_size(); }
  std::string fileName() { return clientInformation_.file_name(); }

private:
  ClientInfo clientInformation_;

  bool initialized_{false};
};

} // namespace client
} // namespace challenge
