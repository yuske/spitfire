/*
 * Copyright (C) 2011 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef WebIDBDatabaseCallbacksImpl_h
#define WebIDBDatabaseCallbacksImpl_h

#include "modules/indexeddb/IDBDatabaseCallbacks.h"
#include "public/platform/WebString.h"
#include "public/platform/modules/indexeddb/WebIDBDatabaseCallbacks.h"
#include "public/platform/modules/indexeddb/WebIDBDatabaseError.h"

#include <memory>

namespace blink {

class WebIDBDatabaseCallbacksImpl final : public WebIDBDatabaseCallbacks {
  USING_FAST_MALLOC(WebIDBDatabaseCallbacksImpl);

 public:
  static std::unique_ptr<WebIDBDatabaseCallbacksImpl> Create(
      IDBDatabaseCallbacks*);

  ~WebIDBDatabaseCallbacksImpl() override;

  void OnForcedClose() override;
  void OnVersionChange(long long old_version, long long new_version) override;
  void OnAbort(long long transaction_id, const WebIDBDatabaseError&) override;
  void OnComplete(long long transaction_id) override;
  void OnChanges(
      const std::unordered_map<int32_t, std::vector<int32_t>>&
          observation_index_map,
      const WebVector<WebIDBObservation>& observations,
      const IDBDatabaseCallbacks::TransactionMap& transactions) override;
  void Detach() override;

 private:
  explicit WebIDBDatabaseCallbacksImpl(IDBDatabaseCallbacks*);

  Persistent<IDBDatabaseCallbacks> callbacks_;
};

}  // namespace blink

#endif  // WebIDBDatabaseCallbacksImpl_h
