#include "server.hpp"

int main(int argc, char *argv[]) {

  boost::asio::io_service io_service;
  challenge::server::Server server(io_service, argv[1]);
  server.Start();
  io_service.run();

  return 0;
}
