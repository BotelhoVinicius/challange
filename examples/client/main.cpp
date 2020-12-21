#include "client.hpp"

int main() {
  challenge::client::Client client;

  client.Connect("connectionInfo");

  return 0;
}
