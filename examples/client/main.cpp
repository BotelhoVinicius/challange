#include "client.hpp"

int main() {
  challenge::client::Client client;

  client.CreateConfig("clientInfo", "server", 5050, 32, "Client");
  client.InitializeConfig("clientInfo");

  return 0;
}
