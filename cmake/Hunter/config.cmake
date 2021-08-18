hunter_config(Boost
   VERSION "1.72.0-p1"
   CMAKE_ARGS
      USE_CONFIG_FROM_BOOST=ON
      Boost_USE_STATIC_LIBS=ON
      Boost_NO_BOOST_CMAKE=ON
)

hunter_config(koinos_log
   URL  "https://github.com/koinos/koinos-log-cpp/archive/414e9a483a20a674eb46a95e0ca27d4b0b9fe13d.tar.gz"
   SHA1 "79defc4a4db453c902708c45f4cc7e53c2b6d7bf"
   CMAKE_ARGS
      BUILD_TESTS=OFF
)

