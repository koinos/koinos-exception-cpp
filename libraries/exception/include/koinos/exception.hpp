
#pragma once

#include <boost/exception/all.hpp>
#include <boost/stacktrace.hpp>

#include <google/protobuf/message.h>
#include <google/protobuf/util/json_util.h>

#include <nlohmann/json.hpp>

#include <koinos/log.hpp>

#define _DETAIL_KOINOS_INIT_VA_ARGS( ... ) init __VA_ARGS__

#define KOINOS_THROW( exception, msg, ... )                                      \
do {                                                                             \
   exception _e( msg );                                                          \
   koinos::detail::json_initializer init( _e );                                  \
   _DETAIL_KOINOS_INIT_VA_ARGS( __VA_ARGS__ );                                   \
   BOOST_THROW_EXCEPTION(                                                        \
      _e                                                                         \
      << koinos::detail::exception_stacktrace( boost::stacktrace::stacktrace() ) \
   );                                                                            \
} while(0)

#define KOINOS_ASSERT( cond, exc_name, msg, ... )     \
   do {                                               \
      if( !(cond) )                                   \
      {                                               \
         KOINOS_THROW( exc_name, msg, __VA_ARGS__ );  \
      }                                               \
   } while (0)

#define KOINOS_CAPTURE_CATCH_AND_RETHROW( ... ) \
catch ( koinos::exception& _e )                 \
{                                               \
   koinos::detail::json_initializer init( _e ); \
   _DETAIL_KOINOS_INIT_VA_ARGS( __VA_ARGS__ );  \
   throw;                                       \
}                                               \
catch ( std::exception& )                       \
{                                               \
   throw;                                       \
}                                               \
catch ( boost::exception& )                     \
{                                               \
   throw;                                       \
}                                               \
catch ( ... )                                   \
{                                               \
   throw;                                       \
}

#define KOINOS_CATCH_LOG_AND_RETHROW( log_level )           \
catch( koinos::exception& _e )                              \
{                                                           \
   LOG( log_level ) << boost::diagnostic_information( _e ); \
   throw;                                                   \
}                                                           \
catch ( std::exception& _e )                                \
{                                                           \
   LOG( log_level ) << _e.what();                           \
   throw;                                                   \
}                                                           \
catch ( boost::exception& _e )                              \
{                                                           \
   LOG( log_level ) << boost::diagnostic_information( _e ); \
   throw;                                                   \
}                                                           \
catch ( ... )                                               \
{                                                           \
   LOG( log_level ) << "caught unknown exception type";     \
   throw;                                                   \
}

#define KOINOS_CATCH_AND_LOG( log_level )                   \
catch( koinos::exception& _e )                              \
{                                                           \
   LOG( log_level ) << boost::diagnostic_information( _e ); \
}                                                           \
catch ( std::exception& _e )                                \
{                                                           \
   LOG( log_level ) << _e.what();                           \
}                                                           \
catch ( boost::exception& _e )                              \
{                                                           \
   LOG( log_level ) << boost::diagnostic_information( _e ); \
}                                                           \
catch ( ... )                                               \
{                                                           \
   LOG( log_level ) << "caught unknown exception type";     \
}

#define KOINOS_CATCH_AND_GET_JSON( j ) \
catch( koinos::exception& _e )         \
{                                      \
   j = _e.get_json();                  \
}

#define KOINOS_CATCH_LOG_AND_GET_JSON( log_level, j )       \
catch( koinos::exception& _e )                              \
{                                                           \
   LOG( log_level ) << boost::diagnostic_information( e );  \
   j = _e.get_json();                                       \
}

#define KOINOS_DECLARE_EXCEPTION( exc_name )                                              \
   struct exc_name : public koinos::exception                                             \
   {                                                                                      \
      exc_name() {}                                                                       \
      exc_name( const std::string& m ) : koinos::exception( m ) {}                        \
      exc_name( std::string&& m ) : koinos::exception( m ) {}                             \
      exc_name( uint32_t code, const std::string& m ) : koinos::exception( code, m ) {}   \
      exc_name( uint32_t code, const std::string&& m ) : koinos::exception( code, m ) {}  \
                                                                                          \
      virtual ~exc_name() {};                                                             \
   };

#define KOINOS_DECLARE_EXCEPTION_WITH_CODE( exc_name, c )                                 \
   struct exc_name : public koinos::exception                                             \
   {                                                                                      \
      exc_name() { }                                                                      \
      exc_name( const std::string& m ) : koinos::exception( c, m ) {}                     \
      exc_name( std::string&& m ) : koinos::exception( c, m ) {}                          \
      exc_name( uint32_t code, const std::string& m ) : koinos::exception( code, m ) {}   \
      exc_name( uint32_t code, const std::string&& m ) : koinos::exception( code, m ) {}  \
                                                                                          \
      virtual ~exc_name() {};                                                             \
   };

#define KOINOS_DECLARE_DERIVED_EXCEPTION( exc_name, base )                   \
   struct exc_name : public base                                             \
   {                                                                         \
      exc_name() {}                                                          \
      exc_name( const std::string& m ) : base( m ) {}                        \
      exc_name( std::string&& m ) : base( m ) {}                             \
      exc_name( uint32_t code, const std::string& m ) : base( code, m ) {}   \
      exc_name( uint32_t code, const std::string&& m ) : base( code, m ) {}  \
                                                                             \
      virtual ~exc_name() {};                                                \
   };

#define KOINOS_DECLARE_DERIVED_EXCEPTION_WITH_CODE( exc_name, base, c )      \
   struct exc_name : public base                                             \
   {                                                                         \
      exc_name() {  }                                                        \
      exc_name( const std::string& m ) : base( c, m ) {}                     \
      exc_name( std::string&& m ) : base( c, m ) {}                          \
      exc_name( uint32_t code, const std::string& m ) : base( code, m ) {}   \
      exc_name( uint32_t code, const std::string&& m ) : base( code, m ) {}  \
                                                                             \
      virtual ~exc_name() {};                                                \
   };

namespace koinos {

// Forward declaration
namespace detail {

struct json_initializer;
using json_info = boost::error_info< struct json_tag, nlohmann::json >;
using exception_stacktrace = boost::error_info< struct stacktrace_tag, boost::stacktrace::stacktrace >;

} // detail

struct exception : virtual boost::exception, virtual std::exception
{
   private:
      std::string msg;
      int32_t code = 1;

   public:
      exception();
      exception( uint32_t c, const std::string& m );
      exception( uint32_t c, std::string&& m );
      exception( const std::string& m );
      exception( std::string&& m );

      virtual ~exception();

      virtual const char* what() const noexcept override;

      std::string get_stacktrace() const;
      const nlohmann::json& get_json() const;
      const std::string& get_message() const;
      const int32_t get_code() { return code; };

      template< class T >
      void add_json( const std::string& key, const T& value )
      {
         ( *boost::get_error_info< koinos::detail::json_info >( *this ) )[ key ] = value;
         do_message_substitution();
      }

   private:
      friend struct detail::json_initializer;

      void do_message_substitution();
};

namespace detail {
std::string json_strpolate( const std::string& format_str, const nlohmann::json& j );

/**
 * Initializes a json object using a bubble list of key value pairs.
 */
struct json_initializer
{
   exception& _e;
   nlohmann::json& _j;

   json_initializer() = delete;
   json_initializer( exception& _e );

   json_initializer& operator()( const std::string& key, const google::protobuf::Message& m );
   json_initializer& operator()( const std::string& key, const char* c );

   template< typename T >
   std::enable_if_t< std::is_integral_v< T >, json_initializer& >
   operator()( const std::string& key, T t )
   {
      _j[key] = t;
      _e.do_message_substitution();
      return *this;
   }

   template< typename T >
   std::enable_if_t< !std::is_base_of_v< google::protobuf::Message, T > && !std::is_integral_v< T >, json_initializer& >
   operator()( const std::string& key, const T& t )
   {
      std::stringstream ss;
      ss << t;
      _j[key] = ss.str();
      _e.do_message_substitution();
      return *this;
   }

   json_initializer& operator()( const google::protobuf::Message& m );
   json_initializer& operator()();
};

} } // koinos::detail
