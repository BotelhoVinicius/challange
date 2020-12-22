#include "client.hpp"

int main() {
  challenge::client::Client client;

  client.InitializeConfig("connectionInfo");

  return 0;
}
