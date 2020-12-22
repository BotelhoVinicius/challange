project(Server)

include_directories(${PROTOBUF_INCLUDE_DIR}
  ${BOOST_INCLUDE_DIRS}
  ${CMAKE_SOURCE_DIR}/src/message)

add_library(
  Server
  STATIC
    server.cpp server.pb.cc)

target_link_libraries(Server
  Message
  ${PROTOBUF_LIBRARY}
  boost_system)

add_executable(ServerApp main.cpp)
target_link_libraries(ServerApp Server)

add_executable(CreateServerConfig config.cpp)
target_link_libraries(CreateServerConfig Server)
