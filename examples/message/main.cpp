#include "client.hpp"
#include "message.hpp"

int main() {
  challenge::client::Client client;

  client.Connect("connectionInfo");

  challenge::message::Message message(client.packageSize());

  message.Read("longText", client.fileName());
  message.Write("");

  return 0;
}
