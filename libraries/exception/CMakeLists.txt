file(GLOB HEADERS "include/koinos/*.hpp")

find_package(CapnProto CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(koinos_log CONFIG REQUIRED)
find_package(Boost CONFIG REQUIRED log log_setup filesystem)

add_library(koinos_exception ${HEADERS} exception.cpp)
target_link_libraries(koinos_exception Koinos::log CapnProto::capnp-json nlohmann_json::nlohmann_json ${CMAKE_DL_LIBS})
target_include_directories(koinos_exception PUBLIC
   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
   $<INSTALL_INTERFACE:include>
)
target_compile_definitions(koinos_exception PUBLIC _GNU_SOURCE)
add_library(Koinos::exception ALIAS koinos_exception)

install(FILES ${HEADERS} DESTINATION "include/koinos")

export(
   TARGETS ${KOINOS_LIB_TARGET_NAME}
   NAMESPACE Koinos::
   FILE ${KOINOS_LIB_CMAKE_PROJECT_TARGETS_FILE}
)

install(
   TARGETS ${KOINOS_LIB_TARGET_NAME}
   EXPORT ${KOINOS_LIB_TARGETS_EXPORT_NAME}
   INCLUDES DESTINATION ${KOINOS_LIB_INCLUDE_INSTALL_DIR}
   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)

install(
   EXPORT ${KOINOS_LIB_TARGETS_EXPORT_NAME}
   NAMESPACE Koinos::
   DESTINATION ${KOINOS_LIB_CONFIG_INSTALL_DIR}
)
