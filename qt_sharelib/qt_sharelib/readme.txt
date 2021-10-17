dll_global 中这样定义宏:
#if defined(DLL_LIBRARY)
#  define DLL_EXPORT Q_DECL_EXPORT
#else
#  define DLL_EXPORT Q_DECL_IMPORT
#endif



DLL_LIBRARY 决定了 DLL_EXPORT 是导入还是导出,
DLL_LIBRARY 定义在dll.pro中:   DEFINES += DLL_LIBRARY



DLL_EXPORT 最终还是以两种方式呈现
一：__declspec(dllexport)
二：__declspec(dllimport)

