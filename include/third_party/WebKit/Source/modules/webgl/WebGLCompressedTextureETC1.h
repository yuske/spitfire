// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef WebGLCompressedTextureETC1_h
#define WebGLCompressedTextureETC1_h

#include "modules/webgl/WebGLExtension.h"

namespace blink {

class WebGLCompressedTextureETC1 final : public WebGLExtension {
  DEFINE_WRAPPERTYPEINFO();

 public:
  static WebGLCompressedTextureETC1* Create(WebGLRenderingContextBase*);
  static bool Supported(WebGLRenderingContextBase*);
  static const char* ExtensionName();

  WebGLExtensionName GetName() const override;

 private:
  explicit WebGLCompressedTextureETC1(WebGLRenderingContextBase*);
};

}  // namespace blink

#endif  // WebGLCompressedTextureETC1_h
