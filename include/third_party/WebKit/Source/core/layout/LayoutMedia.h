/*
 * Copyright (C) 2007, 2008, 2009, 2010 Apple Inc. All rights reserved.
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

#ifndef LayoutMedia_h
#define LayoutMedia_h

#include "core/layout/LayoutImage.h"
#include "platform/wtf/Optional.h"

namespace blink {

class HTMLMediaElement;

class LayoutMedia : public LayoutImage {
 public:
  explicit LayoutMedia(HTMLMediaElement*);
  ~LayoutMedia() override;

  LayoutObject* FirstChild() const {
    DCHECK_EQ(Children(), VirtualChildren());
    return Children()->FirstChild();
  }
  LayoutObject* LastChild() const {
    DCHECK_EQ(Children(), VirtualChildren());
    return Children()->LastChild();
  }

  // If you have a LayoutMedia, use firstChild or lastChild instead.
  void SlowFirstChild() const = delete;
  void SlowLastChild() const = delete;

  const LayoutObjectChildList* Children() const { return &children_; }
  LayoutObjectChildList* Children() { return &children_; }

  HTMLMediaElement* MediaElement() const;

  const char* GetName() const override { return "LayoutMedia"; }

 protected:
  void UpdateLayout() override;

  bool IsOfType(LayoutObjectType type) const override {
    return type == kLayoutObjectMedia || LayoutImage::IsOfType(type);
  }

 private:
  LayoutObjectChildList* VirtualChildren() final { return Children(); }
  const LayoutObjectChildList* VirtualChildren() const final {
    return Children();
  }

  PaintLayerType LayerTypeRequired() const override {
    return kNormalPaintLayer;
  }

  bool CanHaveChildren() const final { return true; }
  bool IsChildAllowed(LayoutObject*, const ComputedStyle&) const final;

  bool IsImage() const final { return false; }
  void PaintReplaced(const PaintInfo&, const LayoutPoint&) const override;

  bool BackgroundShouldAlwaysBeClipped() const final { return false; }

  LayoutUnit ComputePanelWidth(const LayoutRect& media_width) const;

  LayoutObjectChildList children_;
};

DEFINE_LAYOUT_OBJECT_TYPE_CASTS(LayoutMedia, IsMedia());

}  // namespace blink

#endif  // LayoutMedia_h
