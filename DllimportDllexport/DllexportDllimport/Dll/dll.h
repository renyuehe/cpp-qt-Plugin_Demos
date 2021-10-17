#ifndef DLL_H
#define DLL_H

//dll导出类
class __declspec(dllexport) Dll
{
public:
    Dll();
    void run();
};

//dll导出函数
__declspec(dllexport) void run();

#endif // DLL_H
