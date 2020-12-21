project(MessageExample)

add_executable(
  MessageExample
  main.cpp)
target_link_libraries(MessageExample Client Message)
target_include_directories(MessageExample PUBLIC
  ${CMAKE_SOURCE_DIR}/src/client
  ${CMAKE_SOURCE_DIR}/src/message)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/connectionInfo
  ${CMAKE_CURRENT_BINARY_DIR}/connectionInfo COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/longText
  ${CMAKE_CURRENT_BINARY_DIR}/longText COPYONLY)
