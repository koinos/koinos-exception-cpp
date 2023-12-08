include(CTest)

enable_testing()

koinos_add_test(koinos_exception_tests
  SOURCES
    exception_test.cpp
    main.cpp
    test_object.pb.cc
)

target_link_libraries(koinos_exception_tests Koinos::exception)
target_include_directories(koinos_exception_tests PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

add_library(koinos_exception_tests_format
  exception_test.cpp
  main.cpp
)

koinos_add_format_target(koinos_exception_tests_format)
set_target_properties(koinos_exception_tests_format PROPERTIES EXCLUDE_FROM_ALL TRUE)
