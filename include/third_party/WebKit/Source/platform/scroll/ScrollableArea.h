/*
 * Copyright (C) 2008, 2011 Apple Inc. All Rights Reserved.
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
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ScrollableArea_h
#define ScrollableArea_h

#include "platform/PlatformExport.h"
#include "platform/geometry/FloatQuad.h"
#include "platform/geometry/LayoutRect.h"
#include "platform/graphics/Color.h"
#include "platform/heap/Handle.h"
#include "platform/runtime_enabled_features.h"
#include "platform/scroll/ScrollAnimatorBase.h"
#include "platform/scroll/ScrollTypes.h"
#include "platform/scroll/Scrollbar.h"
#include "platform/wtf/MathExtras.h"
#include "platform/wtf/Noncopyable.h"
#include "platform/wtf/Vector.h"

namespace blink {

class CompositorAnimationHost;
class CompositorAnimationTimeline;
class GraphicsLayer;
class LayoutBox;
class LayoutObject;
class PaintLayer;
class PlatformChromeClient;
class ProgrammaticScrollAnimator;
struct ScrollAlignment;
class ScrollAnchor;
class ScrollAnimatorBase;
class SmoothScrollSequencer;
class CompositorAnimationTimeline;

enum IncludeScrollbarsInRect {
  kExcludeScrollbars,
  kIncludeScrollbars,
};

class PLATFORM_EXPORT ScrollableArea : public GarbageCollectedMixin {
  WTF_MAKE_NONCOPYABLE(ScrollableArea);

 public:
  static int PixelsPerLineStep(PlatformChromeClient*);
  static float MinFractionToStepWhenPaging();
  int MaxOverlapBetweenPages() const;

  // Convert a non-finite scroll value (Infinity, -Infinity, NaN) to 0 as
  // per http://dev.w3.org/csswg/cssom-view/#normalize-non_finite-values.
  static float NormalizeNonFiniteScroll(float value) {
    return std::isfinite(value) ? value : 0.0;
  }

  virtual PlatformChromeClient* GetChromeClient() const { return nullptr; }

  virtual SmoothScrollSequencer* GetSmoothScrollSequencer() const {
    return nullptr;
  }

  virtual ScrollResult UserScroll(ScrollGranularity, const ScrollOffset&);

  virtual void SetScrollOffset(const ScrollOffset&,
                               ScrollType,
                               ScrollBehavior = kScrollBehaviorInstant);
  virtual void ScrollBy(const ScrollOffset&,
                        ScrollType,
                        ScrollBehavior = kScrollBehaviorInstant);
  void SetScrollOffsetSingleAxis(ScrollbarOrientation,
                                 float,
                                 ScrollType,
                                 ScrollBehavior = kScrollBehaviorInstant);

  // Scrolls the area so that the given rect, given in the document's content
  // coordinates, such that it's visible in the area. Returns the new location
  // of the input rect relative once again to the document.
  // Note, in the case of a Document container, such as FrameView, the output
  // will always be the input rect since scrolling it can't change the location
  // of content relative to the document, unlike an overflowing element.
  virtual LayoutRect ScrollIntoView(const LayoutRect& rect_in_content,
                                    const ScrollAlignment& align_x,
                                    const ScrollAlignment& align_y,
                                    bool is_smooth,
                                    ScrollType = kProgrammaticScroll,
                                    bool is_for_scroll_sequence = false);

  static bool ScrollBehaviorFromString(const String&, ScrollBehavior&);

  void ContentAreaWillPaint() const;
  void MouseEnteredContentArea() const;
  void MouseExitedContentArea() const;
  void MouseMovedInContentArea() const;
  void MouseEnteredScrollbar(Scrollbar&);
  void MouseExitedScrollbar(Scrollbar&);
  void MouseCapturedScrollbar();
  void MouseReleasedScrollbar();
  void ContentAreaDidShow() const;
  void ContentAreaDidHide() const;

  void FinishCurrentScrollAnimations() const;

  virtual void DidAddScrollbar(Scrollbar&, ScrollbarOrientation);
  virtual void WillRemoveScrollbar(Scrollbar&, ScrollbarOrientation);

  // Called when this ScrollableArea becomes or unbecomes the global root
  // scroller.
  virtual void DidChangeGlobalRootScroller() {}

  virtual void ContentsResized();

  bool HasOverlayScrollbars() const;
  void SetScrollbarOverlayColorTheme(ScrollbarOverlayColorTheme);
  void RecalculateScrollbarOverlayColorTheme(Color);
  ScrollbarOverlayColorTheme GetScrollbarOverlayColorTheme() const {
    return static_cast<ScrollbarOverlayColorTheme>(
        scrollbar_overlay_color_theme_);
  }

  // This getter will create a ScrollAnimatorBase if it doesn't already exist.
  ScrollAnimatorBase& GetScrollAnimator() const;

  // This getter will return null if the ScrollAnimatorBase hasn't been created
  // yet.
  ScrollAnimatorBase* ExistingScrollAnimator() const {
    return scroll_animator_;
  }

  ProgrammaticScrollAnimator& GetProgrammaticScrollAnimator() const;
  ProgrammaticScrollAnimator* ExistingProgrammaticScrollAnimator() const {
    return programmatic_scroll_animator_;
  }

  virtual CompositorAnimationHost* GetCompositorAnimationHost() const {
    return nullptr;
  }
  virtual CompositorAnimationTimeline* GetCompositorAnimationTimeline() const {
    return nullptr;
  }

  // See Source/core/layout/README.md for an explanation of scroll origin.
  const IntPoint& ScrollOrigin() const { return scroll_origin_; }
  bool ScrollOriginChanged() const { return scroll_origin_changed_; }

  // This is used to determine whether the incoming fractional scroll offset
  // should be truncated to integer. Current rule is that if
  // preferCompositingToLCDTextEnabled() is disabled (which is true on low-dpi
  // device by default) we should do the truncation.  The justification is that
  // non-composited elements using fractional scroll offsets is causing too much
  // nasty bugs but does not add too benefit on low-dpi devices.
  // TODO(szager): Now that scroll offsets are floats everywhere, can we get rid
  // of this?
  virtual bool ShouldUseIntegerScrollOffset() const {
    return !RuntimeEnabledFeatures::FractionalScrollOffsetsEnabled();
  }

  virtual bool IsActive() const = 0;
  virtual int ScrollSize(ScrollbarOrientation) const = 0;
  void SetScrollbarNeedsPaintInvalidation(ScrollbarOrientation);
  virtual bool IsScrollCornerVisible() const = 0;
  virtual IntRect ScrollCornerRect() const = 0;
  void SetScrollCornerNeedsPaintInvalidation();
  virtual void GetTickmarks(Vector<IntRect>&) const {}

  // Convert points and rects between the scrollbar and its containing
  // EmbeddedContentView. The client needs to implement these in order to be
  // aware of layout effects like CSS transforms.
  virtual IntRect ConvertFromScrollbarToContainingEmbeddedContentView(
      const Scrollbar& scrollbar,
      const IntRect& scrollbar_rect) const {
    IntRect local_rect = scrollbar_rect;
    local_rect.MoveBy(scrollbar.Location());
    return local_rect;
  }
  virtual IntPoint ConvertFromContainingEmbeddedContentViewToScrollbar(
      const Scrollbar& scrollbar,
      const IntPoint& parent_point) const {
    NOTREACHED();
    return parent_point;
  }
  virtual IntPoint ConvertFromScrollbarToContainingEmbeddedContentView(
      const Scrollbar& scrollbar,
      const IntPoint& scrollbar_point) const {
    NOTREACHED();
    return scrollbar_point;
  }
  virtual IntPoint ConvertFromRootFrame(
      const IntPoint& point_in_root_frame) const {
    NOTREACHED();
    return point_in_root_frame;
  }

  virtual Scrollbar* HorizontalScrollbar() const { return nullptr; }
  virtual Scrollbar* VerticalScrollbar() const { return nullptr; }

  virtual PaintLayer* Layer() const { return nullptr; }

  // scrollPosition is the location of the top/left of the scroll viewport in
  // the coordinate system defined by the top/left of the overflow rect.
  // scrollOffset is the offset of the scroll viewport from its position when
  // scrolled all the way to the beginning of its content's flow.
  // For a more detailed explanation of scrollPosition, scrollOffset, and
  // scrollOrigin, see core/layout/README.md.
  FloatPoint ScrollPosition() const {
    return FloatPoint(ScrollOrigin()) + GetScrollOffset();
  }
  virtual IntSize ScrollOffsetInt() const = 0;
  virtual ScrollOffset GetScrollOffset() const {
    return ScrollOffset(ScrollOffsetInt());
  }
  virtual IntSize MinimumScrollOffsetInt() const = 0;
  virtual ScrollOffset MinimumScrollOffset() const {
    return ScrollOffset(MinimumScrollOffsetInt());
  }
  virtual IntSize MaximumScrollOffsetInt() const = 0;
  virtual ScrollOffset MaximumScrollOffset() const {
    return ScrollOffset(MaximumScrollOffsetInt());
  }

  virtual IntRect VisibleContentRect(
      IncludeScrollbarsInRect = kExcludeScrollbars) const = 0;
  virtual int VisibleHeight() const { return VisibleContentRect().Height(); }
  virtual int VisibleWidth() const { return VisibleContentRect().Width(); }
  virtual IntSize ContentsSize() const = 0;
  virtual IntPoint LastKnownMousePosition() const { return IntPoint(); }

  virtual bool ShouldSuspendScrollAnimations() const { return true; }
  virtual void ScrollbarStyleChanged() {}
  virtual bool ScrollbarsCanBeActive() const = 0;

  // Returns the bounding box of this scrollable area, in the coordinate system
  // of the top-level FrameView.
  virtual IntRect ScrollableAreaBoundingBox() const = 0;

  virtual CompositorElementId GetCompositorElementId() const = 0;
  virtual bool ScrollAnimatorEnabled() const { return false; }

  // NOTE: Only called from Internals for testing.
  void UpdateScrollOffsetFromInternals(const IntSize&);

  IntSize ClampScrollOffset(const IntSize&) const;
  ScrollOffset ClampScrollOffset(const ScrollOffset&) const;

  // Let subclasses provide a way of asking for and servicing scroll
  // animations.
  virtual bool ScheduleAnimation() { return false; }
  virtual void ServiceScrollAnimations(double monotonic_time);
  virtual void UpdateCompositorScrollAnimations();
  virtual void RegisterForAnimation() {}
  virtual void DeregisterForAnimation() {}

  virtual bool UsesCompositedScrolling() const { return false; }
  virtual bool ShouldScrollOnMainThread() const;

  // Overlay scrollbars can "fade-out" when inactive.
  virtual bool ScrollbarsHidden() const;
  virtual void SetScrollbarsHidden(bool);

  // Returns true if the GraphicsLayer tree needs to be rebuilt.
  virtual bool UpdateAfterCompositingChange() { return false; }

  virtual bool UserInputScrollable(ScrollbarOrientation) const = 0;
  virtual bool ShouldPlaceVerticalScrollbarOnLeft() const = 0;

  // Convenience functions
  float MinimumScrollOffset(ScrollbarOrientation orientation) {
    return orientation == kHorizontalScrollbar ? MinimumScrollOffset().Width()
                                               : MinimumScrollOffset().Height();
  }
  float MaximumScrollOffset(ScrollbarOrientation orientation) {
    return orientation == kHorizontalScrollbar ? MaximumScrollOffset().Width()
                                               : MaximumScrollOffset().Height();
  }
  float ClampScrollOffset(ScrollbarOrientation orientation, float offset) {
    return clampTo(offset, MinimumScrollOffset(orientation),
                   MaximumScrollOffset(orientation));
  }

  virtual GraphicsLayer* LayerForContainer() const;
  virtual GraphicsLayer* LayerForScrolling() const { return nullptr; }
  virtual GraphicsLayer* LayerForHorizontalScrollbar() const { return nullptr; }
  virtual GraphicsLayer* LayerForVerticalScrollbar() const { return nullptr; }
  virtual GraphicsLayer* LayerForScrollCorner() const { return nullptr; }
  bool HasLayerForHorizontalScrollbar() const;
  bool HasLayerForVerticalScrollbar() const;
  bool HasLayerForScrollCorner() const;

  void LayerForScrollingDidChange(CompositorAnimationTimeline*);
  bool NeedsShowScrollbarLayers() const { return needs_show_scrollbar_layers_; }
  void DidShowScrollbarLayers() { needs_show_scrollbar_layers_ = false; }

  void CancelScrollAnimation();
  virtual void CancelProgrammaticScrollAnimation();

  virtual ~ScrollableArea();

  // Called when any of horizontal scrollbar, vertical scrollbar and scroll
  // corner is setNeedsPaintInvalidation.
  virtual void ScrollControlWasSetNeedsPaintInvalidation() = 0;

  // Returns the default scroll style this area should scroll with when not
  // explicitly specified. E.g. The scrolling behavior of an element can be
  // specified in CSS.
  virtual ScrollBehavior ScrollBehaviorStyle() const {
    return kScrollBehaviorInstant;
  }

  virtual bool IsScrollable() const { return true; }

  // TODO(bokan): FrameView::setScrollOffset uses updateScrollbars to scroll
  // which bails out early if its already in updateScrollbars, the effect being
  // that programmatic scrolls (i.e. setScrollOffset) are disabled when in
  // updateScrollbars. Expose this here to allow RootFrameViewport to match the
  // semantics for now but it should be cleaned up at the source.
  virtual bool IsProgrammaticallyScrollable() { return true; }

  // Subtracts space occupied by this ScrollableArea's scrollbars.
  // Does nothing if overlay scrollbars are enabled.
  IntSize ExcludeScrollbars(const IntSize&) const;

  virtual int VerticalScrollbarWidth(
      OverlayScrollbarClipBehavior = kIgnorePlatformOverlayScrollbarSize) const;
  virtual int HorizontalScrollbarHeight(
      OverlayScrollbarClipBehavior = kIgnorePlatformOverlayScrollbarSize) const;

  virtual LayoutBox* GetLayoutBox() const { return nullptr; }

  // Maps a quad from the coordinate system of a LayoutObject contained by the
  // ScrollableArea to the coordinate system of the ScrollableArea's visible
  // content rect.  If the LayoutObject* argument is null, the argument quad is
  // considered to be in the coordinate space of the overflow rect.
  virtual FloatQuad LocalToVisibleContentQuad(const FloatQuad&,
                                              const LayoutObject*,
                                              unsigned = 0) const;

  virtual bool IsLocalFrameView() const { return false; }
  virtual bool IsPaintLayerScrollableArea() const { return false; }
  virtual bool IsRootFrameViewport() const { return false; }

  // Returns true if the scroller adjusts the scroll offset to compensate
  // for layout movements (bit.ly/scroll-anchoring).
  virtual bool ShouldPerformScrollAnchoring() const { return false; }

  // Need to promptly let go of owned animator objects.
  EAGERLY_FINALIZE();
  virtual void Trace(blink::Visitor*);

  virtual void ClearScrollableArea();

  virtual ScrollAnchor* GetScrollAnchor() { return nullptr; }

  virtual void DidScrollWithScrollbar(ScrollbarPart, ScrollbarOrientation) {}

  // Returns the task runner to be used for scrollable area timers.
  // Ideally a frame-specific throttled one can be used.
  virtual scoped_refptr<WebTaskRunner> GetTimerTaskRunner() const = 0;

  // Callback for compositor-side scrolling.
  virtual void DidScroll(const gfx::ScrollOffset&);

  virtual void ScrollbarFrameRectChanged() {}

  virtual ScrollbarTheme& GetPageScrollbarTheme() const = 0;

 protected:
  ScrollableArea();

  ScrollbarOrientation ScrollbarOrientationFromDirection(
      ScrollDirectionPhysical) const;
  float ScrollStep(ScrollGranularity, ScrollbarOrientation) const;

  void SetScrollOrigin(const IntPoint&);
  void ResetScrollOriginChanged() { scroll_origin_changed_ = false; }

  // Needed to let the animators call scrollOffsetChanged.
  friend class ScrollAnimatorCompositorCoordinator;
  void ScrollOffsetChanged(const ScrollOffset&, ScrollType);

  bool HorizontalScrollbarNeedsPaintInvalidation() const {
    return horizontal_scrollbar_needs_paint_invalidation_;
  }
  bool VerticalScrollbarNeedsPaintInvalidation() const {
    return vertical_scrollbar_needs_paint_invalidation_;
  }
  bool ScrollCornerNeedsPaintInvalidation() const {
    return scroll_corner_needs_paint_invalidation_;
  }
  void ClearNeedsPaintInvalidationForScrollControls() {
    horizontal_scrollbar_needs_paint_invalidation_ = false;
    vertical_scrollbar_needs_paint_invalidation_ = false;
    scroll_corner_needs_paint_invalidation_ = false;
  }
  void ShowOverlayScrollbars();

  // Called when scrollbar hides/shows for overlay scrollbars. This callback
  // shouldn't do any significant work as it can be called unexpectadly often
  // on Mac. This happens because painting code has to set alpha to 1, paint,
  // then reset to alpha, causing spurrious "visibilityChanged" calls.
  virtual void ScrollbarVisibilityChanged() {}

 private:
  FRIEND_TEST_ALL_PREFIXES(ScrollableAreaTest,
                           PopupOverlayScrollbarShouldNotFadeOut);

  void ProgrammaticScrollHelper(const ScrollOffset&, ScrollBehavior, bool);
  void UserScrollHelper(const ScrollOffset&, ScrollBehavior);

  void FadeOverlayScrollbarsTimerFired(TimerBase*);

  // This function should be overriden by subclasses to perform the actual
  // scroll of the content.
  virtual void UpdateScrollOffset(const ScrollOffset&, ScrollType) = 0;

  virtual int LineStep(ScrollbarOrientation) const;
  virtual int PageStep(ScrollbarOrientation) const;
  virtual int DocumentStep(ScrollbarOrientation) const;
  virtual float PixelStep(ScrollbarOrientation) const;

  mutable Member<ScrollAnimatorBase> scroll_animator_;
  mutable Member<ProgrammaticScrollAnimator> programmatic_scroll_animator_;

  std::unique_ptr<TaskRunnerTimer<ScrollableArea>>
      fade_overlay_scrollbars_timer_;

  unsigned scrollbar_overlay_color_theme_ : 2;

  unsigned scroll_origin_changed_ : 1;

  unsigned horizontal_scrollbar_needs_paint_invalidation_ : 1;
  unsigned vertical_scrollbar_needs_paint_invalidation_ : 1;
  unsigned scroll_corner_needs_paint_invalidation_ : 1;
  unsigned scrollbars_hidden_ : 1;
  unsigned scrollbar_captured_ : 1;
  unsigned mouse_over_scrollbar_ : 1;

  // Indicates that the next compositing update needs to call
  // WebLayer::showScrollbars on our scroll layer. Ignored if not composited.
  unsigned needs_show_scrollbar_layers_ : 1;

  // There are 6 possible combinations of writing mode and direction. Scroll
  // origin will be non-zero in the x or y axis if there is any reversed
  // direction or writing-mode. The combinations are:
  // writing-mode / direction     scrollOrigin.x() set    scrollOrigin.y() set
  // horizontal-tb / ltr          NO                      NO
  // horizontal-tb / rtl          YES                     NO
  // vertical-lr / ltr            NO                      NO
  // vertical-lr / rtl            NO                      YES
  // vertical-rl / ltr            YES                     NO
  // vertical-rl / rtl            YES                     YES
  IntPoint scroll_origin_;
};

}  // namespace blink

#endif  // ScrollableArea_h
