project(Client)

include(FindProtobuf)

find_package(Protobuf REQUIRED)

include_directories(${PROTOBUF_INCLUDE_DIR})

add_library(Client STATIC client.cpp client.pb.cc)

target_link_libraries(Client
  ${PROTOBUF_LIBRARY})

file(GLOB CLIENT_HEADERS client.hpp client.pb.h)

set_target_properties(
  Client
  PROPERTIES
    PUBLIC_HEADER "${CLIENT_HEADERS}")
