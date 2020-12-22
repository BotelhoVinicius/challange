#include "client.hpp"

#include <iostream>

int main(int argc, char *argv[]) {
  challenge::client::Client client;

  client.InitializeConfig(argv[1]);

  for (int i = 2; i < argc; i++) {
    if (!client.SendFile(argv[i])) {
      std::cerr << "Failed to send file" << std::endl;
    }
  }

  return 0;
}
