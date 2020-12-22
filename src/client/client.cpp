#include "client.hpp"

#include "message.hpp"
#include "session.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <thread>

namespace challenge {
namespace client {

bool Client::InitializeConfig(std::string configurationPath) {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    std::fstream fileStream(configurationPath.c_str(),
                            std::ios::in | std::ios::binary);
    if (!clientInformation_.ParseFromIstream(&fileStream)) {
      std::cerr << "Failed to parse server configuration" << std::endl;
      return false;
    }
  }

  if (clientInformation_.has_address()) {
    std::cout << "Server Adress: " << clientInformation_.address() << std::endl;
  } else {
    std::cout << "Server Address: localhost" << std::endl;
    clientInformation_.set_address("localhost");
  }
  std::cout << "Server - Port: " << clientInformation_.port() << std::endl;
  std::cout << "Server - Package Size: " << clientInformation_.package_size()
            << std::endl;
  std::cout << "Server - File Name: " << clientInformation_.file_name()
            << std::endl;

  google::protobuf::ShutdownProtobufLibrary();

  initialized_ = true;

  return true;
}

bool Client::CreateConfig(std::string configFile, std::string address,
                          int32_t port, int32_t packageSize,
                          std::string fileName) {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  clientInformation_.set_address(address);
  clientInformation_.set_port(port);
  clientInformation_.set_package_size(packageSize);
  clientInformation_.set_file_name(fileName);

  std::fstream output(configFile.c_str(),
                      std::ios::out | std::ios::trunc | std::ios::binary);
  if (!clientInformation_.SerializeToOstream(&output)) {
    std::cerr << "Failed to write config file" << std::endl;
    return false;
  }

  google::protobuf::ShutdownProtobufLibrary();
  return true;
}

bool Client::SendFile(std::string filePath) {
  if (!initialized_) {
    std::cerr << "First Initialize Client with server information."
              << std::endl;
  }

  session::Session session;
  message::Message message(clientInformation_.package_size());

  if (!message.Read(filePath, fileName())) {
    return false;
  }

  std::cout << "Starting Session." << std::endl;
  session.Start(clientInformation_.address(), std::to_string(port()));
  std::this_thread::sleep_for(std::chrono::seconds(1));

  std::cout << "Sending " << message.message().size() << " messages."
            << std::endl;
  bool success{true};
  for (MessageInfo msg : message.message()) {
    std::string str;
    success &= msg.SerializeToString(&str);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    session.Write(str);
  }

  std::cout << "Stoping Session." << std::endl;
  session.Stop();

  return success;
}

} // namespace client
} // namespace challenge
