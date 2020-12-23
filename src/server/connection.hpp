#pragma once

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>

#include <iostream>
#include <memory>

#include "message.hpp"

namespace challenge {
namespace server {

class Connection : public std::enable_shared_from_this<Connection> {
public:
  typedef std::shared_ptr<Connection> pointer;

  Connection(boost::asio::io_service &io_service, std::string filePath,
             int32_t timeout_ms)
      : socket_(io_service), filePath_(filePath),
        timer_(io_service, boost::posix_time::milliseconds(timeout_ms)),
        timeout_ms_(timeout_ms) {}
  ~Connection() {
    std::cout << "Writing new file" << std::endl;
    file_.Write(filePath_);
  }

  void Start() { Read(); }

  boost::asio::ip::tcp::socket &socket() { return socket_; }

private:
  void Read() {
    std::cout << "Waiting new message..." << std::endl;
    auto ptr = shared_from_this();
    if (ptr != nullptr) {
      timer_.expires_from_now(boost::posix_time::milliseconds(timeout_ms_));
      timer_.async_wait(boost::bind(&Connection::HandleTimeout, ptr,
                                    boost::asio::placeholders::error));
      boost::asio::async_read_until(
          socket_, message_, "\n",
          boost::bind(&Connection::HandleRead, ptr,
                      boost::asio::placeholders::error,
                      boost::asio::placeholders::bytes_transferred));
    }
  }

  void HandleWrite(const boost::system::error_code &, size_t) {}
  void HandleTimeout(const boost::system::error_code &error) {
    if (error != 0) {
      return;
    }
    {
      std::cerr << "Connection Timeouted." << std::endl;
      socket_.close();
    }
  }
  void HandleRead(const boost::system::error_code &error,
                  size_t bytesTransferred) {
    std::cout << "Handling a read." << std::endl;
    if ((error == boost::asio::error::connection_reset)) {
      std::cerr << "Client Disconnected." << std::endl;
      timer_.cancel();
      return;
    }

    if (bytesTransferred != 0) {
      MessageInfo message;
      {
        auto data = message_.data();
        std::string str;
        str.assign(boost::asio::buffers_begin(data),
                   boost::asio::buffers_begin(data) + bytesTransferred - 1);
        if (!message.ParseFromString(str)) {
          std::cerr << "Failed to parse message" << std::endl;
        } else {
          file_.PushMessage(message);
        }
        message_.consume(bytesTransferred);
      }
      Read();
    } else {
      timer_.cancel();
    }
  }

  boost::asio::ip::tcp::socket socket_;
  boost::asio::streambuf message_;
  boost::asio::deadline_timer timer_;

  message::Message file_;
  std::string filePath_;
  int32_t timeout_ms_;
};

} // namespace server
} // namespace challenge
