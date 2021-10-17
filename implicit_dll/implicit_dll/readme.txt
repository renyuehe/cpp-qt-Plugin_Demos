 
注意：
_declspec(dllexport)
不加就只有dll， 加了就有lib 和dll


隐式调用
#pragma comment(lib,"dll.lib") //等价于 qmake 中的 LIBS += ...
#pragma comment(lib,"dll.lib") //注意：这句不是C++语句，而是编译预处理语句，路径时该文件widget.cpp的路径,而不是最终的可执行程序.exe的路径

