--- third_party/blink/renderer/core/paint/paint_layer.cc.orig	2025-06-30 07:04:30 UTC
+++ third_party/blink/renderer/core/paint/paint_layer.cc
@@ -125,7 +125,7 @@ namespace {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 struct SameSizeAsPaintLayer : GarbageCollected<PaintLayer>, DisplayItemClient {
   // The bit fields may fit into the machine word of DisplayItemClient which
   // has only 8-bit data.
