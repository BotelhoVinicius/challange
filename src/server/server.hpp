#pragma once

#include "connection.hpp"

#include <fstream>
#include <iostream>
#include <string>

#include "server.pb.h"

namespace challenge {
namespace server {

class Server {
public:
  Server() {}
  Server(boost::asio::io_service &io_service, std::string configurationPath) {
    InitializeConfig(configurationPath);
    acceptor_ = new boost::asio::ip::tcp::acceptor(
        io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(),
                                                   serverInformation_.port()));
  }
  ~Server() {
    if (!acceptor_)
      delete acceptor_;
  }

  void Start() { StartAccept(); }

  bool CreateConfig(std::string configFile, int32_t port, std::string filePath,
                    int32_t timeout_ms) {
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    serverInformation_.set_port(port);
    serverInformation_.set_file_path(filePath);
    serverInformation_.set_timeout_ms(timeout_ms);

    std::fstream output(configFile.c_str(),
                        std::ios::out | std::ios::trunc | std::ios::binary);
    if (!serverInformation_.SerializeToOstream(&output)) {
      std::cerr << "Failed to write config file" << std::endl;
      return false;
    }

    google::protobuf::ShutdownProtobufLibrary();
    return true;
  }

private:
  bool InitializeConfig(std::string configurationPath) {
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    {
      std::fstream fileStream(configurationPath.c_str(),
                              std::ios::in | std::ios::binary);
      if (!serverInformation_.ParseFromIstream(&fileStream)) {
        std::cerr << "Failed to parse server configuration" << std::endl;
        return false;
      }
    }

    initialized_ = true;
    return true;
  }
  void StartAccept() {
    if (!initialized_) {
      std::cerr << "Failed: Server isnt initialized!" << std::endl;
    }
    Connection::pointer newConnection = std::make_shared<Connection>(
        acceptor_->get_io_service(), serverInformation_.file_path(),
        serverInformation_.timeout_ms());

    acceptor_->async_accept(newConnection->socket(),
                            boost::bind(&Server::HandleAccept, this,
                                        newConnection,
                                        boost::asio::placeholders::error));
  }

  void HandleAccept(Connection::pointer newConnection,
                    const boost::system::error_code &error) {
    if (!error) {
      newConnection->Start();
    }

    StartAccept();
  }

  bool initialized_{false};
  ServerInfo serverInformation_;
  boost::asio::ip::tcp::acceptor *acceptor_;
};

} // namespace server
} // namespace challenge
