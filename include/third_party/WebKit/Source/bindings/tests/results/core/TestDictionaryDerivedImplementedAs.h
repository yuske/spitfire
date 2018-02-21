// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef TestDictionaryDerivedImplementedAs_h
#define TestDictionaryDerivedImplementedAs_h

#include "bindings/core/v8/string_or_double.h"
#include "bindings/tests/idls/core/TestDictionary.h"
#include "core/CoreExport.h"
#include "platform/heap/Handle.h"
#include "platform/wtf/Vector.h"
#include "platform/wtf/text/WTFString.h"

namespace blink {

class CORE_EXPORT TestDictionaryDerivedImplementedAs : public TestDictionary {
  DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();
 public:
  TestDictionaryDerivedImplementedAs();
  virtual ~TestDictionaryDerivedImplementedAs();
  TestDictionaryDerivedImplementedAs(const TestDictionaryDerivedImplementedAs&);
  TestDictionaryDerivedImplementedAs& operator=(const TestDictionaryDerivedImplementedAs&);

  bool hasDerivedStringMember() const { return !derived_string_member_.IsNull(); }
  const String& derivedStringMember() const {
    return derived_string_member_;
  }
  inline void setDerivedStringMember(const String&);

  bool hasDerivedStringMemberWithDefault() const { return !derived_string_member_with_default_.IsNull(); }
  const String& derivedStringMemberWithDefault() const {
    return derived_string_member_with_default_;
  }
  inline void setDerivedStringMemberWithDefault(const String&);

  bool hasRequiredLongMember() const { return has_required_long_member_; }
  int32_t requiredLongMember() const {
    DCHECK(has_required_long_member_);
    return required_long_member_;
  }
  inline void setRequiredLongMember(int32_t);

  bool hasStringOrDoubleSequenceMember() const { return has_string_or_double_sequence_member_; }
  const HeapVector<StringOrDouble>& stringOrDoubleSequenceMember() const {
    DCHECK(has_string_or_double_sequence_member_);
    return string_or_double_sequence_member_;
  }
  void setStringOrDoubleSequenceMember(const HeapVector<StringOrDouble>&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  virtual void Trace(blink::Visitor*);

 private:
  bool has_required_long_member_ = false;
  bool has_string_or_double_sequence_member_ = false;

  String derived_string_member_;
  String derived_string_member_with_default_;
  int32_t required_long_member_;
  HeapVector<StringOrDouble> string_or_double_sequence_member_;

  friend class V8TestDictionaryDerivedImplementedAs;
};

void TestDictionaryDerivedImplementedAs::setDerivedStringMember(const String& value) {
  derived_string_member_ = value;
}

void TestDictionaryDerivedImplementedAs::setDerivedStringMemberWithDefault(const String& value) {
  derived_string_member_with_default_ = value;
}

void TestDictionaryDerivedImplementedAs::setRequiredLongMember(int32_t value) {
  required_long_member_ = value;
  has_required_long_member_ = true;
}

}  // namespace blink

#endif  // TestDictionaryDerivedImplementedAs_h
