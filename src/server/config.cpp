#include "server.hpp"

#include <iostream>

int main(int argc, char *argv[]) {
  if (argc < 4) {
    std::cout
        << "Usage: CreateConfig <path_and_name> <port> <save_path> <timeout_ms>"
        << std::endl;
    return -1;
  }
  challenge::server::Server server;

  server.CreateConfig(argv[1], atoi(argv[2]), argv[3], atoi(argv[4]));

  return 0;
}
