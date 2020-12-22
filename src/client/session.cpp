#include "session.hpp"

#include <iostream>
#include <thread>

namespace challenge {
namespace session {

Session::Session()
    : io_service_(), socket_(boost::asio::ip::tcp::socket(io_service_)),
      resolver_(new boost::asio::ip::tcp::resolver(io_service_)) {}

void Session::Start(std::string address, std::string port) {
  using namespace boost::asio;
  ip::tcp::resolver::query query(ip::tcp::v4(), address.c_str(), port.c_str());
  connect(socket_, resolver_->resolve(query));
  if (socket_.is_open()) {
    std::cout << "Connection Established with: " << address << ":" << port
              << std::endl;
  } else {
    std::cout << "Socket didnt start." << std::endl;
  }
}

void Session::Stop() { socket_.close(); }

void Session::Write(std::string payload) {
  std::cout << "Writing to socket." << std::endl;
  boost::asio::write(socket_,
                     boost::asio::buffer(std::string(payload + "\n").c_str(),
                                         payload.size() + 1));
}

bool Session::Read() {
  std::cout << "Waiting response." << std::endl;

  char reply[100];
  boost::asio::read(socket_, boost::asio::buffer(&reply, 100));

  if (std::string(reply).compare("ack") == 0) {
    return true;
  }
  return false;
}

} // namespace session
} // namespace challenge
