--- third_party/blink/renderer/core/page/context_menu_controller.cc.orig	2025-06-30 07:04:30 UTC
+++ third_party/blink/renderer/core/page/context_menu_controller.cc
@@ -654,7 +654,7 @@ bool ContextMenuController::ShowContextMenu(LocalFrame
     if (potential_image_node != nullptr &&
         IsA<HTMLCanvasElement>(potential_image_node)) {
       data.media_type = mojom::blink::ContextMenuDataMediaType::kCanvas;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // TODO(crbug.com/40902474): Support reading from the WebGPU front buffer
       // on Linux and remove the below code, which results in "Copy Image" and
       // "Save Image To" being grayed out in the context menu.
