add_library(exception
  koinos/exception.cpp

  ${PROJECT_SOURCE_DIR}/include/koinos/exception.hpp)

target_link_libraries(
  exception
    PUBLIC
      Boost::exception
      Koinos::log
      Koinos::proto
      nlohmann_json::nlohmann_json
      protobuf::libprotobuf)

target_include_directories(
  exception
    PUBLIC
      $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
      $<INSTALL_INTERFACE:include>)

koinos_add_format(TARGET exception)

koinos_install(TARGETS exception)

install(
  DIRECTORY
    ${PROJECT_SOURCE_DIR}/include
  DESTINATION
    ${CMAKE_INSTALL_PREFIX})
