hunter_config(Boost
   VERSION "1.72.0-p1"
   CMAKE_ARGS
      USE_CONFIG_FROM_BOOST=ON
      Boost_USE_STATIC_LIBS=ON
      Boost_NO_BOOST_CMAKE=ON
)

hunter_config(CapnProto
    VERSION "0.8.0"
    URL "https://capnproto.org/capnproto-c++-0.8.0.tar.gz"
    SHA1 fbc1c65b32748029f1a09783d3ebe9d496d5fcc4
)

hunter_config(koinos_log
   URL  "https://github.com/koinos/koinos-log-cpp/archive/4ecb8399d05d1639c52a34845f55aa826f35d484.tar.gz"
   SHA1 "1b11e2acadd4d37a483944096bed916ba579637d"
   CMAKE_ARGS
      BUILD_TESTS=OFF
)

hunter_config(koinos_proto
   URL  "https://github.com/koinos/koinos-proto-cpp/archive/a756ce9cbbfb9c3bc7d3c00fbbab381ba11619e1.tar.gz"
   SHA1 "c6a576625b007bf5234d4149e10a6d92345a6a77"
)
