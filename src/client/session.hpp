#pragma once

#include <boost/asio.hpp>

namespace challenge {
namespace session {

class Session {
public:
  Session();
  ~Session() { delete resolver_; };

  void Start(std::string address, std::string port);
  void Stop();

  void Write(std::string payload);
  bool Read();
  bool isConnected() { return socket_.is_open(); };

private:
  boost::asio::io_service io_service_;
  boost::asio::ip::tcp::socket socket_;
  boost::asio::ip::tcp::resolver *resolver_;
};

} // namespace session
} // namespace challenge
