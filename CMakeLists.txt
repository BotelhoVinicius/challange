cmake_minimum_required(VERSION 3.0)

project(challange)

add_subdirectory(src)

if(BUILD_TESTING)
  add_subdirectory(tests)
endif()
