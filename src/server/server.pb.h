// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: server.proto

#ifndef PROTOBUF_server_2eproto__INCLUDED
#define PROTOBUF_server_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace challenge {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_server_2eproto();
void protobuf_AssignDesc_server_2eproto();
void protobuf_ShutdownFile_server_2eproto();

class ServerInfo;

// ===================================================================

class ServerInfo : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:challenge.ServerInfo)
                                                       */
{
public:
  ServerInfo();
  virtual ~ServerInfo();

  ServerInfo(const ServerInfo &from);

  inline ServerInfo &operator=(const ServerInfo &from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet &unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet *mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor *descriptor();
  static const ServerInfo &default_instance();

  void Swap(ServerInfo *other);

  // implements Message ----------------------------------------------

  inline ServerInfo *New() const { return New(NULL); }

  ServerInfo *New(::google::protobuf::Arena *arena) const;
  void CopyFrom(const ::google::protobuf::Message &from);
  void MergeFrom(const ::google::protobuf::Message &from);
  void CopyFrom(const ServerInfo &from);
  void MergeFrom(const ServerInfo &from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool
  MergePartialFromCodedStream(::google::protobuf::io::CodedInputStream *input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream *output) const;
  ::google::protobuf::uint8 *InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8 *output) const;
  ::google::protobuf::uint8 *
  SerializeWithCachedSizesToArray(::google::protobuf::uint8 *output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }

private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(ServerInfo *other);

private:
  inline ::google::protobuf::Arena *GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void *MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }

public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int32 port = 1;
  bool has_port() const;
  void clear_port();
  static const int kPortFieldNumber = 1;
  ::google::protobuf::int32 port() const;
  void set_port(::google::protobuf::int32 value);

  // required string file_path = 2;
  bool has_file_path() const;
  void clear_file_path();
  static const int kFilePathFieldNumber = 2;
  const ::std::string &file_path() const;
  void set_file_path(const ::std::string &value);
  void set_file_path(const char *value);
  void set_file_path(const char *value, size_t size);
  ::std::string *mutable_file_path();
  ::std::string *release_file_path();
  void set_allocated_file_path(::std::string *file_path);

  // required int32 timeout_ms = 3;
  bool has_timeout_ms() const;
  void clear_timeout_ms();
  static const int kTimeoutMsFieldNumber = 3;
  ::google::protobuf::int32 timeout_ms() const;
  void set_timeout_ms(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:challenge.ServerInfo)
private:
  inline void set_has_port();
  inline void clear_has_port();
  inline void set_has_file_path();
  inline void clear_has_file_path();
  inline void set_has_timeout_ms();
  inline void clear_has_timeout_ms();

  // helper for ByteSize()
  int RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr file_path_;
  ::google::protobuf::int32 port_;
  ::google::protobuf::int32 timeout_ms_;
  friend void protobuf_AddDesc_server_2eproto();
  friend void protobuf_AssignDesc_server_2eproto();
  friend void protobuf_ShutdownFile_server_2eproto();

  void InitAsDefaultInstance();
  static ServerInfo *default_instance_;
};
// ===================================================================

// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// ServerInfo

// required int32 port = 1;
inline bool ServerInfo::has_port() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ServerInfo::set_has_port() { _has_bits_[0] |= 0x00000001u; }
inline void ServerInfo::clear_has_port() { _has_bits_[0] &= ~0x00000001u; }
inline void ServerInfo::clear_port() {
  port_ = 0;
  clear_has_port();
}
inline ::google::protobuf::int32 ServerInfo::port() const {
  // @@protoc_insertion_point(field_get:challenge.ServerInfo.port)
  return port_;
}
inline void ServerInfo::set_port(::google::protobuf::int32 value) {
  set_has_port();
  port_ = value;
  // @@protoc_insertion_point(field_set:challenge.ServerInfo.port)
}

// required string file_path = 2;
inline bool ServerInfo::has_file_path() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ServerInfo::set_has_file_path() { _has_bits_[0] |= 0x00000002u; }
inline void ServerInfo::clear_has_file_path() { _has_bits_[0] &= ~0x00000002u; }
inline void ServerInfo::clear_file_path() {
  file_path_.ClearToEmptyNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_file_path();
}
inline const ::std::string &ServerInfo::file_path() const {
  // @@protoc_insertion_point(field_get:challenge.ServerInfo.file_path)
  return file_path_.GetNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ServerInfo::set_file_path(const ::std::string &value) {
  set_has_file_path();
  file_path_.SetNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:challenge.ServerInfo.file_path)
}
inline void ServerInfo::set_file_path(const char *value) {
  set_has_file_path();
  file_path_.SetNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(value));
  // @@protoc_insertion_point(field_set_char:challenge.ServerInfo.file_path)
}
inline void ServerInfo::set_file_path(const char *value, size_t size) {
  set_has_file_path();
  file_path_.SetNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char *>(value), size));
  // @@protoc_insertion_point(field_set_pointer:challenge.ServerInfo.file_path)
}
inline ::std::string *ServerInfo::mutable_file_path() {
  set_has_file_path();
  // @@protoc_insertion_point(field_mutable:challenge.ServerInfo.file_path)
  return file_path_.MutableNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string *ServerInfo::release_file_path() {
  // @@protoc_insertion_point(field_release:challenge.ServerInfo.file_path)
  clear_has_file_path();
  return file_path_.ReleaseNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ServerInfo::set_allocated_file_path(::std::string *file_path) {
  if (file_path != NULL) {
    set_has_file_path();
  } else {
    clear_has_file_path();
  }
  file_path_.SetAllocatedNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited(), file_path);
  // @@protoc_insertion_point(field_set_allocated:challenge.ServerInfo.file_path)
}

// required int32 timeout_ms = 3;
inline bool ServerInfo::has_timeout_ms() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void ServerInfo::set_has_timeout_ms() { _has_bits_[0] |= 0x00000004u; }
inline void ServerInfo::clear_has_timeout_ms() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void ServerInfo::clear_timeout_ms() {
  timeout_ms_ = 0;
  clear_has_timeout_ms();
}
inline ::google::protobuf::int32 ServerInfo::timeout_ms() const {
  // @@protoc_insertion_point(field_get:challenge.ServerInfo.timeout_ms)
  return timeout_ms_;
}
inline void ServerInfo::set_timeout_ms(::google::protobuf::int32 value) {
  set_has_timeout_ms();
  timeout_ms_ = value;
  // @@protoc_insertion_point(field_set:challenge.ServerInfo.timeout_ms)
}

#endif // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

} // namespace challenge

// @@protoc_insertion_point(global_scope)

#endif // PROTOBUF_server_2eproto__INCLUDED
