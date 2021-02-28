hunter_config(Boost
   VERSION ${HUNTER_Boost_VERSION}
   CMAKE_ARGS
      USE_CONFIG_FROM_BOOST=ON
      Boost_USE_STATIC_LIBS=ON
      Boost_NO_BOOST_CMAKE=ON
)

hunter_config(koinos_log
   URL "https://github.com/koinos/koinos-log-cpp/archive/v0.1.0.tar.gz"
   SHA1 "bc27602cd82a3f3849796ec0d6de37d3841a19ea"
   CMAKE_ARGS
      BUILD_TESTS=OFF
)

hunter_config(koinos_types
   URL "https://github.com/koinos/koinos-types/archive/v0.1.0-alpha.tar.gz"
   SHA1 "0bd263981ae87ef1276ff4f9a483d48ba1277277"
   CMAKE_ARGS
      BUILD_TESTS=OFF
)
 
