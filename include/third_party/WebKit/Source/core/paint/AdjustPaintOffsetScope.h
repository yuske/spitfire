// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef AdjustPaintOffsetScope_h
#define AdjustPaintOffsetScope_h

#include "core/layout/LayoutBox.h"
#include "core/paint/PaintInfo.h"
#include "platform/graphics/paint/ScopedPaintChunkProperties.h"

namespace blink {

class ScopedPaintChunkProperties;

class AdjustPaintOffsetScope {
  STACK_ALLOCATED();

 public:
  AdjustPaintOffsetScope(const LayoutBox& box,
                         const PaintInfo& paint_info,
                         const LayoutPoint& paint_offset)
      : old_paint_info_(paint_info) {
    if (!RuntimeEnabledFeatures::SlimmingPaintV175Enabled() ||
        !ShouldAdjustForPaintOffsetTranslation(box)) {
      adjusted_paint_offset_ = paint_offset + box.Location();
      return;
    }

    AdjustForPaintOffsetTranslation(box);
  }

  const PaintInfo& GetPaintInfo() const {
    return new_paint_info_ ? *new_paint_info_ : old_paint_info_;
  }

  PaintInfo& MutablePaintInfo() {
    if (!new_paint_info_)
      new_paint_info_.emplace(old_paint_info_);
    return *new_paint_info_;
  }

  LayoutPoint AdjustedPaintOffset() const { return adjusted_paint_offset_; }

 private:
  static bool ShouldAdjustForPaintOffsetTranslation(const LayoutBox&);
  void AdjustForPaintOffsetTranslation(const LayoutBox&);

  const PaintInfo& old_paint_info_;
  LayoutPoint adjusted_paint_offset_;
  Optional<PaintInfo> new_paint_info_;
  Optional<ScopedPaintChunkProperties> contents_properties_;
};

}  // namespace blink

#endif  // AdjustPaintOffsetScope_h
