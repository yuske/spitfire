/*
 * Copyright (C) 2011 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef CSSCrossfadeValue_h
#define CSSCrossfadeValue_h

#include "core/CoreExport.h"
#include "core/css/CSSImageGeneratorValue.h"
#include "core/css/CSSPrimitiveValue.h"
#include "core/loader/resource/ImageResourceContent.h"
#include "core/loader/resource/ImageResourceObserver.h"
#include "platform/graphics/Image.h"

namespace blink {

class CrossfadeSubimageObserverProxy;

namespace cssvalue {

class CORE_EXPORT CSSCrossfadeValue final : public CSSImageGeneratorValue {
  friend class blink::CrossfadeSubimageObserverProxy;
  USING_PRE_FINALIZER(CSSCrossfadeValue, Dispose);

 public:
  static CSSCrossfadeValue* Create(CSSValue* from_value,
                                   CSSValue* to_value,
                                   CSSPrimitiveValue* percentage_value) {
    return new CSSCrossfadeValue(from_value, to_value, percentage_value);
  }

  ~CSSCrossfadeValue();

  String CustomCSSText() const;

  scoped_refptr<Image> GetImage(const ImageResourceObserver&,
                                const Document&,
                                const ComputedStyle&,
                                const IntSize& container_size);
  bool IsFixedSize() const { return true; }
  IntSize FixedSize(const Document&, const FloatSize&);

  bool IsPending() const;
  bool KnownToBeOpaque(const Document&, const ComputedStyle&) const;

  void LoadSubimages(const Document&);

  bool HasFailedOrCanceledSubresources() const;

  bool Equals(const CSSCrossfadeValue&) const;

  CSSCrossfadeValue* ValueWithURLsMadeAbsolute();

  void TraceAfterDispatch(blink::Visitor*);

 private:
  CSSCrossfadeValue(CSSValue* from_value,
                    CSSValue* to_value,
                    CSSPrimitiveValue* percentage_value);

  void Dispose();

  class CrossfadeSubimageObserverProxy final : public ImageResourceObserver {
    DISALLOW_NEW();

   public:
    explicit CrossfadeSubimageObserverProxy(CSSCrossfadeValue* owner_value)
        : owner_value_(owner_value), ready_(false) {}

    ~CrossfadeSubimageObserverProxy() override {}
    void Trace(blink::Visitor* visitor) { visitor->Trace(owner_value_); }

    void ImageChanged(ImageResourceContent*,
                      CanDeferInvalidation,
                      const IntRect* = nullptr) override;
    bool WillRenderImage() override;
    String DebugName() const override {
      return "CrossfadeSubimageObserverProxy";
    }
    void SetReady(bool ready) { ready_ = ready; }

   private:
    Member<CSSCrossfadeValue> owner_value_;
    bool ready_;
  };

  bool WillRenderImage() const;
  void CrossfadeChanged(const IntRect&,
                        ImageResourceObserver::CanDeferInvalidation);

  Member<CSSValue> from_value_;
  Member<CSSValue> to_value_;
  Member<CSSPrimitiveValue> percentage_value_;

  Member<ImageResourceContent> cached_from_image_;
  Member<ImageResourceContent> cached_to_image_;

  CrossfadeSubimageObserverProxy crossfade_subimage_observer_;
};

DEFINE_CSS_VALUE_TYPE_CASTS(CSSCrossfadeValue, IsCrossfadeValue());

}  // namespace cssvalue
}  // namespace blink

#endif  // CSSCrossfadeValue_h
