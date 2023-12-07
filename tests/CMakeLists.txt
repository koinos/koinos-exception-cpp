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
