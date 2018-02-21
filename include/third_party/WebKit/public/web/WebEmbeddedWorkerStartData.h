/*
 * Copyright (C) 2013 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef WebEmbeddedWorkerStartData_h
#define WebEmbeddedWorkerStartData_h

#include "public/platform/WebAddressSpace.h"
#include "public/platform/WebContentSecurityPolicy.h"
#include "public/platform/WebString.h"
#include "public/platform/WebURL.h"
#include "public/web/WebSettings.h"

namespace blink {

struct WebEmbeddedWorkerStartData {
  enum PauseAfterDownloadMode {
    kDontPauseAfterDownload,
    kPauseAfterDownload,
  };
  enum WaitForDebuggerMode { kDontWaitForDebugger, kWaitForDebugger };

  WebURL script_url;
  WebString user_agent;
  PauseAfterDownloadMode pause_after_download_mode;
  // Whether to pause the initialization and wait for debugger to attach
  // before proceeding. This technique allows debugging worker startup.
  WaitForDebuggerMode wait_for_debugger_mode;
  // Unique worker token used by DevTools to attribute different instrumentation
  // to the same worker.
  WebString instrumentation_token;
  WebSettings::V8CacheOptions v8_cache_options;

  WebAddressSpace address_space;

  WebEmbeddedWorkerStartData()
      : pause_after_download_mode(kDontPauseAfterDownload),
        wait_for_debugger_mode(kDontWaitForDebugger),
        v8_cache_options(WebSettings::kV8CacheOptionsDefault) {}
};

}  // namespace blink

#endif  // WebEmbeddedWorkerStartData_h
