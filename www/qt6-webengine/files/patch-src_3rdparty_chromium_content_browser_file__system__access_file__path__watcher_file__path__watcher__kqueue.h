--- src/3rdparty/chromium/content/browser/file_system_access/file_path_watcher/file_path_watcher_kqueue.h.orig	2024-07-30 11:12:21 UTC
+++ src/3rdparty/chromium/content/browser/file_system_access/file_path_watcher/file_path_watcher_kqueue.h
@@ -5,6 +5,7 @@
 #ifndef CONTENT_BROWSER_FILE_SYSTEM_ACCESS_FILE_PATH_WATCHER_FILE_PATH_WATCHER_KQUEUE_H_
 #define CONTENT_BROWSER_FILE_SYSTEM_ACCESS_FILE_PATH_WATCHER_FILE_PATH_WATCHER_KQUEUE_H_
 
+#include <sys/time.h>
 #include <sys/event.h>
 
 #include <memory>
