--- media/gpu/test/video_frame_helpers.cc.orig	2025-05-07 06:48:23 UTC
+++ media/gpu/test/video_frame_helpers.cc
@@ -23,7 +23,7 @@
 #include "ui/gfx/buffer_format_util.h"
 #include "ui/gfx/gpu_memory_buffer.h"
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <sys/mman.h>
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
 
