#include "client.hpp"

#include <fstream>
#include <iostream>
#include <string>

namespace challenge {
namespace client {

bool Client::Connect(std::string configurationPath) {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    std::fstream fileStream(configurationPath.c_str(),
                            std::ios::in | std::ios::binary);
    if (!serverInformation_.ParseFromIstream(&fileStream)) {
      std::cerr << "Failed to parse server configuration" << std::endl;
      return false;
    }
  }

  if (serverInformation_.has_address()) {
    std::cout << "Server Adress: " << serverInformation_.address() << std::endl;
  }
  std::cout << "Server - Port: " << serverInformation_.port() << std::endl;
  std::cout << "Server - Package Size: " << serverInformation_.package_size()
            << std::endl;
  std::cout << "Server - File Name: " << serverInformation_.file_name()
            << std::endl;
  std::cout << "Server - Timeout(ms): " << serverInformation_.timeout_ms()
            << std::endl;

  google::protobuf::ShutdownProtobufLibrary();

  return true;
}

bool Client::CreateConfig(std::string configFile, std::string address,
                          int32_t port, int32_t packageSize,
                          std::string fileName, int32_t timeout_ms) {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  serverInformation_.set_address(address);
  serverInformation_.set_port(port);
  serverInformation_.set_package_size(packageSize);
  serverInformation_.set_file_name(fileName);
  serverInformation_.set_timeout_ms(timeout_ms);

  std::fstream output(configFile.c_str(),
                      std::ios::out | std::ios::trunc | std::ios::binary);
  if (!serverInformation_.SerializeToOstream(&output)) {
    std::cerr << "Failed to write config file" << std::endl;
  }
  google::protobuf::ShutdownProtobufLibrary();
}

} // namespace client
} // namespace challenge
