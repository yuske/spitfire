// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MediaSession_h
#define MediaSession_h

#include <memory>
#include "core/dom/ContextLifecycleObserver.h"
#include "modules/ModulesExport.h"
#include "mojo/public/cpp/bindings/binding.h"
#include "platform/bindings/ScriptWrappable.h"
#include "platform/bindings/TraceWrapperMember.h"
#include "platform/heap/Handle.h"
#include "platform/wtf/text/WTFString.h"
#include "public/platform/modules/mediasession/media_session.mojom-blink.h"

namespace blink {

class ExecutionContext;
class MediaMetadata;
class V8MediaSessionActionHandler;

class MODULES_EXPORT MediaSession final
    : public ScriptWrappable,
      public ContextClient,
      blink::mojom::blink::MediaSessionClient {
  USING_GARBAGE_COLLECTED_MIXIN(MediaSession);
  DEFINE_WRAPPERTYPEINFO();
  USING_PRE_FINALIZER(MediaSession, Dispose);

 public:
  static MediaSession* Create(ExecutionContext*);

  void Dispose();

  void setPlaybackState(const String&);
  String playbackState();

  void setMetadata(MediaMetadata*);
  MediaMetadata* metadata() const;

  void setActionHandler(const String& action, V8MediaSessionActionHandler*);

  // Called by the MediaMetadata owned by |this| when it has updates. Also used
  // internally when a new MediaMetadata object is set.
  void OnMetadataChanged();

  void Trace(blink::Visitor*) override;
  void TraceWrappers(const ScriptWrappableVisitor*) const override;

 private:
  friend class V8MediaSession;
  friend class MediaSessionTest;

  enum class ActionChangeType {
    kActionEnabled,
    kActionDisabled,
  };

  explicit MediaSession(ExecutionContext*);

  void NotifyActionChange(const String& action, ActionChangeType);

  // blink::mojom::blink::MediaSessionClient implementation.
  void DidReceiveAction(blink::mojom::blink::MediaSessionAction) override;

  // Returns null when the ExecutionContext is not document.
  mojom::blink::MediaSessionService* GetService();

  mojom::blink::MediaSessionPlaybackState playback_state_;
  Member<MediaMetadata> metadata_;
  HeapHashMap<String, TraceWrapperMember<V8MediaSessionActionHandler>>
      action_handlers_;
  mojom::blink::MediaSessionServicePtr service_;
  mojo::Binding<blink::mojom::blink::MediaSessionClient> client_binding_;
};

}  // namespace blink

#endif  // MediaSession_h
