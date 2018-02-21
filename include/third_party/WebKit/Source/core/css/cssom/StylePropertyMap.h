// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef StylePropertyMap_h
#define StylePropertyMap_h

#include "base/macros.h"
#include "bindings/core/v8/css_style_value_or_string.h"
#include "bindings/core/v8/v8_update_function.h"
#include "core/css/cssom/StylePropertyMapReadonly.h"

namespace blink {

class ExceptionState;
class ExecutionContext;

class CORE_EXPORT StylePropertyMap : public StylePropertyMapReadonly {
  DEFINE_WRAPPERTYPEINFO();

 public:
  void set(const ExecutionContext*,
           const String& property_name,
           HeapVector<CSSStyleValueOrString>& values,
           ExceptionState&);
  void append(const ExecutionContext*,
              const String& property_name,
              HeapVector<CSSStyleValueOrString>& values,
              ExceptionState&);
  void remove(const String& property_name, ExceptionState&);
  void update(const String&, const V8UpdateFunction*) {}

  virtual void set(const ExecutionContext*,
                   CSSPropertyID,
                   HeapVector<CSSStyleValueOrString>& values,
                   ExceptionState&) = 0;
  virtual void append(const ExecutionContext*,
                      CSSPropertyID,
                      HeapVector<CSSStyleValueOrString>& values,
                      ExceptionState&) = 0;
  virtual void remove(CSSPropertyID, ExceptionState&) = 0;

 protected:
  StylePropertyMap() {}

 private:
  DISALLOW_COPY_AND_ASSIGN(StylePropertyMap);
};

}  // namespace blink

#endif
