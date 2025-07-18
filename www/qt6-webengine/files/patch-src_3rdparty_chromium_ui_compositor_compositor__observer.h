--- src/3rdparty/chromium/ui/compositor/compositor_observer.h.orig	2024-06-17 12:56:06 UTC
+++ src/3rdparty/chromium/ui/compositor/compositor_observer.h
@@ -52,7 +52,7 @@ class COMPOSITOR_EXPORT CompositorObserver {
   // Called when a child of the compositor is resizing.
   virtual void OnCompositingChildResizing(Compositor* compositor) {}
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   // Called when a swap with new size is completed.
   virtual void OnCompositingCompleteSwapWithNewSize(ui::Compositor* compositor,
                                                     const gfx::Size& size) {}
