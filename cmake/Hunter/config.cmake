hunter_config(Boost
   VERSION ${HUNTER_Boost_VERSION}
   CMAKE_ARGS
      USE_CONFIG_FROM_BOOST=ON
      Boost_USE_STATIC_LIBS=ON
      Boost_NO_BOOST_CMAKE=ON
)

hunter_config(Protobuf
   VERSION ${HUNTER_Protobuf_VERSION}
   CMAKE_ARGS
      CMAKE_CXX_FLAGS=-fvisibility=hidden
      CMAKE_C_FLAGS=-fvisibility=hidden
)

hunter_config(koinos_log
   URL  "https://github.com/koinos/koinos-log-cpp/archive/8a148b2839116e060b3327fe6358210dd2a55f4d.tar.gz"
   SHA1 "8075e5882ffc5d450b35521792dcf6b29027cebd"
   CMAKE_ARGS
      BUILD_TESTS=OFF
)

hunter_config(koinos_util
   URL  "https://github.com/koinos/koinos-util-cpp/archive/22ebcd097395e1e6035fbec7bb993a44e0eab92d.tar.gz"
   SHA1 "8e51b7d1eac85c413c92b4ffe722a848c6a35520"
   CMAKE_ARGS
      BUILD_TESTS=OFF
)

