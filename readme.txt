//在编程c++dll时 
extern "C"和.def的作用
 extern "c"是c++编译器在编译函数时以c编译器的方式处理函数名
 而.def的作用也是告知编译器以.def导出的文件名的方式编译函数名

动态链接库的使用有两种方式，一种是显式调用。一种是隐式调用。
（1）       显式调用：使用LoadLibrayr载入动态链接库、使用GetProcAddress获取某函数地址。
（2）       隐式调用：可以使用#pragma comment(lib, “XX.lib”)的方式，也可以直接将XX.lib加入到工程中。


----------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------
------------------------------ 动态调用 dll 且只调用 dll --------------------------------------
#### dll-test-dev， dll-test-vs , qtdllTestC#####################################
#### dll-test-dev 和 dll-test-vs 中 通过这种方式：
#include <Windows.h>
//LoadLibrary
//GetProcAddress
//FreeLibrary

#### qtdllTestC 采用了回调函数的方式
#include <Windows.h>
//LoadLibrary
//GetProcAddress
//FreeLibrary

//采用了回调函数的方式

#### onlyDllCall ##################
第一种：LoadLibrary方式，需要 include <windows.h>，但是qt里失败了，虽然vs成功了
第二种：QLibrary方式，成功了

---------------------------------------------------------------------------------------------
需要注意的是 g++ 和 cmake 的不同 ------------------------------
g++：
g++ main.cpp -L./ -lmythread 可以直接连接动态库
cmake 之 CMakeLists.txt：
target_link_libraries(testDll  mypthread) 是无法连接单个动态库的，他会认为你连接的是 .lib

原因：
g++会在so（dll）找导入导出表，但是windows默认是从.lib里面查找函数导入导出表，所以你这里cmake link也认为你是链接的.lib

关于纯动态库连接： g++ 方案是直接连接、cmake 方案是显示调用

----------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------
------------------------------ 动态库调用 但是依赖于 lib --------------------------------------
#### dllimportdllexport  依赖于 lib 的调用方式 #####################################
__declspec(dllexport)   用来导出动态库
__declspec(dllimport)   用来导入动态库

导出和导入方都要包含同样的函数声明方式

#### qt-sharelib , 上述方式的升级版 #####################################
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

#### implicit_dll #############################################
隐式调用
#pragma comment(lib,"dll.lib")

#pragma comment(lib,"dll.lib") //等价于 qmake 中的 LIBS += ...
#pragma comment(lib,"dll.lib") //注意：这句不是C++语句，而是编译预处理语句，路径时该文件widget.cpp的路径,而不是最终的可执行程序.exe的路径

##########################################################

------------------------------------- 纯C++生成 dll 和 调用 dll -------------------------------------
无


########################################################
########################################################
########################################################
-------------------------------- qt界面插件 ------------------------------------
---------------------------- QtPlugin 		：Qt插件基本实现方式
---------------------------- SimN10 		：N10插件基本实现方式
---------------------------- N10Plugins  		：插件管理器（逻辑），插件装载器（界面）
---------------------------- N10SecondPlugin	：二级插件
---------------------------- N10Base  		：消息发布订阅
#### QtPlugin ： 界面插件简单示例

QPluginLoader
qobject_cast
TestOneInterface //插件接口,名字随便取
Q_PLUGIN_METADATA(IID "org.qt-project.Qt.TestOneInterface" FILE "test1.json")
Q_INTERFACES(TestOneInterface) // 将该接口注册到Qt的meta-object system


----------------------------
#### SimN10 ： 最简单的 N10 框架模拟, 还是直接生成插件的方式

#define ComPluginInterface_IID "org.qt-project.Qt.ComPluginInterface/1.0"
//此宏用于把标识符与类名接口关联起来。这个标识符是唯一的
Q_DECLARE_INTERFACE(ComPluginInterface, ComPluginInterface_IID)
Q_PLUGIN_METADATA(IID ComPluginInterface_IID)
// 将该接口注册到Qt的meta-object system
Q_INTERFACES(ComPluginInterface)

----------------------------
#### N10Plugins : 继承于 SimN10，稍微复杂一点点, 但是还没有做消息发布于订阅的机制, 也没有考虑二级插件的实现
在SimN10的基础上设置了动态库集中路径,
通过map的方式对多个动态库界面进行动态加载。

除了标准的插件接口与 SimN10 中的类似之外，
采用了插件管理器： ComPluginManager（插件逻辑层）：用于管理插件，加载插件，map存放插件
以及插件空间窗体：WorkSpaceWidget（界面层）：用于存放插件窗体

----------------------------
#### N10SecondPlugin ：继承于 N10Plugins ，主要实现了二级插件
二级插件的加载方式和主程序加载插件是一样的，这里只是简单的实现了。
重点是如何管理二级插件，代码框架写好才是最重要的

----------------------------
#### N10Base ： 基于以上N10经验，采用消息发布订阅方式

N10Base：继承于 N10Plugins ，在多插件管理器的基础上，增加了一个单例发消息动态库（ComInstance），实现了消息发布订阅。

消息发布订阅的核心就是：插件管理器里面有一个  map<int, list<plugin>> ，map<订阅号, list<插件>>。

一个订阅号可以对应多个插件。

插件对话框 通过 单例发消息动态库（ComInstance）来发消息（信号）， 插件管理器关联了该信号，并通过 map<订阅号, list<插件>> 来处理该信号。

