--- src/3rdparty/chromium/printing/printing_features.cc.orig	2024-07-30 11:12:21 UTC
+++ src/3rdparty/chromium/printing/printing_features.cc
@@ -21,12 +21,12 @@ BASE_FEATURE(kAddPrinterViaPrintscanmgr,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 // Use the CUPS IPP printing backend instead of the original CUPS backend that
 // calls the deprecated PPD API.
 BASE_FEATURE(kCupsIppPrintingBackend,
              "CupsIppPrintingBackend",
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_DISABLED_BY_DEFAULT
 #else
              base::FEATURE_ENABLED_BY_DEFAULT
