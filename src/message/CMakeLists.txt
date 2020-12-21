project(Message)

include(FindProtobuf)

find_package(Protobuf REQUIRED)

include_directories(${PROTOBUF_INCLUDE_DIR})

add_library(Message STATIC message.cpp message.pb.cc)

target_link_libraries(Message
  ${PROTOBUF_LIBRARY})

file(GLOB MESSAGE_HEADERS message.hpp message.pb.h)

set_target_properties(
  Message
  PROPERTIES
  PUBLIC_HEADER "${MESSAGE_HEADERS}")
