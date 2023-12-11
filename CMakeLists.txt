
cmake_minimum_required(VERSION 3.19.0)

cmake_policy(SET CMP0074 NEW)
cmake_policy(SET CMP0114 NEW)

if(${CMAKE_VERSION} VERSION_GREATER_EQUAL 3.24.0)
  cmake_policy(SET CMP0135 NEW)
endif()

if(${CMAKE_VERSION} VERSION_GREATER_EQUAL 3.27.0)
  cmake_policy(SET CMP0144 NEW)
endif()

include(FetchContent)
FetchContent_Declare(
  koinos_cmake
  GIT_REPOSITORY https://github.com/koinos/koinos-cmake.git
  GIT_TAG        f1666ab636b70db9a77347e52e01e88057f8fdf7
)
FetchContent_MakeAvailable(koinos_cmake)

include("${koinos_cmake_SOURCE_DIR}/Koinos.cmake")

project(koinos_exception
  VERSION 1.0.1
  DESCRIPTION "The Koinos exception library"
  LANGUAGES CXX C)

koinos_define_version()

koinos_add_package(Boost CONFIG REQUIRED
  ADD_COMPONENTS exception log test
  FIND_COMPONENTS exception log log_setup)

koinos_add_package(Protobuf CONFIG REQUIRED)
koinos_add_package(nlohmann_json CONFIG REQUIRED)
koinos_add_package(yaml-cpp CONFIG REQUIRED)
koinos_add_package(gRPC CONFIG REQUIRED)
koinos_add_package(abseil NAME absl CONFIG REQUIRED)
koinos_add_package(re2 CONFIG REQUIRED)
koinos_add_package(c-ares CONFIG REQUIRED)
koinos_add_package(ZLIB CONFIG REQUIRED)

koinos_add_package(koinos_util CONFIG REQUIRED)
koinos_add_package(koinos_log CONFIG REQUIRED)
koinos_add_package(koinos_proto CONFIG REQUIRED)

add_subdirectory(src)
add_subdirectory(tests)
