cmake_minimum_required(VERSION 3.0)

project(challenge)

include(FindProtobuf)

find_package(Protobuf REQUIRED)
find_package(Boost REQUIRED)

add_subdirectory(src)
add_subdirectory(examples)

if(BUILD_TESTING)
  add_subdirectory(tests)
endif()
