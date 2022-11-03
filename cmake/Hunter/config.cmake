hunter_config(Boost
   VERSION ${HUNTER_Boost_VERSION}
   CMAKE_ARGS
      USE_CONFIG_FROM_BOOST=ON
      Boost_USE_STATIC_LIBS=ON
      Boost_NO_BOOST_CMAKE=ON
)

hunter_config(Protobuf
   URL  "https://github.com/koinos/protobuf/archive/e1b1477875a8b022903b548eb144f2c7bf4d9561.tar.gz"
   SHA1 "5796707a98eec15ffb3ad86ff50e8eec5fa65e68"
   CMAKE_ARGS
      CMAKE_CXX_FLAGS=-fvisibility=hidden
      CMAKE_C_FLAGS=-fvisibility=hidden
)

hunter_config(yaml-cpp
   VERSION "0.6.3"
   CMAKE_ARGS
      CMAKE_CXX_FLAGS=-fvisibility=hidden
      CMAKE_C_FLAGS=-fvisibility=hidden
)

hunter_config(koinos_log
   URL  "https://github.com/koinos/koinos-log-cpp/archive/84d5707bdd71331203c3bd0a96b1bd0b9c7d0751.tar.gz"
   SHA1 "d67af4848f92c4b19422858424b512de7eacbadc"
   CMAKE_ARGS
      BUILD_TESTS=OFF
)

hunter_config(koinos_util
   URL  "https://github.com/koinos/koinos-util-cpp/archive/191ef0228e6c05a8a678b9de73c0e1d52b769371.tar.gz"
   SHA1 "4d289dd00c20f23be7970f9bc933e79e08b6e933"
   CMAKE_ARGS
      BUILD_TESTS=OFF
)

hunter_config(koinos_proto
   URL  "https://github.com/koinos/koinos-proto-cpp/archive/db90e99d6f8997861db6083efb8d0805bcd51d48.tar.gz"
   SHA1 "366952245578b37bc9991e0994b7585334de7d95"
)
