--- remoting/host/webauthn/remote_webauthn_caller_security_utils.cc.orig	2025-05-07 06:48:23 UTC
+++ remoting/host/webauthn/remote_webauthn_caller_security_utils.cc
@@ -10,7 +10,7 @@
 #include "base/strings/utf_string_conversions.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "base/containers/fixed_flat_set.h"
 #include "base/files/file_path.h"
 #include "base/process/process_handle.h"
@@ -38,7 +38,7 @@ namespace {
 
 // No static variables needed for debug builds.
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 constexpr auto kAllowedCallerPrograms =
     base::MakeFixedFlatSet<base::FilePath::StringViewType>({
@@ -83,7 +83,7 @@ bool IsLaunchedByTrustedProcess() {
 #if !defined(NDEBUG)
   // Just return true on debug builds for the convenience of development.
   return true;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::ProcessId parent_pid =
       base::GetParentProcessId(base::GetCurrentProcessHandle());
   // Note that on Linux the process image may no longer exist in its original
