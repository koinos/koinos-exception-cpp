add_library(exception
  exception.cpp

  ${PROJECT_SOURCE_DIR}/include/koinos/exception.hpp)

target_link_libraries(
  exception
    PUBLIC
      Koinos::log
      Koinos::util
      Koinos::proto
      nlohmann_json::nlohmann_json
      protobuf::libprotobuf)

target_include_directories(
  exception
    PUBLIC
      $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
      $<INSTALL_INTERFACE:include>
)

koinos_add_format_target(exception)

add_library(Koinos::exception ALIAS exception)

install(
  DIRECTORY
    ${PROJECT_SOURCE_DIR}/include
  DESTINATION
    include/
)
