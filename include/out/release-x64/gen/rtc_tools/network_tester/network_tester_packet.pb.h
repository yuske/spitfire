// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: network_tester_packet.proto

#ifndef PROTOBUF_network_5ftester_5fpacket_2eproto__INCLUDED
#define PROTOBUF_network_5ftester_5fpacket_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3003000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3003002 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_util.h>
// @@protoc_insertion_point(includes)
namespace webrtc {
namespace network_tester {
namespace packet {
class NetworkTesterPacket;
class NetworkTesterPacketDefaultTypeInternal;
extern NetworkTesterPacketDefaultTypeInternal _NetworkTesterPacket_default_instance_;
}  // namespace packet
}  // namespace network_tester
}  // namespace webrtc

namespace webrtc {
namespace network_tester {
namespace packet {

namespace protobuf_network_5ftester_5fpacket_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_network_5ftester_5fpacket_2eproto

enum NetworkTesterPacket_Type {
  NetworkTesterPacket_Type_HAND_SHAKING = 0,
  NetworkTesterPacket_Type_TEST_START = 1,
  NetworkTesterPacket_Type_TEST_DATA = 2,
  NetworkTesterPacket_Type_TEST_DONE = 3
};
bool NetworkTesterPacket_Type_IsValid(int value);
const NetworkTesterPacket_Type NetworkTesterPacket_Type_Type_MIN = NetworkTesterPacket_Type_HAND_SHAKING;
const NetworkTesterPacket_Type NetworkTesterPacket_Type_Type_MAX = NetworkTesterPacket_Type_TEST_DONE;
const int NetworkTesterPacket_Type_Type_ARRAYSIZE = NetworkTesterPacket_Type_Type_MAX + 1;

// ===================================================================

class NetworkTesterPacket : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:webrtc.network_tester.packet.NetworkTesterPacket) */ {
 public:
  NetworkTesterPacket();
  virtual ~NetworkTesterPacket();

  NetworkTesterPacket(const NetworkTesterPacket& from);

  inline NetworkTesterPacket& operator=(const NetworkTesterPacket& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::std::string& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::std::string* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const NetworkTesterPacket& default_instance();

  static inline const NetworkTesterPacket* internal_default_instance() {
    return reinterpret_cast<const NetworkTesterPacket*>(
               &_NetworkTesterPacket_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  GOOGLE_ATTRIBUTE_NOINLINE void Swap(NetworkTesterPacket* other);

  // implements Message ----------------------------------------------

  inline NetworkTesterPacket* New() const PROTOBUF_FINAL { return New(NULL); }

  NetworkTesterPacket* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const NetworkTesterPacket& from);
  void MergeFrom(const NetworkTesterPacket& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  void DiscardUnknownFields();
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(NetworkTesterPacket* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::std::string GetTypeName() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  typedef NetworkTesterPacket_Type Type;
  static const Type HAND_SHAKING =
    NetworkTesterPacket_Type_HAND_SHAKING;
  static const Type TEST_START =
    NetworkTesterPacket_Type_TEST_START;
  static const Type TEST_DATA =
    NetworkTesterPacket_Type_TEST_DATA;
  static const Type TEST_DONE =
    NetworkTesterPacket_Type_TEST_DONE;
  static inline bool Type_IsValid(int value) {
    return NetworkTesterPacket_Type_IsValid(value);
  }
  static const Type Type_MIN =
    NetworkTesterPacket_Type_Type_MIN;
  static const Type Type_MAX =
    NetworkTesterPacket_Type_Type_MAX;
  static const int Type_ARRAYSIZE =
    NetworkTesterPacket_Type_Type_ARRAYSIZE;

  // accessors -------------------------------------------------------

  // optional int64 send_timestamp = 2;
  bool has_send_timestamp() const;
  void clear_send_timestamp();
  static const int kSendTimestampFieldNumber = 2;
  ::google::protobuf::int64 send_timestamp() const;
  void set_send_timestamp(::google::protobuf::int64 value);

  // optional int64 arrival_timestamp = 3;
  bool has_arrival_timestamp() const;
  void clear_arrival_timestamp();
  static const int kArrivalTimestampFieldNumber = 3;
  ::google::protobuf::int64 arrival_timestamp() const;
  void set_arrival_timestamp(::google::protobuf::int64 value);

  // optional .webrtc.network_tester.packet.NetworkTesterPacket.Type type = 1;
  bool has_type() const;
  void clear_type();
  static const int kTypeFieldNumber = 1;
  ::webrtc::network_tester::packet::NetworkTesterPacket_Type type() const;
  void set_type(::webrtc::network_tester::packet::NetworkTesterPacket_Type value);

  // optional int32 packet_size = 5;
  bool has_packet_size() const;
  void clear_packet_size();
  static const int kPacketSizeFieldNumber = 5;
  ::google::protobuf::int32 packet_size() const;
  void set_packet_size(::google::protobuf::int32 value);

  // optional int64 sequence_number = 4;
  bool has_sequence_number() const;
  void clear_sequence_number();
  static const int kSequenceNumberFieldNumber = 4;
  ::google::protobuf::int64 sequence_number() const;
  void set_sequence_number(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:webrtc.network_tester.packet.NetworkTesterPacket)
 private:
  void set_has_type();
  void clear_has_type();
  void set_has_send_timestamp();
  void clear_has_send_timestamp();
  void set_has_arrival_timestamp();
  void clear_has_arrival_timestamp();
  void set_has_sequence_number();
  void clear_has_sequence_number();
  void set_has_packet_size();
  void clear_has_packet_size();

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::int64 send_timestamp_;
  ::google::protobuf::int64 arrival_timestamp_;
  int type_;
  ::google::protobuf::int32 packet_size_;
  ::google::protobuf::int64 sequence_number_;
  friend struct protobuf_network_5ftester_5fpacket_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// NetworkTesterPacket

// optional .webrtc.network_tester.packet.NetworkTesterPacket.Type type = 1;
inline bool NetworkTesterPacket::has_type() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void NetworkTesterPacket::set_has_type() {
  _has_bits_[0] |= 0x00000004u;
}
inline void NetworkTesterPacket::clear_has_type() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void NetworkTesterPacket::clear_type() {
  type_ = 0;
  clear_has_type();
}
inline ::webrtc::network_tester::packet::NetworkTesterPacket_Type NetworkTesterPacket::type() const {
  // @@protoc_insertion_point(field_get:webrtc.network_tester.packet.NetworkTesterPacket.type)
  return static_cast< ::webrtc::network_tester::packet::NetworkTesterPacket_Type >(type_);
}
inline void NetworkTesterPacket::set_type(::webrtc::network_tester::packet::NetworkTesterPacket_Type value) {
  assert(::webrtc::network_tester::packet::NetworkTesterPacket_Type_IsValid(value));
  set_has_type();
  type_ = value;
  // @@protoc_insertion_point(field_set:webrtc.network_tester.packet.NetworkTesterPacket.type)
}

// optional int64 send_timestamp = 2;
inline bool NetworkTesterPacket::has_send_timestamp() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void NetworkTesterPacket::set_has_send_timestamp() {
  _has_bits_[0] |= 0x00000001u;
}
inline void NetworkTesterPacket::clear_has_send_timestamp() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void NetworkTesterPacket::clear_send_timestamp() {
  send_timestamp_ = GOOGLE_LONGLONG(0);
  clear_has_send_timestamp();
}
inline ::google::protobuf::int64 NetworkTesterPacket::send_timestamp() const {
  // @@protoc_insertion_point(field_get:webrtc.network_tester.packet.NetworkTesterPacket.send_timestamp)
  return send_timestamp_;
}
inline void NetworkTesterPacket::set_send_timestamp(::google::protobuf::int64 value) {
  set_has_send_timestamp();
  send_timestamp_ = value;
  // @@protoc_insertion_point(field_set:webrtc.network_tester.packet.NetworkTesterPacket.send_timestamp)
}

// optional int64 arrival_timestamp = 3;
inline bool NetworkTesterPacket::has_arrival_timestamp() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void NetworkTesterPacket::set_has_arrival_timestamp() {
  _has_bits_[0] |= 0x00000002u;
}
inline void NetworkTesterPacket::clear_has_arrival_timestamp() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void NetworkTesterPacket::clear_arrival_timestamp() {
  arrival_timestamp_ = GOOGLE_LONGLONG(0);
  clear_has_arrival_timestamp();
}
inline ::google::protobuf::int64 NetworkTesterPacket::arrival_timestamp() const {
  // @@protoc_insertion_point(field_get:webrtc.network_tester.packet.NetworkTesterPacket.arrival_timestamp)
  return arrival_timestamp_;
}
inline void NetworkTesterPacket::set_arrival_timestamp(::google::protobuf::int64 value) {
  set_has_arrival_timestamp();
  arrival_timestamp_ = value;
  // @@protoc_insertion_point(field_set:webrtc.network_tester.packet.NetworkTesterPacket.arrival_timestamp)
}

// optional int64 sequence_number = 4;
inline bool NetworkTesterPacket::has_sequence_number() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void NetworkTesterPacket::set_has_sequence_number() {
  _has_bits_[0] |= 0x00000010u;
}
inline void NetworkTesterPacket::clear_has_sequence_number() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void NetworkTesterPacket::clear_sequence_number() {
  sequence_number_ = GOOGLE_LONGLONG(0);
  clear_has_sequence_number();
}
inline ::google::protobuf::int64 NetworkTesterPacket::sequence_number() const {
  // @@protoc_insertion_point(field_get:webrtc.network_tester.packet.NetworkTesterPacket.sequence_number)
  return sequence_number_;
}
inline void NetworkTesterPacket::set_sequence_number(::google::protobuf::int64 value) {
  set_has_sequence_number();
  sequence_number_ = value;
  // @@protoc_insertion_point(field_set:webrtc.network_tester.packet.NetworkTesterPacket.sequence_number)
}

// optional int32 packet_size = 5;
inline bool NetworkTesterPacket::has_packet_size() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void NetworkTesterPacket::set_has_packet_size() {
  _has_bits_[0] |= 0x00000008u;
}
inline void NetworkTesterPacket::clear_has_packet_size() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void NetworkTesterPacket::clear_packet_size() {
  packet_size_ = 0;
  clear_has_packet_size();
}
inline ::google::protobuf::int32 NetworkTesterPacket::packet_size() const {
  // @@protoc_insertion_point(field_get:webrtc.network_tester.packet.NetworkTesterPacket.packet_size)
  return packet_size_;
}
inline void NetworkTesterPacket::set_packet_size(::google::protobuf::int32 value) {
  set_has_packet_size();
  packet_size_ = value;
  // @@protoc_insertion_point(field_set:webrtc.network_tester.packet.NetworkTesterPacket.packet_size)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


}  // namespace packet
}  // namespace network_tester
}  // namespace webrtc

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::webrtc::network_tester::packet::NetworkTesterPacket_Type> : ::google::protobuf::internal::true_type {};

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_network_5ftester_5fpacket_2eproto__INCLUDED
