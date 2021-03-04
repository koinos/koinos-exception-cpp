hunter_config(Boost
   VERSION ${HUNTER_Boost_VERSION}
   CMAKE_ARGS
      USE_CONFIG_FROM_BOOST=ON
      Boost_USE_STATIC_LIBS=ON
      Boost_NO_BOOST_CMAKE=ON
)

hunter_config(koinos_log
   URL  "https://github.com/koinos/koinos-log-cpp/archive/4ecb8399d05d1639c52a34845f55aa826f35d484.tar.gz"
   SHA1 "1b11e2acadd4d37a483944096bed916ba579637d"
   CMAKE_ARGS
      BUILD_TESTS=OFF
)

hunter_config(koinos_types
   URL "https://github.com/koinos/koinos-types/archive/89164de74999fbc95562ccf524f01d95aa401937.tar.gz"
   SHA1 "846eb8340edd72f4c280690a15fb3af1ee0b9bd7"
   CMAKE_ARGS
      BUILD_TESTS=OFF
)
