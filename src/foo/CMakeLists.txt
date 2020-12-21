add_library(
  ${LIB_FOO}
  STATIC
    foo.cpp)

file(GLOB HEADERS foo.hpp)

set_target_properties(
  ${LIB_FOO}
  PROPERTIES
    PUBLIC_HEADER "${HEADERS}")

install(
  TARGETS ${LIB_FOO}
  LIBRARY DESTINATION lib
  PUBLIC_HEADER DESTINATION include/${INSTALL_INCLUDE_DIR})
