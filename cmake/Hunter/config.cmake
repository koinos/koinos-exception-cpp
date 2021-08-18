hunter_config(Boost
   VERSION ${HUNTER_Boost_VERSION}
   CMAKE_ARGS
      USE_CONFIG_FROM_BOOST=ON
      Boost_USE_STATIC_LIBS=ON
      Boost_NO_BOOST_CMAKE=ON
)

hunter_config(koinos_log
   URL  "https://github.com/koinos/koinos-log-cpp/archive/8a148b2839116e060b3327fe6358210dd2a55f4d.tar.gz"
   SHA1 "8075e5882ffc5d450b35521792dcf6b29027cebd"
   CMAKE_ARGS
      BUILD_TESTS=OFF
)

