# Necessaries tools and Infos

  Necessary tools to build: make and docker.
  To run binaries on host machine check Dockerfile to preview list of dependecies.
  Disclaimer: Boost versio 1.62


# To build docker image

  make build-image

# To build source files

  make build

# To create server config file:

  make shell
  cd bin
  ./CreateServerConfig <path_and_name> <port> <save_path> <timeout_ms>

# To create client config file:

  make shell
  cd bin
  ./CreateClientConfig <path_and_name> <port> <package_size> <prefix> <address>(optional)

# To run server:

  make shell-server
  cd bin
  ./ServerApp <config_file>

# To run client:

  make shell
  cd bin
  ./ClientApp <config_file> <files_to_send ...>
