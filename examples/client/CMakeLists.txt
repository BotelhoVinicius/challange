project(ClientExample)

add_executable(
  ClientExample
  main.cpp)
target_link_libraries(ClientExample Client)
target_include_directories(ClientExample PUBLIC
  ${CMAKE_SOURCE_DIR}/src/client)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/connectionInfo
  ${CMAKE_CURRENT_BINARY_DIR}/connectionInfo COPYONLY)
