// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: header.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "header.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace gazebo {
namespace msgs {

namespace {

const ::google::protobuf::Descriptor* Header_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Header_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_header_2eproto() {
  protobuf_AddDesc_header_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "header.proto");
  GOOGLE_CHECK(file != NULL);
  Header_descriptor_ = file->message_type(0);
  static const int Header_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Header, str_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Header, stamp_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Header, index_),
  };
  Header_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Header_descriptor_,
      Header::default_instance_,
      Header_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Header, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Header, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Header));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_header_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Header_descriptor_, &Header::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_header_2eproto() {
  delete Header::default_instance_;
  delete Header_reflection_;
}

void protobuf_AddDesc_header_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::gazebo::msgs::protobuf_AddDesc_time_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\014header.proto\022\013gazebo.msgs\032\ntime.proto\""
    "I\n\006Header\022\016\n\006str_id\030\001 \001(\t\022 \n\005stamp\030\002 \001(\013"
    "2\021.gazebo.msgs.Time\022\r\n\005index\030\003 \001(\005", 114);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "header.proto", &protobuf_RegisterTypes);
  Header::default_instance_ = new Header();
  Header::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_header_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_header_2eproto {
  StaticDescriptorInitializer_header_2eproto() {
    protobuf_AddDesc_header_2eproto();
  }
} static_descriptor_initializer_header_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Header::kStrIdFieldNumber;
const int Header::kStampFieldNumber;
const int Header::kIndexFieldNumber;
#endif  // !_MSC_VER

Header::Header()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:gazebo.msgs.Header)
}

void Header::InitAsDefaultInstance() {
  stamp_ = const_cast< ::gazebo::msgs::Time*>(&::gazebo::msgs::Time::default_instance());
}

Header::Header(const Header& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:gazebo.msgs.Header)
}

void Header::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  str_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  stamp_ = NULL;
  index_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Header::~Header() {
  // @@protoc_insertion_point(destructor:gazebo.msgs.Header)
  SharedDtor();
}

void Header::SharedDtor() {
  if (str_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete str_id_;
  }
  if (this != default_instance_) {
    delete stamp_;
  }
}

void Header::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Header::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Header_descriptor_;
}

const Header& Header::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_header_2eproto();
  return *default_instance_;
}

Header* Header::default_instance_ = NULL;

Header* Header::New() const {
  return new Header;
}

void Header::Clear() {
  if (_has_bits_[0 / 32] & 7) {
    if (has_str_id()) {
      if (str_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        str_id_->clear();
      }
    }
    if (has_stamp()) {
      if (stamp_ != NULL) stamp_->::gazebo::msgs::Time::Clear();
    }
    index_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Header::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:gazebo.msgs.Header)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string str_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_str_id()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->str_id().data(), this->str_id().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "str_id");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_stamp;
        break;
      }

      // optional .gazebo.msgs.Time stamp = 2;
      case 2: {
        if (tag == 18) {
         parse_stamp:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_stamp()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_index;
        break;
      }

      // optional int32 index = 3;
      case 3: {
        if (tag == 24) {
         parse_index:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &index_)));
          set_has_index();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:gazebo.msgs.Header)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:gazebo.msgs.Header)
  return false;
#undef DO_
}

void Header::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:gazebo.msgs.Header)
  // optional string str_id = 1;
  if (has_str_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->str_id().data(), this->str_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "str_id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->str_id(), output);
  }

  // optional .gazebo.msgs.Time stamp = 2;
  if (has_stamp()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->stamp(), output);
  }

  // optional int32 index = 3;
  if (has_index()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->index(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:gazebo.msgs.Header)
}

::google::protobuf::uint8* Header::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:gazebo.msgs.Header)
  // optional string str_id = 1;
  if (has_str_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->str_id().data(), this->str_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "str_id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->str_id(), target);
  }

  // optional .gazebo.msgs.Time stamp = 2;
  if (has_stamp()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->stamp(), target);
  }

  // optional int32 index = 3;
  if (has_index()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->index(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:gazebo.msgs.Header)
  return target;
}

int Header::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string str_id = 1;
    if (has_str_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->str_id());
    }

    // optional .gazebo.msgs.Time stamp = 2;
    if (has_stamp()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->stamp());
    }

    // optional int32 index = 3;
    if (has_index()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->index());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Header::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Header* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Header*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Header::MergeFrom(const Header& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_str_id()) {
      set_str_id(from.str_id());
    }
    if (from.has_stamp()) {
      mutable_stamp()->::gazebo::msgs::Time::MergeFrom(from.stamp());
    }
    if (from.has_index()) {
      set_index(from.index());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Header::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Header::CopyFrom(const Header& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Header::IsInitialized() const {

  if (has_stamp()) {
    if (!this->stamp().IsInitialized()) return false;
  }
  return true;
}

void Header::Swap(Header* other) {
  if (other != this) {
    std::swap(str_id_, other->str_id_);
    std::swap(stamp_, other->stamp_);
    std::swap(index_, other->index_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Header::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Header_descriptor_;
  metadata.reflection = Header_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace msgs
}  // namespace gazebo

// @@protoc_insertion_point(global_scope)