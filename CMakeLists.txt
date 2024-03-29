
cmake_minimum_required(VERSION 3.19.0)

cmake_policy(VERSION 3.19.0...3.27.4)

include(FetchContent)
FetchContent_Declare(
  koinos_cmake
  GIT_REPOSITORY https://github.com/koinos/koinos-cmake.git
  GIT_TAG        v1.0.0
)
FetchContent_MakeAvailable(koinos_cmake)

include("${koinos_cmake_SOURCE_DIR}/Koinos.cmake")

project(koinos_exception
  VERSION 1.0.2
  DESCRIPTION "The Koinos exception library"
  LANGUAGES CXX C)

koinos_define_version()

koinos_add_package(Boost CONFIG REQUIRED
  ADD_COMPONENTS exception program_options log test
  FIND_COMPONENTS exception program_options log log_setup)

koinos_add_package(Protobuf CONFIG REQUIRED)
koinos_add_package(nlohmann_json CONFIG REQUIRED)
koinos_add_package(gRPC CONFIG REQUIRED)
koinos_add_package(yaml-cpp CONFIG REQUIRED)

koinos_add_package(koinos_util CONFIG REQUIRED)
koinos_add_package(koinos_log CONFIG REQUIRED)
koinos_add_package(koinos_proto CONFIG REQUIRED)

add_subdirectory(src)
add_subdirectory(tests)
