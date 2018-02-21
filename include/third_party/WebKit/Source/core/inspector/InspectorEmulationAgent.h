// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef InspectorEmulationAgent_h
#define InspectorEmulationAgent_h

#include "core/CoreExport.h"
#include "core/inspector/InspectorBaseAgent.h"
#include "core/inspector/protocol/Emulation.h"
#include "platform/scheduler/renderer/web_view_scheduler.h"
#include "platform/wtf/Time.h"

namespace blink {

class WebLocalFrameImpl;
class WebViewImpl;

namespace protocol {
namespace DOM {
class RGBA;
}  // namespace DOM
}  // namespace protocol

class CORE_EXPORT InspectorEmulationAgent final
    : public InspectorBaseAgent<protocol::Emulation::Metainfo>,
      public WebViewScheduler::VirtualTimeObserver {
  WTF_MAKE_NONCOPYABLE(InspectorEmulationAgent);

 public:
  class Client {
   public:
    virtual ~Client() {}

    virtual void SetCPUThrottlingRate(double rate) {}
  };

  static InspectorEmulationAgent* Create(WebLocalFrameImpl*, Client*);
  ~InspectorEmulationAgent() override;

  // protocol::Dispatcher::EmulationCommandHandler implementation.
  protocol::Response resetPageScaleFactor() override;
  protocol::Response setPageScaleFactor(double) override;
  protocol::Response setScriptExecutionDisabled(bool value) override;
  protocol::Response setTouchEmulationEnabled(
      bool enabled,
      protocol::Maybe<int> max_touch_points) override;
  protocol::Response setEmulatedMedia(const String&) override;
  protocol::Response setCPUThrottlingRate(double) override;
  protocol::Response setVirtualTimePolicy(
      const String& policy,
      protocol::Maybe<double> virtual_time_budget_ms,
      protocol::Maybe<int> max_virtual_time_task_starvation_count,
      double* virtual_time_base_ms) override;
  protocol::Response setNavigatorOverrides(const String& platform) override;
  protocol::Response setDefaultBackgroundColorOverride(
      protocol::Maybe<protocol::DOM::RGBA>) override;
  protocol::Response setDeviceMetricsOverride(
      int width,
      int height,
      double device_scale_factor,
      bool mobile,
      protocol::Maybe<double> scale,
      protocol::Maybe<int> screen_width,
      protocol::Maybe<int> screen_height,
      protocol::Maybe<int> position_x,
      protocol::Maybe<int> position_y,
      protocol::Maybe<bool> dont_set_visible_size,
      protocol::Maybe<protocol::Emulation::ScreenOrientation>,
      protocol::Maybe<protocol::Page::Viewport>) override;
  protocol::Response clearDeviceMetricsOverride() override;

  // InspectorBaseAgent overrides.
  protocol::Response disable() override;
  void Restore() override;

  // scheduler::WebViewScheduler::VirtualTimeObserver implementation.
  void OnVirtualTimeAdvanced(WTF::TimeDelta virtual_time_offset) override;
  void OnVirtualTimePaused(WTF::TimeDelta virtual_time_offset) override;

  void Trace(blink::Visitor*) override;

 private:
  InspectorEmulationAgent(WebLocalFrameImpl*, Client*);
  WebViewImpl* GetWebViewImpl();
  void VirtualTimeBudgetExpired();

  Member<WebLocalFrameImpl> web_local_frame_;
  Client* client_;
  bool virtual_time_observer_registered_;
};

}  // namespace blink

#endif  // !defined(InspectorEmulationAgent_h)
