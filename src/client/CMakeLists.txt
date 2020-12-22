project(Client)

include_directories(${PROTOBUF_INCLUDE_DIR}
  ${BOOST_INCLUDE_DIRS}
  ${CMAKE_SOURCE_DIR}/src/message)

add_library(
  Client
  STATIC
    client.cpp client.pb.cc)
target_link_libraries(Client
  Message Session
  ${PROTOBUF_LIBRARY}
  boost_system)

add_library(
  Session
  STATIC
    session.cpp)
target_link_libraries(Session
  pthread
  boost_system)

add_executable(
  ClientApp main.cpp)
target_link_libraries(ClientApp Client)


add_executable(
  CreateClientConfig config.cpp)
target_link_libraries(CreateClientConfig Client)
