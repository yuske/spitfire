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

#ifndef WebServiceWorkerProviderClient_h
#define WebServiceWorkerProviderClient_h

#include "public/platform/WebCommon.h"
#include "public/platform/WebVector.h"
#include "public/platform/modules/serviceworker/WebServiceWorker.h"
#include "public/platform/web_feature.mojom-shared.h"

#include <memory>

namespace blink {

class MessagePortChannel;
class WebServiceWorker;
class WebString;

// See WebServiceWorkerProvider for full documentation.
//
// WebServiceWorkerProviderClient is implemented by ServiceWorkerContainer.
// We probably wouldn't need this abstract class, except we also make a
// MockServiceWorkerProviderClient for unit tests.
class WebServiceWorkerProviderClient {
 public:
  virtual ~WebServiceWorkerProviderClient() {}

  virtual void SetController(std::unique_ptr<WebServiceWorker::Handle>,
                             bool should_notify_controller_change) = 0;

  virtual void DispatchMessageEvent(std::unique_ptr<WebServiceWorker::Handle>,
                                    const WebString& message,
                                    WebVector<MessagePortChannel>) = 0;
  virtual void CountFeature(mojom::WebFeature) = 0;
};

}  // namespace blink

#endif  // WebServiceWorkerProviderClient_h
