#include "client.hpp"

#include <iostream>

int main(int argc, char *argv[]) {
  challenge::client::Client client;
  if (argc < 5) {
    std::cout << "Usage: CreateConfig <path_and_name> <port> <package_size> "
                 "<prefix> <address>(optional)"
              << std::endl;
    return -1;
  }

  if (argc == 5) {
    client.CreateConfig(argv[1], "", atoi(argv[2]), atoi(argv[3]), argv[4]);
  } else {
    client.CreateConfig(argv[1], argv[5], atoi(argv[2]), atoi(argv[3]),
                        argv[4]);
  }

  return 0;
}
