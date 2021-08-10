// Generated by Cap'n Proto compiler, DO NOT EDIT
// source: test.capnp

#pragma once

#include <capnp/generated-header-support.h>
#include <kj/windows-sanity.h>

#if CAPNP_VERSION != 8000
#error "Version mismatch between generated code and library headers.  You must use the same version of the Cap'n Proto compiler and library."
#endif


namespace capnp {
namespace schemas {

CAPNP_DECLARE_SCHEMA(a531aa1edfa77f45);

}  // namespace schemas
}  // namespace capnp


struct ExceptionTestObject {
  ExceptionTestObject() = delete;

  class Reader;
  class Builder;
  class Pipeline;

  struct _capnpPrivate {
    CAPNP_DECLARE_STRUCT_HEADER(a531aa1edfa77f45, 1, 0)
    #if !CAPNP_LITE
    static constexpr ::capnp::_::RawBrandedSchema const* brand() { return &schema->defaultBrand; }
    #endif  // !CAPNP_LITE
  };
};

// =======================================================================================

class ExceptionTestObject::Reader {
public:
  typedef ExceptionTestObject Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline ::capnp::MessageSize totalSize() const {
    return _reader.totalSize().asPublic();
  }

#if !CAPNP_LITE
  inline ::kj::StringTree toString() const {
    return ::capnp::_::structString(_reader, *_capnpPrivate::brand());
  }
#endif  // !CAPNP_LITE

  inline  ::uint32_t getX() const;

  inline  ::uint32_t getY() const;

private:
  ::capnp::_::StructReader _reader;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::List;
  friend class ::capnp::MessageBuilder;
  friend class ::capnp::Orphanage;
};

class ExceptionTestObject::Builder {
public:
  typedef ExceptionTestObject Builds;

  Builder() = delete;  // Deleted to discourage incorrect usage.
                       // You can explicitly initialize to nullptr instead.
  inline Builder(decltype(nullptr)) {}
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline ::capnp::MessageSize totalSize() const { return asReader().totalSize(); }
#if !CAPNP_LITE
  inline ::kj::StringTree toString() const { return asReader().toString(); }
#endif  // !CAPNP_LITE

  inline  ::uint32_t getX();
  inline void setX( ::uint32_t value);

  inline  ::uint32_t getY();
  inline void setY( ::uint32_t value);

private:
  ::capnp::_::StructBuilder _builder;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  friend class ::capnp::Orphanage;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
};

#if !CAPNP_LITE
class ExceptionTestObject::Pipeline {
public:
  typedef ExceptionTestObject Pipelines;

  inline Pipeline(decltype(nullptr)): _typeless(nullptr) {}
  inline explicit Pipeline(::capnp::AnyPointer::Pipeline&& typeless)
      : _typeless(kj::mv(typeless)) {}

private:
  ::capnp::AnyPointer::Pipeline _typeless;
  friend class ::capnp::PipelineHook;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
};
#endif  // !CAPNP_LITE

// =======================================================================================

inline  ::uint32_t ExceptionTestObject::Reader::getX() const {
  return _reader.getDataField< ::uint32_t>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}

inline  ::uint32_t ExceptionTestObject::Builder::getX() {
  return _builder.getDataField< ::uint32_t>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}
inline void ExceptionTestObject::Builder::setX( ::uint32_t value) {
  _builder.setDataField< ::uint32_t>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS, value);
}

inline  ::uint32_t ExceptionTestObject::Reader::getY() const {
  return _reader.getDataField< ::uint32_t>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS);
}

inline  ::uint32_t ExceptionTestObject::Builder::getY() {
  return _builder.getDataField< ::uint32_t>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS);
}
inline void ExceptionTestObject::Builder::setY( ::uint32_t value) {
  _builder.setDataField< ::uint32_t>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS, value);
}