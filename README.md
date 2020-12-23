# Necessary tools and Infos
<br />
  - make<br />
  - docker<br />
  To run binaries on host machine check Dockerfile to preview list of dependecies.<br />
  Disclaimer: Boost version 1.62<br />
 <br />
# Tutorial
<b>Build docker image:</b>
<br />
  make build-image<br />
  docker network create challenge-network<br />
<br />
<b>Build source files:</b>
<br />
  make build<br />
<br />
<b>Create server config file:</b>
<br />
  make shell<br />
  cd bin<br />
  ./CreateServerConfig "path_and_name" "port" "save_path" "timeout_ms"<br />
<br />
<b>Create client config file:</b>
<br />
  make shell<br />
  cd bin<br />
  ./CreateClientConfig "path_and_name" "port" "package_size" "prefix" "address"(optional)<br />
<br />
<b>Run server:</b>
<br />
  make shell-server<br />
  cd bin<br />
  ./ServerApp "config_file"<br />
<br />
<b>Run client:</b>
<br />
  make shell<br />
  cd bin<br />
  ./ClientApp "config_file" "files_to_send_1" "file_to_send_2" "..."<br />
