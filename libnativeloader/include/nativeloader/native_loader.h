/*
 * Copyright (C) 2015 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef NATIVE_LOADER_H_
#define NATIVE_LOADER_H_

#include "jni.h"
#include <stdint.h>
#include <string>
#if defined(__ANDROID__)
#include <android/dlext.h>
#endif

namespace android {

__attribute__((visibility("default")))
void InitializeNativeLoader();

__attribute__((visibility("default")))
jstring CreateClassLoaderNamespace(JNIEnv* env,
                                   int32_t target_sdk_version,
                                   jobject class_loader,
                                   bool is_shared,
                                   jstring library_path,
                                   jstring permitted_path);

__attribute__((visibility("default")))
void* OpenNativeLibrary(JNIEnv* env,
                        int32_t target_sdk_version,
                        const char* path,
                        jobject class_loader,
                        jstring library_path,
                        bool* needs_native_bridge,
                        std::string* error_msg);

__attribute__((visibility("default")))
bool CloseNativeLibrary(void* handle, const bool needs_native_bridge);

#if defined(__ANDROID__)
// Look up linker namespace by class_loader. Returns nullptr if
// there is no namespace associated with the class_loader.
__attribute__((visibility("default")))
android_namespace_t* FindNamespaceByClassLoader(JNIEnv* env, jobject class_loader);
#endif

__attribute__((visibility("default")))
void ResetNativeLoader();

};  // namespace android

#endif  // NATIVE_BRIDGE_H_
