--- chrome/browser/ui/browser.h.orig	2025-02-02 01:39:08 UTC
+++ chrome/browser/ui/browser.h
@@ -301,7 +301,7 @@ class Browser : public TabStripModelObserver,
     std::optional<int64_t> display_id;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // When the browser window is shown, the desktop environment is notified
     // using this ID.  In response, the desktop will stop playing the "waiting
     // for startup" animation (if any).
