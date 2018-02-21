// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef OriginTrialFeatures_h
#define OriginTrialFeatures_h

#include "platform/PlatformExport.h"
#include "platform/wtf/text/WTFString.h"
#include "v8/include/v8.h"

namespace blink {

class ScriptState;
struct WrapperTypeInfo;

using InstallOriginTrialFeaturesFunction = void (*)(const WrapperTypeInfo*,
                                                    const ScriptState*,
                                                    v8::Local<v8::Object>,
                                                    v8::Local<v8::Function>);

using InstallOriginTrialFeaturesOnGlobalFunction =
    void (*)(const WrapperTypeInfo*, const ScriptState*);

using InstallPendingOriginTrialFeatureFunction = void (*)(const String&,
                                                          const ScriptState*);

// Sets the function to be called by |InstallOriginTrialFeatures|. The function
// is initially set to the private |InstallOriginTrialFeaturesDefault| function,
// but can be overridden by this function. A pointer to the previously set
// function is returned, so that functions can be chained.
PLATFORM_EXPORT InstallOriginTrialFeaturesFunction
    SetInstallOriginTrialFeaturesFunction(InstallOriginTrialFeaturesFunction);

// Sets the function to be called by |InstallOriginTrialFeaturesOnGlobal|. It is
// initially set to the private |InstallOriginTrialFeaturesOnGlobalDefault|
// function, but can be overridden by this function. A pointer to the previously
// set function is returned, so that functions can be chained.
PLATFORM_EXPORT InstallOriginTrialFeaturesOnGlobalFunction
    SetInstallOriginTrialFeaturesOnGlobalFunction(
        InstallOriginTrialFeaturesOnGlobalFunction);

// Sets the function to be called by |InstallPendingOriginTrialFeature|. This
// is initially set to the private |InstallPendingOriginTrialFeatureDefault|
// function, but can be overridden by this function. A pointer to the previously
// set function is returned, so that functions can be chained.
PLATFORM_EXPORT InstallPendingOriginTrialFeatureFunction
    SetInstallPendingOriginTrialFeatureFunction(
        InstallPendingOriginTrialFeatureFunction);

// Installs all of the conditionally enabled V8 bindings for the given type, in
// a specific context. This is called in V8PerContextData, after the constructor
// and prototype for the type have been created. It indirectly calls the
// function set by |SetInstallOriginTrialFeaturesFunction|.
PLATFORM_EXPORT void InstallOriginTrialFeatures(const WrapperTypeInfo*,
                                                const ScriptState*,
                                                v8::Local<v8::Object>,
                                                v8::Local<v8::Function>);

// Installs all of the conditionally enabled V8 bindings for the given global
// type (i.e. marked in IDL by [Global] or [PrimaryGlobal]). Specifically,
// global objects must have members on the instance itself, instead of the
// prototype (see https://heycam.github.io/webidl/#Global). This means the
// InstallOriginTrialFeatures() method is insufficient for all conditional V8
// bindings.
PLATFORM_EXPORT void InstallOriginTrialFeaturesOnGlobal(const WrapperTypeInfo*,
                                                        const ScriptState*);

// Installs all of the conditionally enabled V8 bindings for a feature, if
// needed. This is called to install a newly-enabled feature on any existing
// objects. If the target object hasn't been created, nothing is installed. The
// enabled feature will be instead be installed when the object is created
// (avoids forcing the creation of objects prematurely).
PLATFORM_EXPORT void InstallPendingOriginTrialFeature(const String&,
                                                      const ScriptState*);

}  // namespace blink

#endif  // OriginTrialFeatures_h
