#include "session.hpp"

namespace challenge {
namespace session {

Session::Session()
    : io_service_(), socket_(boost::asio::ip::tcp::socket(io_service_)),
      resolver_(new boost::asio::ip::tcp::resolver(io_service_)) {}

void Session::Start(std::string address, std::string port) {
  boost::asio::connect(socket_,
                       resolver_->resolve({address.c_str(), port.c_str()}));
}

void Session::Stop() { socket_.close(); }

void Session::Write(std::string payload) {
  boost::asio::write(socket_,
                     boost::asio::buffer(payload.c_str(), payload.size()));
}

bool Session::Read() {
  char reply;
  boost::asio::read(socket_, boost::asio::buffer(&reply, 1));
  return bool(reply);
}

} // namespace session
} // namespace challenge
