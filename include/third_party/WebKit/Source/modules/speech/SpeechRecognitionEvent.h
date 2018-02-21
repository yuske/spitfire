/*
 * Copyright (C) 2012 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SpeechRecognitionEvent_h
#define SpeechRecognitionEvent_h

#include "modules/EventModules.h"
#include "modules/speech/SpeechRecognitionEventInit.h"
#include "modules/speech/SpeechRecognitionResult.h"
#include "modules/speech/SpeechRecognitionResultList.h"
#include "platform/heap/Handle.h"

namespace blink {

class Document;

class SpeechRecognitionEvent final : public Event {
  DEFINE_WRAPPERTYPEINFO();

 public:
  static SpeechRecognitionEvent* Create(const AtomicString&,
                                        const SpeechRecognitionEventInit&);
  ~SpeechRecognitionEvent() override;

  static SpeechRecognitionEvent* CreateResult(
      unsigned long result_index,
      const HeapVector<Member<SpeechRecognitionResult>>& results);
  static SpeechRecognitionEvent* CreateNoMatch(SpeechRecognitionResult*);

  unsigned long resultIndex() const { return result_index_; }
  SpeechRecognitionResultList* results() const { return results_; }

  // These two methods are here to satisfy the specification which requires
  // these attributes to exist.
  Document* interpretation() { return nullptr; }
  Document* emma() { return nullptr; }

  // Event
  const AtomicString& InterfaceName() const override;

  virtual void Trace(blink::Visitor*);

 private:
  SpeechRecognitionEvent(const AtomicString&,
                         const SpeechRecognitionEventInit&);
  SpeechRecognitionEvent(const AtomicString& event_name,
                         unsigned long result_index,
                         SpeechRecognitionResultList* results);

  unsigned long result_index_;
  Member<SpeechRecognitionResultList> results_;
};

}  // namespace blink

#endif  // SpeechRecognitionEvent_h
