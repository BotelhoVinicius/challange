cmake_minimum_required(VERSION 3.0)

project(challenge)

add_subdirectory(src)
add_subdirectory(examples)

if(BUILD_TESTING)
  add_subdirectory(tests)
endif()
