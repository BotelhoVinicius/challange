FROM debian:9

RUN apt-get update

RUN apt-get install -y gcc vim git make wget sudo python dumb-init cmake build-essential
RUN apt install -y protobuf-compiler libprotobuf-dev
