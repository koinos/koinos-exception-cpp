if (NOT BUILD_TESTING)
  return()
endif()

include(CTest)

enable_testing()

koinos_add_test(exception_tests
  SOURCES
    exception_test.cpp
    main.cpp
    test_object.pb.cc
    test_object.pb.h
)

target_link_libraries(exception_tests Koinos::exception)
target_include_directories(exception_tests PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

koinos_add_format(
  TARGET
    exception_tests
  EXCLUDE
    test_object.pb.cc
    test_object.pb.h
)

koinos_coverage(
  EXECUTABLE
    exception_tests
  EXCLUDE
    "tests/*"
)
